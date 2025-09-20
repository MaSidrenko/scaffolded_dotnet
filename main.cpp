#include <iostream>
#include <filesystem>
#include <windows.h>
#include <locale>
#include <string>
#include <vector>

std::string InsertRazorView(std::string command, std::string toFind, std::string toInsert, std::string model, std::string DbContext, size_t offset = 6);
std::string InsertRazorPage(std::string command, std::string PageName, std::string action, std::string model, std::string DbContext);
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string allCli[5] =
        {
            "",
            "",
            "",
            "",
            ""};
    std::string temp;
    std::string final_command;
    std::string AreaName;
    std::string ControllerName;
    std::string Model;
    std::string DbContext;
    std::string View;
    std::string ComponentName;
    std::string PageName;
    std::string outDir;
    std::string chosee_action;
    size_t pos;
    std::filesystem::path l_dir = std::filesystem::current_path();

    std::cout << "currnet_dir: " << l_dir << std::endl;
    int choseeCLI;
    std::vector<std::pair<std::string, std::string>> cli_command = {
        {"1. MVC Area", "dotnet aspnet-codegenerator area "},
        {"2. MVC Controller - Empty", "dotnet aspnet-codegenerator controller -name " + ControllerName},
        {"3. MVC Controller with read/write actions", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -action -m " + Model},
        {"4. MVC Controller with views using EF", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -m " + Model + " -dc " + DbContext + " --relativeFolderPath Controllers --useDefaultLayout"},
        {"5. API Controller - Empty", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -api"},
        {"6. API Controeller with read/write actions", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -api -action -m " + Model},
        {"7. API Controller with actions, using EF", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -api -m " + Model + " -dc " + DbContext},
        {"8. API with read/write endpoints", "dotnet asp-codegenerator controller -name " + ControllerName + " -api -actions"},
        {"9. API with read/write endpoints, using EF", "dotnet aspnet-codegenerator controller -name " + ControllerName + " -api -m " + Model + " -dc " + DbContext},
        {"10. Razor View - Empty", "dotnet aspnet-codegenerator view " + View + " Empty"},
        {"11. Razor View (expml: Create/Edit/Delete/details)", "dotnet aspnet-codegenerator view " + chosee_action + " " + chosee_action + " -m " + Model + " -dc " + DbContext},
        {"12. Razor Component (Blazor)", "dotnet new razorcomponent -n " + ComponentName},
        {"13. Razor Page - Empty", "dotnet aspnet-codegenerator razor " + PageName + " -outDir " + outDir},
        {"14. Razor Page with read/write", "dotnet aspnet-codegenerator razorpage -m " + Model + " -dc " + DbContext + " -udl -outDir Pages\\" + Model},
        {"15. Razor Page (CRUD)", "dotnet aspnet-codegenerator razor " + PageName + " " + chosee_action + " -m " + Model + " -dc " + DbContext + " -outDir Pages\\" + Model},
        {"16. Identity (Add Identity)", "dotnet aspnet-codegenerator identity -dc " + DbContext}};
    for (size_t i = 0; i < cli_command.size(); ++i)
    {
        std::cout << cli_command[i].first << std::endl;
    }
    std::cout << "Chosee CLI-command: \n";
    std::cin >> choseeCLI;

    switch (choseeCLI)
    {
    case 1:
    {
        std::cout << "You choose: " << cli_command[0].first << std::endl;
        std::cout << "Input area name: \n";
        std::cin >> AreaName;

        final_command = cli_command[0].second + AreaName;

        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 2:
    {
        std::cout << "You choose: " << cli_command[1].first << std::endl;
        std::cout << "Input Controller name: \n";
        std::cin >> ControllerName;
        final_command = cli_command[1].second + ControllerName;
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 3:
    {
        std::cout << "You choose: " << cli_command[2].first << std::endl;
        std::cout << "Input Cotroller name: \n";
        std::cin >> ControllerName;
        std::cout << "\nInput your Model: \n";
        std::cin >> Model;

        final_command = cli_command[2].second;
        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        pos = final_command.find(" -m ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 4, Model);
        }
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 4:
    {
        std::cout << "You choose: " << cli_command[3].first << std::endl;
        std::cout << "Input ContorllerName: \n";
        std::cin >> ControllerName;
        std::cout << "\nInput your Model: \n";
        std::cin >> Model;
        std::cout << "Input your DbContext: \n";
        std::cin >> DbContext;

        final_command = cli_command[3].second;

        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        pos = final_command.find(" -m ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 4, Model);
        }
        pos = final_command.find(" -dc ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 5, DbContext);
        }
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 5:
    {
        std::cout << "You choose: " << cli_command[4].first << std::endl;
        std::cout << "Input Controller Name: \n";
        std::cin >> ControllerName;
        final_command = cli_command[4].second;
        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 6:
    {
        std::cout << "You choose: " << cli_command[5].first << std::endl;
        std::cout << "Input Controller Name: \n";
        std::cin >> ControllerName;
        std::cout << "\nInput your Model: \n";
        std::cin >> Model;
        final_command = cli_command[5].second;
        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        final_command = final_command + Model;
        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 7:
    {
        std::cout << "You choose: " << cli_command[6].first << std::endl;
        std::cout << "Input Controller Name: \n";
        std::cin >> ControllerName;
        std::cout << "\nInput your Model: \n";
        std::cin >> Model;
        std::cout << "\nInput DbContenxt: \n";
        std::cin >> DbContext;

        final_command = cli_command[6].second;

        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }

        pos = final_command.find(" -m ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 4, Model);
        }

        final_command = final_command + DbContext;

        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 8:
    {
        std::cout << "You choose: " << cli_command[7].first << std::endl;
        std::cout << "Input Controller Name: \n";
        std::cin >> ControllerName;
        final_command = cli_command[7].second;
        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 9:
    {
        std::cout << "You choose: " << cli_command[8].first << std::endl;
        std::cout << "Input Controller Name: \n";
        std::cin >> ControllerName;
        std::cout << "Input your Model: \n";
        std::cin >> Model;
        std::cout << "Input DbContext: \n";
        std::cin >> DbContext;

        final_command = cli_command[8].second;

        pos = final_command.find(" -name ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, ControllerName);
        }
        pos = final_command.find(" -m ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 4, Model);
        }

        final_command = final_command + DbContext;

        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 10:
    {
        std::cout << "Your choose: " << cli_command[9].first << std::endl;
        std::cout << "Input View: \n";
        std::cin >> View;

        final_command = cli_command[9].second;
        pos = final_command.find(" view ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 6, View);
        }

        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 11:
    {
        std::cout << "Your choose: " << cli_command[10].first << std::endl;
        std::cout << "Input your Model: \n";
        std::cin >> Model;
        std::cout << "\nInput DbConetext:\n";
        std::cin >> DbContext;

        final_command = cli_command[10].second;

        int choseAct;
        std::cout << "Chosee what you need: \n";
        std::cout << "1. All (CRUD) \n";
        std::cout << "2. Create \n";
        std::cout << "3. Edit \n";
        std::cout << "4. Delete \n";
        std::cout << "5. Details \n";
        std::cout << "6. List(Index) \n";
        std::cin >> choseAct;
        switch (choseAct)
        {
        case 1:
        {

            allCli[0] = InsertRazorView(final_command, "Create", "Create", Model, DbContext);
            final_command = cli_command[10].second;
            allCli[1] = InsertRazorView(final_command, "Edit", "Edit", Model, DbContext);
            final_command = cli_command[10].second;
            allCli[2] = InsertRazorView(final_command, "Delete", "Delete", Model, DbContext);
            final_command = cli_command[10].second;
            allCli[3] = InsertRazorView(final_command, "Details", "Details", Model, DbContext);
            final_command = cli_command[10].second;
            allCli[4] = InsertRazorView(final_command, "Index", "list", Model, DbContext);
            final_command = cli_command[10].second;

            for (int i = 0; i < 5; i++)
            {
                std::cout << "Final Comands: " << *(i + allCli) << std::endl;
            }
        }
        break;
        case 2:
        {
            final_command = InsertRazorView(final_command, "Create", "Create", Model, DbContext);
        }
        break;
        case 3:
        {
            final_command = InsertRazorView(final_command, "Edit", "Edit", Model, DbContext);
        }
        break;
        case 4:
        {
            final_command = InsertRazorView(final_command, "Delete", "Delete", Model, DbContext);
        }
        break;
        case 5:
        {
            final_command = InsertRazorView(final_command, "Details", "Details", Model, DbContext);
        }
        break;
        case 6:
        {
            final_command = InsertRazorView(final_command, "Index", "List", Model, DbContext);
        }
        break;
        }
        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 12:
    {
        std::cout << "Your choose: " << cli_command[11].first << std::endl;
        std::cout << "Input Component Name: \n";
        std::cin >> ComponentName;
        final_command = cli_command[11].second;
        final_command += ComponentName;

        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 13:
    {
        std::cout << "Your choose: " << cli_command[12].first << std::endl;
        std::cout << "Input Page Name: \n";
        std::cin >> PageName;

        std::cout << "Input \"Output Dir\": \n";
        std::cin >> outDir;
        final_command = cli_command[12].second;
        pos = final_command.find(" razor ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 7, PageName);
        }

        final_command += outDir;

        std::cout << "Final Command: " << final_command << std::endl;
    }
    break;
    case 14:
    {
        std::cout << "Your choose: " << cli_command[13].first << std::endl;
        std::cout << "Input your Model: \n";
        std::cin >> Model;
        std::cout << "Input DbContext: \n";
        std::cin >> DbContext;
        final_command = cli_command[13].second;
        pos = final_command.find(" -m ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 4, Model);
        }
        pos = final_command.find(" -dc ");
        if (pos != std::string::npos)
        {
            final_command.insert(pos + 5, DbContext);
        }
        final_command += Model;
    }
    break;
    case 15:
    {
        std::cout << "Your choose: " << cli_command[14].first << std::endl;
        std::cout << "Input Page Name: \n";
        std::cin >> PageName;
        std::cout << "\nInput your Model: \n";
        std::cin >> Model;
        std::cout << "Input DbContext: \n";
        std::cin >> DbContext;
        final_command = cli_command[14].second;

        int choseAct;
        std::cout << "Chosee what you need: \n";
        std::cout << "1. All (CRUD) \n";
        std::cout << "2. Create \n";
        std::cout << "3. Edit \n";
        std::cout << "4. Delete \n";
        std::cout << "5. Details \n";
        std::cout << "6. List(Index) \n";
        std::cin >> choseAct;
        switch (choseAct)
        {
        case 1:
        {
            allCli[0] = InsertRazorPage(final_command, PageName, "Create", Model, DbContext);
            final_command = cli_command[14].second;
            allCli[1] = InsertRazorPage(final_command, PageName, "Edit", Model, DbContext);
            final_command = cli_command[14].second;
            allCli[2] = InsertRazorPage(final_command, PageName, "Delete", Model, DbContext);
            final_command = cli_command[14].second;
            allCli[3] = InsertRazorPage(final_command, PageName, "Details", Model, DbContext);
            final_command = cli_command[14].second;
            allCli[4] = InsertRazorPage(final_command, PageName, "List", Model, DbContext);
            final_command = cli_command[14].second;

            for (int i = 0; i < 5; i++)
            {
                std::cout << "Final Commands: " << *(i + allCli) << std::endl;
            }
        }
        break;
        case 2:
        {
            final_command = InsertRazorPage(final_command, PageName, "Create", Model, DbContext);
        }
        break;
        case 3:
        {
            final_command = InsertRazorPage(final_command, PageName, "Edit", Model, DbContext);
        }
        break;
        case 4:
        {
            final_command = InsertRazorPage(final_command, PageName, "Delete", Model, DbContext);
        }
        break;
        case 5:
        {
            final_command = InsertRazorPage(final_command, PageName, "Details", Model, DbContext);
        }
        break;
        case 6:
        {
            final_command = InsertRazorPage(final_command, PageName, "List", Model, DbContext);
        }
        break;
        }
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    case 16:
    {
        std::cout << "Your choose: " << cli_command[15].first << std::endl;
        std::cout << "Input DbContext: \n";
        std::cin >> DbContext;
        final_command = cli_command[15].second;
        final_command += DbContext;
        std::cout << "Final command: " << final_command << std::endl;
    }
    break;
    }
    return 0;
}
std::string InsertRazorView(std::string command, std::string toFind, std::string toInsert, std::string model, std::string DbContext, size_t offset)
{
    size_t pos = command.find(" view ");
    if (pos != std::string::npos)
    {
        command.insert(pos + offset, toInsert);
    }
    pos = command.find(" " + toFind + " ");
    if (pos != std::string::npos)
    {
        command.insert(pos + toInsert.length() + 2, toInsert);
    }
    pos = command.find(" -m ");
    if (pos != std::string::npos)
    {
        command.insert(pos + 4, model);
    }
    command += DbContext;
    return command;
}
std::string InsertRazorPage(std::string command, std::string PageName, std::string action, std::string model, std::string DbContext)
{
    size_t pos = command.find(" razor ");
    if (pos != std::string::npos)
    {
        command.insert(pos + 7, PageName);
    }
    pos = command.find(" " + PageName + " ");
    if (pos != std::string::npos)
    {
        command.insert(pos + PageName.length() + 2, action);
    }
    pos = command.find(" -m ");
    if (pos != std::string::npos)
    {
        command.insert(pos + 4, model);
    }
    pos = command.find(" -dc ");
    if (pos != std::string::npos)
    {
        command.insert(pos + 5, DbContext);
    }
    command += model;
    return command;
}