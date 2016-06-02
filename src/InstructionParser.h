#ifndef INSTRUCTION_PARSER_H_
#define INSTRUCTION_PARSER_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Position.h"
class InstructionParser
{
public:
   InstructionParser():_filename(), _inputfile() 
   {
        _commands.clear();
        _contents.clear();
   };

   ~InstructionParser(); 

   void load(const std::string &filename);
   void load_str(const std::string &contents);
   void get_commands(std::vector<command_t> &commands);
   void get_edge(Coordinate &edge);

private:
    void parse();
    void parse_edge(const std::string &line);
    void parse_position(const std::string &line, command_t &command);
    void parse_action(const std::string &line, command_t &command);

    std::string _filename;
    std::ifstream _inputfile;
    Coordinate _edge;
    std::vector<command_t> _commands;
    
    std::stringstream _contents;    
    std::stringstream _ss;

};

#endif
