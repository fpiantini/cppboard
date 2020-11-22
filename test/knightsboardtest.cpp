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
