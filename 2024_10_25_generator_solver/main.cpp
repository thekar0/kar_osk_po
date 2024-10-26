#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    int userChoice;
    cout << "What do you want to do?\n1. Generate a file\n2. Solve a file\n";
    cin >> userChoice;
    
    if(userChoice == 1){
        cout << "Creating a file...\n";
    
        ofstream file("data.txt");

        srand(123);

        for(int i = 0; i < 10000; i++){
            file << rand() << "\n";
        }
        cout << "File Created\n";
    }
    else if(userChoice == 2){
        ifstream dataFile("data.txt");

        int numbersEndedWith7 = 0;
        int totalSum = 0;
        int secondModuloBy3 = 0;

        string line;
        int n;

        while(getline(dataFile, line)){
            n = line.length();
            if(line[n-1] == '7'){
                numbersEndedWith7++;
            }
            for(char number : line){
                if(isdigit(number)){
                    totalSum += number - '0';
                }
            }
            if((line[1] - '0') % 3 == 0){
                secondModuloBy3++;
            }
        }
        ofstream answerFile("answers.txt");
        answerFile << "Answer 1: " << numbersEndedWith7 << "\nAnswer 2: " << totalSum << "\nAnswer 3: " << secondModuloBy3;
    }
    return 0;
}