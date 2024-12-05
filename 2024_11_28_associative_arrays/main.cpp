#include <iostream>
#include <vector>
#include <string>
int main()
{
    std::vector<int> tablica;

    auto xd = 54;
    auto bruh = "ghreg";

    for(auto& value : tablica)
    {
        std::cout << value;
    }
    
    std::cout << bruh << "\n" << xd << "\n";
    return 0;
}