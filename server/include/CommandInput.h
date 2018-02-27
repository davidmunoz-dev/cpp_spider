/*
** command.h for  in /home/beche/rendu/test
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Tue Oct  3 13:07:32 2017 beche
** Last update Sat Oct  7 13:32:45 2017 beche
*/

#ifndef COMMANDINPUT_H_
# define COMMANDINPUT_H_

#include <iostream>
#include "Data.h"

class CommandInput
{
 public:
  CommandInput();
  ~CommandInput();
  
  int	          findCmd(char key);
  bool	        execCmd(const int, t_packet *);
  bool	        test(t_packet *);  
  bool	        getKb(t_packet *);
  bool	        getMouse(t_packet *);
  bool	        ping(t_packet *);
  

  char	        keys[10];
  typedef bool  (CommandInput::* funcPtr)(t_packet *);
  funcPtr       array[10];
};
#endif /* COMMANDINPUT_H_ */
