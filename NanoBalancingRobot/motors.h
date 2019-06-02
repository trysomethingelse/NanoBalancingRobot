#ifndef _MOTORS_H_
#define _MOTORS_H_

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


#endif //_MOTORS_H_
