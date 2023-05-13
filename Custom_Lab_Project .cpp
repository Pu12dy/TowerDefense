#include <Servo.h>

// Constant Variables for Input pins
const int BLUE_LED      = 9;
const int RED_LED       = 8;
const int JOY_CLICK     = 7;
const int JOY_Y_AXIS    = A0;
const int JOY_X_AXIS    = A1;
const int SERVO_SIGNAL  = 6;
const int RELAY_TRIGGER = 5;
const int SONIC_TRIGGER = 3;
const int SONIC_ECHO    = 2;

// Joystick Variables
const int  xAxis_median = 508;
const int  yAxis_median = 514;
const char plusMinus    = 100;
const int  xAxisLeft    = xAxis_median - plusMinus;
const int  xAxisRight   = xAxis_median + plusMinus;
const int  yAxisUp      = yAxis_median - plusMinus;
const int  yAxisDown    = yAxis_median + plusMinus;

// Servo Variables
Servo mrServo;
unsigned char currentServoValue;
const int MAX_SERVO = 180;
const int MIN_SERVO = 0; 

// Task Scheduler
typedef struct task
{
  int state;
  unsigned long period;
  unsigned long elapsesTime;
  int(*TickFunc)(int);
} task;

int delay_gcd;
const unsigned short NUMBER_OF_TASKS = 1;
task tasks[NUMBER_OF_TASKS];

//Glogal Variables, shared between State Machines
bool isManualMode;


//Servo State Machine
enum SM_Servo_Sweep_STATES {INIT, AUTO, MANUAL};


//Fan State Machine


// Ultrasonic Sensor State Machine


// Reads in input from joystick and returns a char
// Up = 'U' Down = 'D' Right = 'R' Left = 'L' Clicked = 'J'
// Nothing = 'N'
const unsigned char digitalReadHelper()
{
  const unsigned char jClick = digitalRead(joyClick);
  const int xState = analogRead(xAxis);
  const int yState = analogRead(yAxis);
  
  if(jClick == LOW)
  {
    Serial.println("joyCLick Pressed");
    return 'J';
  }
  else if(xState < xAxisLeft &&  yAxisUp < yState && yState < yAxisDown)
  {
    Serial.println("joystick left");
    return 'L';
  }
  else if(xState > xAxisRight &&  yAxisUp < yState && yState < yAxisDown)
  {
    Serial.println("joystick right");
    return 'R';
  }
  else if(yState < yAxisUp && xAxisLeft < xState && xState < xAxisRight)
  {
    Serial.println("joystick up");
    return 'U';
  }
  else if(yState > yAxisDown && xAxisLeft < xState && xState < xAxisRight)
  {
    Serial.println("joystick down");
    return 'D';
  }
  return 'N';
}


void setup()
{
  serial.begin(9600);

  unsigned char i = 0;
  tasks[i].state = ;
  tasks[i].period = ;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &;
  i++;
}

void loop()
{
  for(unsigned char i = 0; i < NUMBER_OF_TASKS; i++)
  {
    if( (millis() - tasks[i].elapsedTime) >= tasks[i].period)
    {
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis();
    }
  }
}
