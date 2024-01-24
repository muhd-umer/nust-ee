function writeMemberData(filename, data)
    save(filename, '-v7.3', '-append', '-struct', 'data');
end