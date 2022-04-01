#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!";
        return -1;
    }

    int N; fin >> N;
    fin.close();

    ofstream fout("output.txt");
    if (1 <= N && N <= 2 || N == 12)
        fout << "Winter";
    else if (3 <= N && N <= 5)
        fout << "Spring";
    else if (6 <= N && N <= 8)
        fout << "Summer";
    else if (9 <= N && N <= 11)
        fout << "Autumn";
    else
        fout << "Error";
   
    fout.close();

    return 0;
}
