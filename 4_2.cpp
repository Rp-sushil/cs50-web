#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string exp;
	cin>>exp;
	stack<int> s;
	for(int i = 0; i < exp.length(); i++){
		
		if(exp[i] - '0' >= 0 && exp[i] - '0' <= 9){
			s.push(exp[i] - '0');
		}

		else {
			int v1 = s.top(); s.pop();
			int v2 = s.top(); s.pop();
			switch(exp[i]){
				case '+': s.push(v2 + v1); break;
				case '-': s.push(v2 - v1); break;
				case '*': s.push(v2 * v1); break;
				case '/': s.push(v2 / v1); break;
			}
		}
		
	}	
	cout<<s.top()<<endl;
	return 0;
}
