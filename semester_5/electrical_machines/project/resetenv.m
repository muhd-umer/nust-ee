function in = resetEnv(in)
    blk = 'model/Simulaton Mode/SimMode/Trainer/SpeedRef';
    refSpeedValues = [0.2, 0.4, 0.6, 0.8];
    idx = randperm(length(refSpeedValues), 1);
    refspeed = refSpeedValues(idx);
    in = setBlockParameter(in, blk, 'Time', '0');
    in = setBlockParameter(in, blk, 'Before', '0');
    in = setBlockParameter(in, blk, 'After', num2str(refspeed));

end
