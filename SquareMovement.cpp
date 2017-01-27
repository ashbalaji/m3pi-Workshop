#include "mbed.h"
#include "m3pi.h"
 
m3pi m3pi;
 
int main() {
 
    m3pi.printf("Hi World");
 
    wait (2.0);
    m3pi.cls();
    
    m3pi.forward(0.2); 
    wait (1.0);        
    m3pi.left(0.2);
    m3pi.right(-0.2);    
    wait (0.32);   
    m3pi.forward(0.2); 
    wait (1.0);        
    m3pi.left(0.2);
    m3pi.right(-0.2);    
    wait (0.32);      
    m3pi.forward(0.2); 
    wait (1.0);        
    m3pi.left(0.2);    
    m3pi.right(-0.2);    
    wait (0.32);        
    m3pi.forward(0.2); 
    wait (1.0);       
 
    
    m3pi.stop();       
}