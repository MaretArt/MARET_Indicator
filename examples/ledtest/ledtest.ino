#include <MARET_Indicator.h>

#define pinRed 2                // led rgb red pin
#define pinGreen 3              // led rgb green pin
#define pinBlue 4               // led rgn blue pin

/*
    pin of rgb led red
    pin of rgb led green
    pin of rgb led blue
    type: BUZZER / BATTERY / LED (default = LED)
*/
MARET_Indicator led(pinRed, pinGreen, pinBlue, LED);

void setup(){
    // begin the library
    led.begin();
}

void loop(){
    /* ============ custom led 1 ============ */
    /*
        color:
            * MARET_RED
            * MARET_ORANGE
            * MARET_YELLOW
            * MARET_GREEN
            * MARET_BLUE
            * MARET_PURPLE
            * MARET_PINK
            * MARET_LIGHTBLUE
            * MARET_LIGHTGREEN
    */
    led.customLed(MARET_RED);

    /* ============ custom led 2 ============ */
    // set color of led rgb
    /*
        red pwm
        green pwm
        blue pwm
    */
    led.setColor(255, 255, 0);
    // start led custom
    led.print();
}