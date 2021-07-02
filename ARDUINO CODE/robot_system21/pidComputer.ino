
void pidCompute() //10ms
{

  i++;

  MOTOR_POS_RIGHT = cuntR;
  MOTOR_POS_LEFT = cuntL;

  MOTOR_SPEED_RIGHT = MOTOR_POS_RIGHT - MOTOR_POS_RIGHT_LAST;
  MOTOR_SPEED_LEFT = MOTOR_POS_LEFT - MOTOR_POS_LEFT_LAST;
  
 
  
  Err_RIGHT_PWM = (SPEED_SETPOINT_RIGHT) - round(MOTOR_SPEED_RIGHT * FEEDBACK_GAIN);
  Err_LEFT_PWM = (SPEED_SETPOINT_LEFT) - round(MOTOR_SPEED_LEFT * FEEDBACK_GAIN);

  Err_RIGHT_PWM_INTEGRAL = Err_RIGHT_PWM_INTEGRAL + Err_RIGHT_PWM;
  Err_LEFT_PWM_INTEGRAL = Err_LEFT_PWM_INTEGRAL + Err_LEFT_PWM;

  PWM_OUT_RIGHT = round((Kp_RIGHT * Err_RIGHT_PWM) + (Ki_RIGHT * T * Err_RIGHT_PWM_INTEGRAL));
  PWM_OUT_LEFT = round((Kp_LEFT * Err_LEFT_PWM) + (Ki_LEFT * T * Err_LEFT_PWM_INTEGRAL));


  if (PWM_OUT_RIGHT >= 255 )
  {
    PWM_OUT_RIGHT = 255;
  }
  if (PWM_OUT_RIGHT <= -255)
  {
    PWM_OUT_RIGHT = -255;
  }
  ///////////////
  if (PWM_OUT_LEFT >= 255 )
  {
    PWM_OUT_LEFT = 255;
  }
  if (PWM_OUT_LEFT <= -255)
  {
    PWM_OUT_LEFT = -255;
  }

  Go_RIGHT(PWM_OUT_RIGHT);
  Go_LEFT(PWM_OUT_LEFT);

// Dr=Nr*2*pi*Rr/N; meter
Dr=MOTOR_SPEED_RIGHT*.00001568;
Dl=MOTOR_SPEED_LEFT*.00001568;
Dc=(Dl+Dr)/2;
xx=xx+Dc*cos(tetha);
yy=yy+Dc*sin(tetha);
tetha=tetha+(Dr-Dl)/L;
 
  MOTOR_POS_RIGHT_LAST = MOTOR_POS_RIGHT;
  MOTOR_POS_LEFT_LAST = MOTOR_POS_LEFT;

 //  Serial.println(i);
 //  Serial.println(millis());
 //  Serial.println(MOTOR_SPEED_RIGHT);
}
