#include <iostream>
#include <string>
using namespace std;

//Класс, описывающий карту
class Card 
{
    
public:
    Card():
        suit("none"),
        value("none")
    {
    }
    
    Card(string suit, string value):
        suit(suit),
        value(value)
    {
    }
  
    //Информация о масти и величине карты
    string suit;
    string value;
    
    //Метод, сравнивающий масти карт
    bool isIdentSuits(Card anotherCard)
    {
        return this->suit == anotherCard.suit;
    };
    
    //Метод, определяющий, какая из карт "старше"
    bool isGreater(Card anotherCard)
    {
        string values[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
        int thisOrder, anotherOrder;
        
        for (int i = 0; i < 13; ++i)
        {
            if (values[i] == this->value)
                thisOrder = i;
            if (values[i] == anotherCard.value)
                anotherOrder = i;
        };
        
        return thisOrder > anotherOrder;
    };
};

//Класс Игрок, хранящий информацию об имени игрока, массив карт у него на руках и их кол-во
class Player
{
  
public:
    Player(string name, int numCards):
        name(name),
        numCards(numCards)
    {
    }
    
    string name;
    int numCards;
    Card cards[52] = { Card() }; 
};

//Класс колоды, содержащий в себе все карты и их кол-во
class Deck
{
    
public:
    int numCards = 52;
    Card cards[52] = { Card() };  
    
    //Метод, описывающий взятие игроком карты из колоды
    void getCard(Player P)
    {
        P.numCards += 1;
        P.cards[numCards] = this->cards[this->numCards];
        this->numCards -= 1;
    };
};

int main()
{
    return 0;
}



