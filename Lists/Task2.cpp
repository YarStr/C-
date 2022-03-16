#include <iostream>
#include <list>
#include <ctime>

using namespace std;

int main()
{
    
    srand(time(NULL));
    list<int> List;

    int sumOfValues = 0;
    for (int i = 0; i < 10000; ++i)
    {
        int temp = rand() % 200 - 100;
        sumOfValues += temp;
        List.push_back(temp);
    }

    float averageValue = (float)sumOfValues / 10000;

    cout << "Среднее значение: " << averageValue << endl;
    
    return 0;
}
