#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
std::vector<int> read_file_int(std::fstream& file)
{
     std::vector<int> data;

     for (int i = 0; i < 10; i++)
    {
        int v;
        file >> v;
        data.push_back(v);
    }

    file.close();

    for (int value : data) 
    {
        std::cout << value << std::endl;
    }

    return data;
}
std::vector<std::string> read_file_string(std::fstream& file)
{
    std::vector<std::string> data;

    for (int i = 0; i < 10; i++)
    {
        std::string v;
        file >> v;
        data.push_back(v);
    }

    file.close();

    for (std::string value : data) 
    {
        std::cout << value << std::endl;
    }

    return data;
}
std::vector<std::string> read_file_line(std::fstream& file)
{
    std::vector<std::string> data;
    for (int i = 0; i < 10; ++i) 
    {
    std::string v;
    std::getline(file, v);
    data.push_back( v );
    }

    for(std::string line : data)
    {
        std::cout << line << "\n";
    }
    return data;
}
std::vector<std::vector<int>> read_file_macierze(std::fstream& file)
{
    std::vector< std::vector<int> > data;
    for (int j = 0; j < 7; ++j) {
    std::vector<int> row;
    for (int i = 0; i < 7; ++i) {
        int v;
        file >> v;
        row.push_back( v );
    }
    data.push_back(row);
}
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
    return data;
}

struct data_t {
    int number;
    std::string text;
    std::string line;
    std::vector<int> array_numbers;
};
data_t read_file_custom(std::fstream& file)
{
    data_t data;
    file >> data.number;
    file >> data.text;
    file >> std::ws;  // specjalna linia (znajdź w internecie i wyświetl znaczenie std::ws jako output aplikacji)
    std::getline(file, data.line);
    for (int i = 0; i < 10; ++i) 
    {
        int num;
        file >> num;
        data.array_numbers.push_back(num);
    }


    std::cout << data.text;
    std::cout << data.line;
    for (int i = 0; i < 10; i++)
    {
        std::cout << data.array_numbers[i];
    }

    return data;
}

struct data_5
{
    std::string first;
    int second;
    std::string third;
    int fourth;
    std::string fifth;
};
std::vector<data_5> read_file_custom5(std::fstream& file)
{
    std::vector<data_5> data_vector;

    for ( int i = 0; i < 25; i++)
    {
            data_5 data;
    file >> data.first;
    file >> data.second;
    file >> data.third;
    file >> data.fourth;
    file >> data.fifth;

     data_vector.push_back(data);
    }

    for (const auto& data : data_vector)
    {
        std::cout << data.first;
        std::cout << data.second;
        std::cout << data.third;
        std::cout << data.fourth;
        std::cout << data.fifth;
    }

    return data_vector;
}

int main( int argc, char* argv[] )
{
    //Task 0
    std::fstream file_int = open_file("task0_col_data.txt");
    std::vector<int> data_int = read_file_int(file_int);

    //Task 1
    std::fstream file_string = open_file("task1_col_data.txt");
    std::vector<std::string> data_string = read_file_string(file_string);
    
    //Task 2
    std::fstream file_lines = open_file("task2_data.txt");
    std::vector<std::string> data_lines = read_file_line(file_lines);

    //Task 3
    std::fstream file_macierze = open_file("task3_matrix_data.txt");
    std::vector<std::vector<int>> data_macierze = read_file_macierze(file_macierze);

    //Task 4
    std::fstream file_mixed = open_file("task4_custom_data.txt");
    data_t data = read_file_custom(file_mixed);


    //Task 5
    std::fstream file_5 = open_file("task5_data.txt");
    std::vector<data_5> data5 = read_file_custom5(file_5);

    return 0;
}