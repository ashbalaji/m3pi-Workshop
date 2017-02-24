#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
int main() {
 
    // Parameters that affect the performance
    float speed = 0.2;
    float correction = 0.1;   
    float threshold = 0.5;
 
    m3pi.locate(0,1);
    m3pi.printf("Basic LF");
 
    wait(2.0);
    
    m3pi.sensor_auto_calibrate();
    
    while (1) {
 
        // -1.0 is far left, 1.0 is far right, 0.0 in the middle
        float position_of_line = m3pi.line_position();
 
        // Line is more than the threshold to the right, slow the left motor
        if (position_of_line > threshold) {
            m3pi.right_motor(speed);
            m3pi.left_motor(speed-correction);
        }
 
        // Line is more than 50% to the left, slow the right motor
        else if (position_of_line < -threshold) {
            m3pi.left_motor(speed);
            m3pi.right_motor(speed-correction);
        }
 
        // Line is in the middle
        else {
            m3pi.forward(speed);
        }
    }
}
