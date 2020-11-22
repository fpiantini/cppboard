#include <iostream>
#include <set>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cppboard/unichesspset.h"

using namespace std;
using namespace cppboard;
using namespace testing;

class UCPSTester : public Test
{
public:
    UniformChessPieceSet pset;
};

// Requirement: the UCPS class contains a set of pieces,
// and this set is empty after the creation of a UCPS
TEST_F(UCPSTester, PieceSetBitBoardIsEmptyAfterCreation)
{
    BitBoardState bbs;
    bbs = pset.pieceBoard(); 
    ASSERT_EQ(bbs, ClearBoard);

    // This is redundant... but can be useful in the future
    set<string>posActive;
    BitBoard::stateToPosSet(bbs, posActive);
    ASSERT_TRUE(posActive.empty());
}
