//importing all the .hpp files 
#ifndef STATS_HPP
#include "stats.hpp"
#endif
#ifndef FUNCTIONS_HPP
#include "functions.hpp"
#endif
#ifndef MEMINFO_HPP
#include "meminfo.hpp"
#endif
#ifndef UPTIME_HPP
#include "uptime.hpp"
#endif

int main () {
  //this while loop will run forever meaning the screen will keep printing data, waiting for 0.5seconds and then the screen will be cleared 
  while(true){
    clearScreen();
    line();
    displayStatTitle();
    line();
    displayCPU();
    line();
    displyOtherStats();
    line();
    display_memory();
    line();
    display_uptime();
    line();
    delayer();
    clearScreen();
  }
  return 0;
}
