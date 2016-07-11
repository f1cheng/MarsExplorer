#include "Position.h"
#include "MovePlanA.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;

class MovePlanTesting : public ::testing::Test
{
public:
    virtual void SetUp()
    {
    };
    
    virtual void TearDown()
    {
    };

    virtual ~MovePlanTesting(){};

};

TEST_F(MovePlanTesting, test_one_block_walk_around)
{
    MovePlanA plan;
    Position block = {3, 2, EAST};
    StateGrid *grid = new StateGrid(5, 5);
    grid->set_occupied(block);
    Position pos = {1, 2, EAST};
    std::vector<Moving> movings;
    Moving m1 = FORWARD;
    Moving m2 = FORWARD;
    Moving m3 = FORWARD;
    movings.push_back(m1); 
    movings.push_back(m2); 
    movings.push_back(m3); 
   
    plan.visit(pos, movings, grid);
    std::vector<Position> path = plan.get_path();
    EXPECT_EQ(8, path.size());
    Position p1 = {1,2,EAST};
    Position p2 = {2,2,EAST};
    Position p3 = {2,2,SOURTH};
    Position p4 = {2,2,WEST};
    Position p5 = {1,2,WEST};
    Position p6 = {0,2,WEST};
    Position p7 = {5,2,WEST};
    Position p8 = {4,2,WEST};

    EXPECT_EQ(p1, path[0]);
    EXPECT_EQ(p2, path[1]);
    EXPECT_EQ(p3, path[2]);
    EXPECT_EQ(p4, path[3]);
    EXPECT_EQ(p5, path[4]);
    EXPECT_EQ(p6, path[5]);
    EXPECT_EQ(p7, path[6]);
    EXPECT_EQ(p8, path[7]);

}
