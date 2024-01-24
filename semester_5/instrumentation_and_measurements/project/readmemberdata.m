function T = readMemberData(filename, variables)

    mfile = matfile(filename);
    T = table();

    for i = 1:numel(variables)
        var = variables(i);

        switch var
            case {'Health', 'Load'}
                val = mfile.(var);
            case {'Ia', 'Ib', 'Ic'}
                % Electrical signals
                val = getSignal(mfile, var, mfile.Fs_elec);
            case {'Vib_acpi', 'Vib_axial'}
                % Vibration signals
                val = getSignal(mfile, var, mfile.Fs_vib);
            case {'Vib_acpi_env'}
                % Envelope signals for radial vib
                sig = regexprep(var, '_env', '');
                TT = getSignal(mfile, sig, mfile.Fs_vib);
                % Envelope of band-pass filtered signal
                y = bandpass(TT.Data, [900 1300], mfile.Fs_vib);
                yUpper = envelope(y);
                val = timetable(yUpper, 'VariableNames', "Data", 'RowTimes', TT.Time);
            case {'Vib_axial_env'}
                % Envelope signals for axial vib
                sig = regexprep(var, '_env', '');
                TT = getSignal(mfile, sig, mfile.Fs_vib);
                % Envelope of band-pass filtered signal
                y = bandpass(TT.Data, [900 1300], mfile.Fs_vib);
                yUpper = envelope(y);
                val = timetable(yUpper, 'VariableNames', "Data", 'RowTimes', TT.Time);
            otherwise
                % Other features and signals.
                val = mfile.(var);
        end

        if numel(val) > 1
            val = {val};
        end

        T.(var) = val;
    end

end