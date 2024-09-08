#include <AFMotor.h>
//(Make adjustment for left and right diretion. I am assuming left and right and will be including in the code.)
AF_DCMotor motor1(1); // Base motor 1  LEFT
AF_DCMotor motor2(2); // Base motor 2  RIGHT
AF_DCMotor motor3(3); // Garbage pull motor 1 LEFT
AF_DCMotor motor4(4); // Garbage pull motor 2 RIGHT
void setup() {
  Serial.begin(9600);
  // Change Speed as per your requirement maxmimum value = 255, minimum value = 0
  motor1.setSpeed(200); // Motor 1 Speed
  motor2.setSpeed(200); // Motor 2 Speed
  motor3.setSpeed(200); // Motor 3 Speed
  motor4.setSpeed(200); // Motor 4 Speed
  master_stop();

}

void loop() {
  if (Serial.available()){
    String input = Serial.readString();
    if (input == "F"){
        motor1.run(FORWARD);
        motor2.run(FORWARD);
    }
    else if (input == "B"){
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
    }
    else if (input == "L"){
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
    }
    else if (input == "R"){
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
    }
    else if (input == "O"){
        motor3.run(RELEASE); // Stop Motor 3
        motor4.run(RELEASE); // Stop Motor 4
    }
    else if (input == "S"){
        motor1.run(RELEASE); // Stop Motor 1
        motor2.run(RELEASE); // Stop Motor 2
    }

    else if (input == "N"){
        motor3.run(FORWARD); // Make it backward if it don't fulfil your desire.
        motor4.run(FORWARD); // Make it backward if it don't fulfil your desire.
    }

    else{
        master_stop();
    }
  }
}

void master_stop(){
    motor1.run(RELEASE); // Stop Motor 1
    motor2.run(RELEASE); // Stop Motor 2
    motor3.run(RELEASE); // Stop Motor 3
    motor4.run(RELEASE); // Stop Motor 4
}
