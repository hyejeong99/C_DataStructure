#include <iostream>
using namespace std;
typedef int element;
class TNode {
public:
	element data;
	TNode *left, *right;
	TNode(element value) {
		data = value;
		left = NULL; right = NULL;
	}
	TNode(element value, TNode *i, TNode *r) {
		data = value;
		left = i; right = r;
	}
};
void inorder(TNode *root) {//������ȸ
	if (root == NULL) return;
	inorder(root->left);
	/*if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
	cout << (char)root->data << " ";
	else*/ cout << root->data << " ";
	inorder(root->right); //������ȸ
}
void preorder(TNode *root) {//������ȸ
	if (root == NULL) return;
	if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
		cout << (char)root->data << " ";
	else cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(TNode *root) {//������ȸ
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
		cout << (char)root->data << " ";
	else cout << root->data << " ";
}
int evaluate(TNode *root) {
	if (root == NULL) return 0;
	if (root->left == NULL&&root->right == NULL) return root->data;
	int opr1 = evaluate(root->left);
	int opr2 = evaluate(root->right);
	if (root->data == '+')return opr1 + opr2;
	if (root->data == '-')return opr1 - opr2;
	if (root->data == '*') return opr1*opr2;
	if (root->data == '/') return opr1 / opr2;
}
TNode *root = NULL;
void insertNode(element value) {
	TNode *parent, *node;
	node = root;
	parent = NULL;
	//Ž���� ����, value ���� ���� ��尡 �ִ��� �˻�
	while (node != NULL) {
		if (node->data == value) return; //�ϴ� Ż��
		parent = node;
		if (node->data < value) node = node->right;
		else node = node->left;
	}
	//���� ��쿡 ����, ���ο� ��� �߰�
	TNode *new_node = new TNode(value);
	if (parent != NULL) {
		if (parent->data < value) parent->right = new_node;
		else parent->left = new_node;
	}
	else {
		root = new_node;
	}
}
void deleteNode(element value) {
	//value ���� ���� ��� Ž��
	TNode *parent, *node;
	node = root;
	parent = NULL;
	//Ž���� ����, value ���� ���� ��尡 �ִ��� �˻�
	while (node != NULL) {
		if (node->data == value) break; //�ϴ� Ż��
		parent = node;
		if (node->data < value) node = node->right;
		else node = node->left;
	}
	if (node == NULL) {//�׷� ���� ���� ��尡 ������
		cout << "�ش� ��尡 �����ϴ�." << endl;
		return;
	}
	//node�� ����Ű�� ���� ����

	//��� 1:�ܸ������ ���
	if (node->left == NULL&&node->right == NULL) {
		if (parent != NULL) {
			if (parent->left == node)parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;//������ ����� ���, �����ǿ�, ��ü Ʈ���� NULL
	}
	//��� 2:���� ����Ʈ���� ����
	else if (node->left == NULL || node->right == NULL) {
		TNode *child;
		if (node->left == NULL) child = node->right;
		else child = node->left;

		if (parent != NULL)
		{	// �θ���� ����
			if (parent->left == node) parent->left = child;
			else parent->right = child;
		}
		else root = child;//

	}
	//��� 3
	else {
		TNode *succ_p = node;
		TNode *succ = node->right;

		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		//succ�� node�� ������ ����Ʈ�� �� ���� ���� ���� ����Ŵ
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else   succ_p->right = succ->right;

		node->data = succ->data;
		node = succ;

	}


}
void main() {

	insertNode(10);
	insertNode(40);
	insertNode(50);
	insertNode(20);
	insertNode(47);
	insertNode(60);
	insertNode(100);
	insertNode(80);
	insertNode(90);
	insertNode(87);
	insertNode(98);
	inorder(root);
	cout << endl;

	deleteNode(10);
	inorder(root);
	cout << endl;

	deleteNode(20);
	inorder(root);
	cout << endl;

	deleteNode(60);
	inorder(root);
	cout << endl;
}