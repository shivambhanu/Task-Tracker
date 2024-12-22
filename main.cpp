#include <iostream>


void showUsage()
{
    std::cout << "Usage:\n"
              << "\t task-cli add <description>\n"
              << "\t task-cli update <task-number> <description>\n"
              << "\t task-cli delete <task-number>\n"
              << "\t task-cli mark-in-progress <task-number>\n"
              << "\t task-cli mark-done <task-number>\n"
              << "\t task-cli list\n"
              << "\t task-cli list done\n"
              << "\t task-cli list todo\n"
              << "\t task-cli list in-progress\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        std::cout << "Error: Command not provided!\n";
        showUsage();
        return 1;
    }

    std::string command = argv[1];
    if (command == "add")
    {
        if (argc < 3)
        {
            std::cout << "Error: Description not provided for add command!\n";
            return 1;
        }
        std::string description = argv[2];
        std::cout << "Adding task: " << description << std::endl;
    } else if (command == "update")
    {
        if (argc < 4)
        {
            std::cout << "Error: Description not provided for update command!\n";
            return 1;
        }
    }


    return 0;
}