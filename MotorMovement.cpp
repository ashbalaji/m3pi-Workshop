#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
int main() {
 
    m3pi.printf("Hi World");
 
    wait (2.0);
    m3pi.cls();
    
    m3pi.forward(0.5); // Forward half speed
    wait (2.0);        // wait two seconds
    
    m3pi.backward(0.5);// Backward at half speed 
    wait (2.0);        // wait two seconds
    
    m3pi.stop();       
}