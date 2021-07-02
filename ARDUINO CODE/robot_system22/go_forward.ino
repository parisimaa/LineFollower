void go_forward(float meter) {
  double start_x = xx, start_y = yy;
  SPEED_SETPOINT_RIGHT = 100; SPEED_SETPOINT_LEFT = 100;
  //check if arrived

  while ((xx - start_x) * (xx - start_x) + (yy - start_y) * (yy - start_y) < (meter - 0.05) * (meter - 0.05)) {
    delay(1);
  };
  SPEED_SETPOINT_RIGHT = +60; SPEED_SETPOINT_LEFT = +60;
  while ((xx - start_x) * (xx - start_x) + (yy - start_y) * (yy - start_y) < (meter) * (meter)) {
    delay(1);
  };

  SPEED_SETPOINT_RIGHT = +0; SPEED_SETPOINT_LEFT = +0;
  delay(500);
}
