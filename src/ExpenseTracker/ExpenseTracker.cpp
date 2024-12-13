#include "ExpenseTracker.h"
#include <ctime> // For timestamp generation
#include <iostream>
#include <algorithm>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

ExpenseTracker::ExpenseTracker(const string& filename) {
  loadTasks(filename);
}

ExpenseTracker::~ExpenseTracker() {
  saveTasks("tasks.json");
}

std::string ExpenseTracker::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}


void ExpenseTracker::loadTasks(const std::string& filePath) {
    std::ifstream file(filePath);
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
        std::ofstream newFile(filePath);
        newFile << "[]"; 
        newFile.close();
    }
}

void ExpenseTracker::saveTasks(const std::string& filePath) {
    nlohmann::json jsonData;

    for (const auto& task : tasks) {
        jsonData.push_back({
            {"id", task.id},
            {"description", task.description},
            {"amount", task.amount},
            {"createdAt", task.createdAt},
        });
    }

    std::ofstream file(filePath);
    file << jsonData.dump(4);  
    file.close();
}