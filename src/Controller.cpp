#include <iostream>
#include <unistd.h>

#include "Controller.h"

Controller::Controller()
{
    _paths.clear();
}

void Controller::dispatch_command(const std::string &instruction_str)
{
    _parser.load_str(instruction_str);
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new StateGrid(_edge.x, _edge.y);
    for (const auto &com : _commands)
    {
       Explorer e;
       e.init(com.pos, com.movings, _grid);
       _explorers.push_back(e);
    }
}

#ifndef __UT__
void Controller::dispatch_command_from_file(const std::string &filename) 
{
    _parser.load(filename);
    //std::string contents = std::string("5 5\n1 2 N\nLMLMLMLMM");
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new StateGrid(_edge.x, _edge.y);
    for (const auto &com : _commands)
    {
       Explorer e;
       e.init(com.pos, com.movings, _grid);
       _explorers.push_back(e);
    }

}
#endif

void Controller::set_blocked_view(Position p)
{
    _grid->set_blocked(p);
}

void Controller::exec(MoveStrategy *strategy)
{
    int i = 0;
    for (auto &mar : _explorers)
    {
        mar.search_path(strategy);
        mar.walk_path(_paths[i]);
        if (mar.get_path().size() == 0)
            continue;
        set_blocked_view(mar.get_path().back());
        i++;
#ifndef __UT__
        sleep(5);
#endif
    }
}

void Controller::print_paths()
{
/*
   std::cout <<"Output: \n";
   for (size_t i = 0; i < _paths.size(); i++)
   {
       
       for (auto &p : _paths[i])
       {
           print_position(p);
       }
       std::cout << std::endl;
   }  
*/
}
