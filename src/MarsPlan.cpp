#include <iostream>

#include "MarsPlan.h"

MarsPlan::MarsPlan()
{
    _dests.clear();
    _commands.clear(); 
}

MarsPlan::MarsPlan(const std::string &instruction_str)
{

    _parser.load_str(instruction_str);
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new Grid(_edge.x, _edge.y);
    for (const auto &com : _commands)
    {
       MarsExplorer explorer(com);
       _explorers.push_back(explorer);
    }


}

void MarsPlan::init_command(const std::string &instruction_str)
{

    _parser.load_str(instruction_str);
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new Grid(_edge.x, _edge.y);
    for (const auto &com : _commands)
    {
       MarsExplorer explorer(com);
       _explorers.push_back(explorer);
    }


}

void MarsPlan::init_actions(const std::string &filename) 
{
    _parser.load(filename);
    //std::string contents = std::string("5 5\n1 2 N\nLMLMLMLMM");
    //_parser.load_str(contents);
    _parser.get_commands(_commands);
    _parser.get_edge(_edge);
    
    _grid = new Grid(_edge.x, _edge.y);
    for (const auto &com : _commands)
    {
       MarsExplorer *explorer =  new MarsExplorer(com);
       _explorers.push_back(*explorer);
    }
}

void MarsPlan::exec()
{
    for (auto &mar : _explorers)
    {
        mar.visit(*_grid);
    }
}

void MarsPlan::run(const std::string &instruction_str)
{
    init_command(instruction_str);
    exec();
}

void MarsPlan::print()
{
    std::cout <<"Output:"<<std::endl;
    for (auto &mar : _explorers)
    {
        mar.print_pos();
    }
}    
