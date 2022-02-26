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
    
    cout << "Введите через пробел Возраст, Имя и любимый напиток студента:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cin >> mas[i].age >> mas[i].name >> mas[i].drink;
    }
    cout << endl;
    
    cout << "Вот информация, что Вы ввели:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << mas[i].age << " " << mas[i].name << " " << mas[i].drink << endl;
    }
   
    return 0;
}
