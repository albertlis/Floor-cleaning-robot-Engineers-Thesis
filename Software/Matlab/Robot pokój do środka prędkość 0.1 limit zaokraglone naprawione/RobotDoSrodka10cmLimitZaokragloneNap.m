clear all;
close all;
k1 = 10;
k2 = 100;
tsym = 71;
R = 0.034;
l = 0.0965;
wheelSpeedRadiansLimit = 8;

sim('RobotDoSrodka10cmLimitZaokragloneNapSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Trajektoria genarator', 'Trajektoria rzeczywista'}, 'NumColumns', 2);
axis([-0.1 1.1 -0.1 1.15])
print -depsc trajektoriaKwadratk1=1k2=10d02s01LimitZaokragloneNaprawione

figure;
plot(t, fi1);
hold on;
grid on;
plot(t, fi2, '--');
xlabel('t [s]');
ylabel('obr\s');
legend('Lewe', 'Prawe');
%axis([0 130 -8 8])
xlim([0 tsym]);
print -depsc predkosciKolKwadratk1=1k2=10d02s01LimitZaokragloneNaprawione

figure
plot(t, Fid);
hold on;
grid on;
plot(t, Fi, '--');
legend('K¹t zadany', 'K¹t rzeczywisty');
xlabel('t[s]');
ylabel('rad');
xlim([0 tsym]);
print -depsc katyKwadratk1=1k2=10d02s01LimitZaokragloneNaprawione