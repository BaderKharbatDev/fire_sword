#include <Servo.h>

const int touch_pin = 2;
const int led_pin = 4;
const int servo_pin = 3;
Servo servo;
int servo_pos = 20;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(touch_pin, INPUT);
  servo.attach(servo_pin);
  servo.write(servo_pos);
}

void loop() {
  int is_sensor_touched = digitalRead(touch_pin);
  if(is_sensor_touched == HIGH) {
    digitalWrite(led_pin, HIGH);
    servo_pos = 0;
  } else {
    digitalWrite(led_pin, LOW);
    servo_pos = 20;  
  }
  servo.write(servo_pos);
}
