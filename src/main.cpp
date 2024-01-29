#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "dino_game_arduino.h"

#define I2C 1

#ifdef I2C
U8G2_SSD1306_128X64_NONAME_1_HW_I2C oled(U8G2_R0);
#else
/*
 RS   <-> 10
 R/W  <-> 11
 E    <-> 13
 PSB  <-> GND
 RST  <-> 8
*/
U8G2_ST7920_128X64_1_HW_SPI oled(U8G2_R2, 10, 8);
#endif

DinoGameArduino dinoGameArduino(&oled);

#ifdef STM32F1

#define BUTTON1_PIN PB12
#define BUTTON2_PIN PB13

#elif defined(ARDUINO_AVR_UNO)

#define BUTTON1_PIN 6
#define BUTTON2_PIN 7

#endif

void setup()
{
    Serial.begin(115200);

#ifdef I2C
    oled.setI2CAddress(0x3C * 2); // For I2C
#endif

    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
    dinoGameArduino.setup();
}

void loop()
{
    if (digitalRead(BUTTON1_PIN) == HIGH && digitalRead(BUTTON2_PIN) == HIGH)
    {
        dinoGameArduino.setCheatMode(CHEAT_MODE_CHEAT);
    }
    else
    {
        if (digitalRead(BUTTON1_PIN) == HIGH)
        {
            dinoGameArduino.startGame();
        }
        if (digitalRead(BUTTON2_PIN) == HIGH)
        {
            dinoGameArduino.dinoJump();
        }
    }
    dinoGameArduino.loop();
}