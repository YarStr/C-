#include <iostream>

using namespace std;

int main()
{
    string newString = "";
    string Astr = "";

    cin >> newString;

    for (auto c : newString) {

        Astr += c;
        if (islower(c)) {
            Astr = Astr.substr(0, Astr.size() - 1);
            char x = c-32;
            Astr += x;
        }
    }

    cout << Astr << endl;
}


