#include <iostream>

#include "Parser.h"

Parser::~Parser() 
{
    if (_inputfile.is_open())
    {
        _inputfile.close();
    }
} 

void Parser::parse()
{
    std::string line;
    Command command;
    int line_num = 0;
#ifndef __UT__
    std::cout <<"Input:"<<std::endl;
#endif
    while (std::getline(_contents, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

#ifndef __UT__
        std::cout << line << std::endl;
#endif
        if (line_num == 0)
        {
            parse_edge(line);
        }
        else if ((line_num%2) == 1)
        {
            parse_position(line, command);
        }
        else
        {
            parse_action(line, command); 
        }
        
        line_num++;
    }
}

void Parser::load_str(const std::string &contents)
{

    _contents.str(contents);
    parse(); 
}


void Parser::load(const std::string &filename)
{
    _inputfile.open(filename);
    if (!_inputfile.is_open())
    {
        throw std::runtime_error("ERROR: " + _filename + " not found.");
    }
    _contents << _inputfile.rdbuf();    
    _inputfile.close();
    
    parse();
}

void Parser::parse_edge(const std::string &line)
{
    _ss.clear(); 
    _ss.str(line);
    _ss >> _edge.x >>_edge.y;
    if (_ss.fail())
    {
        throw std::runtime_error("ERROR: Parse edge");
    }

}

void Parser::parse_position(const std::string &line, Command &command)
{
    int x, y;
    char d;
    _ss.clear();
    _ss.str(line);
    _ss >> x >>y >>d;
    
    if (_ss.fail())
    {
        throw std::runtime_error("ERROR: Parse position");
    }
    command.pos.coor.x = x;
    command.pos.coor.y = y;
    try
    {
        command.pos.direction = DIRECTIONS.at(d);
    }
    catch(const std::exception &e)
    {
        throw std::runtime_error("ERROR: Parse direction");
    }
}

void Parser::parse_action(const std::string &line, Command &command)
{
    try 
    {
        for (const auto &m : line)
            command.movings.push_back(MOVINGS.at(m));
    }
    catch(const std::exception &e) 
    { 
        throw std::runtime_error("ERROR: Parse moving");
    }
    _commands.push_back(command);
    command.movings.clear();
}  

void Parser::get_commands(std::vector<Command> &commands)
{
    commands = _commands;
}

void Parser::get_edge(Coordinate &edge)
{
    edge = _edge;
}
