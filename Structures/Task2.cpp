#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int age;
    string name;
    string drink;
};

int main()
{
    Student mas[3];
    
    mas[0] = { 23, "John", "Coca-Cola" };
    mas[1] = { 18, "Mary", "Tea" };
    mas[2] = { 19, "Alice", "Vodka" };

    int maxAge = mas[0].age;
    for (int i = 0; i < 3; ++i)
    {
        if (mas[i].age > maxAge)
        {
            maxAge = mas[i].age;
        }
    };
    
    cout << "Максимальный возраст среди студентов: " << maxAge << endl;
   
    return 0;
}
