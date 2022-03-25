#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>

using namespace std;

auto iteratorOfMax(vector<int>& vec, int number)
{
    int max = -1;
    auto it = vec.begin();
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (*i < number && *i > max){
            max = *i;
            it = i;
        }
    }

    if (max == -1)
        it = max_element(vec.begin(), vec.end());

    return it;
}

void doPermutation(vector<int>& vec, int n)
{
    srand(time(NULL));
    
    for (int i = 1; i <= n; ++i)
    {
        int num = rand() % n + 1;
        while (find(vec.begin(), vec.end(), num) != vec.end())
            num = rand() % n + 1;
        vec.push_back(num);        
    } 
}

void doGame(vector<int>& vec)
{
    stack<int> palm;
        
    auto it = vec.begin();
    int number = *it;
    
    for (int i = 0; i < 3; ++i)
    {
        palm.push(*(it + 1));
        vec.erase(it + 1);
    }
    
    it = iteratorOfMax(vec, number) + 1;

    for (int i = 0; i < 3; ++i)
    { 
        vec.insert(it, palm.top());
        palm.pop();
    }

    for (int i : vec)
        cout << i << " ";
    cout << endl;

    auto it_end = vec.end() - 1;
    for (int i = 0; i < distance(it, vec.end()) - 3; ++i)
    {
        vec.insert(vec.begin(), *it_end);
        vec.erase(it_end + 1); 
        it_end = vec.end() - 1;
    }
}

int main() {
    cout << "• Введите n: ";
    int n;
    cin >> n;

    vector<int> permutation;
    doPermutation(permutation, n);

    cout << "Исходная перестановка: ";
    for (int i : permutation)
        cout << i << " ";
    cout << endl;

    cout << "• Введите m: ";
    int m;
    cin >> m;

    for (int j = 0; j < m; ++j)
    {
        cout << "Положение после " << j + 1 << " прохода алгоритма: ";
        doGame(permutation);
    }
    return 0;
}
