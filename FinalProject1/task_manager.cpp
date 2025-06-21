#include "task_manager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Task {
    string description;
    bool done;
};

void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Set a description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
}

void markTask(vector<Task>& tasks) {
    int index;
    cout << "Set a task to be marked as done: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].done = true;
    } else {
        cout << "wrong number.\n";
    }
}

void deleteTask(vector<Task>& tasks) {
    int index;
    cout << "Set a task to be deleted: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "wrong number.\n";
    }
}

void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].done ? "X" : " ") << "] " << tasks[i].description << "\n";
    }
}

void exportTasks(const vector<Task>& tasks, const string& filename) {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.done << ";" << task.description << "\n";
    }
    file.close();
    cout << "Tasks saved to file.\n";
}

void importTasks(vector<Task>& tasks, const string& filename) {
    ifstream file(filename);
    if (!file) {
        ofstream create(filename);
        create.close();
        cout << "Created a new file: " << filename << "\n";
        return;
    }

    tasks.clear();
    string line;
    while (getline(file, line)) {
        size_t sep = line.find(';');
        if (sep != string::npos) {
            bool done = line[0] == '1';
            string desc = line.substr(sep + 1);
            tasks.push_back({desc, done});
        }
    }
    file.close();
    cout << "Tasks imported from file.\n";
}

void taskManager() {
    vector<Task> tasks;
    int option;
    do {
        cout << "\n--- Task manager ---\n";
        cout << "1. Add Task\n2. Set as done\n3. Delete Task\n4. Show Tasks\n";
        cout << "5. Export to file\n6. Import from file\n0. Back\nChoose: ";
        cin >> option;
        switch (option) {
            case 1: addTask(tasks); break;
            case 2: markTask(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: showTasks(tasks); break;
            case 5: exportTasks(tasks, "tasks.txt"); break;
            case 6: importTasks(tasks, "tasks.txt"); break;
        }
    } while (option != 0);
}