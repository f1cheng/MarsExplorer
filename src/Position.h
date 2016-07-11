#ifndef POSITION_H_
#define POSITION_H_

#include <map>
#include <vector>
#include <iostream>

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

extern bool operator==(const Coordinate &p1, const Coordinate &p2);

inline bool operator==(const Coordinate &p1, const Coordinate &p2)
{
    if (p1.x == p2.x &&
        p1.y == p2.y)

        return true;
    return false;    
}


typedef struct {
    Position pos;
    std::vector<Moving> movings;
} Command;

char get_direction(Direction d);
inline char get_direction(Direction d)
{
    for (std::map<char, Direction>::const_iterator it = DIRECTIONS.begin(); 
         it != DIRECTIONS.end(); it++)
    {
        if (it->second == d)
            return it->first;
    }    
    return ' ';
}

void print_position(Position p);
inline void print_position(Position p)
{
    char c = get_direction(p.direction);
    std::cout << " (" << p.coor.x << "," << p.coor.y << "," << c << ")" << std::endl; 
}


void   print_coordinate(Coordinate p);
inline void print_coordinate(Coordinate p)
{
    std::cout << " (" << p.x << "," << p.y << ")" << std::endl; 
}


#endif
