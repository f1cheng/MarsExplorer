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

    void search_path(MoveStrategy *p); 
    
    void walk_path(std::vector<Position> &path)
    {
        path = _path;
        for (auto const p : _path)
        {
            move_view(p);
        }
    };

    void move_view(Position p)
    {
        _grid->trace(p);
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
