#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cppboard/knightsboard.h"

using namespace std;
using namespace cppboard;
using namespace testing;

class KnightsBoardTester : public Test
{
public:
    KnightsBoard kb;
};

// Requirement: the knight board is initially empty
TEST_F(KnightsBoardTester, KnightsBoardIsEmptyAfterCreation)
{
    ASSERT_EQ(kb.state(), ClearBoard);
}
