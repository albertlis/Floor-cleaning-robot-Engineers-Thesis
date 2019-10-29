clear all;
close all;
k1 = 1;
k2 = 10;
tsym = 80;
R = 0.034;
l = 0.095;

sim('RobotDoSrodka10cmLimitSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Trajektoria genarator', 'Trajektoria rzeczywista'}, 'NumColumns', 2);
axis([-0.1 1.1 -0.1 1.15])
print -depsc trajektoriaKwadratk1=1k2=10d02s01

figure;
plot(t, fi1);
hold on;
grid on;
plot(t, fi2, '--');
xlabel('t [s]');
ylabel('obr\s');
legend('Lewe', 'Prawe');
%axis([0 130 -8 8])
print -depsc predkosciKolKwadratk1=1k2=10d02s01