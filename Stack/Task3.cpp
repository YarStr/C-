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
    };

    void push(int data)
    {
        Node* pNode = new Node();
        pNode->data = data;

        if (pTail == nullptr)
        {
            pTail = pNode;
            pTail->pNext = nullptr;
            versions.push_back(pTail);
            return;
        }

        pNode->pNext = pTail;
        pTail = pNode;

        versions.push_back(pTail);
    };

    void pop()
    {
        if (pTail == nullptr)
            return;

        pTail = pTail->pNext;
        
        versions.push_back(pTail);
    };

    int back()
    {
        return pTail->data;
    };

    bool Rollback(int ver)
    {
        if (ver >= versions.size() || ver < 0)
        {
            cout << "ERROR! Incorrect version!" << endl;
            return false;
        }
        pTail = versions[ver];
        versions.push_back(pTail);
        
        return true;
    }

    void Forget()
    {
        Node* pTemp = versions[versions.size() - 1];
        //for (int i = 0; i < versions.size(); ++i)
        //   delete versions[i];
        versions.clear();
        versions.push_back(pTemp);
    }
    
private:
    Node* pTail; 
    vector<Node*> versions;
};

int main()
{
    /*
    verStack Test;
    Test.push(1);
    Test.push(2);
    Test.push(3);
    Test.pop();
    Test.pop();
    Test.push(1);

    Test.Rollback(2);
    Test.push(1);
    
    Test.Rollback(6);
    
    cout << Test.back() << endl;
    Test.Forget();
    cout << Test.back() << endl;
    Test.Rollback(1);
    */
    return 0;
}
