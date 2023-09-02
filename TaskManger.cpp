#include <iostream>
#include <vector>

using namespace std;

struct task // struct to store the task
{
    string disc;
    int id;
};

void addTask(vector<task> &tasks, int &counter, int &id);    // function to add a task prototype
void viewTask(vector<task> &tasks);                          // function to view the tasks prototype
void RemoveTask(vector<task> &tasks, int &counter, int &id); // function to remove a task   prototype
void printMainMenu();                                        // function to print the main menu prototype

int main()
{
    vector<task> tasks; // vector to store tasks

    cout << "Welcome to the Task Manager!" << endl;

    int id = 1;        // to store the id of the task
    int counter = 0;   // to store the number of tasks
    bool check = true; // to check weather the user wants to exit or not
    while (check)
    {
        int choice = 0; // to store the choice of the user
        printMainMenu(); // call the function to print the main menu
        cin >> choice;

        cout << endl;
        switch (choice)
        {
        case 1:

            addTask(tasks, counter, id); // call the function to add a task
            break;
        case 2:

            viewTask(tasks); // call the function to view the tasks
            break;
        case 3:
            RemoveTask(tasks, counter, id); // call the function to remove a task
            break;
        case 4:
            cout << "Exit Minions Task Manger. Have a great day!\n"
                 << endl;
            check = false; // exit the program
            break;
        default:
            cout << "Invalid choice\n"
                 << endl;

            break;
        }
    }
    return 0;
}




void printMainMenu() // function to print the main menu
{
    cout << "1. Add a Task" << endl;
    cout << "2. View All Tasks" << endl;
    cout << "3. Remove a Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}


void addTask(vector<task> &tasks, int &counter, int &id) // pass the vector, counter and id by reference and not by value
{
    tasks.push_back(task()); // add a task to the vector
    cout << "Add a Task" << endl;
    tasks[counter].id = id;
    cout << "Enter the task description: "; // get the task description from the user
    getline(cin >> ws, tasks[counter].disc);
    cout << "Task added successfully\n"
         << endl; // display the success message
    counter++;    // increment the counter
    id++;         // increment the id
}

void viewTask(vector<task> &tasks) // pass the vector by reference and not by value to display the tasks
{
    if (tasks.size() == 0) // check if there are any tasks to display
    {
        cout << "No tasks to display" << endl;
        return;
    }
    else
    {
        cout << "----------------------------------------------------------------------------------------------------" << endl;
        cout << "                                  Current Tasks" << endl; // display the tasks
        for (size_t i = 0; i < tasks.size(); i++)                          // loop to display the tasks
        {

            cout << "        Task ID: " + to_string(tasks[i].id) << endl; // display the id of the task
            cout << "        Task Description: " + tasks[i].disc << endl;
            cout << "\n\n";
        }
        cout << "                                                                      Total Tasks: " + to_string(tasks.size()) << endl;
        cout << "----------------------------------------------------------------------------------------------------\n"
             << endl;
    }
}

void RemoveTask(vector<task> &tasks, int &counter, int &id) // pass the vector by reference and not by value to remove the tasks
{

    if (tasks.size() == 0) // check if there are any tasks to remove
    {
        cout << "No tasks to remove\n"
             << endl;
    }
    else
    {
        cout << "Enter task ID to remove: " << endl;
        int RemoveID; // to store the id of the task to be removed
        cin >> RemoveID;
        bool check = false; // to check if the task is found or not if false then it means the task is not found
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].id == RemoveID) // check if the id of the task matches the id of the task to be removed
            {
                tasks.erase(tasks.begin() + i); // remove the task
                check = true;                   // set the check to true
            }
        }
        if (check == false) // check if the task is not found
        {
            cout << "Task not found" << endl;
        }
        else
        {
            counter--; // decrement the counter
            cout << "Task removed successfully\n"
                 << endl;
        }
    }
}