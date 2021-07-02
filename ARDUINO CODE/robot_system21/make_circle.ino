// radius: meter
void make_circle(float radius, float  radian) {

  double start_tetha = tetha;
  if (radian > 0) {
      

    SPEED_SETPOINT_RIGHT = (radius + (L / 2)) / radius * 100;
    SPEED_SETPOINT_LEFT = (radius - (L / 2)) / radius * 100;
    while ((tetha - start_tetha) < (radian - 0.05) ) {delay(1);};
    SPEED_SETPOINT_RIGHT = (radius + (L / 2)) / radius * 50;
    SPEED_SETPOINT_LEFT = (radius - (L / 2)) / radius * 50;
    while ((tetha - start_tetha) < radian  ){delay(1);} ;
    SPEED_SETPOINT_RIGHT = 0;
    SPEED_SETPOINT_LEFT = 0;
  } else {
    SPEED_SETPOINT_LEFT = (radius + (L / 2)) / radius * 100;
    SPEED_SETPOINT_RIGHT = (radius - (L / 2)) / radius * 100;
    //  2/180*3.1416=0.035   :  2_degree
    while ((tetha - start_tetha) > (radian + 0.05) ) {delay(1);};
    SPEED_SETPOINT_LEFT = (radius + (L / 2)) / radius * 50;
    SPEED_SETPOINT_RIGHT = (radius - (L / 2)) / radius * 50;
    while ((tetha - start_tetha) > radian ) {delay(1);};
    SPEED_SETPOINT_RIGHT = 0; SPEED_SETPOINT_LEFT = 0;

  }
  delay(500);
}
