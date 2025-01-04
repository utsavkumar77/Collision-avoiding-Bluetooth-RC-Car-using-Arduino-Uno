#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int l_f_i_r_p_s = 14;
int r_f_i_r_p_s = 15;
int l_b_i_r_p_s = 16;
int r_b_i_r_p_s = 17;


char command;

void setup()
{
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
  Serial.begin(9600);
  motor1.setSpeed(160);
  motor2.setSpeed(160);
  motor3.setSpeed(160);
  motor4.setSpeed(160);
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    Serial.println(command);

    Stop(); //initialize with motors stopped

    switch (command) {
      case 'F':
        front();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}

void front()
{
  if ( digitalRead(l_f_i_r_p_s) == HIGH && digitalRead(r_f_i_r_p_s) == HIGH )
  {
    motor1.run(FORWARD);  //rotate the motor clockwise
    motor2.run(FORWARD);  //rotate the motor clockwise
    motor3.run(FORWARD);  //rotate the motor clockwise
    motor4.run(FORWARD);  //rotate the motor clockwise
  }
}

void back()
{
  if ( digitalRead(l_b_i_r_p_s) == HIGH && digitalRead(r_b_i_r_p_s) == HIGH )
  {
    motor1.run(BACKWARD); //rotate the motor anti-clockwise
    motor2.run(BACKWARD); //rotate the motor anti-clockwise
    motor3.run(BACKWARD); //rotate the motor anti-clockwise
    motor4.run(BACKWARD); //rotate the motor anti-clockwise
  }
}

void left()
{
  if ( digitalRead(l_f_i_r_p_s) == HIGH )
  {
    motor1.run(BACKWARD); //rotate the motor anti-clockwise
    motor2.run(BACKWARD); //rotate the motor anti-clockwise
    motor3.run(FORWARD);  //rotate the motor clockwise
    motor4.run(FORWARD);  //rotate the motor clockwise
  }
}

void right()
{
  if ( digitalRead(r_f_i_r_p_s) == HIGH  )
  {
    motor1.run(FORWARD);  //rotate the motor clockwise
    motor2.run(FORWARD);  //rotate the motor clockwise
    motor3.run(BACKWARD); //rotate the motor anti-clockwise
    motor4.run(BACKWARD); //rotate the motor anti-clockwise
  }
  else
  {
    // For Buzzer
  }
}

void Stop()
{

  motor1.run(RELEASE); //stop the motor when release the button
  motor2.run(RELEASE); //stop the motor when release the button
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.run(RELEASE); //stop the motor when release the button
}

