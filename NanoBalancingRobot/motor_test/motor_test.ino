#define MOTOR1_Left_PWM 3
#define MOTOR1_Left_Enable 11
#define MOTOR1_Right_PWM 5
#define MOTOR1_Right_Enable 10

#define MOTOR2_Left_PWM 6
#define MOTOR2_Left_Enable 13
#define MOTOR2_Right_PWM 9
#define MOTOR2_Right_Enable 12

enum rotation
{
  LEFT,
  RIGHT,
  NONE
};

void set_motors_pins_output(void);
void motor_control(uint8_t, uint8_t, rotation);
void set_motors_pins_off(void);



void setup() {
  Serial.begin(115200);
  set_motors_pins_off();
  set_motors_pins_output(); 
 
}

void loop() {
  
 

  int counter = 0;
  int counter_dir = 1;
  rotation rot = RIGHT;
  uint8_t motor_speed= 0;
  
 while(1)
 {
    if(counter == 10000)
    {
      counter_dir = -1; 
    }
    if(counter == 0)
    {
      if (rot == LEFT)
        rot = RIGHT;
      else 
        rot = LEFT; 
      counter_dir = 1;
    }
    
    counter += counter_dir;
    Serial.println(counter);
    if ( rot == LEFT) Serial.println("left");
    else Serial.println("right");
    motor_speed = map(counter,0,10000,100,200);
    //motorControl(1,motor_speed,rot);
    motorControl(1,motor_speed,rot);
    motorControl(2,motor_speed,rot);
 }
}


void turnOffMotors()
{
  motorControl(1,0,NONE);
  motorControl(2,0,NONE);
  
}
void motorControl(uint8_t motor_number, uint8_t motor_speed, rotation motor_direction)
{
  if (motor_number == 1)
  {
    if (motor_direction == LEFT)
    {
      digitalWrite(MOTOR1_Right_Enable, LOW);
      analogWrite(MOTOR1_Right_PWM, 0);
      
      digitalWrite(MOTOR1_Left_Enable, HIGH);
      analogWrite(MOTOR1_Left_PWM, motor_speed);
      
    }
    else if(motor_direction == RIGHT)
    {
      digitalWrite(MOTOR1_Left_Enable, LOW);
      analogWrite(MOTOR1_Left_PWM, 0);
      
      digitalWrite(MOTOR1_Right_Enable, HIGH);
      analogWrite(MOTOR1_Right_PWM, motor_speed);
    }
    else
      set_motors_pins_off;
      
  }
  else if (motor_number == 2)
  {
    if (motor_direction == LEFT)
    {
      digitalWrite(MOTOR2_Right_Enable, LOW);
      analogWrite(MOTOR2_Right_PWM, 0);
      
      digitalWrite(MOTOR2_Left_Enable, HIGH);
      analogWrite(MOTOR2_Left_PWM, motor_speed);
      
    }
    else if(motor_direction == RIGHT)
    {
      digitalWrite(MOTOR2_Left_Enable, LOW);
      analogWrite(MOTOR2_Left_PWM, 0);
      
      digitalWrite(MOTOR2_Right_Enable, HIGH);
      analogWrite(MOTOR2_Right_PWM, motor_speed);
    }
  }
    else
      set_motors_pins_off;
}
void set_motors_pins_output(void)
{
  pinMode(MOTOR1_Left_PWM, OUTPUT);
  pinMode(MOTOR1_Left_Enable, OUTPUT);
  pinMode(MOTOR1_Right_PWM, OUTPUT);
  pinMode(MOTOR1_Right_Enable, OUTPUT);

  pinMode(MOTOR2_Left_PWM, OUTPUT);
  pinMode(MOTOR2_Left_Enable, OUTPUT);
  pinMode(MOTOR2_Right_PWM, OUTPUT);
  pinMode(MOTOR2_Right_Enable, OUTPUT);
}
void set_motors_pins_off(void)
{
  digitalWrite(MOTOR1_Left_Enable, LOW);
  digitalWrite(MOTOR1_Right_Enable, LOW);
  analogWrite(MOTOR1_Left_PWM, 0);
  analogWrite(MOTOR1_Right_PWM, 0);

  digitalWrite(MOTOR2_Left_Enable, LOW);
  digitalWrite(MOTOR2_Right_Enable, LOW);
  analogWrite(MOTOR2_Left_PWM, 0);
  analogWrite(MOTOR2_Right_PWM, 0);
}
