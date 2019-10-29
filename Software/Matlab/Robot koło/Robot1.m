clear all;
close all;
k1 = 0.1;
k2 = 1;
wd = 0.1;
R = 10;
tsym = 100;

sim('RobotSim1.slx');


plot(x,y);
hold on;
grid on;
plot(xd,yd,'--');
xlabel('x');
ylabel('y');
legend('Trajektoria rzeczywista', 'Trajektoria genarator');
print -depsc trajektoriaKolo