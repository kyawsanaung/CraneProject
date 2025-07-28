// Joystick analog input pins
#define XPIN A0   // Joystick 1 - X axis
#define YPIN A1   // Joystick 1 - Y axis
#define XPIN2 A2  // Joystick 2 - X axis

// PWM output pins for motor speed control
#define SPEEDPIN1 11  // Motor 1 PWM
#define SPEEDPIN2 10  // Motor 2 PWM
#define SPEEDPIN3 9   // Motor 3 PWM

// Motor 1 control pins (rotation)
#define MOTOR1_RIGHT 7  // Motor 1 - Clockwise
#define MOTOR1_LEFT 6   // Motor 1 - Counterclockwise

// Motor 2 control pins (vertical motion)
#define MOTOR2_FORWARD 5   // Motor 2 - Forward (up)
#define MOTOR2_BACKWARD 4  // Motor 2 - Backward (down)

// Motor 3 control pins (horizontal motion)
#define MOTOR3_FORWARD 3   // Motor 3 - Forward (e.g. right)
#define MOTOR3_BACKWARD 2  // Motor 3 - Backward (e.g. left)

// Motor speed variables
int speedMotor1, speedMotor2, speedMotor3;

// Joystick value variables
int XVal, YVal, XVal2;

void setup() {
  // Set joystick pins as input
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(XPIN2, INPUT);

  // Set motor PWM pins as output
  pinMode(SPEEDPIN1, OUTPUT);
  pinMode(SPEEDPIN2, OUTPUT);
  pinMode(SPEEDPIN3, OUTPUT);

  // Set motor direction pins as output
  pinMode(MOTOR1_RIGHT, OUTPUT);
  pinMode(MOTOR1_LEFT, OUTPUT);
  pinMode(MOTOR2_FORWARD, OUTPUT);
  pinMode(MOTOR2_BACKWARD, OUTPUT);
  pinMode(MOTOR3_FORWARD, OUTPUT);
  pinMode(MOTOR3_BACKWARD, OUTPUT);
}

void loop() {
  // Read joystick values
  XVal = analogRead(XPIN);
  YVal = analogRead(YPIN);
  XVal2 = analogRead(XPIN2);

  // Motor 1 control - Joystick 1 X axis
  if (XVal > 530) {
    speedMotor1 = map(XVal, 530, 1023, 0, 255);
    digitalWrite(MOTOR1_RIGHT, LOW);
    digitalWrite(MOTOR1_LEFT, HIGH);
    analogWrite(SPEEDPIN1, speedMotor1);
  } else if (XVal < 490) {
    speedMotor1 = map(XVal, 490, 0, 0, 255);
    digitalWrite(MOTOR1_RIGHT, HIGH);
    digitalWrite(MOTOR1_LEFT, LOW);
    analogWrite(SPEEDPIN1, speedMotor1);
  }

  // Motor 2 control - Joystick 1 Y axis
  if (YVal > 530) {
    speedMotor2 = map(YVal, 530, 1023, 0, 255);
    digitalWrite(MOTOR2_FORWARD, LOW);
    digitalWrite(MOTOR2_BACKWARD, HIGH);
    analogWrite(SPEEDPIN2, speedMotor2);
  } else if (YVal < 490) {
    speedMotor2 = map(YVal, 490, 0, 0, 255);
    digitalWrite(MOTOR2_FORWARD, HIGH);
    digitalWrite(MOTOR2_BACKWARD, LOW);
    analogWrite(SPEEDPIN2, speedMotor2);
  }

  // Motor 3 control - Joystick 2 X axis
  if (XVal2 > 530) {
    speedMotor3 = map(XVal2, 530, 1023, 0, 255);
    digitalWrite(MOTOR3_FORWARD, LOW);
    digitalWrite(MOTOR3_BACKWARD, HIGH);
    analogWrite(SPEEDPIN3, speedMotor3);
  } else if (XVal2 < 490) {
    speedMotor3 = map(XVal2, 490, 0, 0, 255);
    digitalWrite(MOTOR3_FORWARD, HIGH);
    digitalWrite(MOTOR3_BACKWARD, LOW);
    analogWrite(SPEEDPIN3, speedMotor3);
  }
}
