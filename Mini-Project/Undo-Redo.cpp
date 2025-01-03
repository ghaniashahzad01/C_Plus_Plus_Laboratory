#include<iostream>
#include<stack>
#include <string>
using namespace std;

class ToDoList {
    stack<string> undoStack;  // For undoing tasks
    stack<string> redoStack;  // For redoing tasks

public:
    // Function to add a task
    void addTask(const string& task) {
        undoStack.push(task);
        // Clear the redo stack when a new task is added
        while (!redoStack.empty()) {
            redoStack.pop();
        }
        cout << "Task added: " << task << endl;
    }

    // Function to undo
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }
        string lastTask = undoStack.top();
        undoStack.pop();
        redoStack.push(lastTask);  // Add the undone task to the redo stack
        cout << "Undo performed: Removed task -> " << lastTask << endl;
    }

    // Function to redo
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }
        string task = redoStack.top();
        redoStack.pop();
        undoStack.push(task);  // Add the redone task back to the undo stack
        cout << "Redo performed: Added task -> " << task << endl;
    }

    // Function to show all tasks
    void showTasks() {
        stack<string> tempStack = undoStack;  // Temporarily copy the undo stack
        cout << "Current To-Do List:" << endl;
        if (tempStack.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        while (!tempStack.empty()) {
            cout << "- " << tempStack.top() << endl;
            tempStack.pop();
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task\n2. Undo\n3. Redo\n4. Show Tasks\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                todo.addTask(task);
                break;
            case 2:
                todo.undo();
                break;
            case 3:
                todo.redo();
                break;
            case 4:
                todo.showTasks();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
