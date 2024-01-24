function u = unitstep(k, n)
    u = zeros(1, length(n));
    indexer = find(n == k);
    u(indexer:length(u)) = 1;
    stem(n, u);
    grid on
    title('Unit Step u[k - n]')
    xlabel('n')
    ylabel('u[n]')
end