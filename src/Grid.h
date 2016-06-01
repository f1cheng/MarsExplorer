#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Position.h"

class Grid
{
public:
    Grid() {};
    Grid(int x, int y);
    ~Grid();

    STATE visit(Position &pos, std::vector<Moving> movings);
    void set_edge(int x, int y);
    Coordinate get_edge(void);
private:
    STATE check_pos(Position &pos);
    bool out_of_range(Position &pos);
    void set_occupied(Position &pos);
    bool is_occupied(Position &pos);
    Coordinate _edge;
    int **_coords;
};

#endif
