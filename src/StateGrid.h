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
    void set_value(Coordinate coor, int value);
    State check_pos(Position &pos);

    void trace(Position pos); 
    void set_blocked(Position pos);

    std::vector<Coordinate> set_neighbor(Coordinate cur);
    int get_value(Coordinate coor);
    std::vector<Coordinate> get_pre_neighbors(Coordinate cur);

    State check_coor(Coordinate coor);
private:
    void adjust(Coordinate &coor);
    void init_states(int x, int y);
    void init_values(int x, int y);
    void init_plane(int x, int y);    

    bool out_of_range(Position &pos);
    bool is_occupied(Position &pos);

    bool out_of_range(Coordinate coor);
    bool is_occupied(Coordinate coor);


    Coordinate _edge;
    int **_states;
    int **_values;
    char **_plane;
};

#endif
