#include <iostream>
#include <stack>
using namespace std;

int main(){
	string str;
	int cO = 0, cE = 0;
	stack<char> stack1;
	cin>>str;
	
	
	for (auto c : str)
		{
			if (c == '(' || c == '[' || c == '{')
				cO++;
			if (c == ')' || c == '}' || c == ']')
				cE++;
		}
	if (cO != cE)
		cout << "Скобки расставлены неверно" << endl;
	else{
		for (auto c : str) {
			if (c == '(' || c == '[' || c == '{')
				stack1.push(c);
			if (c == ')' || c == '}' || c == ']'){
				
				if (c == ')' && stack1.top() == '(')
					stack1.pop();
				else if (c == ']' && stack1.top() == '[')
					stack1.pop();
				else if (c == '}' && stack1.top() == '{')
					stack1.pop();
				else {
					cout << "Скобки расставлены неверно" << endl;
					exit(0);
				}
			}
		}
	};
	return 0;
}