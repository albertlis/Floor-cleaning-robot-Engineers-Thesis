k1 = 0.1;
k2 = 1;
R = 0.034;
l = 0.095;
tsym = 160;
%s = 'generator';
%for i = 20:40
   % Legend{i} = ['k2 ' num2str(i/10, 2)];
%end
sim('RobotRownolegleSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend('Trajektoria genarator', 'Trajektoria rzeczywista');
axis([-1 15 -1 12])
print -depsc trajektoriaRownoleglek1=02k2=10s1

k1 = 1;
k2 = 10;
tsym = 130;

sim('RobotRownolegleSim');
figure;
plot(xd,yd,'--');
hold on;
grid on;
plot(x,y);
xlabel('x');
ylabel('y');
legend({'Trajektoria genarator', 'Trajektoria rzeczywista'}, 'NumColumns', 2);
axis([-1 11 -1 11.5])
print -depsc trajektoriaRownoleglek1=1k2=10

figure;
plot(t, fi1);
hold on;
grid on;
plot(t, fi2, '--');
xlabel('t [s]');
ylabel('obr\s');
legend('Lewe', 'Prawe');
axis([0 130 -8 8])
print -depsc predkosciKolRownoleglek1=1k2=10
