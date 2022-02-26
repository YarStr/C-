#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Student
{
    int age;
    string name;
    string drink;
};

bool isPrime(int num)
{
    for (int i = 2; i < (int)pow(num, 0.5) + 1; ++i)
    {
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    Student mas[3];
    
    mas[0] = { 23, "John", "Coca-Cola" };
    mas[1] = { 18, "Mary", "Tea" };
    mas[2] = { 19, "Alice", "Vodka" };

    cout << "Студенты, возраст которых - простое число:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        if (isPrime(mas[i].age))
        {
            cout << mas[i].name << " " << mas[i].drink << endl;
        }
    }
   
    return 0;
}
