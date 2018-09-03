using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "main.h"

struct{
  uint r0=0;
  uint r1=0;
  uint r2=0;
  uint r3=0;
  uint r4=0;
  uint r5=0;
  uint r6=0;
  uint r7=0;
  uint *r13 = &sp;
  uint *r14 = &lr;
  uint *r15 = &pc;

  uint sp;
  uint lr;
  uint pc;
  uint cpsr;
}registers;

void printRegisters(){
  cout << "r0 => ";
  printRegister(&registers.r0);
  cout <<"r1 => ";
  printRegister(&registers.r1);
  cout <<"r2 => ";
  printRegister(&registers.r2);
  cout <<"r3 => ";
  printRegister(&registers.r3);
  cout <<"r4 => ";
  printRegister(&registers.r4);
  cout << "r5 => ";
  printRegister(&registers.r5);
  cout << "r6 => ";
  printRegister(&registers.r6);
  cout <<"r7 => ";
  printRegister(&registers.r7);

  cout <<"sp => ";
  printRegister(&registers.sp);
  cout <<"lr => ";
  printRegister(&registers.lr);
  cout <<"cpsr => ";
  printRegister(&registers.cpsr);

}


int main(const int argc,const char *argv[]){
  if(argc!=2){
    cout << "Usage:thumblator <source file> \n";
    return(-20);
  }

  ifstream input;
  input.open(argv[1]);
  string line;

  if(!input){
    std::cerr << "Unable to open file" << std::endl;
  }else{
    while(getline(input,line)){
      cout << line << "\n";

    }
  }
  cout << endl;

  MOV(&registers.r0,1000);
  //MOV(&registers.r1,&registers.r0);
  ADD(&registers.r0,&registers.r0,&registers.r0);
  STR(0x1,&registers.r0);
  LDR(&registers.r1,0x1);
  LDRB(&registers.r2,0x1);
  XOR(&registers.r0,&registers.r0);

  printRegisters();
  input.close();
  return(0);
}
