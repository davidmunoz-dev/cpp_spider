//
// CommandOutput.cpp for  in /home/beche/rendu/cpp_spider/server
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Sat Oct  7 13:41:58 2017 beche
// Last update Sat Oct  7 15:59:25 2017 beche
//

#include <iostream>
#include "CommandOutput.hpp"
#include "Data.h"

CommandOutput::CommandOutput()
{
  this->array[0] = &CommandOutput::pong;

  this->keys[0] = "pong";
}

CommandOutput::~CommandOutput(){
}

bool	CommandOutput::exec(const std::string &input)
{
  int	i;

  i = 0;
  for (i = 0; i < 3; i++)
    {
      if (input == this->keys[i])
	{
	  ((*this).*array[i])();
	}
    }
  return (true);
}

bool CommandOutput::pong()
{
  std::cout << "pong" << std::endl;
  return (true);
}


bool CommandOutput::pullKb(){

  t_paquet p;

  p.opcode = 0x10;
  p.kbdata = NULL;
  p.msdata = NULL;
  (void)p;
  return (true);
}
bool CommandOutput::pullMs(){
  return (true);
}
