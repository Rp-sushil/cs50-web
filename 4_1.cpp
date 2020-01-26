#include <iostream>
#include <stack>
using namespace std;


int pre(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    
    else if (ch == '*' || ch == '/')
        return 2;
    
    else if (ch == '^')
        return 3;

    else
        return 4;
}

int main()
{
    stack<char> s;
    string exp;
    cin >> exp;
    s.push('(');
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
            s.push(exp[i]);
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            if (s.top() == '(')
            {
                s.push(exp[i]);
            }
            else
            {
                char op = s.top();
                if (pre(op) < pre(exp[i]))
                {
                    s.push(exp[i]);
                }
                else
                {
		    if(exp[i] == '^'){
			    s.push(exp[i]);
		    	    continue;
			   }
		    char op = s.top();
                    s.pop();
                    s.push(exp[i]);
                    cout << op;
                }
            }
        }
        else if (exp[i] == ')')
        {
            char ch = s.top();
            while (ch != '(')
            {
                cout << ch;
                s.pop();
                ch = s.top();
            }
            s.pop();
        }
        else
        {
            cout << exp[i];
        }
       
    }
    char ch = s.top();
    while (ch != '(')
    {
        cout << ch;
        s.pop();
        ch = s.top();
    }
    return 0;
}
