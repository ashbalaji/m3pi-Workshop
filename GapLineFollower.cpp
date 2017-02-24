#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
// Minimum and maximum motor speeds
#define MAX 0.2
#define MIN 0
 
// PID terms
#define P_TERM 1
#define I_TERM 0
#define D_TERM 20
 
int main() {
 
    m3pi.locate(0,1);
    m3pi.printf("Line PID");
 
    wait(2.0);
 
    m3pi.sensor_auto_calibrate();
 
    float right;
    float left;
    float current_pos_of_line = 0.0;
    float previous_pos_of_line = 0.0;
    float derivative,proportional,integral = 0;
    float power;
    float speed = MAX;
    
    while (1) {
       
        current_pos_of_line = m3pi.line_position();        
        proportional = current_pos_of_line;
        
        //Add in code to make your robot to continue following the line even if there are gaps
        //Hint: Navigating a gap is same as coming back on to the track once the m3pi stops sensing a line
     
        derivative = current_pos_of_line - previous_pos_of_line;
        
        integral += proportional;
        
        previous_pos_of_line = current_pos_of_line;
        
        power = (proportional * (P_TERM) ) + (integral*(I_TERM)) + (derivative*(D_TERM)) ;
        
        right = speed+power;
        left  = speed-power;
        
        if (right < MIN)
            right = MIN;
        else if (right > MAX)
            right = MAX;
            
        if (left < MIN)
            left = MIN;
        else if (left > MAX)
            left = MAX;
            
        m3pi.left_motor(left);
        m3pi.right_motor(right);
 
    }
}
