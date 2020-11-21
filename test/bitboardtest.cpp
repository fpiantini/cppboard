#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "bitboard/bitboard.h"

using namespace bitboard;
using namespace testing;

const uint64_t BottomLeftUpperRightDiagonal = 0x8040201008040201;

class BBTester : public Test
{
public:
    BitBoard bboard;
};

TEST_F(BBTester, AfterDefinitionBoardIsEmpty)
{
    ASSERT_EQ(bboard.bbs, 0);
}

TEST_F(BBTester, A1_Busy)
{
    bboard.reset();
    bboard.setpos("a1");
    ASSERT_EQ(bboard.bbs, 1);
}

TEST_F(BBTester, B1_Busy)
{
    bboard.reset();
    bboard.setpos("b1");
    ASSERT_EQ(bboard.bbs, 2);
}

TEST_F(BBTester, DiagonalBottomLeftToUpperRightBusy)
{
    bboard.reset();
    bboard.setpos("a1");
    bboard.setpos("b2");
    bboard.setpos("c3");
    bboard.setpos("d4");
    bboard.setpos("e5");
    bboard.setpos("f6");
    bboard.setpos("g7");
    bboard.setpos("h8");
    ASSERT_EQ(bboard.bbs, BottomLeftUpperRightDiagonal);
}

