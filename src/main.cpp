#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <OneButton.h>
#include "dino_game_arduino.h"

U8G2_SSD1306_128X64_NONAME_1_HW_I2C oled(U8G2_R0);

DinoGameArduino dinoGameArduino(&oled);

// 默认Arduino的模拟引脚不带上拉电阻, 这里A1,A2,A3分别外接了上拉电阻
OneButton button1(A1);
OneButton button2(A2);
OneButton button3(A3);

void startGame();
void setCheat();
void dinoJump();
void showUltraman();

void setup()
{
    Serial.begin(115200);

    oled.setI2CAddress(0x3C * 2);

    button1.attachClick(startGame);
    button1.attachLongPressStart(setCheat);

    button2.attachClick(dinoJump);
    button2.attachDuringLongPress(dinoJump);

    button3.attachLongPressStart(showUltraman);

    dinoGameArduino.setup();
}

void loop()
{
    button1.tick();
    button2.tick();
    button3.tick();

    dinoGameArduino.loop();
}

void startGame()
{
    Serial.println("startGame");
    dinoGameArduino.startGame();
}

void setCheat()
{
    dinoGameArduino.setCheatMode(CHEAT_MODE_CHEAT);
}

void dinoJump()
{
    dinoGameArduino.dinoJump();
}

void showUltraman()
{
    dinoGameArduino.showUltraman();
}