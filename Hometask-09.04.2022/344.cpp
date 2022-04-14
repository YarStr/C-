#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Number
{
    int value;
    int order;
};

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!" << endl;
        return -1;
    }
    
    int n;
    fin >> n;

    vector <Number> nums;
    int val;
    for (int ord = 0; ord < n; ++ord)
    {
        fin >> val;
        Number tNumb = { val, ord+1 };
        nums.push_back(tNumb);
    }

    fin.close();

    sort(nums.begin(), nums.end(), [](Number a, Number b)
        {
            return a.value > b.value;
        });

    int Min = INT_MAX;
    Number answ[2];

    for (int i = 0; i < n - 1; ++i)
    {
        Number a = nums[i];
        Number b = nums[i + 1];
        int len = a.value - b.value;
        if (Min > len)
        {
            Min = len;
            answ[0] = a;
            answ[1] = b;
        }
        
        else if (Min == len)
        {
            if (min(answ[0].value, answ[1].value) > min(a.value, b.value))
            {
                answ[0] = a;
                answ[1] = b;
            }
        }
    }

    if (answ[0].value > answ[1].value)
    {
        Number temp = answ[0];
        answ[0] = answ[1];
        answ[1] = temp;
    }

    cout << Min << endl;
    for (Number i : answ)
        cout << i.order<< " ";
    cout << endl;
    
    return 0;
}
