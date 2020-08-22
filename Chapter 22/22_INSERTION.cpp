#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>

/*
//MY
void insertionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		//A[0..i-1]�� A[i]�� �����ִ´�.
		int j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			//�Һ��� a:A[j+1..i]�� ��� ���Ҵ� A[j]���� ũ��
			//�Һ��� b:A[0..i] ������ A[j]�� �����ϸ� ���ĵǾ� �ִ�
			swap(A[j - 1], A[j]);
			--j;
		}
	}
}
*/


/*
int N;
int A[50000];
int B[50000];	//idx

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			B[i] = i;
		}
		for (int i = 1; i < N; i++) {
			int k = i;
			for (int j = 0; j < A[i]; j++) {
				swap(B[k], B[k - 1]);
				--k;
			}
		}
		for (int i = 0; i < N; i++) {
			A[B[i]] = i;
		}
		for (int i = 0; i < N; i++) {
			cout << A[i] + 1 << ' ';
		}
	}
	return 0;
}
*/

//ANS
typedef int KeyType;
//Ʈ���� �� ��带 �����Ѵ�.
struct Node {
	//��忡 ����� ����
	KeyType key;
	//�� ����� �켱����(priority)
	//�� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ũ��(size)
	int priority, size;
	//�� �ڽ� ����� ������
	Node* left, * right;
	//�����ڿ��� ���� �켱������ �����ϰ�, size�� left/right�� �ʱ�ȭ
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	//size����� ����
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;
//root�� ��Ʈ�� �ϴ� Ʈ���� key�̸��� ���� �̻��� ���� ����
//�� ���� Ʈ������ �и�
NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	//��Ʈ�� key�̸��̸� ������ ����Ʈ���� �ɰ���.
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	//��Ʈ�� key �̻�̳� ���� ����Ʈ���� �ɰ���.
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
//root�� ��Ʈ�� �ϴ� Ʈ���� �� ��� node�� ������ �� ��� Ʈ����
//��Ʈ�� ��ȯ�Ѵ�.
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	//node�� ��Ʈ�� ��ü�ؾ� �Ѵ�.
	//�ش� ����Ʈ���� ������ �߶� ���� �ڼ����� �Ѵ�.
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

//a�� b�� �� ���� Ʈ���̰�, max(a) < min(b)�� �� �� ���� ��ģ��.
Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

//root�� ��Ʈ�� �ϴ� Ʈ������ key�� ����� ��� Ʈ���� ��Ʈ�� ��ȯ
Node* erase(Node* root, KeyType key) {
	if (root == NULL) return root;
	//root�� ����� �� ����Ʈ���� ��ģ �� ��ȯ�Ѵ�.
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

Node* kth(Node* root, int k) {
	//���� ����Ʈ���� ũ�⸦ ���
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1)return root;
	return kth(root->right, k - leftSize - 1);
}

int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}

//shifted[i] =A[i]�� �������� �� ĭ �����̴°�?
int n, shifted[5000];
int A[50000];
//n, shifted[]�� ���� A[]�� ���� �����Ѵ�.
void solve() {
	//1~N������ ���ڸ� ��� �����ϴ� Ʈ���� �����.
	Node* candidates = NULL;
	for (int i = 0; i < n; i++) 
		candidates = insert(candidates, new Node(i + 1));
	//�ڿ������� A[]�� ä��������.
	for (int i = n - 1; i >= 0; i--) {
		//�ĺ� �� �� ������ ū ���� larger�� �ִ�.
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		candidates = erase(candidates, k->key);
	}	
}

int main() {
	int C;
	cin >> C;
	
	for (int c = 0; c < C; c++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> shifted[i];
		}
		solve();
		for (int i = 0; i < n; i++) {
			cout << A[i]<< ' ';
		}
		cout << endl;
	}
	return 0;
}