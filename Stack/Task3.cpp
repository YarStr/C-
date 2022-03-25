#include <iostream>
#include <vector>
using namespace std;

struct Node 
{
    int data;
    Node* pNext;
};

class verStack
{
public:
    verStack()
    {
        pTail = nullptr;
        versions = new Node*[30];
        currentVersion = 0;
    };

    ~verStack()
    {
        Node* pTemp = pTail;
        while (pTemp != nullptr)
        {
            Node* pDeleteNode = pTemp;
            pTemp = pTemp->pNext;
            delete pDeleteNode;
        }
        delete[] versions;
    };

    //Сложность - O(n), где n = currentVersion
    void addVersion()
    {
        if (currentVersion == 29)
        {   
            Forget();
            currentVersion = -1;
        }
        
        ++currentVersion;
        versions[currentVersion] = pTail;
    }

    //Сложность - O(n), где n = currentVersion
    void Forget()
    {
        versions[0] = versions[currentVersion]; 
        currentVersion = 0;
    }

    //Сложность сводится к сложности addVersion, т.е. O(n), где n = currentVersion
    void push(int data)
    {
        Node* pNode = new Node();
        pNode->data = data;

        if (pTail == nullptr)
        {
            pTail = pNode;
            pTail->pNext = nullptr;
            addVersion();
            --currentVersion;
            return;
        }

        pNode->pNext = pTail;
        pTail = pNode;

        addVersion();
    };

    //Сложность сводится к сложности addVersion, т.е. O(n), где n = currentVersion
    void pop() 
    {
        if (pTail == nullptr)
            return;

        pTail = pTail->pNext;
        addVersion();
    };

    //Сложность - O(1)
    int back()
    {
        return pTail->data;
    };

    //Сложность - O(n+m), где n = currentVersion, m = ver
    bool Rollback(int ver)
    {
        if (ver > currentVersion || ver < 0)
        {
            cout << "ERROR! Incorrect version!" << endl;
            return false;
        }
        pTail = versions[ver];
        addVersion();
        
        return true;
    }
    
private:
    Node* pTail; 
    Node** versions;
    int currentVersion; 
};

int main()
{
    return 0;
}
