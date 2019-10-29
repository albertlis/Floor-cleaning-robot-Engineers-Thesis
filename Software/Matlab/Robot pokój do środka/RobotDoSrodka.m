k1 = 0.2;
k2 = 1;
R = 0.034;
l = 0.095;
tsym = 200;

sim('RobotDoSrodkaSim');

plot(x,y);
hold on;
grid on;
plot(xd,yd,'--');
xlabel('x');
ylabel('y');
legend('Trajektoria rzeczywista', 'Trajektoria genarator');
axis([-1 11 -1 11])
print -depsc trajektoriaKwadratk1=02k2=10s1

k1 = 1;
k2 = 10;
tsym = 130;

sim('RobotDoSrodkaSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Trajektoria genarator', 'Trajektoria rzeczywista'}, 'NumColumns', 2);
axis([-1 11 -1 11.5])
print -depsc trajektoriaKwadratk1=1k2=10

figure;
plot(t, fi1);
hold on;
grid on;
plot(t, fi2, '--');
xlabel('t [s]');
ylabel('obr\s');
legend('Lewe', 'Prawe');
%axis([0 130 -8 8])
print -depsc predkosciKolKwadratk1=1k2=10