#include "MarsPlan.h"

#ifndef __UT__
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    MarsPlan plan;
    plan.dispatch_command_from_file("test.txt");
    plan.exec();
    plan.print();
    return 0;
}
#endif
