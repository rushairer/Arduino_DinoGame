#ifndef __DINO_GAME_ARDUINO_H_
#define __DINO_GAME_ARDUINO_H_

#include "dino_game.h"
#include <U8g2lib.h>

unsigned int getDinoImageAddress(Dino *dino);
unsigned int getObstacleImageAddress(Obstacle *obstacle);

class DinoGameArduino;

// PRE-SAVED BITMAP CONSTANTS

// 20 x 21
static const unsigned char dinoBlahImg[] U8X8_PROGMEM = {
    0x00, 0xFC, 0x07, 0x00, 0xFE, 0x07, 0x00, 0xC6, 0x0F, 0x00, 0xC6, 0x0F,
    0x00, 0xCE, 0x0F, 0x00, 0xFE, 0x0F, 0x00, 0xFE, 0x0F, 0x06, 0xFF, 0x03,
    0x87, 0x7F, 0x00, 0xE7, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00,
    0xFF, 0x3F, 0x00, 0xFE, 0x3F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x1F, 0x00,
    0xF0, 0x1F, 0x00, 0xF0, 0x0E, 0x00, 0x60, 0x0E, 0x00, 0x60, 0x0E, 0x00,
    0xE0, 0x1E, 0x00};

// 20 x 21
static const unsigned char dinoJumpImg[] U8X8_PROGMEM = {
    0x00, 0xFC, 0x07, 0x00, 0xFE, 0x07, 0x00, 0xEE, 0x0F, 0x00, 0xFE, 0x0F,
    0x00, 0xFE, 0x0F, 0x00, 0xFE, 0x0F, 0x00, 0xFE, 0x07, 0x06, 0xFF, 0x03,
    0xC3, 0xFF, 0x00, 0xE7, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00,
    0xFF, 0x3F, 0x00, 0xFE, 0x3F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x1F, 0x00,
    0xF0, 0x1F, 0x00, 0xF0, 0x0E, 0x00, 0x60, 0x0E, 0x00, 0xE0, 0x0E, 0x00,
    0xE0, 0x1E, 0x00};

// 20 x 21
static const unsigned char dinoLeftImg[] U8X8_PROGMEM = {
    0x00, 0xFC, 0x07, 0x00, 0xFE, 0x07, 0x00, 0xEE, 0x0F, 0x00, 0xFE, 0x0F,
    0x00, 0xFE, 0x0F, 0x00, 0x7E, 0x08, 0x00, 0x7E, 0x00, 0x06, 0xFF, 0x03,
    0x87, 0x3F, 0x00, 0xE7, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00,
    0xFF, 0x3F, 0x00, 0xFE, 0x3F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x1F, 0x00,
    0xF0, 0x1F, 0x00, 0xE0, 0x1E, 0x00, 0x60, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0xE0, 0x00, 0x00};

// 20 x 21
static const unsigned char dinoRightImg[] U8X8_PROGMEM = {
    0x00, 0xFC, 0x07, 0x00, 0xEE, 0x07, 0x00, 0xE6, 0x0F, 0x00, 0xFE, 0x0F,
    0x00, 0xFE, 0x0F, 0x00, 0xFE, 0x0F, 0x00, 0x7C, 0x00, 0x06, 0xFF, 0x03,
    0xC3, 0xFF, 0x00, 0xE7, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00,
    0xFF, 0x3F, 0x00, 0xFE, 0x3F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x1F, 0x00,
    0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xE0, 0x0E, 0x00, 0x00, 0x0E, 0x00,
    0x00, 0x1E, 0x00};

// shape 0:  39 x 12
static const unsigned char cloudImg[] U8X8_PROGMEM = {
    0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xBE, 0x03, 0x00, 0x00, 0x00,
    0x03, 0x06, 0x00, 0x00, 0x80, 0x01, 0x04, 0x00, 0x00, 0x40, 0x00, 0x1C,
    0x00, 0x00, 0x40, 0x00, 0xE4, 0x03, 0x00, 0x18, 0x00, 0x00, 0x02, 0xE0,
    0x0F, 0x00, 0x00, 0x0E, 0x30, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x20, 0x12, 0x00, 0x00, 0x00, 0x40, 0x03, 0xFF, 0xFF, 0xFF, 0x7F};

// shape 1: 10 x 20
static const unsigned char oneCactusImg[] U8X8_PROGMEM = {
    0x30, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x01, 0xFB, 0x03,
    0xFF, 0x03, 0xFF, 0x03, 0xFF, 0x03, 0xFF, 0x03, 0xFF, 0x03, 0xFF, 0x01,
    0xFE, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00,
    0x78, 0x00, 0x00, 0x00};

// shape 2: 20 x 20
static const unsigned char twoCactusImg[] U8X8_PROGMEM = {
    0x30, 0xC0, 0x00, 0x38, 0xE0, 0x00, 0x38, 0xE8, 0x00, 0x38, 0xEC, 0x00,
    0x38, 0xED, 0x04, 0xBB, 0xED, 0x0E, 0xBB, 0xED, 0x0E, 0xBB, 0xFD, 0x0E,
    0xBB, 0xFD, 0x0E, 0xBB, 0xF9, 0x0E, 0xFF, 0xF1, 0x0F, 0xFF, 0xE0, 0x07,
    0x7E, 0xE0, 0x01, 0x38, 0xE0, 0x00, 0x38, 0xE0, 0x00, 0x38, 0xE0, 0x00,
    0x38, 0xE0, 0x00, 0x38, 0xE0, 0x00, 0x38, 0xE0, 0x00, 0x00, 0x00, 0x00};

// shape 3: 20 x 20
static const unsigned char threeCactusImg[] U8X8_PROGMEM = {
    0x00, 0xC0, 0x00, 0x18, 0xC0, 0x01, 0x18, 0xC0, 0x01, 0x58, 0xD8, 0x01,
    0x58, 0xFC, 0x01, 0x58, 0xFC, 0x0F, 0x78, 0xDC, 0x0F, 0x7F, 0xFC, 0x0F,
    0x3B, 0xFD, 0x0D, 0x1B, 0xF9, 0x0C, 0x5B, 0xF5, 0x0F, 0x5B, 0xC5, 0x07,
    0x5F, 0xE7, 0x03, 0xDE, 0xE7, 0x01, 0xD8, 0xC3, 0x01, 0x98, 0xC1, 0x01,
    0x18, 0xC1, 0x01, 0x18, 0xC1, 0x01, 0x18, 0xE1, 0x01, 0x00, 0x00, 0x00};

// shape 4: 6 x 12
static const unsigned char oneSmallCactusImg[] U8X8_PROGMEM = {
    0x0C, 0x0C, 0x3C, 0x3D, 0x2D, 0x3D, 0x1D, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C};

// shape 5: 12 x 12
static const unsigned char twoSmallCactusImg[] U8X8_PROGMEM = {
    0x0C, 0x03, 0x0C, 0x03, 0x6C, 0x0B, 0x6D, 0x0B, 0x6D, 0x0B, 0xBD, 0x0B,
    0x1F, 0x0F, 0x0E, 0x03, 0x0C, 0x03, 0x0C, 0x03, 0x0C, 0x03, 0x0C, 0x03};

// shape 6: 17 x 12
static const unsigned char threeSmallCactusImg[] U8X8_PROGMEM = {
    0x04, 0x41, 0x00, 0x0C, 0x61, 0x00, 0xFC, 0x79, 0x01, 0xFD, 0x7D, 0x01,
    0x7D, 0x6D, 0x01, 0x7D, 0x7D, 0x01, 0xCF, 0xE5, 0x01, 0xCE, 0x67, 0x00,
    0x8C, 0x67, 0x00, 0x0C, 0x63, 0x00, 0x0C, 0x61, 0x00, 0x0C, 0x61, 0x00};

// 'birdUp', 21x18px
static const unsigned char birdUpImg[] PROGMEM = {
    0x80, 0x00, 0x00, 0x80, 0x01, 0x00, 0x80, 0x03, 0x00, 0x30, 0x07, 0x00, 0x38, 0x0f, 0x00, 0x7c,
    0x1f, 0x00, 0x7e, 0x3f, 0x00, 0xff, 0x3f, 0x00, 0xc0, 0x7f, 0x00, 0x80, 0xff, 0x1f, 0x00, 0xff,
    0x03, 0x00, 0xfe, 0x0f, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const unsigned char birdDownImg[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x38, 0x00, 0x00, 0x7c,
    0x00, 0x00, 0x7e, 0x00, 0x00, 0xff, 0x3f, 0x00, 0xc0, 0x7f, 0x00, 0x80, 0xff, 0x1f, 0x00, 0xff,
    0x03, 0x00, 0xff, 0x0f, 0x00, 0xff, 0x01, 0x00, 0x0f, 0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x01, 0x00};

static const unsigned char gameOverImg[] U8X8_PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x01, 0x02, 0x0C, 0x0C, 0x3E, 0x00, 0x78, 0x60,
    0x30, 0x7C, 0xF0, 0x01, 0x0C, 0x01, 0x07, 0x14, 0x0A, 0x02, 0x00, 0x84,
    0x40, 0x10, 0x04, 0x10, 0x02, 0x04, 0x00, 0x05, 0x14, 0x0A, 0x02, 0x00,
    0x02, 0x41, 0x10, 0x04, 0x10, 0x02, 0x04, 0x00, 0x05, 0x14, 0x0A, 0x02,
    0x00, 0x02, 0xC1, 0x18, 0x04, 0x10, 0x02, 0xC4, 0x81, 0x0D, 0x34, 0x0B,
    0x3E, 0x00, 0x02, 0x81, 0x08, 0x7C, 0xF0, 0x01, 0x04, 0x81, 0x08, 0x24,
    0x09, 0x02, 0x00, 0x02, 0x81, 0x0D, 0x04, 0x10, 0x01, 0x04, 0x81, 0x0F,
    0x64, 0x09, 0x02, 0x00, 0x02, 0x01, 0x05, 0x04, 0x10, 0x02, 0x0C, 0xC1,
    0x18, 0xC4, 0x08, 0x02, 0x00, 0x84, 0x00, 0x05, 0x04, 0x10, 0x02, 0xF8,
    0x41, 0x10, 0xC4, 0x08, 0x3E, 0x00, 0x78, 0x00, 0x07, 0x7C, 0x10, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00};

class DinoGameArduino
{
public:
    DinoGameArduino(U8G2 *u8g2);
    virtual ~DinoGameArduino();

    void setup();
    void loop();

    void startGame();
    void setCheatMode(CheatMode cheatMode);
    void dinoJump();
    void showUltraman();

protected:
    U8G2 *_u8g2;
    DinoGame _dinoGame;

    void drawDino();
    void drawObstacleReal();
    void drawObstacleBackup();

private:
    unsigned int _dinoImageAddress;
    unsigned int _obstacleRealImageAddress;
    unsigned int _obstacleBackupImageAddress;
};

#endif // !__DINO_GAME_ARDUINO_H_