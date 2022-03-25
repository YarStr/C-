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
    
    stack<int> palm;
    for (int j = 0; j < m; ++j)
    {
        cout << "Положение после " << j+1 << " прохода алгоритма: ";
        
        auto it = permutation.begin();
        int number = *it;
        
        for (int i = 0; i < 3; ++i)
        {
            palm.push(*(it + 1));
            permutation.erase(it + 1);
        }
        
        it = iteratorOfMax(permutation, number) + 1;
    
        for (int i = 0; i < 3; ++i)
        { 
            permutation.insert(it, palm.top());
            palm.pop();
        }
    
        for (int i : permutation)
            cout << i << " ";
        cout << endl;

        auto it_end = permutation.end() - 1;
        for (int i = 0; i < distance(it, permutation.end()) - 3; ++i)
        {
            permutation.insert(permutation.begin(), *it_end);
            permutation.erase(it_end + 1); 
            it_end = permutation.end() - 1;
        }
    }
    
    return 0;
}
