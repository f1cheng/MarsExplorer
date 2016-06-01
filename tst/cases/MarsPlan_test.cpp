#include "Position.h"
#include "MarsPlan.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"
TEST(MarsPlan_test, left)
{

    std::string contents = std::string("5 5\n1 2 E\nL");
    MarsPlan plan(contents);
    plan.exec();
    //plan.print();

    position_t p1 = {1, 2, NORTH};
    std::vector<MarsExplorer> explorers = plan.get_explorers();
    EXPECT_EQ(true, p1 == explorers[0].get_destination().get());    
}

TEST(MarsPlan_test, right)
{
    std::string contents = std::string("5 5\n1 2 E\nR");
    MarsPlan plan(contents);
    plan.exec();

    position_t p1 = {1, 2, SOURTH};
    std::vector<MarsExplorer> explorers = plan.get_explorers();
    EXPECT_EQ(true, p1 == explorers[0].get_destination().get());    


}

TEST(MarsPlan_test, forward)
{
    std::string contents = std::string("5 5\n1 2 E\nM");
    MarsPlan plan(contents);
    plan.exec();

    position_t p1 = {2, 2, EAST};
    std::vector<MarsExplorer> explorers = plan.get_explorers();
    EXPECT_EQ(true, p1 == explorers[0].get_destination().get());    


}


TEST(MarsPlan_test, forward_out_of_boundary)
{
    std::string contents = std::string("5 5\n0 0 S\nM");
    MarsPlan plan(contents);
    plan.exec();

    position_t p1 = {0, -1, SOURTH};
    std::vector<MarsExplorer> explorers = plan.get_explorers();
    EXPECT_EQ(true, p1 == explorers[0].get_destination().get());    


}


/*
TEST(DISABLED_MarsPlan_test, two_go_destinations)
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
      EXPECT_EQ(true, dests[i] == expect_dests[i]); 
  }
}
*/
