#include <iostream>
#include <string>
#include "ExpenseTracker/ExpenseTracker.h"
using namespace std;


int main(int argc, char* argv[]) {
  ExpenseTracker expenseTracker("tasks.json");

  if (argc < 2) {
        cerr << "Error: No command provided. Available commands are: add, list, summary, delete, mark-done, list." << std::endl;
        return 1;
  }

  string command = argv[1];

  if (argc == 4) {
    string optionCommand = argv[3];
    if (command == "delete")
    {
      expenseTracker.deleteTask(atoi(optionCommand.c_str()));
    }else if (command == "summary"){
      expenseTracker.summary(atoi(optionCommand.c_str()));
    }else{
      cerr << "Error: No command provided. Available commands with 3 arguments are: delete, summary." << std::endl;
    }
    
  }else if (argc == 6){
    string description = argv[3];
    string amount = argv[5];

    if (command == "add")
    {
      expenseTracker.addTask(description, atoi(amount.c_str()));
    }


  }else {
    if (command == "list")
    {
      expenseTracker.list();
    }else if (command == "summary") {
      expenseTracker.summary();

    } else {
      cerr << "Error: No command provided. Available commands are: list, summary." << std::endl;
    }
  }
  
  



  return 0;
}