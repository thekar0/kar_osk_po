#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int taskA(std::vector<std::string> vector)
{
    int result = 0;
    for (const std::string& line: vector)
    {
        if (line[2] == '1' && line[3] == '2') // jezeli miesiac = 12
        {
            result ++;
        }
    }
    return result;
}

int taskB(std::vector<std::string> vector)
{
    int result = 0;
    for (const std::string& line: vector)
    {
        if ((line[9] - '0') % 2 == 0)
        {
            result ++;
        }
    }
    return result;
}

std::string taskC(std::vector<std::string> vector)
{
    std::string result = "";
    std::string currentYear = "";
    int currentStreak = 0;
    for (const std::string& line: vector)
    {
        if ((line[0] + line[1]) - '0' )
        {
            std::cout << "xd";
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> lines;
    std::fstream file("pesel.txt", std::ios::in);
    std::string line;
    while (getline (file, line))
    {
        lines.push_back(line);
    }
    std::cout << taskA(lines) << std::endl;
    std::cout << taskB(lines) << std::endl;
    file.close();
}