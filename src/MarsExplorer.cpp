#include "MarsExplorer.h"

MarsExplorer::MarsExplorer(const command_t &command) 
{
    _origin = Position(command.pos);
    _destination = _origin; 
    _movings = command.movings;

}

void MarsExplorer::walk_through(Grid &grid)
{
    grid.visit(_destination, _movings);
    _destination.print();
}


position_t MarsExplorer::walk_through2(Grid &grid)
{
    grid.visit(_destination, _movings);
    _destination.print();
    return _destination.get();

}
