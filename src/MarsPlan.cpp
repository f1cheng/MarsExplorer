#include <iostream>

#include "MarsPlan.h"

void MarsPlan::init_actions(const std::string &filename) 
{
    _dests.clear();
    _parser.load(filename);
    _commands.clear(); 
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    for (const auto &com : _commands)
    {
       MarsExplorer explorer(com);
       _explorers.push_back(explorer);
    }
}

void MarsPlan::exec()
{
    std::cout <<"Output:"<<std::endl;
    position_t p;
    for (auto mar : _explorers)
    {
        p = mar.walk_through2(_grid);
        _dests.push_back(p);
    }
}    
