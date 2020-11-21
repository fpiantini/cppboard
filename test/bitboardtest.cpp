#include <iostream>
#include <list>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "bitboard/bitboard.h"

using namespace std;
using namespace bitboard;
using namespace testing;

class BBTester : public Test
{
public:
    BitBoard bboard;
};

TEST_F(BBTester, AfterDefinitionBoardIsEmpty)
{
    ASSERT_EQ(bboard.state(), 0);
}

TEST_F(BBTester, A1_Busy)
{
    bboard.reset();
    bboard.setPos("a1");
    ASSERT_EQ(bboard.state(), 1);
}

TEST_F(BBTester, B1_Busy)
{
    bboard.reset();
    bboard.setPos("b1");
    ASSERT_EQ(bboard.state(), 2);
}

TEST_F(BBTester, DiagonalBottomLeftToUpperRightBusy)
{
    bboard.reset();
    bboard.setPos(list<string>
        {"a1", "b2", "c3", "d4", "e5", "f6", "g7", "h8"});
    ASSERT_EQ(bboard.state(), BottomLeftUpperRightDiagonal);
}

TEST_F(BBTester, DiagonalBottomRightToUpperLeftBusy)
{
    bboard.reset();
    bboard.setPos(list<string>
        {"a8", "b7", "c6", "d5", "e4", "f3", "g2", "h1"});
    ASSERT_EQ(bboard.state(), BottomRightUpperLeftDiagonal);
}

TEST_F(BBTester, BoardCenterBusy)
{
    bboard.reset();
    bboard.setPos(list<string>
        {"d4", "e4", "d5", "e5"});
    ASSERT_EQ(bboard.state(), BoardCenter);
}

TEST_F(BBTester, CornersBusy)
{
    bboard.reset();
    bboard.setPos(list<string>
        {"a1", "h1", "a8", "h8"});
    ASSERT_EQ(bboard.state(), Corners);
}

TEST(BitBoardTester, UsingConstructorBothKingsInitial)
{
    BitBoard bb(list<string>{"e1", "e8"});
    ASSERT_EQ(bb.state(), CH_BothKingsInitial);

}

TEST(BitBoardTester, UsingConstructorBothQueensInitial)
{
    BitBoard bb(list<string>{"d1", "d8"});
    ASSERT_EQ(bb.state(), CH_BothQueensInitial);

}

TEST(BitBoardTester, UsingConstructorFullBoardInitial)
{
    BitBoard bb(list<string>{
        "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
        "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
        "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
        "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"
    });
    ASSERT_EQ(bb.state(), CH_FullInitial);
}

TEST(BitBoardTester, UsingValueContructorCheckerInitial)
{
    BitBoard bb(CHK_Initial);
    list<string>actCells;
    bb.activeCells(actCells);

    ASSERT_EQ(actCells.size(), 24);
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "a1") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "c1") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "e1") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "g1") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "b2") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "d2") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "f2") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "h2") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "a3") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "c3") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "e3") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "g3") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "b6") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "d6") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "f6") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "h6") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "a7") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "c7") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "e7") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "g7") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "b8") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "d8") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "f8") != actCells.end());
    ASSERT_TRUE(std::find(actCells.begin(), actCells.end(), "h8") != actCells.end());
}
