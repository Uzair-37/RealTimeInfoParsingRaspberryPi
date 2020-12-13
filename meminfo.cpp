#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

//this function is used to display memory information 
void display_memory(){
  cout <<"MEMORY             "<<endl;
  ifstream file("/proc/meminfo", std::ifstream::in);
  string line;

  if(!file.good()){
    cerr << "Could not open file.... exitting..." << endl;
    exit(EXIT_FAILURE);
  }
  string requiredData[4]={"MemTotal:","MemFree:","Cached:","Buffers:"};
  while(getline(file, line)){
    stringstream linestream(line);
    string token;
    long long unsigned int data;
  //this string array stores all the strings that we want to search for when looking for specific information about memory 
    
    getline(linestream, token, ' ');
    for( int i=0;i<sizeof(requiredData)/sizeof(requiredData[0]);i++){
      //when the specific memory information is found, the data on that line is printed out 
      if(token == requiredData[i]){
        linestream >> data; 
        cout<<"                        "<< *(requiredData+i) << (data/1000) <<"MB"<<endl;
        requiredData[i].erase();
      }  
    }
  }

  for( int i=0;i<sizeof(requiredData)/sizeof(requiredData[0]);i++){
      //when the specific memory information is found, the data on that line is printed out 
      if(requiredData[i]!=""){
        cout<<"                        "<< *(requiredData+i) << "NOT FOUND"<<endl;
      }  
    }
  file.close();
}