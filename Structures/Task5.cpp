#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string value;
    int wins;
};

int Game(string firstVal, string secondVal)
{
    if (firstVal == "stone"){
        if (secondVal == "scissors") return 1;
		if (secondVal == "paper") return 0;
    }
    
    if (firstVal == "scissors"){
        if (secondVal == "stone") return 0;
		if (secondVal == "paper") return 1;
    }
    
    if (firstVal == "paper"){
        if (secondVal == "scissors") return 0;
		if (secondVal == "stone") return 1;
    }
    
    return 0;
}


int main()
{
    Student mas[4];
    
    mas[0] = { "John", "stone", 0 };
    mas[1] = { "Mary", "scissors", 0 };
    mas[2] = { "Alice", "paper", 0 };
    mas[3] = { "Tomas", "stone", 0 };
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            
            if (i == j) continue;
            else
            {
                string firstVal = mas[i].value;
                string secondVal = mas[j].value;
                mas[i].wins += Game(firstVal, secondVal);
                mas[j].wins += Game(secondVal, firstVal);
            }
        }
    }
    
    int maxWins = mas[0].wins;
    int winner = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (maxWins <= mas[i].wins)
        {
            maxWins = mas[i].wins;
            winner = i;
        }
    }
    
    cout << "Победитель - " << mas[winner].name
    << " с кол-вом побед: " << mas[winner].wins/2 << endl;
    
    return 0;
}
