#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ifstream f_in("input.txt");
    ofstream f_out("output.txt");

    string str;

    while (!f_in.eof())
    {
        getline(f_in, str);
        reverse(str.begin(), str.end());
        f_out << str << '\n';
    }
    f_in.close();
    f_out.close();
}
