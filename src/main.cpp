#include "MovePlanA.h"
#include "Explorer.h"
#include "Controller.h"



#ifndef __UT__
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    std::string cmds = std::string("5 5\n2 2 E\nM\n1 2 E\nMMM");
    //std::string cmds = std::string("5 5\n2 2 E\nM\n");

    Controller control;
    control.dispatch_command(cmds); //control.dispatch_command_from_file("test.txt");

    MoveStrategy *strategy = new MovePlanA();
    control.exec(strategy);
    control.print_paths();

    return 0;

/*
    MoveStrategy *strategy = new MovePlanA();
    Position block = {3, 2, EAST};
    StateGrid *grid = new StateGrid(5, 5);
    grid->print_values();
    grid->set_occupied(block);
    Position pos = {1, 2, EAST};
    std::vector<Moving> movings;
    Moving m1 = FORWARD;
    Moving m2 = FORWARD;
    Moving m3 = FORWARD;
    movings.push_back(m1);
    movings.push_back(m2);
    movings.push_back(m3);
    
    Exp e;
    e.init(pos, movings, grid);
    e.execute(strategy);
    grid->print_values();

    std::vector<Position> path = e.get_path();
    for (auto const p : path)
    {
        print_position(p);
    } 

*/

/*
    plan.init(pos, movings);
    grid->print_values();
    plan.visit(*grid);
    grid->print_values();
    std::vector<Position> path = plan.get_path();
    
    grid->print_values();
    sleep(1);
    std::system("clear");
    grid->print_values();
    grid->set_value(pos.coor, 100);
    sleep(1);
    std::system("clear");
    grid->print_values();
*/
}


#endif
