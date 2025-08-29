#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<string, int> province;

    province["Phectchaburi"] = 253;

    province["Bangkok"] = 450;

    cout << "Phectchaburi : " << province["Phectchaburi"] << endl;
    cout << "Bangkok : " << province["Bangkok"] << endl;

    return 0;
}