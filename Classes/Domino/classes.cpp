#include <iostream>
#include <string>
using namespace std;

//Класс, описывающий игральную кость
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
    
    //Значения на краях игральной кости. Для упрощения логики названы "левым" и "правым" 
    int leftValue;
    int rightValue;
    
    //Метод, устанавливающий, равно ли какое-нибудь значение на кости заданному
    bool IsEquals(int value)
    {
        if (this->leftValue == value or this->rightValue == value)
            return 1;
        return 0;
    }
};

//Класс Игрок, хранящий информацию об имени игрока, массив костей у него на руках и их кол-во
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
    Dice dices[21] = { Dice() }; //Максимальное кол-во костей на руках - 21, т.к. каждый игрок берёт по 7, а всего их 28
    
    //Сумма очков со всех костей на руках игрока. Подсчитывается при завершении раунда.
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

//Класс, описывающий так назывемый "Базар" - раздаточные кости домино, которые игроки добирают к себе в руку
class Market
{
    
public:
    int numberOfDices = 28;
    Dice dices[28] = { Dice() };  //При начале игры костей максимальное кол-во - 28, из которого потом раздаются кости
    
    //Метод, описывающий взятие игроком кости из "базара"
    void getDice(Player P)
    {
        P.numberOfDices += 1;
        P.dices[numberOfDices] = this->dices[this->numberOfDices];
        this->numberOfDices -= 1;
    };
};

//Класс, описывающий игровое поле. Т.к. кости складываются в один ряд, то хранит лишь левое и правое крайние значения
//из горизонтального ряда рзложенных костей домино.
class Board
{
    
public:    
    int leftValue;
    int rightValue;
    
    //Метод, определяющий, может ли игрок ходить с текущим набором костей на руке
    bool CanMove(Player P)
    {
        for (int i = 0; i < P.numberOfDices; ++i){
            if (P.dices[i].IsEquals(this->leftValue) or P.dices[i].IsEquals(this->rightValue))
                return 1;
        }
        return 0;
    }
    
    //Метод, устанавливающий кость домино на поле 
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


