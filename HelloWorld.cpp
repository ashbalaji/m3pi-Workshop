#include "mbed.h"
#include "m3pi.h"
//Necessary header files must be included

m3pi m3pi;
//Initialising the object m3pi

int main() {
 
    m3pi.printf("Hi World"); //To print on the LCD screen of the m3pi
    wait (2.0);              //Wait for 2 seconds before executing the next set of code
    m3pi.stop();             //To stop m3pi execution
}
