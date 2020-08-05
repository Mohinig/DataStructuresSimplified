#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout << q.front() << endl;;
	q.pop();
	cout << q.size() << endl;
	cout << q.empty() << endl;
	return 0;
}