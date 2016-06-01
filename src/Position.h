#ifndef POSITION_H_
#define POSITION_H_

#include <map>
#include <vector>

typedef enum {
    EAST, SOURTH, WEST, NORTH
} Direction;

typedef enum {
    LEFT, RIGHT, FORWARD
} Moving;

typedef enum {
    OK,
    OCCUPIED,
    OUT_OF_RANGE
} STATE;
const std::map<char, Direction> DIRECTIONS = {{'E', EAST},
                                              {'S', SOURTH},
                                              {'W', WEST},
                                              {'N', NORTH}};

const std::map<char, Moving> MOVINGS = {{'L', LEFT},
                                        {'R', RIGHT},
                                        {'M', FORWARD}};

const std::map<char, std::string> STATES = {{0, ""},
                                            {1, "OCCUPIED"},
                                            {2, "OUT OF RANGE"}};


typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    int x;
    int y;
    Direction direction;
} position_t;

bool operator==(position_t &p1, position_t &p2);


typedef struct {
    position_t pos;
    std::vector<Moving> movings;
} command_t;

class Position
{
public:
    Position() {};
    Position(const position_t &p);
    ~Position() {};
    friend bool operator==(Position &p1, Position &p2);
    bool move(const Moving moving);
    position_t get()
    {
        return _p;
    }

private:
    position_t _p; 

    void left();
    void right();
    void forward();

};

#endif
