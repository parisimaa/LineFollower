#include <DueTimer.h>

///////////////////
double xx = 0, yy = 0, tetha = 3.1416 / 2.0;
float Dr = 0, Dl = 0, Dc = 0, L = 0.245; // x,y are pulses

boolean DirectionR = LOW;
boolean DirectionL = LOW;
long cuntR = 0;
long cuntL = 0;
int i = 0;

long MOTOR_POS_RIGHT = 0;
long MOTOR_POS_LEFT = 0;
long MOTOR_POS_RIGHT_LAST = 0;
long MOTOR_POS_LEFT_LAST = 0;
int MOTOR_SPEED_RIGHT = 0;
int MOTOR_SPEED_LEFT = 0;

int Err_LEFT_PWM_INTEGRAL = 0;
int Err_RIGHT_PWM_INTEGRAL = 0;


int PWM_OUT_LEFT = 0;
int PWM_OUT_RIGHT = 0;

int Err_RIGHT_PWM = 0;
int Err_LEFT_PWM = 0;

float Kp_RIGHT = 1.5;
float Ki_RIGHT = 60;
float Kd_RIGHT = 0;

float Kp_LEFT = 1.5;
float Ki_LEFT = 60;
float Kd_LEFT = 0;



//// Right Motor////
#define M1R 5
#define M2R 6
#define ENR 7
#define AR 18
#define BR 19

////Left Motor////
#define M1L 11
#define M2L 10
#define ENL 8
#define AL 2
#define BL 3

////Buser & LED////
#define Buser 13
#define LED 37


float T = 0.010;
float FEEDBACK_GAIN = 1.25; //2.47/2
int SPEED_SETPOINT_RIGHT = 0; //100 =>81 pulse/5ms
int SPEED_SETPOINT_LEFT = 0;

void setup() {



  // rightMotor initialization
  pinMode(M1R, OUTPUT);
  pinMode(M2R, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(AR, INPUT);
  pinMode(BR, INPUT);

  //  LeftMotor initialization
  pinMode(M1L, OUTPUT);
  pinMode(M2L, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(AL, INPUT);
  pinMode(BL, INPUT);

  pinMode(Buser, OUTPUT);
  pinMode(LED, OUTPUT);

  attachInterrupt(AR, CunterR, RISING);
  attachInterrupt(AL, CunterL, RISING);

  Serial.begin(38400);

  //start timers
  Timer2.attachInterrupt(pidCompute);
  Timer2.start(10000); // Calls every T=10ms

  delay(5000);

 
}


void loop() {
  for(int i = 1 ; i<=2 ; i++ ){
        go_forward(0.4*1.313064331);//a to b
        delay(1000);
      
        turn(2.179*1.399);//b
        delay(1000);

        go_forward(0.7*1.313064331);//b to d 
        delay(1000);
        
        turn(-2.179*1.399);//d
        delay(1000);
        
        go_forward(0.4*1.313064331);//d to f
        delay(1000);

        turn(2.179*1.399);//f
        delay(1000);

        go_forward(0.23346758*1.313064331);// f to g
        delay(1000);
        
        turn(2.198242193*1.399);//g
        delay(1000);

        go_forward(0.40549515*1.313064331);//g to c
        delay(1000);

        turn(-2.198242193*1.399);//c
        delay(1000);
        
        go_forward(0.23346758*1.313064331);//c to d 
        delay(1000);
        
        turn(-2.179*1.399);//d
        delay(1000);

        go_forward(0.2*1.313064331);//d to e
        delay(1000);

        turn(1.23569311*1.399);//e
        delay(1000);
        
        go_forward(0.2027475*1.313064331);//e to g
        delay(1000);

        turn(0.94335046*1.399);//g
        delay(1000);
        
        go_forward(0.46653242*1.313064331);//g to h
        delay(1000);

        turn(-2.179*1.399);//h
        delay(1000);
        
        go_forward(0.4*1.313064331);//h to i
        delay(1000);

        turn(-1.90589543*1.399);//i
        delay(1000);
        
        go_forward(0.8110225*1.313064331);//i to c
        delay(1000);

        turn(0.94335046*1.399);//c
        delay(1000);
        
        go_forward(0.46653242*1.313064331);//c to b
        delay(1000);

        turn(3.141592654*1.399);//b
        delay(1000);
        
        go_forward(0.46653242*1.313064331);//b to c
        delay(1000);
        
        go_forward(0.23346758*1.313064331);//c to d
        delay(1000);
        
        turn(2.533345409*1.399);//d
        delay(1000);

         go_forward(0.57445626*1.313064331);//d to a
        delay(1000);

         turn(1.570796327*1.399);//a
        delay(1000);
        
        
  }
Serial.print("xx(mm)=");
Serial.println(1000*xx);
  Serial.print("yy(mm)=");
  Serial.println(1000*yy);
  Serial.print("tetha (degree)=");
  Serial.println(tetha*180/3.1416);
  delay(100000);
  }
