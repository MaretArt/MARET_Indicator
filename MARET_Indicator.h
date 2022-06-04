// Fernandy Maret Astriawan
// ig: @fernandymaret_

#ifndef MARET_Indicator_h
#define MARET_Indicator_h

#include <Arduino.h>

/* Uncomment to enable printing out nice debug messages. */
//#define MARET_DEBUG

#define DEBUG_PRINTER                                    \
  Serial /**< Define where debug output will be printed. \
          */

#ifdef MARET_DEBUG
#define DEBUG_PRINT(...)              \
  {                                   \
    DEBUG_PRINTER.print(__VA_ARGS__); \
  }
#define DEBUG_PRINTLN(...)              \
  {                                     \
    DEBUG_PRINTER.println(__VA_ARGS__); \
  }
#else
#define DEBUG_PRINT(...) \
  {                      \
  } /**< Debug Print Placeholder if Debug is disabled */
#define DEBUG_PRINTLN(...) \
  {                        \
  } /**< Debug Print Line Placeholder if Debug is disabled */
#endif

static const uint8_t BUZZER{11};
static const uint8_t BATTERY{12};
static const uint8_t LED{13};

static const uint8_t MORE{15};
static const uint8_t LESS{16};

static const uint8_t MARET_RED{18};
static const uint8_t MARET_ORANGE{19};
static const uint8_t MARET_YELLOW{20};
static const uint8_t MARET_GREEN{21};
static const uint8_t MARET_BLUE{22};
static const uint8_t MARET_PURPLE{23};
static const uint8_t MARET_PINK{24};
static const uint8_t MARET_LIGHTBLUE{25};
static const uint8_t MARET_LIGHTGREEN{26};

class MARET_Indicator
{
public:
  MARET_Indicator(uint8_t pin, uint8_t type = BUZZER);
  MARET_Indicator(uint8_t pin, uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, float vref = 5.00, float low = 2.80, float normal = 3.70, float full = 4.20, float R1 = 100000.00, float R2 = 10000.00, uint8_t volt = MORE, uint8_t type = BATTERY);
  MARET_Indicator(uint8_t pin, uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, float vref = 5.00, float low = 2.80, float normal = 3.70, float full = 4.20, uint8_t volt = LESS, uint8_t type = BATTERY);
  MARET_Indicator(uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue, uint8_t type = LED);
  void begin();
  void click(uint8_t loop = 1, uint8_t _delay = 100);
  void warning(uint8_t loop = 1, uint8_t _delay = 100);
  void start(uint8_t loop = 1, uint8_t _delay = 100);
  void pause(uint8_t loop = 1, uint8_t _delay = 100);
  void continues(uint8_t loop = 1, uint8_t _delay = 100);
  void stop(uint8_t loop = 1, uint8_t _delay = 100);
  void timesup(uint8_t loop = 1, uint8_t _delay = 100);
  void batteryLevel(uint8_t typeIndicator = 4);
  void customBuzzer1(uint8_t delayHigh, uint8_t delayLow = 100, uint8_t loop = 1);
  void customBuzzer2(uint8_t delayHigh1, uint8_t delayLow1, uint8_t delayHigh2, uint8_t delayLow2 = 100, uint8_t loop = 1);
  void customBuzzer3(uint8_t delayHigh1, uint8_t delayLow1, uint8_t delayHigh2, uint8_t delayLow2, uint8_t delayHigh3, uint8_t delayLow3 = 100, uint8_t loop = 1);
  void customBattery(uint8_t fromVoltage, uint8_t toVoltage, uint8_t color);
  void customLed(uint8_t color);
  void setColor(uint8_t red, uint8_t green, uint8_t blue);
  void setVoltage(float fromVoltage, float toVoltage);
  void print();

private:
  uint8_t _pin, _type, _volt, _pinRed, _pinGreen, _pinBlue;
  uint8_t _red, _green, _blue;
  float _vref, _low, _normal, _full, _R1, _R2;
  float v;
  float readVoltage();
  float _fromVoltage, _toVoltage;
  int vin;
};

#endif