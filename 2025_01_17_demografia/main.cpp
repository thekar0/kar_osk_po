#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct linia 
{
    std::string powiat;
    std::string wojewodztwo;
    int ludnosc_ogolem;
    float wsp_urodzen;
    float wsp_zgonow;
    float saldo_migracji;
};

std::vector<std::string> split (const std::string& str, char delimiter)
{
    std::vector <std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int zadanie_1 (std::vector <linia> lines)
{
    int result = 0;
    for (linia l : lines)
    {
        if (l.wojewodztwo == "mazowieckie" && l.saldo_migracji < 0)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    std::ifstream file("demografia.txt");

    std::vector<linia> lines;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line)) {
            std::vector <std::string> split_line = split(line, '\t');

            linia l;

            l.powiat = split_line[0];
            l.wojewodztwo = split_line[1];
            l.ludnosc_ogolem = std::stoi(split_line[2]);
            l.wsp_urodzen = std::stof(split_line[3]);
            l.wsp_zgonow = std::stof(split_line[4]);
            l.saldo_migracji = std::stof(split_line[5]);

            lines.push_back(l);
        }

        std::cout << zadanie_1(lines);

        file.close();

        // std::cout << zadanie_1(lines);

    }
}