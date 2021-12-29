#include <Arduino.h>
#include <unity.h>


/*! @brief Test that sprite changes state. */
void Test_spriteStateChange(void)
{
   // TEST_ASSERT_EQUAL(to check, 0);
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    
    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(Test_spriteStateChange);

}

void loop()
{
    UNITY_END(); // stop unit testing
}