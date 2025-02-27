#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::string current_file = "przyklad.txt";

class Interface
{
    public:
        virtual void load() = 0;
        virtual void process() = 0;
        virtual void save() = 0;
        virtual ~Interface() {}
};

class Zadanie_1_Pixel : public Interface
{
    public:
        std::set<int> pixels;
        int smallest;
        int largest;

        void load() override 
        {
            std::ifstream file(current_file, std::ios::in);
            std::string line;
            while(std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string pixel;

                while (iss >> pixel) 
                {
                    pixels.insert(std::stoi(pixel));
                }
            }
        }

        void process() override
        {
            largest = *pixels.begin();
            smallest = *pixels.begin();

            for (const auto& pixel : pixels)
            {
                if (largest < pixel)
                {
                    largest = pixel;
                }
                if (smallest > pixel)
                {
                    smallest = pixel;
                }
            }
        }

        void save() override
        {
            std::cout << largest << " " << smallest;
        }
};

class Zadanie_2_Pixel : public Interface
{
    public:
    std::vector<std::string> pixel_line;
    int lines_to_remove = 0;
    
    void load() override
    {
        std::ifstream file(current_file, std::ios::in);
        std::string line;
        while(std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string pixel;
            while (iss >> pixel) 
            {
                pixel_line.push_back(pixel);
            }
            //1 - 160 | 320 - 160
            for (int i = 0; i < 160; i++)
            {
                std::cout << pixel_line[i] << " : " << pixel_line[319 - i] << "\n"; //-1 bo indexowanie od 0
            }
            pixel_line.clear();
        }

    }

    void process() override
    {

    }

    void save() override
    {

    }
};

int main()
{
    Zadanie_2_Pixel zadanie;
    zadanie.load();
    return 0;
}