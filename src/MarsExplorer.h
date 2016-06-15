#ifndef MARS_EXPLORER_H_
#define MARS_EXPLORER_H_

#include <iostream>
#include <vector>

#include "Position.h"
#include "Grid.h"

class MarsExplorer
{
public:
    MarsExplorer() {};
    ~MarsExplorer() {};
    MarsExplorer(const Command &command);
    void print_pos();
    Position get_pos()
    {
        return _curr_pos;
    };

    State get_state()
    {
        return _state;
    };

    void visit(Grid &grid);
private:
    Position lookat_next(Moving moving, Grid &grid);
    void left(Position &p);
    void right(Position &p);
    void forward(Position &p, Grid &grid);
    void process_edge(Position &p, Grid &grid);

    std::vector<Moving> _movings;
    Position _curr_pos;
    Position _block_pos;
    State _state;
};

#endif
