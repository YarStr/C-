#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!";
        return -1;
    }
    
    vector <int> nums;
    int temp;
    for (fin >> temp; !fin.eof(); fin >> temp)
        nums.push_back(temp);

    fin.close();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i)
        if (nums[i] - nums[i + 1] != nums[i + 1] - nums[i + 2])
        {
            cout << "No" << endl;
            return 0;
        }
    
    cout << "Yes" << endl;
    return 0;
}
