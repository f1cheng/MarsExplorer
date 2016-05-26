#include "MarsExplorer.cpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(MarsExplorer_test, init)
{
  //MarsExplorer mars;
  MarsPlan plan;
  plan.init_actions();
  plan.exec();
  std::cout << "ABCD\n";
  EXPECT_EQ(1, 1);
}
