#ifndef MOVE_STRATEGY_H_
#define MOVE_STRATEGY_H_

#include "StateGrid.h"

class MoveStrategy
{
public:
    MoveStrategy() {};
    virtual ~MoveStrategy() {};

    virtual void visit(Position start, std::vector<Moving> movings, StateGrid *grid) = 0;
    virtual std::vector<Position> get_path() 
    {
        return _path;
    };

private:
    Position _start;
    std::vector<Moving> _movings;
    StateGrid *_grid;

    std::vector<Position> _path;
};

#endif
