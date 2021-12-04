#include <iostream>
using namespace std;

int main() {
    int arr1[] = { 1, 2, 4, 6 };
    int arr2[] = { 4, 5, 1, 45, 32, 2, 5, 7, 4, 7, 6 };
    
    int len1 = size(arr1);
    int len2 = size(arr2);

    int flag1 = 0;
    int flag2 = 0;
    
    while (flag1 < len1 && flag2 != len2){
        for (int j = flag2; j < len2; ++j){
            if (arr1[flag1] == arr2[j]){
                flag1 += 1;
                flag2 = j+1;
                break;
            }
            if (j == len2 - 1){
                flag2 = len2;
            }
        }
    }
    
    if (flag1 == len1){
        cout << "Входит" << endl;
    }
    else {
        cout << "Не входит" << endl; 
    }
}
