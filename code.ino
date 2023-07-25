#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void moveArmTo(double l1, double l2, double x, double z){
  double q1;
  double q2;
  if(z <12.02){
    double curPos2 = servo2.read();
    double curPos3 = servo3.read();
    q2 = PI - acos((l1*l1 + l2*l2 - x*x - z*z)/ (2*l1*l2));
    q1 = atan(x/z) - atan((l2*sin(q2)) / (l1 + l2*cos(q2)));
    q1 = q1 * (180/PI);
    q2 = q2 * (180/PI);
    q1 = 90 - q1;
    q2 = q2 + 90;
    // ---------- MOVING SERVO 2 ----------
    if(curPos2 < q1){
      for(int i = curPos2; i <= q1; i++){
        servo2.write(i);
        delay(15);
      }
    }else{
      for(int i = curPos2; i >= q1; i--){
        servo2.write(i);
        delay(15);
      }
    }
    
    // ---------- MOVING SERVO 3 ----------
    if(curPos3 < q2){
      for(int i = curPos3; i <= q2; i++){
        servo3.write(i);
        delay(15);
      }
    }else{
      for(int i = curPos3; i >= q2; i--){
        servo3.write(i);
        delay(15);
      }
    }

  }else{
    double curPos2 = servo2.read();
    double curPos3 = servo3.read();
    q2 = acos((x*x + z*z - l1*l1 - l2*l2) / (2*l1*l2));
    q1 = atan(x/z) - atan((l2*sin(q2)) / (l1 + l2*cos(q2)));
    q1 = q1 * (180/PI);
    q2 = q2 * (180/PI);
    q1 = q1+45;
    q2 = q2-45;

    
    // ---------- MOVING SERVO 2 ----------
    if(curPos2 < q1){
      for(int i = curPos2; i <= q1; i++){
        servo2.write(i);
        delay(15);
      }
    }else{
      for(int i = curPos2; i >= q1; i--){
        servo2.write(i);
        delay(15);
      }
    }
    
    // ---------- MOVING SERVO 3 ----------
    if(curPos3 < q2){
      for(int i = curPos3; i <= q2; i++){
        servo3.write(i);
        delay(15);
      }
    }else{
      for(int i = curPos3; i >= q2; i--){
        servo3.write(i);
        delay(15);
      }
    }
  }
}

void closeClaw(){
  for(int i = 0 ; i <= 180 ; i++){
    servo4.write(i);
    delay(30);
  }
}

void openClaw(){
  for(int i = 180 ; i >=0 ; i--){
    servo4.write(i);
    delay(30);
  }
}
void setup() {
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);

}

void loop() {
  
}
