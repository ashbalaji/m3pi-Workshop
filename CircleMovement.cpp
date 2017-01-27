#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
int main() {
 
    m3pi.printf("Hi World");
 
    wait (2.0);
    m3pi.cls();
    
   
    m3pi.right(0.5);
    
    wait(5.0);
    m3pi.stop();       
}