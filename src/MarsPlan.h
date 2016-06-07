#ifndef MARS_PLAN_H_
#define MARS_PLAN_H_ 


#include "InstructionParser.h"
#include "MarsExplorer.h"

class MarsPlan
{
public:
    MarsPlan();
    MarsPlan(const std::string &instruction_str);
    virtual ~MarsPlan() {};
    void init_actions(const std::string &filename);
    void exec();
    void print();
    std::vector<MarsExplorer> &get_explorers()
    {
        return _explorers;
    }

    std::vector<Position> get_destinations()
    {
       return _dests; 
    }; 

private:
    std::vector<MarsExplorer> _explorers;
    Grid *_grid; 
    std::vector<Position> _dests;     
    
    InstructionParser _parser; 
    Coordinate _edge;
    std::vector<Command> _commands;
};

#endif
