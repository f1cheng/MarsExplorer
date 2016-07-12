#include "Explorer.h"

void Explorer::search_path(MoveStrategy *p)
{
    p->visit(_start, _movings, _grid);
    _path = p->get_path();
}


