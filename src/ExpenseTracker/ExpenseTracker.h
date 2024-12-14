#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <vector>
#include <string>

using namespace std;

struct Task
{
  int id;
  string description;
  int amount;
  string createdAt;
  string jsonFilePath;
};

class ExpenseTracker
{
public:
  ExpenseTracker(const string& filePath = "tasks.json" );
  ~ExpenseTracker();
  void addTask(const string& description, const int amount);
  void list();
  void summary();
  void summary(const int month);
  void deleteTask(int taskId);


private:
  vector<Task> tasks;
  int nextId;
  string getCurrentTimestamp() const;
  void loadTasks(const string& filePath);
  void saveTasks(const string& filePath);

};

#endif