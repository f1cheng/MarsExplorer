#include "Explorer.h"

void Explorer::search_path(MoveStrategy *p)
{
    if (_grid->out_of_range(_start))
    {
        std::cout<<"search path is out of range!"<<std::endl;
        return;
    }
    p->visit(_start, _movings, _grid);
    _path = p->get_path();
}
