#include <iostream>
#include <cstring>

#include "StateGrid.h"

StateGrid::StateGrid(int x, int y) 
{
    _edge.x = x;
    _edge.y = y;

    int _x = x+1, _y = y+1;
    _states = new int *[_x];
    for (int i=0; i < _x; i++)
    {
       _states[i] = new int [_y](); 
    }
}

StateGrid::~StateGrid()
{
    for (int i=0; i < (_edge.x + 1); i++)
        delete [] _states[i];
    delete [] _states; 
}

State StateGrid::check_pos(Position &pos)
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

void StateGrid::set_edge(int x, int y)
{
    _edge.x = x;
    _edge.y = y;
}

Coordinate StateGrid::get_edge(void)
{
    return _edge;
}

bool StateGrid::out_of_range(Position &pos)
{
    if((pos.coor.x > _edge.x) ||
       (pos.coor.y > _edge.y))
        return true;
    if ((pos.coor.x <0) ||
        (pos.coor.y <0))
        return true;
    return false;
      
}

void StateGrid::set_occupied(Position &pos)
{
    if (out_of_range(pos))
    {
        return;
    }
    _states[pos.coor.x][pos.coor.y] = OCCUPIED;
}

bool StateGrid::is_occupied(Position &pos)
{
    return _states[pos.coor.x][pos.coor.y] == OCCUPIED;
}    
