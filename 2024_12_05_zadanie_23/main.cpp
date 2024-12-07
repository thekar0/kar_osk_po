#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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
    std::map <std::string, int> years_map;

    for(const std::string& line : vector)
    {
        std::string id = line.substr(0, 2);
        years_map[id]++;
    }

    std::string result = "0";
    int max = 0;
    for(const auto& year : years_map)
    {
        if (year.second > max)
        {
            result = year.first;
            max = year.second;
        }
    }

    return result;
}

std::vector<std::string> taskD(std::vector<std::string> vector)
{
    std::vector <std::string> result;

    for(const std::string& line : vector)
    {
        int wages[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

        int sum = 0;

        for(int i = 0; i < 10; i++)
        {
            sum += (line[i] - '0') * wages[i];
        }

        if((10 - (sum % 10)) != line[10] - '0')
        {
            result.push_back(line);
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result.size() - i - 1; j++)
        {
            if(result[j] > result[j + 1])
            {
                std::swap(result[j], result[j + 1]);
            }
        }
    }

    return result;
}

std::map<std::string, int> taskE(std::vector<std::string> vector)
{
    std::map <std::string, int> result = 
    {
        {"50s", 0},
        {"60s", 0},
        {"70s", 0},
        {"80s", 0},
        {"90s", 0},
    };

    for(std::string line : vector)
    {
        switch (line[0] - '0')
        {
        case 5:
            result["50s"]++;
            break;
        case 6:
            result["60s"]++;
            break;
        case 7:
            result["70s"]++;
            break;
        case 8:
            result["80s"]++;
            break;
        case 9:
            result["90s"]++;
            break;
        default:
            std::cout << "Podana wartość nie należy do lat 50-99";
            break;
        }
    }

    return result;
}
int main()
{
    std::vector<std::string> lines;
    std::fstream input_file("pesel.txt", std::ios::in);
    std::string line;
    while (getline (input_file, line))
    {
        lines.push_back(line);
    }
    input_file.close();
    std::fstream output_file("odp.txt", std::ios::out);
    output_file << "Zadanie A: " << taskA(lines) << std::endl;
    output_file << "Zadanie B: " << taskB(lines) << std::endl;
    output_file << "Zadanie C: " << taskC(lines) << std::endl;

    output_file << "Zadanie D: " << std::endl;
    for(std::string line : taskD(lines))
    {
        output_file << '\t' << line << std::endl;
    }

    output_file << "Zadanie E: " << std::endl;
    
    for(const auto& decade : taskE(lines))
    {
        output_file << '\t' << decade.first << ": " << decade.second << std::endl;
    }
}