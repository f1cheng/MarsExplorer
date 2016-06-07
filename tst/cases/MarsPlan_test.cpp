#include "Position.h"
#include "MarsPlan.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(turn_left_test, east_to_north)
{

    std::string contents = std::string("5 5\n1 2 E\nL");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, NORTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(turn_left_test, sourth_to_east)
{

    std::string contents = std::string("5 5\n1 2 S\nL");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, EAST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(turn_left_test, west_to_sourth)
{

    std::string contents = std::string("5 5\n1 2 W\nL");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, SOURTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(turn_left_test, north_west)
{

    std::string contents = std::string("5 5\n1 2 N\nL");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, WEST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(turn_right_test, east_to_sourth)
{

    std::string contents = std::string("5 5\n1 2 E\nR");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, SOURTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(turn_right_test, sourth_to_west)
{

    std::string contents = std::string("5 5\n1 2 S\nR");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, WEST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(turn_right_test, west_to_north)
{

    std::string contents = std::string("5 5\n1 2 W\nR");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, NORTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(turn_right_test, north_to_east)
{

    std::string contents = std::string("5 5\n1 2 N\nR");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, EAST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(move_forward_test, to_east)
{
    std::string contents = std::string("5 5\n1 2 E\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {2, 2, EAST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(move_forward_test, to_sourth)
{
    std::string contents = std::string("5 5\n1 2 S\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 1, SOURTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(move_forward_test, to_west)
{
    std::string contents = std::string("5 5\n1 2 WEST\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {0, 2, WEST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}


TEST(move_forward_test, to_north)
{
    std::string contents = std::string("5 5\n1 2 NORTH\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 3, NORTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(move_forward_test, out_of_range)
{
    std::string contents = std::string("1 2\n1 2 E\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {2, 2, EAST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
    EXPECT_EQ(OUT_OF_RANGE, explorers[0].get_state());    
}

TEST(move_conflict_test, pos_was_occupied)
{
    std::string contents = std::string("5 5\n1 2 E\nMM\n1 2 E\nMM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {2, 2, EAST};
    EXPECT_EQ(p1, explorers[1].get_pos());    
    EXPECT_EQ(OCCUPIED, explorers[1].get_state());    


}
