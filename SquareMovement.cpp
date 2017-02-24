#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
int main() {
 
    m3pi.printf("Square");
    wait (2.0);
    m3pi.cls();
   
    //Include code to make the m3pi move in a square
    //Hint: Moving forward for some time and then moving left for some time makes your robot move along the legs of a right angle triangle
    
    m3pi.stop();       
}
