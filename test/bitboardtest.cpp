#include <iostream>
#include <set>

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
    bboard.setPos(set<string>
        {"a1", "b2", "c3", "d4", "e5", "f6", "g7", "h8"});
    ASSERT_EQ(bboard.state(), BottomLeftUpperRightDiagonal);
}

TEST_F(BBTester, DiagonalBottomRightToUpperLeftBusy)
{
    bboard.reset();
    bboard.setPos(set<string>
        {"a8", "b7", "c6", "d5", "e4", "f3", "g2", "h1"});
    ASSERT_EQ(bboard.state(), BottomRightUpperLeftDiagonal);
}

TEST_F(BBTester, BoardCenterBusy)
{
    bboard.reset();
    bboard.setPos(set<string>
        {"d4", "e4", "d5", "e5"});
    ASSERT_EQ(bboard.state(), BoardCenter);
}

TEST_F(BBTester, CornersBusy)
{
    bboard.reset();
    bboard.setPos(set<string>
        {"a1", "h1", "a8", "h8"});
    ASSERT_EQ(bboard.state(), Corners);
}

TEST(BitBoardTester, UsingConstructorBothKingsInitial)
{
    BitBoard bb(set<string>{"e1", "e8"});
    ASSERT_EQ(bb.state(), CH_BothKingsInitial);

}

TEST(BitBoardTester, UsingConstructorBothQueensInitial)
{
    BitBoard bb(set<string>{"d1", "d8"});
    ASSERT_EQ(bb.state(), CH_BothQueensInitial);

}

TEST(BitBoardTester, UsingConstructorFullBoardInitial)
{
    BitBoard bb(set<string>{
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
    set<string>actCells;
    bb.activeCells(actCells);

    ASSERT_EQ(actCells.size(), 24);
    ASSERT_TRUE(actCells.find("a1") != actCells.end());
    ASSERT_TRUE(actCells.find("c1") != actCells.end());
    ASSERT_TRUE(actCells.find("e1") != actCells.end());
    ASSERT_TRUE(actCells.find("g1") != actCells.end());
    ASSERT_TRUE(actCells.find("b2") != actCells.end());
    ASSERT_TRUE(actCells.find("d2") != actCells.end());
    ASSERT_TRUE(actCells.find("f2") != actCells.end());
    ASSERT_TRUE(actCells.find("h2") != actCells.end());
    ASSERT_TRUE(actCells.find("a3") != actCells.end());
    ASSERT_TRUE(actCells.find("c3") != actCells.end());
    ASSERT_TRUE(actCells.find("e3") != actCells.end());
    ASSERT_TRUE(actCells.find("g3") != actCells.end());
    ASSERT_TRUE(actCells.find("b6") != actCells.end());
    ASSERT_TRUE(actCells.find("d6") != actCells.end());
    ASSERT_TRUE(actCells.find("f6") != actCells.end());
    ASSERT_TRUE(actCells.find("h6") != actCells.end());
    ASSERT_TRUE(actCells.find("a7") != actCells.end());
    ASSERT_TRUE(actCells.find("c7") != actCells.end());
    ASSERT_TRUE(actCells.find("e7") != actCells.end());
    ASSERT_TRUE(actCells.find("g7") != actCells.end());
    ASSERT_TRUE(actCells.find("b8") != actCells.end());
    ASSERT_TRUE(actCells.find("d8") != actCells.end());
    ASSERT_TRUE(actCells.find("f8") != actCells.end());
    ASSERT_TRUE(actCells.find("h8") != actCells.end());
}

TEST_F(BBTester, CheckUppercase)
{
    bboard.reset();
    bboard.setPos("A1");
    ASSERT_EQ(bboard.state(), 1);
}

TEST_F(BBTester, BoardDoNotChangeIfInvalidCoordinates)
{
    bboard.reset();
    bboard.setPos("i1");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("a9");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("aa");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("aa");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("bb");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("a1andotherthings...");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("2d");
    ASSERT_EQ(bboard.state(), ClearBoard);
    bboard.setPos("Cf3");
    ASSERT_EQ(bboard.state(), ClearBoard);
}
