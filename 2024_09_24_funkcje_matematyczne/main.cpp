#include <math.h>
#include <iostream>

float Delta(int a, int b, int c) {
    float delta = (b * b) - (4 * (a * c));
    if(delta < 0) {
        std::cout << "No results!\n";
        exit(0);
    }
    else{
        delta = sqrt(delta);
        return delta;
    }
}
float x1(int a, int b, int c, float delta) {
    float x = ((b * -1) + delta) / 2 * a;
    return x;
}
float x2(int a, int b, int c, float delta) {
    float x = ((b * -1) - delta) / 2 * a;
    return x;
}

int main() {
    int a,b,c;

    std::cout << "Value of a: ";
    std::cin >> a;
    std::cout << "\nValue of b: ";
    std::cin >> b;
    std::cout << "\nValue of c: "; 
    std::cin >> c;

    float delta = Delta(a, b, c);

    if (delta > 0) {
        float answer1 = x1(a, b, c, delta);
        float answer2 = x2(a, b, c, delta);
        std::cout << "\nFirst x: " << answer1 << "\n";
        std::cout << "Second x: " <<  answer2 << "\n";
    }
    else if (delta == 0) {
        float answer1 = x1(a, b, c, delta);
        std::cout << "\nOnly x: " << answer1 << "\n";
    }
}