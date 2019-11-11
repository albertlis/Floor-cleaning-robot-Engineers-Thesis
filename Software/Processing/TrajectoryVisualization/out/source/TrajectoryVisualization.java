import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class TrajectoryVisualization extends PApplet {


// import java.io.*;

Serial myPort;
PrintWriter file;

public void setup() {
     
    
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

public void draw() {
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


  public void settings() {  size(1000, 1000);  noSmooth(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "TrajectoryVisualization" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
