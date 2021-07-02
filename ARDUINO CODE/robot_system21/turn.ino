void turn(float radian) {
  double start_tetha = tetha;
  if (radian > 0) {
    SPEED_SETPOINT_RIGHT = +70; SPEED_SETPOINT_LEFT = -70;
    //  3/180*3.1416=0.05
    while ((tetha - start_tetha) < (radian - 0.05) ) {delay(1);};
    SPEED_SETPOINT_RIGHT = +30; SPEED_SETPOINT_LEFT = -30;
    while ((tetha - start_tetha) < radian ) {delay(1);};
    SPEED_SETPOINT_RIGHT = 0; SPEED_SETPOINT_LEFT = 0;

  } else {
    SPEED_SETPOINT_RIGHT = -70; SPEED_SETPOINT_LEFT = +70;
    //  2/180*3.1416=0.035   :  2_degree
    while ((tetha - start_tetha) > (radian + 0.05) ) {delay(1);};
    SPEED_SETPOINT_RIGHT = -30; SPEED_SETPOINT_LEFT = +30;
    while ((tetha - start_tetha) > radian ) {delay(1);};
    SPEED_SETPOINT_RIGHT = 0; SPEED_SETPOINT_LEFT = 0;

  }
  delay(500);
}
