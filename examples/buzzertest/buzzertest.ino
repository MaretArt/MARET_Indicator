#include <MARET_Indicator.h>

MARET_Indicator buzzer(2, BUZZER); // pin | type: BUZZER / BATTERY / LED (default = BUZZER)

void setup()
{
    // begin the library
    buzzer.begin();

    // click
    buzzer.start();

    delay(500);

    // click with loop
    buzzer.start(2, 500); // loop (default = 1) | delay (default = 100)

    delay(500);

    // warning
    buzzer.warning();

    delay(500);

    // warning with loop
    buzzer.warning(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // start
    buzzer.start();

    delay(500);

    // start with loop
    buzzer.start(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // pause
    buzzer.pause();

    delay(500);

    // pause with loop
    buzzer.pause(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // continue
    buzzer.continues();

    delay(500);

    // continue with loop
    buzzer.continues(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // stop
    buzzer.stop();

    delay(500);

    // stop with loop
    buzzer.stop(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // timesup
    buzzer.timesup();

    delay(500);

    // timesup with loop
    buzzer.timesup(2); // loop (default = 1) | delay (default = 100)

    delay(500);

    // custom 1
    buzzer.customBuzzer1(500, 100, 2); // delay high | delay low (default = 100) | loop (default = 1)

    delay(500);

    // custom 2
    buzzer.customBuzzer2(500, 100, 200, 100, 2); // delay high1 | delay low1 | delay high2 | delay low2 (default = 100) | loop (default = 1)

    delay(500);

    // custom 3
    buzzer.customBuzzer3(500, 100, 200, 100, 200, 100, 2); // delay high1 | delay low1 | delay high2 | delay low2 | delay high3 | delay low3 (default = 100) | loop (default = 1)
}

void loop() {}