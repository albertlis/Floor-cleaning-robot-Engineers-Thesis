k1 = 0.2;
k2 = 1;
wd = 0.1;
R = 10;
tsym = 100;

sim('RobotSim.slx');

plot(x,y);
hold on;
plot(xd,yd,'--');
legend('Rzeczywista', 'Genarator');