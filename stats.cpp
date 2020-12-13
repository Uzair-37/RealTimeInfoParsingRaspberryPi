#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip> 
using namespace std;

//this function is responsible for counting the number of CPUs in the system and printing the int out 
void displayStatTitle(){
  ifstream file("/proc/stat", std::ifstream::in);
  string line;
  if(!file.good()){
    cerr << "Could not open file.... exitting..." << endl;
    exit(EXIT_FAILURE);
  }
  
  int number=-1;  //this variable is used to change the string cpu to cpu0, cpu1,cpu2 etc 
  int count=0;   //this variable is used to count the total number of CPUs found 
  while(getline(file, line)){
    string cpuName="cpu"+to_string(number);
    stringstream linestream(line);
    string token;
    getline(linestream, token, ' ');
    if(token==cpuName){
      count++;
    }
    number++;
  }
  cout<<"CPU Cores: "<<count<<endl;                              
}

//this function is responsible for displaying CPU data in percentages 
void displayCPU(){
  cout<<"CPU       User         Nice        System       Idle"<<endl;
  ifstream file("/proc/stat", std::ifstream::in);
  string line;
  if(!file.good()){
    cerr << "Could not open file.... exitting..." << endl;
    exit(EXIT_FAILURE);
  }
  int number=-1;  //this variable is used again to print out data for every single CPU in any given system 
  while(getline(file, line)){
    string cpuName="cpu"+to_string(number);
    stringstream linestream(line);
    string token;
    double user_cycles,nice_cycles,system_cycles,idle_cycles;
    getline(linestream, token, ' ');
    if(token==cpuName){
      linestream >> user_cycles >> nice_cycles >> system_cycles >> idle_cycles;
      double total=(100/(user_cycles+nice_cycles+system_cycles+idle_cycles));
      cout<<fixed<< setprecision(1)<<cpuName<<"      " << user_cycles*total << "%        " << nice_cycles*total << "%        " << system_cycles*total << "%        " << idle_cycles*total << "%        "<< endl;
    }
    number++;
  }
}


void displyOtherStats(){
  ifstream file("/proc/stat", std::ifstream::in);
  string line;
  if(!file.good()){
    cerr << "Could not open file.... exitting..." << endl;
    exit(EXIT_FAILURE);
  }

  //this 2D array consists of the data we are looking for in the stats of the system and its name
  string requiredData[2][4]={{"Page","Swap","Interrupts Serviced","Context Switch Counts"} , {"page","swap","intr","ctxt"}};
  while(getline(file, line)){
    stringstream linestream(line);
    string token;
    double data;
    getline(linestream, token, ' ');
    for( int i=0;i<4;i++){

      //if the data is found, its printed out and the data is removed from the 2D array 
      if(token == requiredData[1][i]){
        linestream >> data; 
        cout<<fixed<<setprecision(2)<<"                  "<< requiredData[0][i]<<": "<< (data/1000000000) <<" Billion(s)"<<endl;
        requiredData[1][i].erase();
        requiredData[0][i].erase();
      }
    } 
  }
  //if the 2D array has any remaining information, that means data for that information was not found and the following code runs
  for( int i=0;i<4;i++){
    if(requiredData[1][i] !=""){
    cout<<"                        "<< requiredData[0][i] << ": " <<"NOT FOUND"<<endl;
    }
  } 
  file.close();
}
