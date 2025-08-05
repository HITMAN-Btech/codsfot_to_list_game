#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }

    cout << "\n To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "✔" : " ") << "] "
             << tasks[i].description << "\n";
    }
}

void markCompleted() {
    int index;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << " Invalid task number.\n";
    }
}

void deleteTask() {
    int index;
    viewTasks();
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    } else {
        cout << " Invalid task number.\n";
    }
}

void showMenu() {
    cout << "\n======= TO-DO LIST MANAGER =======\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout <<  "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
