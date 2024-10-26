#include <math.h>
#include <iostream>

int main() {
    int a,b,c;

    std::cout << "Value of a: ";
    std::cin >> a;
    std::cout << "\nValue of b: ";
    std::cin >> b;
    std::cout << "\nValue of c: "; 
    std::cin >> c;

    float delta = (b * b) - (4 * (a * c));
    if(delta < 0) {
        std::cout << "No results!\n";
        exit(0);
    }
    else{
        delta = sqrt(delta);
    }

    if (delta > 0) {
        float answer1 = ((b * -1) - delta) / 2 * a;
        float answer2 = ((b * -1) + delta) / 2 * a;
        std::cout << "\nFirst x: " << answer1 << "\n";
        std::cout << "Second x: " <<  answer2 << "\n";
    }
    else if (delta == 0) {
        float answer1 = ((b * -1) + delta) / 2 * a;;
        std::cout << "\nOnly x: " << answer1 << "\n";
    }
    return 0;
}