#include "Position.h"
#include "MoveStrategy.h"
#include "StateGrid.h"

class MovePlanA : public MoveStrategy
{

public:
    //MovePlanA() {};
    virtual ~MovePlanA() {};

    std::vector<Position> get_path()
    {
        return _path;
    };

    virtual void visit(Position start, std::vector<Moving> movings, StateGrid *grid);

    void pure_visit(Position start, std::vector<Moving> moves);

    void init(Position pos, std::vector<Moving> movings, StateGrid *grid)
    {
        _path.clear();
        _start = pos;
        _movings = movings; 
        _grid = grid;
    };

    std::vector<Moving> calculate_movings(Direction orig, std::vector<Coordinate> coors);
    std::vector<Moving> get_movings(Coordinate s, Coordinate d, Direction src, Direction &des); 

    Direction neighbor_direction(Coordinate s, Coordinate d); 
    std::vector<Moving> turn(Direction src, Direction des);

private:
    std::vector<Coordinate>  move_around(Position curr_pos, std::vector<Moving> movings);
    std::vector<Coordinate> shortest_path(Coordinate cur, Coordinate dest);
    std::vector<Coordinate> list_shortest_path_coors(Coordinate dest);
    std::vector<Position>  lookat_possible_dests(Position pos, std::vector<Moving> movings);

    Position lookat_next(Position p, Moving moving);
    void left(Position &pos);
    void right(Position &pos);
    void forward(Position &pos);
    void process_edge(Position &pos);

    Position _start;
    std::vector<Moving> _movings;
    StateGrid *_grid;

    std::vector<Position> _path;

};
