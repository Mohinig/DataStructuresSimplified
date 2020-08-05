#include<vector>
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
	vector<int> q;
public:
	PriorityQueue() {

	}
	bool isEmpty() {
		return q.size() == 0;
	}
	int getSize() {
		return q.size();
	}
	int getMin() {
		if (isEmpty()) {
			return 0;
		}
		return q[0];
	}
	void insert(int element) {
		int temp;
		q.push_back(element);
		int childIndex = q.size() - 1;
		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;
			if (q[childIndex] < q[parentIndex]) {
				temp = q[childIndex];
				q[childIndex] = q[parentIndex];
				q[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}
	int removeMin() {
		int temp;
		if (isEmpty()) {
			return 0;
		}
		int x = q[0];
		q[0] = q[q.size() - 1];
		q.pop_back();
		int rootIndex = 0;
		int leftIndex = 2 * rootIndex + 1;
		int rightIndex = 2 * rootIndex + 2;
		while (leftIndex < q.size()) {

			int minIndex = rootIndex;
			if (q[rightIndex] < q[minIndex] && rightIndex < q.size()) {
				minIndex = rightIndex;
			}
			if (q[leftIndex] < q[minIndex]) {
				minIndex = leftIndex;
			}
			if (minIndex == rootIndex) {
				break;
			}
			temp = q[minIndex];
			q[minIndex] = q[rootIndex];
			q[rootIndex] = temp;
			rootIndex = minIndex;
			leftIndex = 2 * rootIndex + 1;
			rightIndex = 2 * rootIndex + 2;
		}
		return x;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	PriorityQueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);
	cout << p.getSize() << endl;
	while (!p.isEmpty()) {
		cout << p.removeMin() << " ";
	}
	cout << endl;
	return 0;
}