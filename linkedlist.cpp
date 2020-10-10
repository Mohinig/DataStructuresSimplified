#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		next = NULL;

	}
};
class Pair {
public:
	Node* head;
	Node* tail;
};
Node* takeInput() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1) {
		Node* newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
}
Node* insert(Node* head, int i, int data) {
	Node* newNode = new Node(data);
	Node* temp = head;
	int c = 0;
	if (i == 0) {
		newNode->next = head;
		head = newNode;
		return head;
	}
	while (c < i - 1 && temp != NULL) {
		temp = temp->next;
		c++;
	}
	if (temp != NULL) {
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return head;
}
Node* del(Node* head, int x) {
	Node* temp = head;
	int c = 0;
	if (x == 0) {
		head = temp->next;
		return head;
	}

	while (c < x - 1 && temp != NULL) {
		temp = temp->next;
		c++;
	}
	Node* temp1 = temp->next;
	temp->next = temp1->next;
	return head;
}
Pair reverse(Node* head) {
	if (head == NULL || head->next == NULL) {
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	Pair smallAns = reverse(head->next);
	smallAns.tail->next = head;
	head->next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}
Node* rev(Node* head) {
	return reverse(head).head;
}
void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;

	}
	cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//int i,data,x;
	//int l;
	Node* head = takeInput();
	print(head);
	/*cin>>i>>data;
	head=insert(head,i,data);
	cin>>x;
	head=del(head,x);
	print(head);*/
	head = rev(head);
	print(head);
}