// Fernandy Maret Astriawan
// ig: @fernandymaret_

#include "MARET_Indicator.h"

MARET_Indicator::MARET_Indicator(uint8_t pin, uint8_t type = BUZZER)
{
    _pin = pin;
    _type = type;
}

MARET_Indicator::MARET_Indicator(uint8_t pin, uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, float vref = 5.00, float low = 2.80, float normal = 3.70, float full = 4.20, float R1 = 100000.00, float R2 = 10000.00, uint8_t volt = MORE, uint8_t type = BATTERY)
{
    _pin = pin;
    _volt = volt;
    _type = type;
    _pinRed = pinRed;
    _pinGreen = pinGreen;
    _pinBlue = pinBlue;
    _vref = vref;
    _low = low;
    _normal = normal;
    _full = full;
    _R1 = R1;
    _R2 = R2;
}

MARET_Indicator::MARET_Indicator(uint8_t pin, uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, float vref = 5.00, float low = 2.80, float normal = 3.70, float full = 4.20, uint8_t volt = LESS, uint8_t type = BATTERY)
{
    _pin = pin;
    _volt = volt;
    _type = type;
    _pinRed = pinRed;
    _pinGreen = pinGreen;
    _pinBlue = pinBlue;
    _vref = vref;
    _low = low;
    _normal = normal;
    _full = full;
}

MARET_Indicator::MARET_Indicator(uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, uint8_t type = LED)
{
    _type = type;
    _pinRed = pinRed;
    _pinGreen = pinGreen;
    _pinBlue = pinBlue;
}

void MARET_Indicator::begin()
{
    switch (_type)
    {
    case BUZZER:
        pinMode(_pin, OUTPUT);
        break;

    case BATTERY:
        pinMode(_pin, INPUT);
        pinMode(_pinRed, OUTPUT);
        pinMode(_pinGreen, OUTPUT);
        pinMode(_pinBlue, OUTPUT);
        break;

    case LED:
        pinMode(_pinRed, OUTPUT);
        pinMode(_pinGreen, OUTPUT);
        pinMode(_pinBlue, OUTPUT);
        break;
    }

    DEBUG_PRINTLN("MARET_Indicator is begin...")
}

void MARET_Indicator::click(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(50);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("click...");
}

void MARET_Indicator::warning(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(750);
        digitalWrite(_pin, LOW);
        delay(500);
        digitalWrite(_pin, HIGH);
        delay(750);
        digitalWrite(_pin, LOW);
        delay(500);
        digitalWrite(_pin, HIGH);
        delay(750);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("warning...");
}

void MARET_Indicator::start(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        delay(100);
        digitalWrite(_pin, HIGH);
        delay(300);
        digitalWrite(_pin, LOW);
        delay(50);
        digitalWrite(_pin, HIGH);
        delay(100);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("start...");
}

void MARET_Indicator::pause(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(250);
        digitalWrite(_pin, LOW);
        delay(100);
        digitalWrite(_pin, HIGH);
        delay(250);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("pause...");
}

void MARET_Indicator::continues(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(250);
        digitalWrite(_pin, LOW);
        delay(100);
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("continue...");
}

void MARET_Indicator::stop(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        delay(200);
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        delay(200);
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("stop...");
}

void MARET_Indicator::timesup(uint8_t loop = 1, uint8_t _delay = 100)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(_delay);
        }
    }

    DEBUG_PRINTLN("timesup...");
}

float MARET_Indicator::readVoltage()
{
    vin = analogRead(_pin);
    v = (vin * _vref) / 1024.00;

    switch (_volt)
    {
    case MORE:
        v = v / (_R2 / (_R1 + _R2));
        break;

    case LESS:
        break;
    }

    DEBUG_PRINT("The Current Voltage is: ");
    DEBUG_PRINTLN(v, DEC);
    return v;
}

void MARET_Indicator::batteryLevel(uint8_t typeIndicator = 4)
{
    switch (typeIndicator)
    {
    case 2:
        if (readVoltage() < _normal)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
        }
        else if (readVoltage() >= _normal)
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
        }
        break;

    case 3:
        if (readVoltage() < (((_normal - _low) / 2) + _low))
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
        }
        else if (readVoltage() >= (((_normal - _low) / 2) + _low) && readVoltage() < (((_full - _normal) / 2) + _normal))
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 255);
        }
        else if (readVoltage() >= (((_full - _normal) / 2) + _normal))
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
        }
        break;

    case 4:
        if (readVoltage() < (((_normal - _low) / 2) + _low))
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
        }
        else if (readVoltage() >= (((_normal - _low) / 2) + _low) && readVoltage() < _normal)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 128);
        }
        else if (readVoltage() >= _normal && readVoltage() < (((_full - _normal) / 2) + _normal))
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 255);
        }
        else if (readVoltage() >= (((_full - _normal) / 2) + _normal))
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
        }
        break;
    }
}

void MARET_Indicator::customBuzzer1(uint8_t delayHigh, uint8_t delayLow = 100, uint8_t loop = 1)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(delayHigh);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(delayLow);
        }
    }
}

void MARET_Indicator::customBuzzer2(uint8_t delayHigh1, uint8_t delayLow1, uint8_t delayHigh2, uint8_t delayLow2 = 100, uint8_t loop = 1)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(delayHigh1);
        digitalWrite(_pin, LOW);
        delay(delayLow1);
        digitalWrite(_pin, HIGH);
        delay(delayHigh2);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(delayLow2);
        }
    }
}

void MARET_Indicator::customBuzzer3(uint8_t delayHigh1, uint8_t delayLow1, uint8_t delayHigh2, uint8_t delayLow2, uint8_t delayHigh3, uint8_t delayLow3 = 100, uint8_t loop = 1)
{
    for (int i = 0; i < loop; i++)
    {
        digitalWrite(_pin, HIGH);
        delay(delayHigh1);
        digitalWrite(_pin, LOW);
        delay(delayLow1);
        digitalWrite(_pin, HIGH);
        delay(delayHigh2);
        digitalWrite(_pin, LOW);
        delay(delayLow2);
        digitalWrite(_pin, HIGH);
        delay(delayHigh3);
        digitalWrite(_pin, LOW);
        if (loop > 1)
        {
            delay(delayLow3);
        }
    }
}

void MARET_Indicator::customBattery(uint8_t fromVoltage, uint8_t toVoltage, uint8_t color)
{
    switch (color)
    {
    case MARET_RED:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
            analogWrite(_pinBlue, 0);
        }
        break;

    case MARET_ORANGE:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 128);
            analogWrite(_pinBlue, 0);
        }
        break;

    case MARET_YELLOW:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 255);
            analogWrite(_pinBlue, 0);
        }
        break;

    case MARET_GREEN:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
            analogWrite(_pinBlue, 0);
        }
        break;

    case MARET_PURPLE:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
            analogWrite(_pinBlue, 255);
        }
        break;

    case MARET_PINK:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 0);
            analogWrite(_pinBlue, 128);
        }
        break;

    case MARET_LIGHTBLUE:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
            analogWrite(_pinBlue, 255);
        }
        break;

    case MARET_LIGHTGREEN:
        if (readVoltage() >= fromVoltage && readVoltage() < toVoltage)
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 255);
            analogWrite(_pinBlue, 128);
        }
        break;
    }
}

void MARET_Indicator::customLed(uint8_t color)
{
    switch (color)
    {
    case MARET_RED:
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 0);
        analogWrite(_pinBlue, 0);
        break;

    case MARET_ORANGE:
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 128);
        analogWrite(_pinBlue, 0);
        break;

    case MARET_YELLOW:
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 255);
        analogWrite(_pinBlue, 0);
        break;

    case MARET_GREEN:
        analogWrite(_pinRed, 0);
        analogWrite(_pinGreen, 255);
        analogWrite(_pinBlue, 0);
        break;

    case MARET_PURPLE:
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 0);
        analogWrite(_pinBlue, 255);
        break;

    case MARET_PINK:
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 0);
        analogWrite(_pinBlue, 128);
        break;

    case MARET_LIGHTBLUE:
        analogWrite(_pinRed, 0);
        analogWrite(_pinGreen, 255);
        analogWrite(_pinBlue, 255);
        break;

    case MARET_LIGHTGREEN:
        analogWrite(_pinRed, 0);
        analogWrite(_pinGreen, 255);
        analogWrite(_pinBlue, 128);
        break;
    }
}

void MARET_Indicator::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
    _red = red;
    _green = green;
    _blue = blue;
}

void MARET_Indicator::setVoltage(float fromVoltage, float toVoltage)
{
    _fromVoltage = fromVoltage;
    _toVoltage = toVoltage;
}

void MARET_Indicator::print()
{
    switch (_type)
    {
    case BATTERY:
        if (readVoltage() >= _fromVoltage && readVoltage() < _toVoltage)
        {
            analogWrite(_pinRed, _red);
            analogWrite(_pinGreen, _green);
            analogWrite(_pinBlue, _blue);
        }
        break;

    case LED:
        analogWrite(_pinRed, _red);
        analogWrite(_pinGreen, _green);
        analogWrite(_pinBlue, _blue);
    }
}