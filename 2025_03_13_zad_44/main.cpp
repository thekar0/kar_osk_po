#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::fstream open_file(std::string filename);
int amount_of_even_numbers(std::fstream& file);
void task_1(std::fstream& file);
int gcd(int a, int b);

int main()
{
    std::fstream task_0_file = open_file("skrot.txt");
    std::fstream task_1_file = open_file("skrot2.txt");

    amount_of_even_numbers(task_0_file);
    std::cout << "\n";
    task_1(task_1_file);
}

std::fstream open_file(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::in);
    if(!file)
    {
        std::cout << "Error opening the file\n";
    }
    return file;
}
int amount_of_even_numbers(std::fstream& file)
{
    std::vector<std::string> data;

    for (int i = 0; i < 200; i++)
    {
        std::string str;
        file >> str;
        data.push_back(str);
        //std::cout << str << " ";
    }

    file.close();

    int count = 0;
    int highest = 0;
    for (const std::string& str : data) 
    {
        bool even_number = true;

        for (const char& c : str) 
        {
            if ((c - '0') % 2 != 0)
            {
                even_number = false;
                break;
            }
        }
        if (even_number)
        {
            count++;
            if (std::stoi(str) > highest)
            {
                highest = std::stoi(str);
            }
        }
    }

    std::cout << "najwieksza " << highest << std::endl;
    std::cout << "ile " << count << std::endl;
    return count;
}

void task_1(std::fstream& file)
{
    std::vector<std::string> data;

    for (int i = 0; i < 200; i++)
    {
        std::string str;
        file >> str;
        data.push_back(str);
        //std::cout << str << " ";
    }

    file.close();

    for (const std::string& str : data) 
    {
        int normal = std::stoi(str);
        std::string not_even;
        for (const char& c : str) 
        {
            if ((c - '0') % 2 != 0)
            {
                not_even += c;
            }
        }
        //std::cout << not_even << std::endl;
        int not_even_number = std::stoi (not_even);
        //std::cout << gcd(not_even_number, normal) << "\n";
        if (gcd(not_even_number, normal) == 7)
        {
            std::cout << not_even_number << " " << normal << "\n";
        }
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}