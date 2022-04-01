#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!";
        return -1;
    }
    
    int n; fin >> n;
    vector<int> numbers;
    int temp;

    for (int i = 0; i < n; ++i)
    {
        fin >> temp;
        numbers.push_back(temp);
    }
    
    ofstream fout("output.txt");
    for (int i = n - 1; i >= 0; --i)
        fout << numbers[i] << " ";
    fout.close();
    
    return 0;
}
