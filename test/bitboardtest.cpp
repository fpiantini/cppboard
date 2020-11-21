#include <list>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "bitboard/bitboard.h"

using namespace bitboard;
using namespace testing;

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
    bboard.setpos(std::list<std::string>
        {"a1", "b2", "c3", "d4", "e5", "f6", "g7", "h8"});
    ASSERT_EQ(bboard.bbs, BottomLeftUpperRightDiagonal);
}

TEST_F(BBTester, DiagonalBottomRightToUpperLeftBusy)
{
    bboard.reset();
    bboard.setpos(std::list<std::string>
        {"a8", "b7", "c6", "d5", "e4", "f3", "g2", "h1"});
    ASSERT_EQ(bboard.bbs, BottomRightUpperLeftDiagonal);
}

TEST_F(BBTester, BoardCenterBusy)
{
    bboard.reset();
    bboard.setpos(std::list<std::string>
        {"d4", "e4", "d5", "e5"});
    ASSERT_EQ(bboard.bbs, BoardCenter);
}

TEST_F(BBTester, CornersBusy)
{
    bboard.reset();
    bboard.setpos(std::list<std::string>
        {"a1", "h1", "a8", "h8"});
    ASSERT_EQ(bboard.bbs, Corners);
}
