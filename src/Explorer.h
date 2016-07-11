#ifndef MARS_EXPLORER_H_
#define MARS_EXPLORER_H_

#include <iostream>
#include <vector>

#include "Position.h"
#include "StateGrid.h"
#include "MoveStrategy.h"

class Explorer
{

public:
    Explorer() {};
    ~Explorer() {};

    void init(Position start, std::vector<Moving> movings, StateGrid *grid)
    {
       _start = start; 
       _movings = movings;
       _grid = grid;
    };

    void execute(MoveStrategy *p); 
/*
    void execute(MoveStrategy *p) 
    {
        p->visit(_start, _movings, _grid);
    };
*/
    void walk_path(std::vector<Position> &path)
    {
        path = _path;
    };
    std::vector<Position> get_path()
    {
        return _path;
    };
    
private:
    std::vector<Moving> _movings;
    Position _start;
    StateGrid *_grid;
    std::vector<Position> _path;

};

#endif
