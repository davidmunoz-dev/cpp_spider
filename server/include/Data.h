/*
** Data.h for  in /home/beche/rendu/cpp_spider/server/serial
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Wed Oct  4 19:50:50 2017 beche
** Last update Mon Nov  6 18:01:03 2017 Lezard
*/

#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/asio/write.hpp>
#include <boost/bind.hpp>
#include <list>

typedef struct  t_packet
{
  char		      opcode;
  unsigned int	timestamp;
  char	        key_code;
  int		        status;
  int		        x;
  int		        y;
  char          k[30];
  char          name[50];
}		            t_packet;

#endif 
