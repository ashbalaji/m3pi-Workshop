#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
// Minimum and maximum motor speeds
#define MAX 0.20
#define MIN 0
 
// PID terms
#define P_TERM 1
#define I_TERM 0
#define D_TERM 20
 
int main() {
 
    m3pi.locate(0,1);
    m3pi.printf("Shortest");
 
    wait(2.0);
 
    m3pi.sensor_auto_calibrate();
 
    //float right;
    //float left;
    float curr = 0.0;
   
    float speed = MAX;
    int count=0;
    while (1) {
        
        curr=m3pi.line_position();
        
        if(curr<0.3 && curr>-0.3)
             m3pi.forward(speed);
        else
        { if((count-count/2)==0)
           while(m3pi.line_position()>0.1)
             { m3pi.right_motor(speed);
               m3pi.left_motor(-speed);
             }
          else
           while(m3pi.line_position()<-0.1)
             { m3pi.right_motor(-speed);
               m3pi.left_motor(speed);
             }     
          count=count+1;
        }          
    }
}
