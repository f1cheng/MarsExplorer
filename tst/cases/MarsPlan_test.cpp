#include "Position.h"
#include "MarsPlan.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"
TEST(MarsPlan_test, left)
{
}

TEST(MarsPlan_test, right)
{
}

TEST(MarsPlan_test, forward)
{
}

TEST(MarsPlan_test, two_go_destinations)
{
  MarsPlan plan;
  std::vector<position_t> dests;
  plan.init_actions("test.txt");
  plan.exec();
  dests = plan.get_destinations();
  
  position_t p1={1, 3, NORTH};
  position_t p2={5, 1, EAST};
  std::vector<position_t> expect_dests;
  expect_dests.clear();
  expect_dests.push_back(p1);
  expect_dests.push_back(p2);

  for (unsigned int i = 0; i < dests.size(); i++)
  {    
      //Position p1 = Position(dests[i]);
      //Position p2 = Position(expect_dests[i]);
      EXPECT_EQ(true, dests[i] == expect_dests[i]); 
  }
}
