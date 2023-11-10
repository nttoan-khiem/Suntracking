#include <Servo.h>
/*  SCHEMATIC
  => A0 LDR 0 or 1
  => A1 LDR 1 or 0
  => D9 Control Servo
*/
Servo myServo;  // create a servo object
int value1, value2;
int angle = 90;
void setup() {
  myServo.attach(9);   
  myServo.write(angle); //Thực thi đưa góc ban đầu của servo về 90 độ.
  Serial.begin(9600);  // open a serial connection to computer
}
void loop(){
  value1 = analogRead(A0);  // read LDR 1
  value2 = analogRead(A1);  // read LDR 2 //Nếu chiều quay bị ngược hay đổi lại chân.
  Serial.print("A0: ");
  Serial.print(value1);
  Serial.println(" unit");
  Serial.print("A1: ");
  Serial.print(value2);
  Serial.println(" unit");
  Serial.println("==============================================");
  if(value1 > value2){
    if(value1 - value2 > 50){ //Chap nhan sai so (Chấp nhận sai số)
       angle -= 2;
    }
    if(angle > 180){    //giới hạn góc độ từ 0 đến 180 
      angle  = 180;
    } else if (angle < 0){
      angle = 0;
    }
  }else if(value1 < value2){
    if(value1 - value2 < -50){  //Chap nhan sai so (Chấp nhận sai số)
      angle += 2;
    }
    if(angle > 180){    //giới hạn góc độ từ 0 đến 180 
      angle  = 180;
    } else if (angle < 0){
      angle = 0;
    }
  }
  myServo.write(angle); //Thực thi
  delay(100); //delay thời gian chờ servo quây đến góc đã đặt
}