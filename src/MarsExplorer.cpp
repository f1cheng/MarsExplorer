
#include <iostream>
#include "MarsExplorer.h"
/* Remember: private data should having interface to accessing by interface*/
typedef struct {
    int x;
    int y;
} Coordinate;

/*
typedef enum {
    EAST, SOURTH, WEST, NORTH
} Direction;

typedef enum {
    LEFT, RIGHT, FORWARD
} Moving;

const std::map<char, Direction> DIRECTIONS = {{'E', EAST},
                                              {'S', SOURTH},
                                              {'W', WEST},
                                              {'N', NORTH}};
const std::map<char, Moving> MOVINGS = {{'L', LEFT},
                                        {'R', RIGHT},
                                        {'M', FORWARD}};

*/

typedef struct {
    Coordinate begin;
    Direction direction;
    std::vector<Moving> movings;
} command_t;

class ConfigParser;

class Position
{
private:
    Coordinate _curr;
    Direction _direction; 
    void left()
    {
        _direction = static_cast<Direction>((_direction+3) % 4);
    };
    void right()
    {
        _direction = static_cast<Direction>((_direction+1) % 4);
    }; 

    void forward()
    {
        if (_direction == EAST)
            _curr.x += 1;
        else if (_direction == SOURTH)
            _curr.y -= 1;
        else if (_direction == WEST)
            _curr.x -= 1;
        else if (_direction == NORTH)
            _curr.y += 1;
        
    }

public:
    Position() {};
    ~Position() {};
    Position(int x, int y, Direction d)
    {
        _curr.x = x;
        _curr.y = y;
        _direction = d;
    };
    
    void print() 
    {
        std::cout << _curr.x << " " << _curr.y << " " << _direction << std::endl;
    }

    Position &operator=(const Position &pos)
    { 
        this->_curr.x = pos._curr.x;
        this->_curr.y = pos._curr.y;
        this->_direction = pos._direction;
        return *this;
    };

    bool move(const Moving moving)
    {
        switch (moving)
        {
        case LEFT:
            left();
            break;
        case RIGHT:
            right();
            break;
        case FORWARD:
            forward();
            break;
        default:
            break;
        }
          
        return true;
       
    };
};

class Grid
{
public:
    Grid() {};
    Grid(int x, int y) 
    {
        _edge.x = x;
        _edge.y = y;
    };

    ~Grid() {};
    bool visit(Position &pos, std::vector<Moving> movings)
    {
        for(const auto &direction : movings)
            pos.move(direction);
        return true;
    };

    void set_edge(int x, int y)
    {
        _edge.x = x;
        _edge.y = y;
    };

    Coordinate get_edge(void)
    {
        return _edge;
    };

private:
    Coordinate _edge;
};

class MarsExplorer
{
public:
    MarsExplorer() {};
    ~MarsExplorer() {};
    MarsExplorer(int x, int y, char direction, const std::string &orders) 
    {
        set_current_pos(x, y, direction);
        translate_path(orders); 
    };

    void walk_through(Grid &grid)
    {
        grid.visit(destination, movings);
        destination.print();
    };

private:
    void set_current_pos(int x, int y, char direction)
    {
        origin = Position(x, y, DIRECTIONS.at(direction));
        destination = origin;
    };

    void translate_path(const std::string &orders)
    {
        for (auto const &c : orders)
        {
            movings.push_back(MOVINGS.at(c));
        }
    };

private:
    Position origin;
    std::vector<Moving> movings;
    Position destination;
};

class MarsPlan
{
public:
    MarsPlan() {};
    ~MarsPlan() {};
    void init_actions() 
    {
        _grid.set_edge(5, 5); 
        Coordinate c1={1,2};
        Direction d1=NORTH;
        std::vector<Moving> movings= {LEFT, FORWARD, LEFT, FORWARD, LEFT, FORWARD, LEFT, FORWARD, FORWARD}; 
        command_t com1 = {c1, d1, movings}; 
        _commands.clear();
        _commands[0] = com1;

        _explorers.clear();
        MarsExplorer mar(1, 2, 'N', std::string("LMLMLMLMM"));
        _explorers.push_back(mar);

    };

    void exec()
    {
        std::cout << " in exec \n";
        for (auto mar : _explorers)
            mar.walk_through(_grid);
    };    

private:
    std::vector<MarsExplorer> _explorers;
    Grid _grid; 
    
    ConfigParser *_config;
    Coordinate _edge;
    std::map<int, command_t> _commands;

    //ActionCommand commands;
};

#if 0

typedef struct {
    Coordinate begin;
    Direction direction;
    std::vector<Moving> movings;
} command_t;


Test Input：
5 5
1 2 N
LMLMLMLMM
3 3 E
MMRMMRMRRM

Expected Output:
1 3 N
5 1 E
int mm_main(int argc, char **argv)
{
    MarsPlan plan;
    ConfigParser config;
    config.load(file);
    Coordinate coor = config.get_coordinate();
    std::map<int, command_t> commands;
    commands = config.get_pos_movings();
    return 0;
}
#endif
