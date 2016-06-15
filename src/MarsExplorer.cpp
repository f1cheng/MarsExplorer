#include <iostream>

#include "MarsExplorer.h"
   
static char get_direction(Direction d)
{
    for (std::map<char, Direction>::const_iterator it = DIRECTIONS.begin(); 
         it != DIRECTIONS.end(); it++)
    {
        if (it->second == d)
            return it->first;
    }    
    return ' ';
}

MarsExplorer::MarsExplorer(const Command &command) 
{
    _curr_pos = command.pos;
    _movings = command.movings;

}

void MarsExplorer::print_pos()
{
    char c = get_direction(_curr_pos.direction);
    std::cout << _curr_pos.coor.x << " " << _curr_pos.coor.y << " " << c << " " << STATES.at(_state)<< " ";
    if (_state == OCCUPIED)
    {
        std::cout <<_block_pos.coor.x << " " << _block_pos.coor.y <<std::endl;    
    }
    else
    {
        std::cout <<std::endl;
    }
}

void MarsExplorer::visit(Grid &grid)
{
    _state = grid.check_pos(_curr_pos);
    if (_state != OK)
    {
        return;
    }

    for (auto const moving : _movings)
    {
        Position new_pos = lookat_next(moving, grid);
        _state = grid.check_pos(new_pos);
        if (_state == OCCUPIED)
        {
            _block_pos = new_pos;
            break;
        }
        _curr_pos = new_pos;
    }
    grid.set_occupied(_curr_pos);
}

Position MarsExplorer::lookat_next(Moving moving, Grid &grid)
{   
    Position pos =_curr_pos;
    switch (moving)
    {
    case LEFT:
        left(pos);
        break;
    case RIGHT:
        right(pos);
        break;
    case FORWARD:
        forward(pos, grid);
        break;
    default:
        break;
    }
    return pos;
}

void MarsExplorer::left(Position &pos)
{
    pos.direction = static_cast<Direction>((pos.direction+3) % 4);
}

void MarsExplorer::right(Position &pos)
{
    pos.direction = static_cast<Direction>((pos.direction+1) % 4);
}

void MarsExplorer::forward(Position &pos, Grid &grid)
{
    if (pos.direction == EAST)
        pos.coor.x += 1;
    else if (pos.direction == SOURTH)
        pos.coor.y -= 1;
    else if (pos.direction == WEST)
        pos.coor.x -= 1;
    else if (pos.direction == NORTH)
        pos.coor.y += 1;

    process_edge(pos, grid);
}

void MarsExplorer::process_edge(Position &pos, Grid &grid)
{
    int edge_x, edge_y;
    edge_x = grid.get_edge().x;
    edge_y = grid.get_edge().y;
    
    if (pos.coor.x == (edge_x + 1))
    {
        pos.coor.x = 0;
    }
    else if (pos.coor.x == -1)
    {
        pos.coor.x = edge_x;
    }
 
    if (pos.coor.y == (edge_y + 1))
    {
        pos.coor.y = 0;
    }
    else if (pos.coor.y == -1)
    {
        pos.coor.y = edge_y;
    }
}

