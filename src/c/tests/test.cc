#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "../smartPerf.h"
#include "gtest/gtest.h"
  
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

void go1() { // 10ms
    int k;
    for (int i = 0 ; i < 1000000 ; i++) {
        k = (random() * 61323) / 3311383 + 998793 - 2;
    }

}

void go2() { // 100ms
    int k;
    for (int i = 0 ; i < 10000000 ; i++) {
        k = (random() * 61323) / 3311383 + 998793 - 2;
    }

}
TEST(simple, success) {/*{{{*/
    smartPerf::start("test long long key name1");
    go2();
    clock_t timeDiff = smartPerf::end();
    if (timeDiff > 0)
        ASSERT_TRUE(true);
    else 
        ASSERT_TRUE(false);

    smartPerf::clear();
    smartPerf::start("test2");
    go1();
    clock_t timeDiff2 = smartPerf::end();
    if (timeDiff2 > 0)
        ASSERT_TRUE(true);
    else 
        ASSERT_TRUE(false);

    smartPerf::print();

}/*}}}*/

TEST(defaultKey, success) {/*{{{*/
    smartPerf::start();
    go1();
    clock_t timeDiff = smartPerf::end();
    if (timeDiff > 0)
        ASSERT_TRUE(true);
    else 
        ASSERT_TRUE(false);

    smartPerf::start();
    go1();
    clock_t timeDiff2 = smartPerf::end();
    if (timeDiff2 > 0)
        ASSERT_TRUE(true);
    else 
        ASSERT_TRUE(false);


}/*}}}*/



int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}  
