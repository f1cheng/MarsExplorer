#ifndef MARS_EXPLORER_H_
#define MARS_EXPLORER_H_

#include <iostream>
#include <vector>

#include "Position.h"
#include "StateGrid.h"

class Explorer
{
public:
    Explorer() 
    {
        _path.clear();
    };

    ~Explorer() {};
    Explorer(const Command &command);
    void print_pos();
    Position get_pos()
    {
        return _curr_pos;
    };

    State get_state()
    {
        return _state;
    };

    void visit(StateGrid &grid);

    void walk_path(std::vector<Position> &path)
    {
        path = _path;
    }

private:
    Position lookat_next(Moving moving, StateGrid &grid);
    void left(Position &p);
    void right(Position &p);
    void forward(Position &p, StateGrid &grid);
    void process_edge(Position &p, StateGrid &grid);

    std::vector<Moving> _movings;
    Position _curr_pos;
    Position _block_pos;
    State _state;

    std::vector<Position> _path;
};

#endif
