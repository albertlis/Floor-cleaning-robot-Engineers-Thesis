import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.ArrayList; 
import processing.serial.*; 
import java.util.Collections; 
import java.lang.Math; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Processing extends PApplet {






public class Measurement
{
    public int angle;
    public int distance;
    public Measurement(int angle, int distance)
    {
        this.angle = angle;
        this.distance = distance;
    }
}


Serial myPort;
ArrayList<PVector> points;
final int arraySize = 500;
final int borderSize = 40;

public void setup() {
    
    //fullScreen();
    points = new ArrayList<PVector>(Collections.nCopies(181, new PVector(0,0)));
    try
    {
        String portName = Serial.list()[0];
        myPort = new Serial(this, portName, 115200);
    }
    catch(ArrayIndexOutOfBoundsException e) 
    { 
        println("Can't open serial port");
        System.exit(1); 
    }
    while(myPort.available() > 0) 
        myPort.readString();
    background(102);
}

public void draw() {
    stroke(255);
    Measurement measurement = readDistanceMeasurements();
    PVector temp = new PVector();
    PVector downCenter = new PVector(width/2, height);
    // int a = measurement.getDistance();
    if(measurement.angle != -1 && measurement.distance != -1 && measurement.distance != 0)
    {
        background(102);
        // temp.x = map(cos(radians(measurement.angle)), -1.0, 1.0, -width/2, width/2) + width/2;
        // temp.y = (sin(radians(measurement.angle)) * (float)measurement.distance) + height/2 ;
        // println(temp.y);
        // println("Angle: " + measurement.angle);
        points.set(measurement.angle, temp);
        println("Angle: " + measurement.angle + " Distance: " + measurement.distance);
        // lineAngle((int)downCenter.x, (int)downCenter.y, radians(measurement.angle), measurement.distance);
        /*
        for(int i = 0; i < 180; ++i)
        {
            lineAngle((int)downCenter.x, (int)downCenter.y, measurement.angle, measurement.distance*100)
        }*/
        // line(downCenter.x, downCenter.y, temp.x, temp.y);
        for( PVector point : points)
        {
            lineAngle((int)downCenter.x, (int)downCenter.y, radians(measurement.angle), measurement.distance);
        }
    }
}

public Measurement readDistanceMeasurements()
{
    int angle = new Integer(0);
    int distance = new Integer(0);
    if(myPort.available() > 0)
    {
         delay(10);
        String data = myPort.readString();

        int firstSpacebarIndex = data.indexOf(" ");
        int secondSpacebarIndex = data.indexOf(" ", firstSpacebarIndex+1);
        String angleStr = new String();
        
        if (firstSpacebarIndex != -1)
        {
            try { angleStr = data.substring(firstSpacebarIndex+1, secondSpacebarIndex); }
            catch (StringIndexOutOfBoundsException e) {
                angleStr = "Err";
            }

            try { angle = Integer.parseInt(angleStr); }
            catch (NumberFormatException e) {
                angle = 0;
            } 
            // println(angle);
        }

        int thirdSpecebarIndex = data.lastIndexOf(" ");
        if(thirdSpecebarIndex != -1)
        {
            String distanceStr = data.substring(thirdSpecebarIndex+1);
            try { distanceStr = distanceStr.substring(0, distanceStr.length()-2); }
            catch (StringIndexOutOfBoundsException e) {
                distanceStr = "Error";
            }
            
            try { distance = Integer.parseInt(distanceStr); }
            catch (NumberFormatException e) {
                distance = 0;
            } 
            /*
            if(distanceStr.equals("Error") || angleStr.equals("Err"))
                println(data);
            else 
                println(distance);
                */
            // println(distance);
        }
        return new Measurement(angle, distance);
    }
    // println(angle);
    return new Measurement(-1, -1);
}

public void lineAngle(int x, int y, float angle, float length)
{
  line(x, y, x+cos(angle)*length, y-sin(angle)*length);
}
  public void settings() {  size(600, 400); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Processing" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
