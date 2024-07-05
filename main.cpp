#include "mbed.h"
#include <cstdio>
/*
This Mbed program configures an interrupt on a button connected to pin PC_13. 
When the button is pressed, the bttnFall function sets the int_trig flag to 1.
The main loop continuously checks this flag, and when it finds the flag set, it prints "bttnFall" and resets the flag to 0.
*/
InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;

void bttnFall(){
    int_trig = 1;
}


// main() runs in its own thread in the OS
int main()
{
    bluebtn.fall(&bttnFall);

    // this is lab 1 embedded sys module
    while (true) {
        if(int_trig ==1){
            int_trig = 0;
            printf("bttnFall \r\n");
            
        }
    }
}

