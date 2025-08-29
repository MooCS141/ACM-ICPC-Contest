#include <iostream>

using namespace std;

struct Student
{
    string name;
} std1, std2;

int main() {
    std1.name = "Apirak";
    cout << std1.name << endl;
    return 0;
}