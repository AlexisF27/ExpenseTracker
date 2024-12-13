#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <vector>
#include <string>

using namespace std;

struct Task
{
  int id;
  string description;
  string amount;
  string createdAt;
  string jsonFilePath;
};

class ExpenseTracker
{
public:
  ExpenseTracker();
  ~ExpenseTracker();

private:
  vector<Task> tasks;
  int nextId;
  string getCurrentTimestamp() const;
  void loadTasks(const std::string& filePath);
  void saveTasks(const std::string& filePath);

};

#endif