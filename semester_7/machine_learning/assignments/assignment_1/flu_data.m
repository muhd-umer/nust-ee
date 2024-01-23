load flu;
Y = double(flu(:,2:end-1));
[n,d] = size(Y);
x = flu.WtdILI;
figure;
regions = flu.Properties.VarNames(2:end-1);
plot(x,Y,'x')
legend(regions,'Location','NorthWest')
% Export files
savemat = [x Y];
save("flu_data.mat", "savemat")
t = dataset2table(flu);
writetable(t, "flu_data.csv")