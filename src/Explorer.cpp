#include "Explorer.h"

void Explorer::execute(MoveStrategy *p)
{
    p->visit(_start, _movings, _grid);
    _path = p->get_path();
}


