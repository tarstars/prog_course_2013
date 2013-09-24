c = dlmread('a.txt');
sz = size(c);

ql = linspace(0, 2*pi, sz(2));
yq = linspace(0, 10, sz(1));

[QL, YQ] = meshgrid(ql, yq);
mesh(QL/pi, YQ, c)
xlabel('ql/\pi');
ylabel('\eta/q');