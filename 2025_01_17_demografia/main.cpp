#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

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

std::map <std::string, float> zadanie_2 (std::vector <linia> lines)
{
    std::map <std::string, float> result;

    std::string powiaty_w_rankingu[10] = {};

    for (int i = 0; i < 10; i++)
    {
        float najwiekszy_przyrost = lines[0].wsp_urodzen - lines[0].wsp_zgonow;
        std::string najwiekszy_przyrost_owner = "";

        for (linia l : lines)
        {
            float przyrost = (l.wsp_urodzen - l.wsp_zgonow);
            std::string powiat = l.powiat;

            if (przyrost > najwiekszy_przyrost)
            {
                bool already_in_ranking = false;
                for(int j = 0; j < 10; j++)
                {
                    if (powiat == powiaty_w_rankingu[j])
                    {
                        already_in_ranking = true;
                    }       
                }
                if (already_in_ranking == false)
                {
                    najwiekszy_przyrost = przyrost;
                    najwiekszy_przyrost_owner = powiat;
                }
            }
        }

        powiaty_w_rankingu[i] = najwiekszy_przyrost_owner;
        result.insert( {najwiekszy_przyrost_owner, najwiekszy_przyrost});

    }

    return result;

}

std::map<std::string, int> zadanie_3 (std::vector <linia> lines)
{
    std::map <std::string, int> wojewodztwa_and_ludnosc;

    for (linia l : lines)
    {
        wojewodztwa_and_ludnosc[l.wojewodztwo] += l.ludnosc_ogolem;
    }

    int four_highest[4];
    
    for (int i = 0; i < 4; i++)
    {
        int highest = 0;
        for ( const auto& pair : wojewodztwa_and_ludnosc )
        {
            // std::cout << pair.first << " " << pair.second << "\n";
            if (pair.second > highest)
            {
                bool already_in_ranking = false;
                for (int j = 0; j < 4; j++)
                {
                    if (pair.second == four_highest[j])
                    {
                        already_in_ranking = true;
                    }
                }

                if (already_in_ranking == false)
                {
                    four_highest[i] = pair.second;
                }
            }
        }
    }

    std::map <std::string, int> result;

    for (const auto& pair : wojewodztwa_and_ludnosc)
    {
        for (int i = 0; i < 4; i++)
        {
            if (four_highest[i] == pair.second)
            {
                result[pair.first] = pair.second;
            }
        }
    }

    return result;
}

std::map <std::string, int> zadanie_4(std::vector<linia> lines)
{
    std::map <std::string, int> result;

    for (linia l : lines)
    {
        if (l.wojewodztwo == "opolskie")
        {
            int liczba_urodzen = std::round(l.ludnosc_ogolem / 1000 * l.wsp_urodzen);

            result[l.powiat] = liczba_urodzen;
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

            std::replace(split_line[3].begin(), split_line[3].end(), ',', '.');
            std::replace(split_line[4].begin(), split_line[4].end(), ',', '.');

            l.powiat = split_line[0];
            l.wojewodztwo = split_line[1];
            l.ludnosc_ogolem = std::stoi(split_line[2]);
            l.wsp_urodzen = std::stof(split_line[3]);
            l.wsp_zgonow = std::stof(split_line[4]);
            l.saldo_migracji = std::stof(split_line[5]);

            lines.push_back(l);
        }

        file.close();

        // for (linia l : lines)
        // {
        //     std::cout << l.powiat << " " << l.wojewodztwo << " " << l.ludnosc_ogolem << " " << l.wsp_urodzen << " " << l.wsp_zgonow << " " << l.saldo_migracji << std::endl;
        // }

        std::cout << "Zadanie 1: " << "\n\t" << zadanie_1(lines) << "\n";

        std::cout << "Zadanie 2:\n";

        for (const auto& pair : zadanie_2(lines))
        {
            std::cout << "\t" << pair.first << " " << pair.second << "\n";
        }

        std::cout << "Zadanie 3:\n";
        for (const auto& pair : zadanie_3(lines))
        {
            std::cout << "\t" << pair.first << " " << pair.second << "\n";
        }

        std::cout << "Zadanie 4:\n";
        for (const auto& pair : zadanie_4(lines))
        {
            std::cout << "\t" << pair.first << " " << pair.second << "\n";
        }
    }
}
