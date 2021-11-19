#include <iostream>
#include <cstring>
using namespace std;

void palindrome(string a) {
	int length = a.length();
	bool b=1;
	if (length <= 1) { cout << "YES" << endl; }
	else if(a[0] == a[length-1])
		{
		a = a.substr(1, (length - 2));
		palindrome(a);
		}
	else {cout << "NO" << endl;
	}

}


int main()
{
	string str = "";
	cin >> str;
	//int len = str.length();
	//cout << len << endl;
	palindrome(str);
}


