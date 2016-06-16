#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Position.h"

class StateGrid
{
public:
    StateGrid() {};
    StateGrid(int x, int y);
    ~StateGrid();

    void set_edge(int x, int y);
    Coordinate get_edge(void);
    void set_occupied(Position &pos);

    State check_pos(Position &pos);
private:

    bool out_of_range(Position &pos);
    bool is_occupied(Position &pos);

    Coordinate _edge;
    int **_states;
};

#endif
