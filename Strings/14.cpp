#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputString;
    string word;
    string masWords[255];

    cout << "Input sentence:" << endl;
    getline(cin, inputString);
    cout << endl;
      
    int count = 0;
    for (auto symb : inputString) {
        if (symb != ' ')
            word += symb;
        else
        {
            masWords[count] = word;
            word = "";
            ++count;
        }
    }

    masWords[count] = word;
    ++count;

    for (int i = 0; i < count; ++i) {

        for (int j = 0; j < count-i-1; ++j) {

            if (masWords[j].length() < masWords[j + 1].length()) {
                swap(masWords[j], masWords[j + 1]);
            }
        }
    }

    cout << "Output sentence:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << masWords[i] << " ";
    }
    cout << endl;
}
