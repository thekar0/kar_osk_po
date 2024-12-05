#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

struct Object
{
    int a;
    std::string op;
    int b;
    float result;

    friend std::ostream& operator<<(std::ostream& os, const Object& obj)
    {
        os << obj.a << " " << obj.op << " " << obj.b << " = " << obj.result << "\n";
        return os;
    }
};

int main()
{
    std::ofstream file("data.txt");
    std::string operators[5] = {"addition", "subtraction", "multiplication", "division", "modulo"};
    for(int i = 0; i < 10; i++)
    {
        Object object;
        object.a = rand() % 100;
        object.op = operators[rand() % 5];
        object.b = rand() % 100;
        if(object.op == "addition")
        {
            object.result = object.a + object.b;
        }
        else if(object.op == "subtraction")
        {
            object.result = object.a - object.b;
        }
        else if(object.op == "multiplication")
        {
            object.result = object.a * object.b;
        }
        else if(object.op == "division")
        {
            if (object.b != 0)
            {
                object.result = object.a / object.b;
            }
            else
            {
                object.result = 0;
            }
        }
        else if(object.op == "modulo")
        {
            if (object.b != 0)
            {
                object.result = object.a % object.b;
            }
            else
            {
                object.result = 0;
            }
        }
        file << object;
    }
    file.close();
    return 0;
    }