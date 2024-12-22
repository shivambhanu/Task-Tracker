#include <iostream>

void showUsage()
{
    std::cout << "Usage:\n"
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

int main(const int argc, char* argv[]) {
    // argv[0] = ./Task_Tracker
    // argv[1] = task-cli

    if (argc < 3)
    {
        std::cout << "Error: Command not provided!\n";
        showUsage();
        return 1;
    }

    std::string command = argv[2];
    if (command == "add")
    {
        if (argc < 4)
        {
            std::cout << "Error: Description not provided for add command!\n";
            return 1;
        }
        std::string description = argv[3];
        std::cout << "Adding task: " << description << std::endl;
    } else if (command == "update")
    {
        if (argc < 5)
        {
            std::cout << "Error: task-id OR Description is not provided for update command!\n";
            return 1;
        }
        std::string task_id = argv[3];
        std::string description = argv[4];

        std::cout << "Updating task: " << task_id << " by: " << description << std::endl;
    } else if (command == "delete")
    {
        if (argc < 4)
        {
            std::cout << "Error: task-id is not provided for delete command!\n";
            return 1;
        }
        std::string task_id = argv[3];
        std::cout << "Deleting task: " << task_id << std::endl;
        //TODO: fetch the task description and print it also
    } else if (command == "mark-in-progress")
    {
        if (argc < 4)
        {
            std::cout << "Error: task-id is not provided for mark-in-progress command!\n";
            return 1;
        }
        std::string task_id = argv[3];
        std::cout << "Marking task: " << task_id  << " in progress."<< std::endl;
    } else if (command == "mark-done")
    {
        if (argc < 4)
        {
            std::cout << "Error: task-id is not provided for mark-done command!\n";
            return 1;
        }
        std::string task_id = argv[3];
        std::cout << "Marking task: " << task_id << "as done!" << std::endl;
    } else if (command == "list")
    {
        if (argc < 4)
        {
            std::cout << "Listing all tasks:" << std::endl;
        } else
        {
            std::string list_command = argv[3];

            if (list_command == "done")
            {
                std::cout << "Listing all DONE tasks" << std::endl;
            } else if (list_command == "todo")
            {
                std::cout << "Listing all pending tasks" << std::endl;
            } else if (list_command == "in-progress")
            {
                std::cout << "Listing tasks that are in progress" << std::endl;
            } else
            {
                std::cout << "Error: Command not valid -- here!\n";
                showUsage();
                return 1;
            }
        }
    } else
    {
        std::cout << "Error: Command not valid!\n";
        showUsage();
        return 1;
    }

    return 0;
}