#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "bitboard/bitboard.h"

using namespace bitboard;
using namespace testing;

class BitBoardTester : public Test
{
public:
    BitBoard bboard;
};

TEST_F(BitBoardTester, DummyTest)
{
    ASSERT_EQ(1, 1);
}
