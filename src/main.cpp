#include "MovePlanA.h"
#include "Controller.h"

#ifndef __UT__
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    std::string cmds = std::string("5 5\n2 2 E\nM\n1 2 E\nMMM");
    //std::string cmds = std::string("5 5\n2 2 E\nM\n");

    Controller control;
    //control.dispatch_command(cmds); 
    control.dispatch_command_from_file("test.txt");
    //control.dispatch_command_from_file("test_debug.TXT");

    MoveStrategy *strategy = new MovePlanA();
    control.exec(strategy);
    control.print_paths();

    return 0;
}


#endif
