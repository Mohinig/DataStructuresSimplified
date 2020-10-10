#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};
BinaryTreeNode<int>* takeInput() {
	int rootdata;
	cin >> rootdata;
	if (rootdata == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while (pendingNode.size() != 0) {
		BinaryTreeNode<int>* front = pendingNode.front();
		pendingNode.pop();
		int leftchild;
		cin >> leftchild;
		if (leftchild != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchild);
			front->left = child;
			pendingNode.push(child);
		}
		int rightchild;
		cin >> rightchild;
		if (rightchild != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchild);
			front->right = child;
			pendingNode.push(child);
		}

	}
	return root;
}
void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL)
		cout << "L" << root->left->data << " ";
	if (root->right != NULL)
		cout << "R" << root->right->data << " ";
	cout << endl;
	printTree(root->left);

	printTree(root->right);
}

int count(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;
	return 1 + count(root->left) + count(root->right);
}
void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return ;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

pair<int, int> diameter(BinaryTreeNode<int>* root) {
	if (root = NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}


	pair<int, int> leftAns = diameter(root->left);
	pair<int, int> rightAns = diameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;
	int height = 1 + max(lh, rh);
	int dia = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = dia;
	cout << p.first << " " << p.second;
	return p;

}

void levelOrder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return;
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while ( pendingNode.empty() == false) {
		BinaryTreeNode<int>* front = pendingNode.front();
		cout << front->data << " " ;
		pendingNode.pop();
		if (front->left != NULL) {
			pendingNode.push(front->left);
		}
		if (front->right != NULL) {
			pendingNode.push(front->right);
		}

	}
}
int height(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	BinaryTreeNode<int>* root = takeInput();
	levelOrder(root);
	cout << endl;
	cout << height(root);
	//cout << count(root) << endl;
	//pair<int, int> p = diameter(root);
	//cout << p.second << endl;
	delete root;
	return 0;

}