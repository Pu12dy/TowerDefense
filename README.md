# Ping Pong Ball Defense Tower

### Demo Video: https://youtu.be/fIcg26GEW10 
The Ping Pong Ball Defense Tower is a fan that oscillates 180 degrees scanning in front of it for a threat (ping pong ball). When the defense tower detects a threat (ping pong ball) it activates the fan to blow the threat(ball) way. Once the threat of the ping pong ball has been eliminated, the defense tower will turn off its fan, return to oscillating 180 degrees and scanning for the next threat. There is also a manual mode that allows the defense tower to be controlled by a joystick


## Hardware Components Used
![schematic](/assets/schematic.jpg)
###	Computing
- Uno R3 Controller Board
### Inputs
- Ultrasonic Sensor
- Joystick
### Outputs
- Servo Motor SG90
- Fan Blade and 3-6V DC Motor
- 2 LED’s
### Power Control
- 5V relay
- 5V Power Supply

## User Guide:
Upon initial start up, the defense tower is in automated mode. In this mode, the fan oscillates 180 degrees scanning of any object in front of it. When a threat is detected by the towe the red LED will illuminate, the tower will stop oscillation, and the fan will turn on to blow away the threat. Once the threat has been eliminated, the red LED and the fan will shut off and the tower will again begin to ociillate, scanning for the next threat.
If the user would like to maunally control the defense tower, all you need to do is click in the joystick. This will illuminate the blue LED signalling that the tower is now in manual mode. The user can now control the tower by moving the joystick left to make the tower rotate to the left, right to make the tower rotate to the right, and up to turn on the tower fan. To return the tower to the automated mode, simply click the joystick in again. This will result in the blue LED turning off and the defense tower will begin oscillateing on its own again. 
