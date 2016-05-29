#ifndef MARS_EXPLORER_H_
#define MARS_EXPLORER_H_

#include <vector>

#include "Grid.h"

class MarsExplorer
{
public:
    MarsExplorer() {};
    ~MarsExplorer() {};
    MarsExplorer(const command_t &command);
    void walk_through(Grid &grid);
    position_t walk_through2(Grid &grid);

private:
    Position _origin;
    std::vector<Moving> _movings;
    Position _destination;
};

#endif
