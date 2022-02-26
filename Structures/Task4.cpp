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
    
    string names[3];
    
    for (int i = 0; i < 3; ++i)
    {
        const int nameLength =  mas[i].name.length();
        char reverseName[nameLength + 1];
        reverseName[nameLength] = '\0';
        
        for (int j = 0; j < nameLength; ++j){
            reverseName[nameLength - j - 1] = mas[i].name[j];
        }
        
        names[i] = reverseName;
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3-i-1; ++j) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < 3; ++i)
    {
        cout << names[i] << endl;
    }
    
    return 0;
}
