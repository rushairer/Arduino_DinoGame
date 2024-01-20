#include <unity.h>
#include "dino_game.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_dino_game_init()
{
    DinoGame dinogame(128, 64, nullptr, nullptr);
    dinogame.startGame();

    TEST_ASSERT_EQUAL(1, dinogame.getLevel());
    TEST_ASSERT_EQUAL(0, dinogame.getScore());
    TEST_ASSERT_EQUAL(GAME_WAITING_STATUS, dinogame.getGameStatus());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_dino_game_init);

    UNITY_END();
}
