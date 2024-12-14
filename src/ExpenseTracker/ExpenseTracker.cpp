#include "ExpenseTracker.h"
#include <ctime> // For timestamp generation
#include <iostream>
#include <algorithm>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

ExpenseTracker::ExpenseTracker(const string& filename) : nextId(1) {
  loadTasks(filename);
}

ExpenseTracker::~ExpenseTracker() {
  saveTasks("tasks.json");
}

string ExpenseTracker::getCurrentTimestamp() const {
    time_t now = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}


void ExpenseTracker::loadTasks(const string& filePath) {
    ifstream file(filePath);
    if (file.is_open()) {
        nlohmann::json jsonData;
        file >> jsonData;
        file.close();

        for (const auto& taskData : jsonData) {
            Task task;
            task.id = taskData["id"];
            task.description = taskData["description"];
            task.amount = taskData["amount"];
            task.createdAt = taskData["createdAt"];
            tasks.push_back(task);

            if (task.id >= nextId) {
                nextId = task.id + 1;
            }
        }
    } else {
        ofstream newFile(filePath);
        newFile << "[]"; 
        newFile.close();
    }
}

void ExpenseTracker::saveTasks(const string& filePath) {
    nlohmann::json jsonData;

    for (const auto& task : tasks) {
        jsonData.push_back({
            {"id", task.id},
            {"description", task.description},
            {"amount", task.amount},
            {"createdAt", task.createdAt},
        });
    }

    ofstream file(filePath);
    file << jsonData.dump(4);  
    file.close();
}

void ExpenseTracker::addTask(const string& description, int amount) {
    Task task;
    task.id = nextId++;
    task.description = description;
    task.amount = amount;
    task.createdAt = getCurrentTimestamp();
    tasks.push_back(task);
    cout << "Task added successfully." << endl;
}
void ExpenseTracker::list() {
    // Print the header row
    cout << setw(5) << "#"
         << setw(12) << "Date"
         << setw(15) << "Description"
         << setw(8) << "Amount" 
         << endl;

    // Print a horizontal separator
    cout << string(40, '-') << endl;

    // Print each task in a formatted row
    for (const auto& task : tasks) {
        cout << setw(5) << task.id
             << setw(12) << task.createdAt.substr(0, 10) // Extract just the date (YYYY-MM-DD)
             << setw(15) << task.description
             << "$" << task.amount // Add a dollar sign for the amount
             << endl;
    }
}

void ExpenseTracker::summary() {
    int totalAmount = 0;
    for (const auto& task : tasks) {
        totalAmount += task.amount;
    }
    cout << "Total amount: $" << totalAmount << endl;
}

void ExpenseTracker::summary(const int month) {
    int totalAmount = 0;
    for (const auto& task : tasks) {
        if (task.createdAt.substr(5, 2) == to_string(month)) {
            totalAmount += task.amount;
        }
    }
    cout << "Total amount for month " << month << ": $" << totalAmount << endl;
}

void ExpenseTracker::deleteTask(int taskId) {
    auto it = find_if(tasks.begin(), tasks.end(), [taskId](const Task& task) { return task.id == taskId; });
    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task deleted successfully." << endl;
    } else {
        cout << "Task not found." << endl;
    }
}

