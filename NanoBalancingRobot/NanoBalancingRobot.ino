#include "MPU9250.h"
#include "motors.h"
#include <PID_v1.h>


MPU9250 mpu;
double SetpointPID, InputPID, OutputPID;
double Kp= 100 , Ki=0, Kd=0;
PID myPID(&InputPID, &OutputPID, &SetpointPID, Kp, Ki, Kd, DIRECT);
rotation rot; 


void setup()
{
    Serial.begin(115200);
    Wire.begin();

    delay(2000);
    mpu.setup();

    turnOffMotors();
    set_motors_pins_output(); 

    for(int i = 0 ;i <1000;i++)//get true value by measuring of many times
      mpu.update();

    SetpointPID = mpu.getPitch();//default point is starting point
     
    //turn the PID on
    myPID.SetMode(AUTOMATIC);
}

void loop()
{
   // static uint32_t prev_ms = millis();
    //if ((millis() - prev_ms) > 16)
    //{
       
        mpu.update();
        InputPID= mpu.getPitch();

        if (InputPID < SetpointPID)
        {
          rot = LEFT;
        }
        else
        {
          InputPID = SetpointPID - InputPID ; //other side should has also values of control (PID returns ~0 when overshots)
          rot = RIGHT;
        }


        
        myPID.Compute();
//       if (InputPID < SetpointPID)
//          OutputPID = -255;
//       else
//          OutputPID = 255;

        int motor_speed = 0;
        
        if (OutputPID < 0)
        {
            motor_speed = -OutputPID;
        }
        else
        {
            motor_speed = OutputPID;
        }

        if (motor_speed > 255)
            motor_speed = 255;
          
         // motor_speed =0 ;
        motorControl(1,motor_speed,rot);
        motorControl(2,motor_speed,rot);
        

        Serial.print("motor_speed: ");
        Serial.print(motor_speed);

        if (rot == LEFT)
          Serial.println(", rotation: LEFT");
        else if (rot == RIGHT)
          Serial.println(", rotation: RIGHT");

        Serial.print("Input PID:");
        Serial.println(InputPID);

        Serial.print("Output PID:");
        Serial.println(OutputPID);

        Serial.print("Setpoint PID:");
        Serial.println(SetpointPID);

      //  prev_ms = millis();
    //}
//    delay(1000);
}
