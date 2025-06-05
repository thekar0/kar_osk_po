#include <iostream>
#include <vector>
#include <fstream>

void print_vector(std::vector<int> vector);

int main()
{
    std::ifstream file("dane.txt");

    std::vector<int> liczby;

    int line;
    while (file >> line) {
        // std::cout << "Read number: " << line << '\n';
        liczby.push_back(line);
    }

    int curr_lucky_number = 1;

    // usuwanie liczb parzystych
    for (int i = liczby.size() - 1; i >= 0; --i) {
        if (liczby[i] % 2 == 0) {
            liczby.erase(liczby.begin() + i);
        }
    }

    curr_lucky_number = liczby[1];

    std::cout << curr_lucky_number;

    // print_vector(liczby);
}

void print_vector(std::vector<int> vector)
{
    for (int liczba : vector)
    {
        std::cout << "nr" << liczba << "\n";
    }
}