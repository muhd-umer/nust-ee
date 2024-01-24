function TT = getSignal(mfile, signame, Fs)
    signame = char(signame);
    n = size(mfile, signame, 1);
    t = (0:n - 1)' / Fs;
    I = find((t >= 5.0) & (t <= 7.0)); % random 2.0 sec of data
    TT = timetable(mfile.(signame)(I, 1), 'VariableNames', "Data", 'RowTimes', seconds(t(I)));
end