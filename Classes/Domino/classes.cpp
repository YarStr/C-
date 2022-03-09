#include <iostream>
#include <string>
using namespace std;

class Dice 
{
  
public:
    Dice():
        leftValue(0),
        rightValue(0)
    {
    }
    
    Dice(int leftValue, int rightValue):
        leftValue(leftValue),
        rightValue(rightValue)
    {
    }
    
    int leftValue;
    int rightValue;
    
    bool IsEquals(int value)
    {
        if (this->leftValue == value or this->rightValue == value)
            return 1;
        return 0;
    }
};

class Player
{
  
public:
    Player(string name, int numberOfDices):
        name(name),
        numberOfDices(numberOfDices)
    {
    }
    
    string name;
    int numberOfDices;
    Dice dices[21] = { Dice() };
    
    int sumOfDiceValues()
    {
        int sum = 0;
        for (int i = 0; i < this->numberOfDices; ++i)
        {
            sum += this->dices[i].leftValue + this->dices[i].rightValue;
        }
        return sum;
    };
};

class Market
{
    
public:
    int numberOfDices = 28;
    Dice dices[28] = { Dice() };
    
    void getDice(Player P)
    {
        P.numberOfDices += 1;
        P.dices[numberOfDices] = this->dices[this->numberOfDices];
        this->numberOfDices -= 1;
    };
};

class Board
{
    
public:    
    int leftValue;
    int rightValue;
    
    bool CanMove(Player P)
    {
        for (int i = 0; i < P.numberOfDices; ++i){
            if (P.dices[i].IsEquals(this->leftValue) or P.dices[i].IsEquals(this->rightValue))
                return 1;
        }
        return 0;
    }
    
    void SetDice(Dice D, string side)
    {
        if (side == "left"){
            if (D.leftValue == this->leftValue){
                this->leftValue = D.rightValue;
            }
            else {
                this->leftValue = D.leftValue;
            }
        }
        else {
            if (D.leftValue == this->rightValue){
                this->rightValue =  D.rightValue;
            }
            else {
                this->rightValue = D.leftValue;
            }
        }
        
    }
};



int main()
{
    return 0;
}


