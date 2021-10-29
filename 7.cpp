#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    for (int i = 0; i <= 9; ++i) {
        cout << "№" << i+1 << endl;

        cin >> num1 >> num2;
        if (num1 > num2) {
            cout << "the bigger " <<num1 << endl;
        }
        else {
            cout << "the bigger " << num2 << endl;
        }
    }
}
