#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Position.h"

class Grid
{
public:
    Grid() {};
    Grid(int x, int y);
    ~Grid() {};

    bool visit(Position &pos, std::vector<Moving> movings);
    void set_edge(int x, int y);
    Coordinate get_edge(void);

private:
    Coordinate _edge;
};

#endif
