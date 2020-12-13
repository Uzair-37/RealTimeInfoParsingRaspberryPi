#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>


using namespace std;

//my local fucntion for calculating seconds 
int calculateSecond(int totalTime){
  int seconds= (int)totalTime % 60;
  return seconds;
}

//my local function for calculating minutes 
int calculateMinute(int totalTime){
  int minutes=((int) totalTime % 3600)/60;
  return minutes;
}

//my local function for calculating hours 
int calculateHour(int totalTime){
  int hours= ((int)totalTime % 216000)/3600;
  return hours;
}

//the function is used to calculate the total up time as well as idle time in hours, minutes and seconds
void display_uptime(){
  ifstream file("/proc/uptime");
  string line;
  if(!file.good()){
  cerr << "Could not open file.... exitting..." << endl;
  exit(EXIT_FAILURE);
  }
  while(getline(file, line)){
    stringstream linestream(line);
    double uptime_total;
    double uptime_idle;
    linestream >> uptime_total>> uptime_idle;
    uptime_idle=uptime_idle/4;
    cout << "SYSTEM"<<endl;
    cout << "              UP for "   << calculateHour((int)uptime_total)   <<  " hours "<< calculateMinute((int)uptime_total)<<" minutes and "<<calculateSecond((int)uptime_total)<<" seconds"<<endl;
    cout << "            IDLE for "   << calculateHour((int)uptime_idle)   <<   " hours "<< calculateMinute((int)uptime_idle)<<" minutes and "<<calculateSecond((int)uptime_idle)<<" seconds"<<endl;
    cout << "------------------------------------------------------------------------------\n";
    int uptime_active= uptime_total-uptime_idle;
    //these 3 lines are responsible displaying information about the energy used during active and idle state in MJoules
    cout << "ENERGY"<<endl;
    cout << "                 IN ACTIVE STATE: " <<((uptime_active*120)/1000000)<<" MJoules"<<endl;
    cout << "                   IN IDLE STATE: " <<((uptime_idle*70)/1000000) <<" MJoules"<<endl;   
  }
}