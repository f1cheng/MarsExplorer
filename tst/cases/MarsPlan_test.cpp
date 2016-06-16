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

    void move_as_expected(const std::string &cmds, Position expect_pos)
    {
        plan.run(cmds);
        get_pos_for_explorer(0);
        EXPECT_EQ(expect_pos, dest_pos);    
    };

    void move_as_expected_for_pos_out_of_range(const std::string &cmds, Position expect_pos)
    {
        plan.run(cmds);
        get_pos_for_explorer(0);
        EXPECT_EQ(expect_pos, dest_pos);    
        EXPECT_EQ(OUT_OF_RANGE, explorers[0].get_state());    
    };


    void move_as_expected_for_pos_occupied(const std::string &cmds, Position expect_pos)
    {
        plan.run(cmds);
        get_pos_for_explorer(1);
        EXPECT_EQ(expect_pos, dest_pos);    
        EXPECT_EQ(OCCUPIED, explorers[1].get_state());    
    };

    void get_pos_for_explorer(int i)
    {
        explorers = plan.get_explorers();
        dest_pos = explorers[i].get_pos();  
    };

    virtual ~MarsTesting(){};

private:
    MarsPlan plan;
    std::vector<Explorer> explorers;
    Position dest_pos;
};

TEST_F(MarsTesting, turn_left__move_from_east_to_north)
{
    std::string cmds = std::string("5 5\n1 2 E\nL");
    Position expect_pos = {1, 2, NORTH};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, turn_left__move_from_sourth_to_east)
{
    std::string cmds = std::string("5 5\n1 2 S\nL");
    Position expect_pos = {1, 2, EAST};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, turn_left__move_from_west_to_sourth)
{
    std::string cmds = std::string("5 5\n1 2 W\nL");
    Position expect_pos = {1, 2, SOURTH};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, turn_left__move_from_north_to_west)
{
    std::string cmds = std::string("5 5\n1 2 N\nL");
    Position expect_pos = {1, 2, WEST};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, turn_right__move_from_east_to_sourth)
{
    std::string cmds = std::string("5 5\n1 2 E\nR");
    Position expect_pos = {1, 2, SOURTH};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, turn_right__move_from_sourth_to_west)
{
    std::string cmds = std::string("5 5\n1 2 S\nR");
    Position expect_pos = {1, 2, WEST};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, turn_right__move_from_west_to_north)
{
    std::string cmds = std::string("5 5\n1 2 W\nR");
    Position expect_pos = {1, 2, NORTH};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, turn_right__move_from_north_to_east)
{
    std::string cmds = std::string("5 5\n1 2 N\nR");
    Position expect_pos = {1, 2, EAST};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_forward__one_step_to_east)
{
    std::string cmds = std::string("5 5\n1 2 E\nM");
    Position expect_pos = {2, 2, EAST};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, move_forward__one_step_to_sourth)
{
    std::string cmds = std::string("5 5\n1 2 S\nM");
    Position expect_pos = {1, 1, SOURTH};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, move_forward__one_step_to_west)
{
    std::string cmds = std::string("5 5\n1 2 WEST\nM");
    Position expect_pos = {0, 2, WEST};
    move_as_expected(cmds, expect_pos);
}


TEST_F(MarsTesting, move_forward__one_step_to_north)
{
    std::string cmds = std::string("5 5\n1 2 NORTH\nM");
    Position expect_pos = {1, 3, NORTH};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_cross_to_west_edge_when_out_of_edge_for_east)
{
    std::string cmds = std::string("1 2\n1 2 E\nM");
    Position expect_pos = {0, 2, EAST};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_cross_to_north_edge_when_out_of_edge_for_sourth)
{
    std::string cmds = std::string("1 2\n1 0 S\nM");
    Position expect_pos = {1, 2, SOURTH};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_cross_to_east_edge_when_out_of_edge_for_west)
{
    std::string cmds = std::string("1 2\n0 2 W\nM");
    Position expect_pos = {1, 2, WEST};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_cross_to_sourth_edge_when_out_of_edge_for_north)
{
    std::string cmds = std::string("1 2\n1 2 N\nM");
    Position expect_pos = {1, 0, NORTH};
    move_as_expected(cmds, expect_pos);
}

TEST_F(MarsTesting, move_not_allowed_as_cur_pos_out_of_edge)
{
    std::string cmds = std::string("1 2\n2 2 N\nM");
    Position expect_pos = {2, 2, NORTH};
    move_as_expected_for_pos_out_of_range(cmds, expect_pos);
}


TEST_F(MarsTesting, move_conflict_test_pos_was_occupied)
{
    std::string cmds = std::string("5 5\n1 2 E\nMM\n1 2 E\nMM");
    Position expect_pos = {2, 2, EAST};
    move_as_expected_for_pos_occupied(cmds, expect_pos);
}

