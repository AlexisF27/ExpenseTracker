#include <iostream>
#include <string>
#include "ExpenseTracker/ExpenseTracker.h"
using namespace std;


int main(int argc, char* argv[]) {

  if (argc < 2) {
        cerr << "Error: No command provided. Available commands are: add, list, summary, delete, mark-done, list." << std::endl;
        return 1;
  }

  string command = argv[1];

  if (argc == 3) {
    string optionCommand = argv[2];
    if (command == "delete")
    {

    }else if (command == "summary"){

    }else{
      cerr << "Error: No command provided. Available commands with 3 arguments are: delete, summary." << std::endl;
    }
    
  }else if (argc == 5){
    string description = argv[3];
    string amount = argv[5];


  }else {
    if (command == "list")
    {
      /* code */
    }else if (command == "summary") {

    } else {
      cerr << "Error: No command provided. Available commands are: list, summary." << std::endl;
    }
  }
  
  



  return 0;
}