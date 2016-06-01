#include <iostream>

#include "InstructionParser.h"

InstructionParser::~InstructionParser() 
{
    if (_inputfile.is_open())
    {
        _inputfile.close();
    }
} 

void InstructionParser::load_str(const std::string &contents)
{

    std::stringstream whole_ss(contents);
    _commands.clear();
    
    std::string line;
    command_t command;
    int line_num = 0;
    //std::cout <<"Input:"<<std::endl;
    while (std::getline(whole_ss, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        //std::cout << line << std::endl;
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


void InstructionParser::load(const std::string &filename)
{
    _commands.clear();
    _inputfile.open(filename);
    if (!_inputfile.is_open())
    {
        throw std::runtime_error("ERROR: " + _filename + " not found.");
    }
    
    std::string line;
    command_t command;
    int line_num = 0;
    std::cout <<"Input:"<<std::endl;
    while (!_inputfile.eof())
    {
        std::getline(_inputfile, line);
        if (line.size() == 0)
        {
            continue;
        }

        std::cout << line << std::endl;
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
    
    _inputfile.close();
}

void InstructionParser::parse_edge(const std::string &line)
{
    _ss.clear(); 
    _ss.str(line);
    _ss >> _edge.x >>_edge.y;
    if (_ss.fail())
    {
        throw std::runtime_error("ERROR: Parse edge");
    }

}

void InstructionParser::parse_position(const std::string &line, command_t &command)
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
    command.pos.x = x;
    command.pos.y = y;
    try
    {
        command.pos.direction = DIRECTIONS.at(d);
    }
    catch(const std::exception &e)
    {
        throw std::runtime_error("ERROR: Parse direction");
    }
}

void InstructionParser::parse_action(const std::string &line, command_t &command)
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

void InstructionParser::get_commands(std::vector<command_t> &commands)
{
    commands = _commands;
}

void InstructionParser::get_edge(Coordinate &edge)
{
    edge = _edge;
}
