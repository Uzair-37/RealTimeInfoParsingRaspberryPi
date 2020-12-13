#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
/* To enable the usage of uSleep() */
#include <ctime>
#include <unistd.h>

//these functions are common functions that will be utilised multiple times in main.cpp
void clearScreen(){
  std::cout << "\033[2J\033[1;1H";
}

//this function is responsible for making the project sleep for 0.5 seconds 
void delayer(){
  usleep(500000);
}

//this function is responsible for creating lines 
void line(){
  std::cout << "------------------------------------------------------------------------------\n";
}
#endif