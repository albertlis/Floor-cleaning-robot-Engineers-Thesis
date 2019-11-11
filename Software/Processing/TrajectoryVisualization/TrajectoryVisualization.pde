import processing.serial.*;
// import java.io.*;

Serial myPort;
PrintWriter file;

void setup() {
    size(1000, 1000); 
    noSmooth();
    try {
        String portName = Serial.list()[0];
        myPort = new Serial(this, portName, 115200);
    }
    catch(ArrayIndexOutOfBoundsException e) { 
        println("Can't open serial port");
        System.exit(1); 
    }
    while(myPort.available() > 0) 
        myPort.readString(); 
    background(50);
    // try{
        file = createWriter("E:/Pulpit/wheelSpeeds.txt");
    // }
    // catch(IOException e) {}
}

void draw() {
    translate(100, height-10);

    String buffer = new String();
    if(myPort.available() > 0) {
        buffer = myPort.readString();
        buffer = buffer.trim();
    }

    if (!buffer.isEmpty()) {
        String[] splittedBuffer = buffer.split(" ");
        buffer = "";
        // println(splittedBuffer);
        if(splittedBuffer.length == 24 ) {
            // println(splittedBuffer);
            try {
                stroke(255);
                strokeWeight(4);
                int x1Value = Integer.parseInt(splittedBuffer[1]);
                int y1Value = Integer.parseInt(splittedBuffer[3]);
                point(x1Value, -y1Value);
                // println(xValue + " " + yValue);
                stroke(255, 0, 0);
                strokeWeight(3);
                int x2Value = Integer.parseInt(splittedBuffer[5]);
                int y2Value = Integer.parseInt(splittedBuffer[7]);
                point(x2Value, -y2Value);
                double ph1Speed = Double.parseDouble(splittedBuffer[9]);
                double ph2Speed = Double.parseDouble(splittedBuffer[11]);
                double fid = Double.parseDouble(splittedBuffer[13]);
                double fi = Double.parseDouble(splittedBuffer[15]);
                double vGiven = Double.parseDouble(splittedBuffer[17]);
                double wGiven = Double.parseDouble(splittedBuffer[19]);
                double vRobot = Double.parseDouble(splittedBuffer[21]);
                double wRobot = Double.parseDouble(splittedBuffer[23]);
                file.println(ph1Speed + " " + ph2Speed + " " + fid + " " + fi + " " + vGiven + " " + wGiven + " "+ vRobot + " " + wRobot);
                file.flush();
            }
            catch (NumberFormatException e) {};
        }
    }
}


