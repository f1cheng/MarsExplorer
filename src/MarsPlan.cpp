#include <iostream>

#include "MarsPlan.h"

MarsPlan::MarsPlan()
{
    _dests.clear();
    _commands.clear(); 
}

void MarsPlan::init_actions(const std::string &filename) 
{
/*    

5 5\n1 2 N\nLMLMLMLMM
1 2 N
LMLMLMLMM

*/
    _parser.load(filename);
    //std::string contents = std::string("5 5\n1 2 N\nLMLMLMLMM");
    //_parser.load_str(contents);
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new Grid(_edge.x, _edge.y);
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
        p = mar.walk_through(*_grid);
        _dests.push_back(p);
    }
}    
