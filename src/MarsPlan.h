#ifndef MARS_PLAN_H_
#define MARS_PLAN_H_ 


#include "InstructionParser.h"
#include "Explorer.h"

class MarsPlan
{
public:
    MarsPlan();
    virtual ~MarsPlan() {};
    void dispatch_command(const std::string &instruction_str);
#ifndef __UT__
    void dispatch_command_from_file(const std::string &filename);
#endif
    void exec();

    void run(const std::string &instruction_str);

    void print();
    std::vector<Explorer> &get_explorers()
    {
        return _explorers;
    }

    std::vector<Position> get_destinations()
    {
       return _dests; 
    }; 

private:
    std::vector<Explorer> _explorers;
    StateGrid *_grid; 
    std::vector<Position> _dests;     
    
    InstructionParser _parser; 
    Coordinate _edge;
    std::vector<Command> _commands;
};

#endif
