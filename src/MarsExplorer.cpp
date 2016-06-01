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

MarsExplorer::MarsExplorer(const command_t &command) 
{
    _origin = Position(command.pos);
    _destination = _origin; 
    _movings = command.movings;

}

position_t MarsExplorer::walk_through(Grid &grid)
{
    _state = grid.visit(_destination, _movings);
    print_destination();
    return _destination.get();

}

void MarsExplorer::print_destination()
{
    char c = get_direction(_destination.get().direction);
    std::cout << _destination.get().x << " " << _destination.get().y << " " << c << " " << STATES.at(_state) <<std::endl;    
}

