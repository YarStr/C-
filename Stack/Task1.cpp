#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int priority(string symb)
{
    if (symb == "(" || symb == ")"){
        return 1;
    }
    else if (symb == "+" || symb == "-"){
        return 2;
    }
    else if (symb == "*" || symb == "/"){
        return 3;
    }
    else if (symb == "^"){
        return 4;
    }
    else return 0;
}

string operation(string charA, string charB, string symb)
{
    int a = stoi(charA);
    int b = stoi(charB);
    
    if (symb == "+"){
        return to_string(a+b);
    }
    else if (symb == "-"){
        return to_string(a-b);
    }
    else if (symb == "*"){
        return to_string(a*b);
    }
    else if (symb == "/"){
        return to_string(a/b);
    }
    return to_string(pow(a,b));
}

int main() {  
    string input = "(2+3)^2-(6+8)/2";
    cout << "• Input expression: " << input << endl;

    string output = "";
    stack<string> Stack;

    for (int i = 0; i < input.length(); ++i){
    	string symb = "";
        symb += input[i];
    
        if (symb == " ")
            continue;
             
    	else if (priority(symb) == 0)
    		output += symb;
            
    	else if (symb == "(")
    		Stack.push("(");
        
    	else if (symb == ")")
            while (Stack.top() != "(")
            {
    			output += Stack.top();
                Stack.pop();
            }
            
    	else
        {
    		while (priority(symb) <= priority(Stack.top()))
            {
    			output += Stack.top();
                Stack.pop();
            }
    		Stack.push(symb);
    	}
    }
    
    while (!Stack.empty())
    {
        if (Stack.top() != "(")
            output += Stack.top();
        Stack.pop();
    }

    cout << endl;
    cout << "• Output expression: "  << output << endl;

    for (int i = output.size()-1; i >= 0; --i)
    {
        string symb = "";
        symb += output[i];
        Stack.push(symb);
    }
    
    stack<string> TempStack;
    while (!Stack.empty())
    {
        string symb = Stack.top();
        Stack.pop();
        
        if (priority(symb) == 0)
            TempStack.push(symb);
        
        else 
        {
            string tempB = TempStack.top();
            TempStack.pop();
            string tempA = TempStack.top();
            TempStack.pop();
            
            TempStack.push(operation(tempA, tempB, symb));
        }
    }

    cout << endl;
    cout << "• Result: " << TempStack.top() << endl;
}
