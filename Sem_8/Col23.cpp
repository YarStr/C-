#include <iostream>;
using namespace std;

/*
Col23. Дан массив целых чисел длины N,
упорядоченный строго по возрастанию, и целое число X.
Найти в массиве любые два различных элемента с суммой X,
совершая при этом менее квадратичного числа операций
(то есть быстрее, чем перебор всех пар элементов).
Запрещается использовать встроенные коллекции (Dictionary, HashSet и т.п.)
*/

int main()
{
    int diff;
    int flag = 0;
    int X = 34;
    int mas[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 } ;

    for (int i = size(mas) - 1; i >= 0; --i) {
        diff = X - mas[i];
        if ( diff >= 0 && mas[i] * 2 >= X ) {
            for (int j = 0; j < i; ++j) {
                if (mas[j] == diff) {
                    cout << mas[j] << " " << mas[i] << endl;
                    flag = 1;
                    break;
                } 
            }
            if (flag) { break; }
        }
    }
}
