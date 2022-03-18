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

    list<float> values;
    
    while (!inputFile.eof())
    {
        float temp;
        inputFile >> temp;
        values.push_back(temp);
    }

    values.sort();

    float sumOfValues = 0;
    for (float i : values)
    {
        sumOfValues += i;
    }

    float averageValue = (float)sumOfValues / values.size();

    cout << "Среднее значение: " << averageValue << endl;

    cout << "Массив: ";
    for (float i : values)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
