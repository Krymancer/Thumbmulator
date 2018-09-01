using namespace std;

#include <iostream>
#include <stdlib.h>
#include "main.h"

int main(const int argc,const char *argv[]){
  if(argc!=2){
    cout << "Usage:thumblator <source file> \n";
    return(-20);
  }

  cout << argc<< "\n";
  for(int count=0;count<argc;count++){
    cout << argv[count] << "\n";
  }
  return(0);
}
