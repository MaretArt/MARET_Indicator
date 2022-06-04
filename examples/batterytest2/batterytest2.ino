#include <MARET_Indicator.h>

#define pinBattery A0           // battery voltage pin
#define pinRed 2                // led rgb red pin
#define pinGreen 3              // led rgb green pin
#define pinBlue 4               // led rgn blue pin

float VREF = 5.00;              // define vref
float lowVoltage = 2.80;        // define low voltage of battery
float normalVoltage = 3.70;     // define normal voltage of battery
float fullVoltage = 4.20;       // define full voltage of battery

/*
    pin of voltage in
    pin of rgb led red
    pin of rgb led green
    pin of rgb led blue
    VREF (default = 5.00)
    low voltage (default = 2.80)
    normal voltage (default 3.70)
    full voltage (default = 4.20)
    battery voltage is MORE or LESS than VREF (default = LESS) *if MORE see batterytest1.ino
    type: BUZZER / BATTERY / LED (default = BATTERY)
*/
MARET_Indicator battery(pinBattery, pinRed, pinGreen, pinBlue, VREF, lowVoltage, normalVoltage, fullVoltage, LESS, BATTERY);

void setup(){
    // begin the library
    battery.begin();
}

void loop(){
    /* ============= start battery level ============= */
    /*
        number of led colors 2 / 3 / 4 (default = 4);
        2 = red and green
        3 = red, yellow and green
        4 = red, orange, yellow and green
    */
    battery.batteryLevel(4);

    /* ============ custom battery level 1 ============ */
    /*
        from voltage
        to voltage
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
    battery.customBattery(2.70, 3.70, MARET_RED);

    /* ============ custom battery level 2 ============ */
    // set color of led rgb
    /*
        red pwm
        green pwm
        blue pwm
    */
    battery.setColor(255, 255, 0);
    // set from voltage and to voltage
    /*
        from voltage
        to voltage
    */
    battery.setVoltage(2.70, 3.70);
    // start battery level custom
    battery.print();
}