// this isnt made to be good code, just something i threw together for easier toggling

#include <iostream>
#include <fstream>
#include <string>

void createbackup(std::string dir)
{
    std::ifstream fin(dir + "\\settings.json");
    std::ofstream fout(dir + "\\settings.json.bak");

    std::string line;
    while (std::getline(fin, line))
        fout << line << '\n';
}

void restorejson(std::string dir, std::string json)
{
    std::ifstream fin(json);
    std::ofstream fout(dir + "\\settings.json");

    std::string line;
    while (std::getline(fin, line))
        fout << line << '\n';

    fout.close();
}

void replacejson(std::string dir)
{
    std::ofstream fout(dir + "\\settings.json");

    // edited json data used for bypassing
    std::string json[10] = { "{",
        "	\"title\"											: \"ELDEN RING™\",",
        "	\"executable\"									: \"eldenring.exe\",",
        "	\"productid\"										: \"0\",",
        "	\"sandboxid\"										: \"0\",",
        "	\"deploymentid\"									: \"0\",",
        "	\"requested_splash\"								: \". / EasyAntiCheat / SplashScreen.png\",",
        "	\"wait_for_game_process_exit\"					: \"false\",",
        "	\"logo_position\"									: \"bottom - left\"",
        "}" };

    for (int i = 0; i < 10; i++)
        fout << json[i] << '\n';
}

int main()
{
    int mode;
    int mode2 = 0;

    while (true)
    {
        std::cout << "Select mode:" <<
            "\n \"0\" - Install updated settings.json" <<
            "\n \"1\" - Restore old settings.json from backup file\n" <<
            "Mode: ";

        std::string inp;
        std::cin >> inp;
        if (inp == "0")
        {
            mode = 0;
            break;
        }
        if (inp == "1")
        {
            mode = 1;
            break;
        }
        else
            std::cout << "\n\nInvalid input, only use \"0\" or \"1\" (Without quotations)\n\n";
    }

	std::cout << "\n\n\n============================================================\n" << "\nCopy and Paste in your Elden Ring EAC Folder directory here" <<
        "\nSome common directories include: \n - \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\ELDEN RING\\Game\\EasyAntiCheat\" \n - \"D:\\SteamLibrary\\steamapps\\common\\ELDEN RING\\Game\\EasyAntiCheat\" ";
    std::cout << "\n\n > ";
	std::string dir;
    while (mode2 == 0)
    {
        std::getline(std::cin, dir);

        if (dir != "")
        {
            while (true)
            {
                std::cout << "Does the directory : " + dir + " look right?" <<
                    "\n \"0\" - No, input again" <<
                    "\n \"1\" - Yes, continue\n" <<
                    "Mode: ";

                std::string inp;
                std::cin >> inp;

                if (inp == "0")
                {
                    dir = "";
                    mode2 = 0;
                    std::cout << "\n\n > ";
                    break;
                }
                if (inp == "1")
                {
                    mode2 = 1;
                    break;
                }
                else
                    std::cout << "\n\nInvalid input, only use \"0\" or \"1\" (Without quotations)\n\n";
            }
        }
    }


    if (mode == 0)
    {
        createbackup(dir);
        replacejson(dir);
        std::cout << "\nCreated a backup of \"settings.json\" as \"settings.json.bak\"" <<
            "\nEnabled bypass for \"settings.json\"";
    }
    else
    {
        restorejson(dir, dir + "\\settings.json.bak");
        std::cout << "\nAttempted to restore \"settings.json\" from \"settings.json.bak\"";
    }

    std::cout << "\nThis process may now be safely exited.";
    std::string a; std::cin >> a;
}
