clear all;
close all;
k1 = [0.1 0.5 1 5 10];
k2 = 1;
wd = 0.1;
R = 10;
tsym = 200;

sim('RobotDoSrodkaPorownanieParametrowSim');
figure;
plot(xd,yd,'r--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Generator', 'k1 = 0.1', 'k1 = 0.5', 'k1 = 1', 'k1 = 5', 'k1 = 10'},'FontSize', 7, 'NumColumns', 3);
axis([-1 11 -1 12])
print -depsc trajektoriaKwadratPorownaniek1

k1 = 0.1;
k2 = [50 10 5 1];

sim('RobotDoSrodkaPorownanieParametrowSim');
figure
plot(xd,yd,'r--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Generator', 'k2 = 50', 'k2 = 10', 'k2 = 5', 'k2 = 1'},'FontSize', 7, 'NumColumns', 3);
axis([-1 11 -1 12])
print -depsc trajektoriaKwadratPorownaniek2