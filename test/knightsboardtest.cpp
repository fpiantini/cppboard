#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cppboard/knightsboard.h"

using namespace std;
using namespace cppboard;
using namespace testing;

// the knight board is initially empty
TEST(KnightsBoardTester, KnightsBoardIsEmptyAfterCreation)
{
    KnightsBoard kb;
    ASSERT_EQ(kb.state(), ClearBoard);
}

// the knight board for white player is initially correctly
TEST(KnightsBoardTester, WhiteKnightsInitialization)
{
    KnightsBoard kb(KnightsBoard::InitialWhite);
    ASSERT_EQ(kb.state(), CH_WhiteKnightsInitial);
}

// the knight board for black player is initially correctly
TEST(KnightsBoardTester, BlackKnightsInitialization)
{
    KnightsBoard kb(KnightsBoard::InitialBlack);
    ASSERT_EQ(kb.state(), CH_BlackKnightsInitial);
}

// return the valid moves for the initial position of the white knigths
// Please notes that valid moves does not take into account cells
// taken by other pieces in initial board
TEST(KnightsBoardTester, DISABLED_WhiteKnightsInitialValidMoves)
{
    // The function validMoves is still under development!!
    set<string>validMoves;
    KnightsBoard kb(KnightsBoard::InitialWhite);
    kb.validMoves(validMoves);
    ASSERT_EQ(validMoves.size(), 6);
    ASSERT_TRUE(validMoves.find("a3") != validMoves.end());
    ASSERT_TRUE(validMoves.find("c3") != validMoves.end());
    ASSERT_TRUE(validMoves.find("d2") != validMoves.end());
    ASSERT_TRUE(validMoves.find("e2") != validMoves.end());
    ASSERT_TRUE(validMoves.find("f3") != validMoves.end());
    ASSERT_TRUE(validMoves.find("h3") != validMoves.end());

}

// Add a test for the case in which a "valid" move is not really
// valid because the piece  is placed in a cell occupied
// by a friend piece
