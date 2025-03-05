#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

std::string current_file = "przyklad.txt";

class Interface
{
    public:
        virtual void load() = 0;
        virtual void process() = 0;
        virtual void save() = 0;
        virtual ~Interface() {}
};

class Zadanie_Pixele : public Interface
{
    public:
        // ZADANIE_1
        std::set<int> pixels;
        int smallest;
        int largest;
        // ZADANIE_1

        //ZADANIE_2
        std::vector<std::string> pixel_line;
        int lines_to_remove = 0;
        //ZADANIE_2

        //ZADANIE_3
        std::map<std::string, int> pixel_occurences;
        int most_popular_number ;
        int least_popular_number;
        std::string most_popular_number_owner ;
        std::string least_popular_number_owner;
        //ZADANIE_3

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
                    pixels.insert(std::stoi(pixel)); // ZADANIE_1
                    pixel_line.push_back(pixel); //ZADANIE_2
                    pixel_occurences[pixel]++; //ZADANIE_3
                }
            }
        }

        void process() override
        {
            //ZADANIE_1
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
            //ZADANIE_1

            //ZADANIE_2
            for (int i = 0; i < 160; i++) //1 - 160 | 320 - 160
            {
                if (pixel_line[i] != pixel_line[319 - i]) //-1 bo indexowanie od 0
                {
                    lines_to_remove++;
                    break;
                }
            }
            pixel_line.clear();
            //ZADANIE_2

            //ZADANIE_3
            most_popular_number = pixel_occurences.begin()->second;
            least_popular_number = pixel_occurences.begin()->second;
            most_popular_number_owner = pixel_occurences.begin()->first;
            least_popular_number_owner = pixel_occurences.begin()->first;

            for(const auto& pair : pixel_occurences)
            {
                //std::cout << pair.first << " : " << pair.second << "\n";   

                if (pair.second > most_popular_number)
                {
                    most_popular_number_owner = pair.first;
                    most_popular_number = pair.second;
                }
                if (pair.second < least_popular_number)
                {
                    least_popular_number_owner = pair.first;
                    least_popular_number = pair.second;
                }
            }
            //ZADANIE_3
        }

        void save() override
        {
            std::cout << "Zadanie_1: " << largest << " " << smallest << std::endl; //ZADANIE_1
            std::cout << "Zadanie_2: " << lines_to_remove << std::endl; //ZADANIE_2
            std::cout << "Zadanie_3\n\tMost popular: " << most_popular_number_owner << "\n\tLeast popular: " << least_popular_number_owner << std::endl; //ZADANIE_3
        }
};

class Zadanie_Cezar : public Interface
{
    public:

        virtual void load(){}
        virtual void process(){}

        bool is_upper_case(char character)
        {
            if ('A' <= character && character <= 'Z')
            {
                return true;
            }
            return false;
        }

        bool is_special_character(char character)
        {
            if(character == ' ' || character == '\n')
            {
                return true;
            }
            return false;
        }

        bool is_string_valid(std::string str) 
        {
            int n = str.size();
            for (int i = 0; i < n; i++)
            {
                if (is_special_character(str[i]))
                {
                    continue;
                }
                if(!is_upper_case(str[i]))
                {
                    return false;
                }
            }
            return true;
        }

        std::string encryption(std::string str, int shift)
        {
            int n = str.size();
            std::string result = str;

            for (int i = 0; i < n; i++)
            {
                // E(x) = (x + shift) % 26
                if(!is_special_character(str[i]))
                {
                    if (std::islower(str[i])) 
                    {
                        result[i] = 'a' + (str[i] - 'a' + shift) % 26;
                    }
                    else if (std::isupper(str[i])) 
                    {
                        result[i] = 'A' + (str[i] - 'A' + shift) % 26;
                    }
                }
            }
            return result;
        }

        std::string decryption(std::string str, int shift)
        {
            int n = str.size();
            std::string result = str;
        
            for (int i = 0; i < n; i++) {
                if (!is_special_character(str[i])) 
                {
                    if (std::islower(str[i])) 
                    {
                        int new_char = (str[i] - 'a' - shift) % 26;
                        if (new_char < 0) 
                        {
                            new_char += 26;
                        }
                        result[i] = 'a' + new_char;
                    }
                    else if (std::isupper(str[i])) 
                    {
                        int new_char = (str[i] - 'A' - shift) % 26;
                        if (new_char < 0) 
                        {
                            new_char += 26;
                        }
                        result[i] = 'A' + new_char;
                    }
                }
            }
            return result;
        }

        virtual void save()
        {
            std::string encrypted = "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD";
            std::string decrypted = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
        }
};

int main()
{
    Zadanie_Pixele pixele;
    pixele.load();
    pixele.process();
    pixele.save();

    Zadanie_Cezar cezar;
    //std::cout << "Zadanie 1: " << cezar.is_upper_case('F') << std::endl;
    //std::cout << "Zadanie 2: " << cezar.is_special_character('\n') << std::endl;
    return 0;
}