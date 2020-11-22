#include <iostream>
#include <set>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cppboard/bitboard.h"
#include "cppboard/bbchessdefs.h"
#include "cppboard/bbcheckersdefs.h"

using namespace std;
using namespace cppboard;
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

TEST_F(BBTester, IfACellIsFirstSetAndThenClearedBoardIsClear)
{
    bboard.reset();
    bboard.setPos("d3");
    bboard.clearPos("d3");
    ASSERT_EQ(bboard.state(), ClearBoard);

}

TEST_F(BBTester, IfASetOfCellsIsFirstSetAndThenClearedBoardIsClear)
{
    bboard.reset();
    bboard.setPos(set<string>{
        "b3", "c4", "f5", "g6"});
    bboard.clearPos(set<string>{
        "b3", "c4", "f5", "g6"});
    ASSERT_EQ(bboard.state(), ClearBoard);

}

TEST_F(BBTester, MoveAPieceFromH2ToB8)
{
    bboard.reset();
    bboard.setPos("h2");
    bboard.move("h2", "b8");
    ASSERT_EQ(bboard.state(), bboard.generateStateFromPos("b8"));
}

TEST_F(BBTester, DontMoveANotExistingPiece)
{
    bboard.reset();
    bboard.setPos("h2");
    bboard.move("h3", "c8");
    ASSERT_EQ(bboard.state(), bboard.generateStateFromPos("h2"));
}

TEST_F(BBTester, DontMoveIntoABusyPlace)
{
    bboard.reset();
    bboard.setPos("h2");
    bboard.setPos("b8");
    bboard.move("h2", "b8");
    ASSERT_EQ(bboard.state(), bboard.generateStateFromPos(set<string>{"h2", "b8"}));
}

// Additional requirements: the bitboard class shall have a static method that,
// given a bitboard state, returns the set of the active positions in that board
TEST_F(BBTester, ClearBitboardShallReturnAnEmptySetOfPositions)
{
    set<string> posSet;
    bboard.stateToPosSet(ClearBoard, posSet);
    ASSERT_TRUE(posSet.empty());
}
TEST_F(BBTester, BitboardWithKingsInInitialPositionShallReturnE1andE8)
{
    set<string> posSet;
    bboard.stateToPosSet(CH_BothKingsInitial, posSet);
    ASSERT_EQ(posSet.size(), 2);
    ASSERT_TRUE(posSet.find("e1") != posSet.end());
    ASSERT_TRUE(posSet.find("e8") != posSet.end());
}

// ------------------------------------------------------------------------------------
// New set of tests... We need functions that given a board returns a set of
// two dimensional integer vector with the indexes of the active cells.
// the format shall be [col, row]
// For example, for the starting kings positions this function shall return:
//         { [4,0], [4,7] }
// From an index in this format, it is possible to compute the related bit
// position in the BitBoard:
//    bit = pos[1] * 8 + pos[0]
// Also a utility function that converts a string position in a coordinate
// pair is necessary
TEST_F(BBTester, CheckNumericalIndexesIfOnlyA1Active)
{
    set<pair<int, int>>posNdx;
    bboard.reset();
    bboard.setPos("a1");
    bboard.activeCellsNdx(posNdx);

    ASSERT_EQ(posNdx.size(), 1);
    ASSERT_TRUE(posNdx.find(pair<int,int>{0,0}) != posNdx.end());
}
TEST_F(BBTester, CheckNumericalIndexesIfOnlyD2Active)
{
    set<pair<int, int>>posNdx;
    bboard.reset();
    bboard.setPos("d2");
    bboard.activeCellsNdx(posNdx);

    ASSERT_EQ(posNdx.size(), 1);
    ASSERT_TRUE(posNdx.find(pair<int,int>{1,3}) != posNdx.end());
}

TEST_F(BBTester, CheckNumericalIndexesIfA1B3C2D4E5F7G6H8Active)
{
    set<pair<int, int>>posNdx;
    bboard.reset();
    bboard.setPos(set<string>{
        "a1", "b3", "c2", "d4", "e5", "f7", "g6", "h8"});
    bboard.activeCellsNdx(posNdx);

    ASSERT_EQ(posNdx.size(), 8);
    ASSERT_TRUE(posNdx.find(pair<int,int>{0,0}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{2,1}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{1,2}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{3,3}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{4,4}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{6,5}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{5,6}) != posNdx.end());
    ASSERT_TRUE(posNdx.find(pair<int,int>{7,7}) != posNdx.end());
}

TEST_F(BBTester, CheckConversionToIndexForPositionA1)
{
    pair<int,int> coord = bboard.posToCoordinates("a1");
    ASSERT_EQ(coord.first, 0);
    ASSERT_EQ(coord.second, 0);
}

TEST_F(BBTester, CheckConversionToIndexForInvalidPositions)
{
    pair<int,int> coord = bboard.posToCoordinates("a9");
    ASSERT_EQ(coord.first, INVALID_COORD);
    ASSERT_EQ(coord.second, INVALID_COORD);
    coord = bboard.posToCoordinates("i1");
    ASSERT_EQ(coord.first, INVALID_COORD);
    ASSERT_EQ(coord.second, INVALID_COORD);
}