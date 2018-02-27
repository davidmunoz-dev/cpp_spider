//
// CommandOutput.hpp for  in /home/beche/rendu/cpp_spider/server
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Sat Oct  7 13:35:48 2017 beche
// Last update Sat Oct  7 15:58:29 2017 beche
//

#ifndef COMMANDOUTPUT_HPP_
# define COMMANDOUTPUT_HPP_

class CommandOutput
{
public:
  CommandOutput();
  ~CommandOutput();

  bool	exec(const std::string &input);

  bool pong();
  bool pullKb();
  bool pullMs();
  typedef bool (CommandOutput::*funcPtr)();
  funcPtr array[10];
  std::string keys[10];
};

#endif /* COMMANDOUTPUT_HPP_ */
