#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{ 
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string str;
    
    while (!inputFile.eof())
    {
        getline(inputFile, str);
        string elem;
        int mas[255];
        int masLength = 0;

        //Получение массива из строки файла
        for (int i = 0; i < size(str); ++i) {
            if (str[i] != ' ') {
                elem += str[i];
            }
            else {
                mas[masLength] = stoi(elem);
                ++masLength;
                elem = "";
            }  
        }
        mas[masLength] = stoi(elem);
        ++masLength;

        //Сортировка пузырьком элементов массива по возрастанию
        for (int i = 0; i < masLength; ++i) {
            for (int j = 0; j < masLength - i - 1; ++j) {
                if (mas[j] < mas[j + 1]) {
                    swap(mas[j], mas[j + 1]);
                }
            }
        }

        //Проверка, могут ли элементы быть членами арифм. прогрессии
        int check = 1;
        int compare = mas[1] - mas[0];
        for (int i = 1; i < masLength - 1; ++i) {
            if (mas[i + 1] - mas[i] != compare) {
                check = 0;
                break;
            }
        }
        
        //Запись строки, если она удовлетворяет условию
        if (check == 1 && masLength > 1) {
            outputFile << str << '\n';
        }
    }

    inputFile.close();
    outputFile.close();
}
