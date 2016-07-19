#ifndef INSTRUCTION_PARSER_H_
#define INSTRUCTION_PARSER_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Position.h"

class Parser
{
public:
   Parser():_filename(), _inputfile() 
   {
        _commands.clear();
        _contents.clear();
   };

   ~Parser(); 

   void load(const std::string &filename);
   void load_str(const std::string &contents);
   void get_commands(std::vector<Command> &commands);
   void get_edge(Coordinate &edge);

private:
    void parse();
    void parse_edge(const std::string &line);
    void parse_position(const std::string &line, Command &command);
    void parse_action(const std::string &line, Command &command);

    std::string _filename;
    std::ifstream _inputfile;
    Coordinate _edge;
    std::vector<Command> _commands;
    
    std::stringstream _contents;    
    std::stringstream _ss;

};

#endif
