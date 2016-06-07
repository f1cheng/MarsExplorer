#include <iostream>
#include <cstring>

#include "Grid.h"

Grid::Grid(int x, int y) 
{
    _edge.x = x;
    _edge.y = y;

    int _x = x+1, _y = y+1;
    _coords = new int *[_x];
    for (int i=0; i < _x; i++)
    {
       _coords[i] = new int [_y](); 
    }
}

Grid::~Grid()
{
    for (int i=0; i < (_edge.x + 1); i++)
        delete [] _coords[i];
    delete [] _coords; 
}

State Grid::check_pos(Position &pos)
{
    /* range should be check firstly */
    if (out_of_range(pos))
    {
        return OUT_OF_RANGE;
    }
    else if (is_occupied(pos))
    {
        return OCCUPIED;
    }
    else
    {
        return OK;
    }
}

/*
 * current solution: 
 * out of range should not affect others, so move it to out of range(INVALID), 
 * not stay there to occupy a posion.
*/

void Grid::set_edge(int x, int y)
{
    _edge.x = x;
    _edge.y = y;
}

Coordinate Grid::get_edge(void)
{
    return _edge;
}

bool Grid::out_of_range(Position &pos)
{
    if((pos.coor.x > _edge.x) ||
       (pos.coor.y > _edge.y))
        return true;
    if ((pos.coor.x <0) ||
        (pos.coor.y <0))
        return true;
    return false;
      
}

void Grid::set_occupied(Position &pos)
{
    if (out_of_range(pos))
    {
        return;
    }
    _coords[pos.coor.x][pos.coor.y] = OCCUPIED;
}

bool Grid::is_occupied(Position &pos)
{
    return _coords[pos.coor.x][pos.coor.y] == OCCUPIED;
}    
