%% PWM Switching frequency
PWM_frequency = 5e3;
T_pwm = 1 / PWM_frequency;

%% Sample Times
Ts = T_pwm;
Ts_simulink = T_pwm / 2;
Ts_motor = T_pwm / 2;
Ts_inverter = T_pwm / 2;
Ts_speed = 10 * Ts;

%% Data type for controller & code-gen
dataType = 'single';

%% System Parameters
pmsm = mcb_SetPMSMMotorParameters('Maxon_EC_Speedgoat');
pmsm.PositionOffset = 0.165;

target = mcb_SetProcessorDetails('F28379D', PWM_frequency);

%% Target & Inverter Parameters
inverter = mcb_SetInverterParameters('BoostXL-DRV8305');
inverter = mcb_updateInverterParameters(pmsm, inverter, target);
inverter.ISenseMax = inverter.ISenseMax * target.ADC_Vref / inverter.ISenseVref;

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm, inverter); %rpm // Base speed of motor at given Vdc

%% PU System details
PU_System = mcb_SetPUSystem(pmsm, inverter);

%% Controller design
PI_params = mcb.internal.SetControllerParameters(pmsm, inverter, PU_System, T_pwm, Ts, Ts_speed);

%Updating delays for simulation
PI_params.delay_Currents = 1;
PI_params.delay_Position = 1;
