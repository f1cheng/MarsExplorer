#ifndef MARS_PLAN_H_
#define MARS_PLAN_H_ 


#include "Position.h"
#include "InstructionParser.h"
#include "MarsExplorer.h"

class MarsPlan
{
public:
    MarsPlan() {};
    virtual ~MarsPlan() {};
    void init_actions(const std::string &filename);
    void exec();
    std::vector<position_t> get_destinations()
    {
       return _dests; 
    }; 
private:
    std::vector<MarsExplorer> _explorers;
    Grid _grid; 
    std::vector<position_t> _dests;     
    
    InstructionParser _parser; 
    Coordinate _edge;
    std::vector<command_t> _commands;

};

#endif
