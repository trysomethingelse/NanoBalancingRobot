

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
    if (motor_direction == RIGHT)
    {
      digitalWrite(MOTOR2_Right_Enable, LOW);
      analogWrite(MOTOR2_Right_PWM, 0);
      
      digitalWrite(MOTOR2_Left_Enable, HIGH);
      analogWrite(MOTOR2_Left_PWM, motor_speed);
      
    }
    else if(motor_direction == LEFT)
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
