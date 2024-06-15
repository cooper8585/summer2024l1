#include "mbed.h"
#include <cstdio>
/*
a few words max 100 on the program
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
            printif("bttnFall \r\n");
            
        }
    }
}

