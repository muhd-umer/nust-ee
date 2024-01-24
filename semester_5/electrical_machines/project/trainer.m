run('data.m');
mdl = 'model';
% open_system(mdl)

%% Create observation specifications
numObservations = 8;
observationInfo = rlNumericSpec([numObservations 1], "DataType", dataType);
observationInfo.Name = 'observations';
observationInfo.Description = 'Information on error and reference signal';

%% Create action specifications
numActions = 2;
actionInfo = rlNumericSpec([numActions 1], "DataType", dataType);
actionInfo.Name = 'vqdRef';
agentblk = 'model/Current Controller/Control Variant Subsystem/TD3 Agent/RL Agent';
env = rlSimulinkEnv(mdl, agentblk, observationInfo, actionInfo);
env.ResetFcn = @resetEnv;

%% Create agent
rng(0) % fix the random seed

statePath = [featureInputLayer(numObservations, 'Normalization', 'none', 'Name', 'State')
             fullyConnectedLayer(64, 'Name', 'fc1')];
actionPath = [featureInputLayer(numActions, 'Normalization', 'none', 'Name', 'Action')
              fullyConnectedLayer(64, 'Name', 'fc2')];
commonPath = [additionLayer(2, 'Name', 'add')
              reluLayer('Name', 'relu2')
              fullyConnectedLayer(32, 'Name', 'fc3')
              reluLayer('Name', 'relu3')
              fullyConnectedLayer(16, 'Name', 'fc4')
              fullyConnectedLayer(1, 'Name', 'CriticOutput')];
criticNetwork = layerGraph();
criticNetwork = addLayers(criticNetwork, statePath);
criticNetwork = addLayers(criticNetwork, actionPath);
criticNetwork = addLayers(criticNetwork, commonPath);
criticNetwork = connectLayers(criticNetwork, 'fc1', 'add/in1');
criticNetwork = connectLayers(criticNetwork, 'fc2', 'add/in2');
criticOptions = rlRepresentationOptions('LearnRate', 1e-4, 'GradientThreshold', 1);

critic1 = rlQValueRepresentation(criticNetwork, observationInfo, actionInfo, ...
    'Observation', {'State'}, 'Action', {'Action'}, criticOptions);
critic2 = rlQValueRepresentation(criticNetwork, observationInfo, actionInfo, ...
    'Observation', {'State'}, 'Action', {'Action'}, criticOptions);

actorNetwork = [featureInputLayer(numObservations, 'Normalization', 'none', 'Name', 'State')
                fullyConnectedLayer(64, 'Name', 'actorFC1')
                reluLayer('Name', 'relu1')
                fullyConnectedLayer(32, 'Name', 'actorFC2')
                reluLayer('Name', 'relu2')
                fullyConnectedLayer(numActions, 'Name', 'Action')
                tanhLayer('Name', 'tanh1')];
actorOptions = rlRepresentationOptions('LearnRate', 1e-3, 'GradientThreshold', 1, ...
    'L2RegularizationFactor', 0.001);
actor = rlDeterministicActorRepresentation(actorNetwork, observationInfo, actionInfo, ...
    'Observation', {'State'}, 'Action', {'tanh1'}, actorOptions);
Ts_agent = Ts;
agentOptions = rlTD3AgentOptions("SampleTime", Ts_agent, ...
    "DiscountFactor", 0.995, ...
    "ExperienceBufferLength", 2e6, ...
    "MiniBatchSize", 512, ...
    "NumStepsToLookAhead", 1, ...
    "TargetSmoothFactor", 0.005, ...
    "TargetUpdateFrequency", 10);

agentOptions.ExplorationModel.Variance = 0.05;
agentOptions.ExplorationModel.VarianceDecayRate = 2e-4;
agentOptions.ExplorationModel.VarianceMin = 0.001;
agentOptions.TargetPolicySmoothModel.Variance = 0.1;
agentOptions.TargetPolicySmoothModel.VarianceDecayRate = 1e-4;

agent = rlTD3Agent(actor, [critic1, critic2], agentOptions);

%% Trainer
T = 1.0;
maxepisodes = 100;
maxsteps = ceil(T / Ts_agent);
trainingOpts = rlTrainingOptions( ...
    'MaxEpisodes', maxepisodes, ...
    'MaxStepsPerEpisode', maxsteps, ...
    'StopTrainingCriteria', 'AverageReward', ...
    'StopTrainingValue', -190, ...
    'SaveAgentCriteria', 'EpisodeCount', ...
    'SaveAgentValue', 5, ...
    'ScoreAveragingWindowLength', 10);

doTraining = true;
trainingStats = train(agent, env, trainingOpts);    
