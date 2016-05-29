#include "Grid.h"

Grid::Grid(int x, int y) 
{
    _edge.x = x;
    _edge.y = y;
}

bool Grid::visit(Position &pos, std::vector<Moving> movings)
{
    for(const auto &direction : movings)
        pos.move(direction);
    return true;
}

void Grid::set_edge(int x, int y)
{
    _edge.x = x;
    _edge.y = y;
}

Coordinate Grid::get_edge(void)
{
    return _edge;
}

