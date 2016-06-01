#ifndef MARS_EXPLORER_H_
#define MARS_EXPLORER_H_

#include <iostream>
#include <vector>

#include "Grid.h"

class MarsExplorer
{
public:
    MarsExplorer() {};
    ~MarsExplorer() {};
    MarsExplorer(const command_t &command);
    position_t walk_through(Grid &grid);
    void print_destination();
    Position get_destination()
    {
        return _destination;
    };
private:
    Position _origin;
    std::vector<Moving> _movings;
    Position _destination;
    STATE _state;
};

#endif
