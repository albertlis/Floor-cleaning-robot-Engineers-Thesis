k1 = 0.2;
k2 = 1;
wd = 0.1;
R = 10;
tsym = 120;
sim('RobotSim2.slx');


plot(x,y);
hold on;
grid on;
plot(xd,yd,'--');
legend('Rzeczywista', 'Genarator');
axis([-2 12 -2 12])