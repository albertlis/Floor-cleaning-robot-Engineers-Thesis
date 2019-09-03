import java.util.ArrayList;
import processing.serial.*;
import java.util.Collections;
import java.lang.Math;

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

void setup() {
    size(600, 400);
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

void draw() {
    stroke(255);
    Measurement measurement = readDistanceMeasurements();
    PVector temp = new PVector();
    PVector downCenter = new PVector(width/2, height);
    // int a = measurement.getDistance();
    if(measurement.angle != -1 && measurement.distance != -1 && measurement.distance != 0)
    {
        background(102);
        println("Angle: " + measurement.angle + " Distance: " + measurement.distance);
        lineAngle((int)downCenter.x, (int)downCenter.y, radians(measurement.angle), measurement.distance);

    }
}

Measurement readDistanceMeasurements()
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

void lineAngle(int x, int y, float angle, float length)
{
  line(x, y, x+cos(angle)*length, y-sin(angle)*length);
}
