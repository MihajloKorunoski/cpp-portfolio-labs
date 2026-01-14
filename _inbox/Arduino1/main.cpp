#include <Servo.h>

int analog_pot = 0;

int output = 0;

Servo servo_13;

void setup()
{
    pinMode(A0, INPUT);
    servo_13.attach(13, 500, 2500);

}

void loop()
{
    output = map(analogRead(A0), 0, 1023, 0, 180);
    servo_13.write(output);
    delay(10);
}
