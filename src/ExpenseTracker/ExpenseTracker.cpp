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