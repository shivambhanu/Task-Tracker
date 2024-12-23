#include <iostream>
#include "Task.h"
#include <fstream>
using namespace std;


int global_task_id = 0;
vector<Task> tasks;

void showUsage()
{
    cout << "Usage:\n"
              << "\t task-cli add <description>\n"
              << "\t task-cli update <task-id> <description>\n"
              << "\t task-cli delete <task-id>\n"
              << "\t task-cli mark-in-progress <task-id>\n"
              << "\t task-cli mark-done <task-id>\n"
              << "\t task-cli list\n"
              << "\t task-cli list done\n"
              << "\t task-cli list todo\n"
              << "\t task-cli list in-progress\n";
}

void get_tasks_file()
{
    string filename = "tasks.txt";

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open())
    {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    for (Task task : tasks)
    {
        outfile << task.get_description() << endl;
    }

    outfile.close();
}

int main(const int argc, char* argv[]) {
    // argv[0] = ./Task_Tracker
    // argv[1] = task-cli

    if (argc < 3)
    {
        cout << "Error: Command not provided!\n";
        showUsage();
        return 1;
    }

    string command = argv[2];
    if (command == "add")
    {
        if (argc < 4)
        {
            cout << "Error: Description not provided for add command!\n";
            return 1;
        }
        string description = argv[3];
        int task_id = global_task_id++;

        auto now = chrono::system_clock::now();
        string curr_time = format("{:%Y-%m-%d %H:%M:%S}", now);

        Task new_task(task_id, description, "todo", curr_time, curr_time);
        cout << "Task added successfully (ID: " << task_id << ")" << endl;

        new_task.display_task();
        tasks.push_back(new_task);

        get_tasks_file();
    }






    // else if (command == "update")
    // {
    //     if (argc < 5)
    //     {
    //         cout << "Error: task-id OR Description is not provided for update command!\n";
    //         return 1;
    //     }
    //     string task_id = argv[3];
    //     string description = argv[4];
    //
    //     cout << "Updating task: " << task_id << " by: " << description << endl;
    // } else if (command == "delete")
    // {
    //     if (argc < 4)
    //     {
    //         cout << "Error: task-id is not provided for delete command!\n";
    //         return 1;
    //     }
    //     string task_id = argv[3];
    //     cout << "Deleting task: " << task_id << endl;
    //     //TODO: fetch the task description and print it also
    // } else if (command == "mark-in-progress")
    // {
    //     if (argc < 4)
    //     {
    //         cout << "Error: task-id is not provided for mark-in-progress command!\n";
    //         return 1;
    //     }
    //     string task_id = argv[3];
    //     cout << "Marking task: " << task_id  << " in progress."<< endl;
    // } else if (command == "mark-done")
    // {
    //     if (argc < 4)
    //     {
    //         cout << "Error: task-id is not provided for mark-done command!\n";
    //         return 1;
    //     }
    //     string task_id = argv[3];
    //     cout << "Marking task: " << task_id << "as done!" << endl;
    // } else if (command == "list")
    // {
    //     if (argc < 4)
    //     {
    //         cout << "Listing all tasks:" << endl;
    //     } else
    //     {
    //         string list_command = argv[3];
    //
    //         if (list_command == "done")
    //         {
    //             cout << "Listing all DONE tasks" << endl;
    //         } else if (list_command == "todo")
    //         {
    //             cout << "Listing all pending tasks" << endl;
    //         } else if (list_command == "in-progress")
    //         {
    //             cout << "Listing tasks that are in progress" << endl;
    //         } else
    //         {
    //             cout << "Error: Command not valid -- here!\n";
    //             showUsage();
    //             return 1;
    //         }
    //     }
    // } else
    // {
    //     cout << "Error: Command not valid!\n";
    //     showUsage();
    //     return 1;
    // }

    return 0;
}