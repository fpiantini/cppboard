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

TEST_F(UCPSTester, DummyTest)
{
    ASSERT_EQ(1, 1);
}
