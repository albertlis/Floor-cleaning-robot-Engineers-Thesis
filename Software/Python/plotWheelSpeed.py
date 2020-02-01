import matplotlib.pyplot as plt
import serial

# ser = serial.Serial('COM5', 7200000)
file = open("data.txt", "r")

phi1 = list()
phi2 = list()
fid = list()
fi = list()
vGiven = list()
wGiven = list()
vRobot = list()
wRobot = list()
time = list()
X1 = list()
Y1 = list()
X2 = list()
Y2 = list()
P11 = list()
P21 = list()

xlimit = 110
# print(ser.readline())
for line in file:
    line.strip()
    # line = ser.readline().decode('utf-8')
    # line = file.readline()
    if len(line) < 2:
        continue
    lineSplited = line.split()
    # print(lineSplited[0])
    # lineFloats = map(float, lineSplited)
    lineFloats = [float(i) for i in lineSplited]
    # print(lineFloats)
    x1, y1, x2, y2, p11, p12, p21, p22, fd, f, vd, wd, vr, wr, t = lineFloats
    phi1.append(p11)
    phi2.append(p12)
    fid.append(fd)
    fi.append(f)
    vGiven.append(vd)
    wGiven.append(wd)

    # wRobot.append(wr)
    time.append(t/1000.0)
    X1.append(x1)
    Y1.append(y1)
    X2.append(x2)
    Y2.append(y2)
    if p21 < 2.0:
        P11.append(p21)
    else:
        P11.append(P11[-1])
    if p22 < 2.0:
        P21.append(p22)
    else:
        P21.append(P11[-1])
    if vr < 0.2:
        vRobot.append(vr)
    else:
        vRobot.append(vRobot[-1])
    if wr < 2.0:
        wRobot.append(wr)
    else:
        wRobot.append(wRobot[-1])
    # file.write(str(x1) + ' ' + str(y1) + ' ' + str(x2) + ' ' + str(y2) + ' ' + str(p11) + ' ' + str(p12) + ' ' + str(p21) + ' ' + str(p22) + ' ' + str(fd) + ' ' + \
    #             str(f) + ' ' + str(vd) + ' ' + str(wd) + ' ' + str(vr) + ' ' + str(wr) + ' ' + str(t) + '\r\n')
    if p21 < 0.01 and p22 < 0.01:
        break
file.close()

plt.figure()
plt.plot(time, P11, '--', label='prawe robot')
plt.plot(time, P21, '--', label='lewe robot')
plt.plot(time, phi2, label='lewe generator')
plt.plot(time, phi1, label='prawe generator')

plt.legend(loc="upper right")
plt.grid()
# plt.title('Prędkości kół')
plt.xlabel('t[s]')
plt.ylabel('obr/s')
# plt.xlim([0, xlimit])
plt.savefig("predkosciKolPythonOstatnie.eps")
plt.savefig("predkosciKolPythonOstatnie..png")

plt.figure()
plt.plot(X2, Y2,'--', label='robot')
plt.plot(X1, Y1, label='generator')
plt.legend(loc="upper right")
plt.grid()
plt.xlabel('x')
plt.ylabel('y')
# plt.xlim([0, xlimit])
plt.savefig("trajektoriaPythonOstatnie.eps")
plt.savefig("trajektoriaPythonOstatnie..png")

plt.figure()
plt.plot(time, fi,'--', label='robot')
plt.plot(time, fid, label='generator')
plt.legend(loc="upper right")
plt.grid()
plt.xlabel('t[s]')
plt.ylabel('rad')
# plt.xlim([0, xlimit])
plt.savefig("katPythonOstatnie.eps")
plt.savefig("katPythonOstatnie..png")

plt.figure()
plt.plot(time, vRobot,'--', label='robot')
plt.plot(time, vGiven, label='generator')
plt.legend(loc="upper right")
plt.grid()
plt.xlabel('t[s]')
plt.ylabel('v[m/s]')
# plt.xlim([0, xlimit])
plt.savefig("predkoscPythonOstatnie.eps")
plt.savefig("predkoscPythonOstatnie..png")

plt.figure()
plt.plot(time, wRobot,'--', label='robot')
plt.plot(time, wGiven, label='generator')
plt.legend(loc="upper right")
plt.grid()
plt.xlabel('t[s]')
plt.ylabel('w[rad/s]')
# plt.xlim([0, xlimit])
plt.savefig("predkoscKatPythonOstatnie.eps")
plt.savefig("predkoscKatPythonOstatnie..png")

plt.show()