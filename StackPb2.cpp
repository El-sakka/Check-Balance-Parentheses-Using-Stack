// cheak if paranthses is Balanced or not
#include <bits/stdc++.h>
using namespace std;
/*	solution
 * 	scan string from left to right
 * 	if openning parantheses push it to stack
 * 	else if closing parantheses check
 * 		top of stack matches current closing or not
 * 		if no return false
 * 		if yes return true	 and pop from stack
 * 	should end up with empty stack
 */
bool AllPair(char p1, char p2) {
	if (p1 == '(' && p2 == ')')
		return true;
	else if (p1 == '{' && p2 == '}')
		return true;
	else if (p1 == '[' && p2 == ']')
		return true;
	return false;
}

bool CheckBalace(string exp) {
	stack<char> s;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (s.empty() || !AllPair(s.top(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return (s.empty()) ? true : false;
}

int main() {
	string  exp;
	cin>>exp;
	(CheckBalace(exp))?cout<<"YES\n":cout<<"NO\n";

	return 0;
}
