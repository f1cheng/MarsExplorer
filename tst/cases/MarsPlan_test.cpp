#include "Position.h"
#include "MarsPlan.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;

class MarsTesting : public ::testing::Test
{
public:
    virtual void SetUp()
    {
    };
    
    virtual void TearDown()
    {
    };

    void test1(const std::string &contents)
    {
        plan.run(contents);
        get_pos_for_explorer(0);
    };

    void test2(const std::string &contents, Position expect_pos)
    {
        plan.run(contents);
        get_pos_for_explorer(0);
        //Position expect_pos = {1, 2, NORTH};
        EXPECT_EQ(expect_pos, test_pos);    
   
    };


    void get_pos_for_explorer(int i)
    {
        explorers = plan.get_explorers();
        test_pos = explorers[i].get_pos();  
    };

    ~MarsTesting(){};
private:
protected:
    MarsPlan plan;
    std::vector<MarsExplorer> explorers;
    Position test_pos;
};

TEST_F(MarsTesting, testxxxx1)
{
    std::string contents = std::string("5 5\n1 2 E\nL");
    plan.run(contents);
    EXPECT_EQ(0, 0);
}

//TEST_F(turn_left_test, east_to_north)
TEST_F(MarsTesting, east_to_north)
{

    std::string contents = std::string("5 5\n1 2 E\nL");

    //MarsPlan plan(contents);
    //plan.exec();
    test1(contents);
    Position expect_pos = {1, 2, NORTH};
    EXPECT_EQ(expect_pos, test_pos);    
    //std::vector<MarsExplorer> explorers = plan.get_explorers();
    //Position p1 = {1, 2, NORTH};
    //EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST_F(MarsTesting, east_turn_left_to_north2)
{

    std::string contents = std::string("5 5\n1 2 E\nL");

    Position expect_pos = {1, 2, NORTH};
    test2(contents, expect_pos);
    //std::vector<MarsExplorer> explorers = plan.get_explorers();
    //Position p1 = {1, 2, NORTH};
    //EXPECT_EQ(p1, explorers[0].get_pos());    
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

TEST(move_forward_test, toward_east_when_out_of_edge)
{
    std::string contents = std::string("1 2\n1 2 E\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {0, 2, EAST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(move_forward_test, toward_sourth_when_out_of_edge)
{
    std::string contents = std::string("1 2\n1 0 S\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, SOURTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(move_forward_test, toward_west_when_out_of_edge)
{
    std::string contents = std::string("1 2\n0 2 W\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 2, WEST};
    EXPECT_EQ(p1, explorers[0].get_pos());    
}

TEST(move_forward_test, toward_north_when_out_of_edge)
{
    std::string contents = std::string("1 2\n1 2 N\nM");
    MarsPlan plan(contents);
    plan.exec();

    std::vector<MarsExplorer> explorers = plan.get_explorers();
    Position p1 = {1, 0, NORTH};
    EXPECT_EQ(p1, explorers[0].get_pos());    
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

