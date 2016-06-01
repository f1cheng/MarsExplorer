#include "MarsPlan.h"

#ifndef __UT__
int main(int argc, char **argv)
#else
int main_func(int argc, char **argv)
#endif
{
    (void)argc;
    (void)argv;
    MarsPlan plan;
    plan.init_actions("test.txt");
    plan.exec();
    return 0;
}
