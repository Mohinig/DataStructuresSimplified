#include<bits/stdc++.h>
using namespace std;
#include <stack>
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;
	return 0;
}