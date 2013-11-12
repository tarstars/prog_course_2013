sol = dlmread('sol.txt'); % [v1 v2 v3 phi]

hold on
plot(sol(:,1).*cos(sol(:,4)),  sol(:,1).*sin(sol(:,4)), 'b',...
    'LineWidth',2)
plot(sol(:,2).*cos(sol(:,4)),  sol(:,2).*sin(sol(:,4)), 'r',...
    'LineWidth',2)
plot(sol(:,3).*cos(sol(:,4)),  sol(:,3).*sin(sol(:,4)), 'g',...
    'LineWidth',2)
grid on