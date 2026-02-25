#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
#include "main.h"
using namespace std;

string printResult(string name, string output, string expected) {
    stringstream result;
    if (expected == output) {
        result << GREEN << name << " PASS " << RESET << "\n";
    }

    else {
        result << RED << name << " FAILED " << RESET << "\n";
        cout << "Your result: \n" << output << "\n";
        cout << "Expected result: \n" << expected << "\n"; 
    }

    return result.str();
}