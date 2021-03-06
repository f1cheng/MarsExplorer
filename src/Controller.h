#ifndef MARS_PLAN_H_
#define MARS_PLAN_H_ 


#include "Parser.h"
#include "Explorer.h"

class Controller
{
public:
    Controller();
    virtual ~Controller() {};
    void dispatch_command(const std::string &instruction_str);
#ifndef __UT__
    void dispatch_command_from_file(const std::string &filename);
#endif
    void exec(MoveStrategy *m);

    std::vector<Explorer> &get_exps()
    {
        return _explorers;
    }

    std::map<int, std::vector<Position>> &get_paths()
    {
        return _paths;
    }

    void print_paths();

    void set_blocked_view(Position p);
private:
    std::vector<Explorer> _explorers;
    StateGrid *_grid; 
    std::map<int, std::vector<Position>> _paths;
    
    Parser _parser; 
    Coordinate _edge;
    std::vector<Command> _commands;
};

#endif
