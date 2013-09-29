c = dlmread('a.txt');

%plot(c(:,1),c(:,2), c(:,1),c(:,3))  %circlewalk

plot(c(:,1),c(:,2))  %PolyEq
axis([0 6 0 10])

grid on