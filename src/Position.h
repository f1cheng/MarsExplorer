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
    OUT_OF_RANGE,
    BLOCKED = 10
} State;

const std::map<char, Direction> DIRECTIONS = {{'E', EAST},
                                              {'S', SOURTH},
                                              {'W', WEST},
                                              {'N', NORTH}};

const std::map<char, Moving> MOVINGS = {{'L', LEFT},
                                        {'R', RIGHT},
                                        {'M', FORWARD}};

const std::map<char, std::string> STATES = {{OK, ""},
                                            {OCCUPIED, "OCCUPIED"},
                                            {OUT_OF_RANGE, "OUT OF RANGE"}};


typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate coor;
    Direction direction;
} Position;

extern bool operator==(const Position &p1, const Position &p2);

inline bool operator==(const Position &p1, const Position &p2)
{
    if (p1.coor.x == p2.coor.x &&
        p1.coor.y == p2.coor.y &&
        p1.direction == p2.direction)
        return true;
    return false;    
}

typedef struct {
    Position pos;
    std::vector<Moving> movings;
} Command;

#endif
