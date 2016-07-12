#include <iostream>
#include <cstring>
#include <unistd.h>

#include "StateGrid.h"
void StateGrid::init_states(int x, int y)
{
    int _x = x+1, _y = y+1;
    _states = new int *[_x];
    for (int i=0; i < _x; i++)
    {
       _states[i] = new int [_y](); 
    }
}

void StateGrid::init_values(int x, int y)
{
    int _x = x+1, _y = y+1;
    _values = new int *[_x];
    for (int i=0; i < _x; i++)
    {
       _values[i] = new int [_y](); 
    }

    for (int i = 0; i <= _edge.x; i++)
    {
        for (int j = 0; j <= _edge.y; j++)
        {
           _values[i][j] = 0;
        }
    }

}

void StateGrid::init_plane(int x, int y)
{
    int _x = x+1, _y = y+1;
    _plane = new char *[_x];
    for (int i=0; i < _x; i++)
    {
       _plane[i] = new char [_y](); 
    }
}

void StateGrid::set_blocked(Position pos)
{
    set_occupied(pos);
    trace(pos);
}

void StateGrid::trace(Position pos)
{
    sleep(1);
    std::system("clear");
 
    for (int i = 0; i <= _edge.x; i++)
    { 
        for (int j = 0; j <= _edge.y; j++)
        {
            _plane[i][j] = '0';
        }
    }
 
    char sky = '0';
    sky = get_direction(pos.direction);
    _plane[_edge.y-pos.coor.y][pos.coor.x] = sky; 

    for (int i = 0; i <= _edge.x; i++)
    { 
        for (int j = 0; j <= _edge.y; j++)
        {
            if (_states[i][j] == OCCUPIED)
            {
                sky = '*';
                _plane[_edge.y-j][i] = sky; 
            }
        }
    }
 
    for (int i = 0; i <= _edge.x; i++)
    { 
        for (int j = 0; j <= _edge.y; j++)
        {
            std::cout<<"   "<<_plane[i][j];
        }
        std::cout<<std::endl;
    }
}

void StateGrid::set_value(Coordinate coor, int value)
{
    _values[coor.x][coor.y] = value;
}

StateGrid::StateGrid(int x, int y) 
{
    _edge.x = x;
    _edge.y = y;
    init_states(x, y);
    init_values(x, y);
    init_plane(x, y);
}

StateGrid::~StateGrid()
{
    for (int i=0; i < (_edge.x + 1); i++)
    {
       delete [] _states[i];
       delete [] _values[i];
       delete [] _plane[i];
    }
    delete [] _states; 
    delete [] _values;
    delete [] _plane;
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

State StateGrid::check_coor(Coordinate coor)
{
    if (out_of_range(coor))
    {
        return OUT_OF_RANGE;
    }
    else if (is_occupied(coor))
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

bool StateGrid::out_of_range(Coordinate coor)
{
    if((coor.x > _edge.x) ||
       (coor.y > _edge.y))
        return true;
    if ((coor.x <0) ||
        (coor.y <0))
        return true;
    return false;
      
}


bool StateGrid::is_occupied(Coordinate coor)
{
    return _states[coor.x][coor.y] == OCCUPIED;
}    



std::vector<Coordinate> StateGrid::set_neighbor(Coordinate cur)
{
    std::vector<Coordinate> v;
    Coordinate east, sourth, west, north;
    east = sourth = west = north = cur;
    int val = get_value(cur);
    
    east.x++;
    sourth.y--;
    west.x--;
    north.y++;
    adjust(east);
    adjust(sourth);
    adjust(west);
    adjust(north);
    State state = check_coor(east);
    int value;
    value = get_value(east);
    if ((state == OK) && (value == 0))
    {
        v.push_back(east);
    }
    state = check_coor(sourth);
    value = get_value(sourth);
    if ((state == OK) && (value == 0))
    {
        v.push_back(sourth);
    }
    state = check_coor(west);
    value = get_value(west);
    if ((state == OK) && (value == 0))
    {
        v.push_back(west);
    }
    state = check_coor(north);
    value = get_value(north);
    if ((state == OK) && (value == 0))
    {
        v.push_back(north);
    }

    for (auto const c : v)
    {
        set_value(c, val+1);
    }

    return v;
}


void StateGrid::adjust(Coordinate &coor)
{
    int edge_x, edge_y;
    edge_x = get_edge().x;
    edge_y = get_edge().y;

    if (coor.x == (edge_x + 1))
    {
        coor.x = 0;
    }
    else if (coor.x == -1)
    {
        coor.x = edge_x;
    }

    if (coor.y == (edge_y + 1))
    {
        coor.y = 0;
    }
    else if (coor.y == -1)
    {
        coor.y = edge_y;
    }
}

int StateGrid::get_value(Coordinate coor)
{
    return _values[coor.x][coor.y];
}

std::vector<Coordinate> StateGrid::get_pre_neighbors(Coordinate cur)
{
    std::vector<Coordinate> v;
    Coordinate east, sourth, west, north;
    east = sourth = west = north = cur;
    int val = get_value(cur);
    
    east.x++;
    sourth.y--;
    west.x--;
    north.y++;
    adjust(east);
    adjust(sourth);
    adjust(west);
    adjust(north);
    State state = check_coor(east);
    int value;
    value = get_value(east);
    if ((state == OK) && (value == (val-1)))
    {
        v.push_back(east);
    }
    state = check_coor(sourth);
    value = get_value(sourth);
    if ((state == OK) && (value == (val-1)))
    {
        v.push_back(sourth);
    }
    state = check_coor(west);
    value = get_value(west);
    if ((state == OK) && (value == (val-1)))
    {
        v.push_back(west);
    }
    state = check_coor(north);
    value = get_value(north);
    if ((state == OK) && (value == (val-1)))
    {
        v.push_back(north);
    }

    return v;
}


