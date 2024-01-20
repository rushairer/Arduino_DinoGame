#include "dino_game_arduino.h"

unsigned int getDinoImageAddress(Dino *dino)
{
    unsigned int dinoImageAddress;
    switch (dino->pose)
    {
    case DINO_JUMP:
        dinoImageAddress = reinterpret_cast<unsigned int>(dinoJumpImg);
        break;
    case DINO_LEFT:
        dinoImageAddress = reinterpret_cast<unsigned int>(dinoLeftImg);
        break;
    case DINO_RIGHT:
        dinoImageAddress = reinterpret_cast<unsigned int>(dinoRightImg);
        break;
    case DINO_BLAH:
    default:
        dinoImageAddress = reinterpret_cast<unsigned int>(dinoBlahImg);
        break;
    }

    return dinoImageAddress;
}

unsigned int getObstacleImageAddress(Obstacle *obstacle)
{
    unsigned int obstacleImageAddress;

    switch (obstacle->category)
    {
    case OBSTACLE_ONE_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(oneCactusImg);
        break;
    case OBSTACLE_TWO_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(twoCactusImg);
        break;
    case OBSTACLE_THREE_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(threeCactusImg);
        break;
    case OBSTACLE_ONE_SMALL_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(oneSmallCactusImg);
        break;
    case OBSTACLE_TWO_SMALL_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(twoSmallCactusImg);
        break;
    case OBSTACLE_THREE_SMALL_CACTUS:
        obstacleImageAddress = reinterpret_cast<unsigned int>(threeSmallCactusImg);
        break;
    case OBSTACLE_BIRD:
    default:
        obstacleImageAddress = reinterpret_cast<unsigned int>(obstacle->frame.postion.x % 20 > 10 ? birdUpImg : birdDownImg);
        break;
    }

    return obstacleImageAddress;
}

// public
DinoGameArduino::DinoGameArduino(U8G2 *u8g2)
    : _u8g2(u8g2),
      _dinoGame(_u8g2->getWidth(), _u8g2->getHeight(), millis, random)
{
}

DinoGameArduino::~DinoGameArduino()
{
}

void DinoGameArduino::setup()
{
    _u8g2->begin();
    _u8g2->enableUTF8Print();

    _dinoGame.setup();
    delay(300);
}

void DinoGameArduino::loop()
{
    _u8g2->firstPage();
    do
    {
        _u8g2->setFont(u8g2_font_timR08_tf);
        _u8g2->setFontMode(1);
        _u8g2->setBitmapMode(1);
        _u8g2->setFontPosTop();

        Dino *dino = _dinoGame.getDino();
        _dinoImageAddress = getDinoImageAddress(dino);
        drawDino();

        Obstacle *obstacleReal = _dinoGame.getObstacleReal();
        _obstacleRealImageAddress = getObstacleImageAddress(obstacleReal);
        drawObstacleReal();

        Obstacle *obstacleBackup = _dinoGame.getObstacleBackup();
        _obstacleBackupImageAddress = getObstacleImageAddress(obstacleBackup);
        drawObstacleBackup();

        if (_dinoGame.getGameStatus() == GAME_WAITING_STATUS)
        {
            _u8g2->setCursor(0, 0);
            _u8g2->setFont(u8g2_font_timR12_tf);
            _u8g2->print("= Dino Game =");
        }

    } while (_u8g2->nextPage());

    _dinoGame.loop();
}

void DinoGameArduino::startGame()
{
    if (_dinoGame.getGameStatus() != GAME_PLAYING_STATUS)
    {
        _dinoGame.startGame();
    }
}

void DinoGameArduino::setCheatMode(CheatMode cheatMode)
{
    _dinoGame.setCheatMode(cheatMode);
}

void DinoGameArduino::dinoJump()
{
    _dinoGame.dinoJump();
}

void DinoGameArduino::showUltraman()
{
}

// protected

void DinoGameArduino::drawDino()
{
    Dino *dino = _dinoGame.getDino();
    _u8g2->drawXBMP(
        dino->frame.postion.x,
        dino->frame.postion.y - dino->frame.offset.y,
        dino->frame.size.width,
        dino->frame.size.height,
        reinterpret_cast<const unsigned char *>(_dinoImageAddress));
}

void DinoGameArduino::drawObstacleReal()
{
    Obstacle *obstacle = _dinoGame.getObstacleReal();
    _u8g2->drawXBMP(
        obstacle->frame.postion.x,
        obstacle->frame.postion.y,
        obstacle->frame.size.width,
        obstacle->frame.size.height,
        reinterpret_cast<const unsigned char *>(_obstacleRealImageAddress));
}

void DinoGameArduino::drawObstacleBackup()
{
    Obstacle *obstacle = _dinoGame.getObstacleBackup();
    _u8g2->drawXBMP(
        obstacle->frame.postion.x,
        obstacle->frame.postion.y,
        obstacle->frame.size.width,
        obstacle->frame.size.height,
        reinterpret_cast<const unsigned char *>(_obstacleBackupImageAddress));
}
