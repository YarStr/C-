#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* pNext;
};

class myQueue
{
public:
    myQueue()
    {
        counter = 0;
        pHead = nullptr;
        pTail = nullptr;
    };

    ~myQueue()
    {
        Node* pTemp = pHead;
        while (pTemp != nullptr)
        {
            Node* pDeleteNode = pTemp;
            pTemp = pTemp->pNext;
            delete pDeleteNode;
        }
    };

    void push(int data)
    {
        ++counter;
        
        Node* pNode = new Node();
        pNode->data = data;
        pNode->pNext = nullptr;

        if (pTail == nullptr)
        {
            pTail = pNode;
            pHead = pNode;
            return;
        }

        pTail->pNext = pNode;
        pTail = pNode;
    };

    void pop()
    {
        if (pHead == nullptr)
            return;

        Node* pTemp = pHead;
        pHead = pTemp->pNext;
        delete pTemp;
        --counter;
    };

    int front()
    {
        return pHead->data;
    };

    int back()
    {
        return pTail->data;
    };

    int size()
    {
        return counter;
    };
 
private:
    int counter;
    Node* pHead;
    Node* pTail; 
};

int main() {
    return 0;
}
