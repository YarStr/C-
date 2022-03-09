#include <iostream>
#include <string>
using namespace std;

//Класс игрового поля, содержащий имя игрока и информацию о расстановке его кораблей
class Field
{
    string playerName;
    int space[10][10];
    
public:
    
    //Метод определения, пустая ли клетка поля
    bool isEmpty(int x, int y)
    {
        return this->space[x][y] == 0;
    }
    
    //Метод для заполнения клетки. Используется при расстановке кораблей
    void Add(int x, int y)
    {
       this->space[x][y] = 1;
       return 0;
    }
    
    //Метод проверки, было ли ранее атаковано поле
    bool isAttacked(int x, int y)
    {
        if (this->space[x][y] == 2)
            return 1;
        else 
            return 0;
    }
    
    //Метод атаки на заданное поле
    int Attack(int x, int y)
    {
        int result = 0;
        if (this->space[x][y] == 1)
            result = 1;
        this->space[x][y] == 2;
        return result;
    }
};

int main()
{
    return 0;
}


