#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::fstream open_file(std::string filename);

int main() {
    std::fstream file = open_file("liczby_przyklad.txt");
    
    std::vector<int> row1;
    std::vector<int> row2;

    for (int i = 0; i < 220; i++)
    {
        int v;
        file >> v;
        if (i < 200)
        {
            row1.push_back(v);
        }
        else
        {
            row2.push_back(v);
        }
    }
    //TASK_0
    int task_0 = 0;
    for (int i = 0; i < row1.size(); i++)
    {
        for (int j = 0; j < row2.size(); j++)
        {
            if ((row2[j] % row1[i]) == 0)
            {
                task_0 += 1;
                break;
            }
        }
    }
    std::cout << "Task 0: " << task_0 << std::endl;
    //TASK_0

    //TASK_1
    std::vector<int> sorted = row1;
    std::sort(sorted.begin(), sorted.end());
    std::cout << "Task 1: " << sorted[100] << std::endl;
    //TASK_1

    //TASK_2
    int block_size = 50;
    int highest_average = 0.0;

    int best_start = 0;
    int best_end = 0;
    double max_average = -1;

    for (size_t start = 0; start < row1.size(); start++)
    {
        for (size_t end = start + 50; end <= row1.size(); end++)
        {
            int sum = 0;

            for (size_t i = start; i < end; i++)
            {
                sum += row1[i];
            }

            double average = static_cast<double>(sum) / (end - start);

            if (average > max_average)
            {
                max_average = average;
                best_start = start;
                best_end = end;
            }
        }
    }

    std::cout << "Task 2:\n\tMax average: " << max_average << "\n\tBlock size: " << best_end - best_start << "\n\tStarting number: " << row1[best_start]; 
    //TASK_2

    return 0;
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