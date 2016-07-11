#include <iostream>

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

void Controller::exec(MoveStrategy *strategy)
{
    int i = 0;
    for (auto &mar : _explorers)
    {
        mar.execute(strategy);
        mar.walk_path(_paths[i]);
        //_paths[i] = mar.get_path();
        i++;
    }
}

void Controller::print_paths()
{
   for (size_t i = 0; i < _paths.size(); i++)
   {
       
       for (auto &p : _paths[i])
       {
           print_position(p);
       }
       std::cout << std::endl;
   }  

}

//options: commands, edge as the params
void Controller::run(const std::string &instruction_str)
{
    //dispatch_command(instruction_str);
    //exec(strategy);
}

void Controller::print()
{
    std::cout <<"\nOutput: \n";
    print_paths();
}    
