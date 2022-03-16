#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile;
    
    inputFile.open("input.txt");

    if (!inputFile.is_open())
    {
        cout << "File input.txt does not exist!" << endl;
        return 1;
    }    

    list<int> values;
    
    while (!inputFile.eof())
    {
        int temp;
        inputFile >> temp;
        values.push_back(temp);
    }

    values.sort();

    int sumOfValues = 0;
    for (int i : values)
    {
        sumOfValues += i;
    }

    float averageValue = (float)sumOfValues / values.size();

    cout << "Среднее значение: " << averageValue << endl;

    cout << "Массив: ";
    for (int i : values)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
