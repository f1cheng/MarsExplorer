#include <iostream>

#include "Position.h"

bool operator==(position_t &p1, position_t &p2)
{
    if (p1.x == p2.x &&
        p1.y == p2.y &&
        p1.direction == p2.direction)
        return true;
    return false;    
}

bool operator==(Position &p1, Position &p2)
{
    if (p1.get().x == p2.get().x &&
        p1.get().y == p2.get().y &&
        p1.get().direction == p2.get().direction)
        return true;
    return false;
}

Position::Position(const position_t &p)
{
   _p.x = p.x;
   _p.y = p.y;
   _p.direction = p.direction;       

}

/*
void Position::print() 
{
    char c = get_direction(_p.direction);
    std::cout << _p.x << " " << _p.y << " " << c << std::endl;
}
*/

bool Position::move(const Moving moving)
{
    switch (moving)
    {
    case LEFT:
        left();
        break;
    case RIGHT:
        right();
        break;
    case FORWARD:
        forward();
        break;
    default:
        break;
    }
      
    return true;
   
}

void Position::left()
{
    _p.direction = static_cast<Direction>((_p.direction+3) % 4);
}
void Position::right()
{
    _p.direction = static_cast<Direction>((_p.direction+1) % 4);
} 

void Position::forward()
{
    if (_p.direction == EAST)
        _p.x += 1;
    else if (_p.direction == SOURTH)
        _p.y -= 1;
    else if (_p.direction == WEST)
        _p.x -= 1;
    else if (_p.direction == NORTH)
        _p.y += 1;
}
