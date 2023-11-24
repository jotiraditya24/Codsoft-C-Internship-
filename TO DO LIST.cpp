#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool isComplete;

    Task(const std::string& desc) : description(desc), isComplete(false) {}
};

void addTask(std::vector<Task>& taskList, const std::string& taskDescription) {
    Task newTask(taskDescription);
    taskList.push_back(newTask);
    std::cout << "Task added: " << taskDescription << std::endl;
}

void displayTasks(const std::vector<Task>& taskList) {
    std::cout << "To-Do List:\n";
    for (std::vector<Task>::const_iterator it = taskList.begin(); it != taskList.end(); ++it) {
        const Task& task = *it;
        std::cout << "- " << task.description;
        if (task.isComplete) {
            std::cout << " [Completed]";
        }
        std::cout << std::endl;
    }
}

void markTaskAsComplete(std::vector<Task>& taskList, const std::string& taskDescription) {
    for (std::vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->description == taskDescription) {
            it->isComplete = true;
            std::cout << "Task marked as complete: " << taskDescription << std::endl;
            return;  // Stop searching once task is found and marked
        }
    }
    std::cout << "Task not found: " << taskDescription << std::endl;
}

void removeTask(std::vector<Task>& taskList, const std::string& taskDescription) {
    for (std::vector<Task>::iterator it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->description == taskDescription) {
            taskList.erase(it);
            std::cout << "Task removed: " << taskDescription << std::endl;
            return;  // Stop searching once task is found and removed
        }
    }
    std::cout << "Task not found: " << taskDescription << std::endl;
}

int main() {
    std::vector<Task> taskList;

    char choice;
    do {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Mark Task as Complete\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                addTask(taskList, taskDescription);
                break;
            }
            case '2':
                displayTasks(taskList);
                break;
            case '3': {
                std::string taskDescription;
                std::cout << "Enter task description to mark as complete: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                markTaskAsComplete(taskList, taskDescription);
                break;
            }
            case '4': {
                std::string taskDescription;
                std::cout << "Enter task description to remove: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                removeTask(taskList, taskDescription);
                break;
            }
            case '5':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '5');

    return 0;
}


