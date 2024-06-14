#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks, int index);
void removeTask(vector<Task> &tasks, int index);

int main() {
    vector<Task> tasks; // Initialize vector to store tasks
    int choice;

    cout << "Welcome to the To-Do List Manager!\n";

    // Main menu loop
    do {
        // Display menu options
        cout << "\nMain Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore any newline characters in the input buffer
                getline(cin, description); // Read the entire line including spaces
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a task to the list
void addTask(vector<Task> &tasks, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view all tasks in the list
void viewTasks(const vector<Task> &tasks) {
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task index!\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task> &tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task index!\n";
    }
}
