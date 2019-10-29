clear all;
close all;
k1 = 1;
k2 = 10;
R = 0.034;
l = 0.0965;
tsym = 75;
szerokoscMycia = 0.2;
wrToObrPerSecondPrescaler = 7/16;
wrLimit =  2.5 * wrToObrPerSecondPrescaler;
wheelSpeedRadiansLimit = 8;

sim('RobotRownolegle10cmSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend('Trajektoria genarator', 'Trajektoria rzeczywista');
title('Trajektoria');
axis([-0.2 1.1 -0.1 1.1])
print -depsc trajektoriaRownoleglek1=1k2=10s=01d02

figure;
plot(t, fi1);
hold on;
grid on;
plot(t, fi2, '--');
xlabel('t [s]');
ylabel('obr\s');
legend('Lewe', 'Prawe');
title('Prêdkoœci kó³');
%axis([0 75 -2 2])
print -depsc predkoscKolRownoleglek1=1k2=10s=01d02

figure;
plot(t,wr);
grid on;
hold on;
title('Prêdkoœæ k¹towa');