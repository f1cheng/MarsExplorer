#ifndef MARS_EXPLORER_
#define MARS_EXPLORER_

#include <string>
#include <vector>
#include <map>

typedef enum {
    EAST, SOURTH, WEST, NORTH
} Direction;

typedef enum {
    LEFT, RIGHT, FORWARD
} Moving;
/*
const std::map<char, Direction> DIRECTIONS = {{'E', EAST}, 
                                        {'S', SOURTH}, 
                                        {'W', WEST}, 
                                        {'N', NORTH}};
const std::map<char, Moving> MOVINGS = {{'L', LEFT}, 
                                     {'R', RIGHT}, 
                                     {'M', FORWARD}};


const std::map<char, int> MARS_DIRECTIONS = {{'E', EAST}, {'S', SOURTH}, {'W', WEST}, {'N', NORTH}};
const std::map<char, int> MARS_MOVINGS = {{'L', LEFT}, {'R', RIGHT}, {'M', FORWARD}};
*/

const std::map<char, Direction> DIRECTIONS = {{'E', EAST},
                                              {'S', SOURTH},
                                              {'W', WEST},
                                              {'N', NORTH}};
const std::map<char, Moving> MOVINGS = {{'L', LEFT},
                                        {'R', RIGHT},
                                        {'M', FORWARD}};
#endif
