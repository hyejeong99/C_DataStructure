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
void inorder(TNode *root) {//중위순회
	if (root == NULL) return;
	inorder(root->left);
	/*if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
	cout << (char)root->data << " ";
	else*/ cout << root->data << " ";
	inorder(root->right); //중위순회
}
void preorder(TNode *root) {//전위순회
	if (root == NULL) return;
	if (root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')
		cout << (char)root->data << " ";
	else cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(TNode *root) {//후위순회
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
	//탐색을 통해, value 값을 갖는 노드가 있는지 검색
	while (node != NULL) {
		if (node->data == value) return; //일단 탈출
		parent = node;
		if (node->data < value) node = node->right;
		else node = node->left;
	}
	//없는 경우에 한해, 새로운 노드 추가
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
	//value 값을 가진 노드 탐색
	TNode *parent, *node;
	node = root;
	parent = NULL;
	//탐색을 통해, value 값을 갖는 노드가 있는지 검색
	while (node != NULL) {
		if (node->data == value) break; //일단 탈출
		parent = node;
		if (node->data < value) node = node->right;
		else node = node->left;
	}
	if (node == NULL) {//그런 값을 가진 노드가 없으면
		cout << "해당 노드가 없습니다." << endl;
		return;
	}
	//node가 가리키는 값을 삭제

	//경우 1:단말노드인 경우
	if (node->left == NULL&&node->right == NULL) {
		if (parent != NULL) {
			if (parent->left == node)parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;//유일한 노드인 경우, 삭제되염, 전체 트리는 NULL
	}
	//경우 2:한쪽 서브트리만 존재
	else if (node->left == NULL || node->right == NULL) {
		TNode *child;
		if (node->left == NULL) child = node->right;
		else child = node->left;

		if (parent != NULL)
		{	// 부모노드와 연결
			if (parent->left == node) parent->left = child;
			else parent->right = child;
		}
		else root = child;//

	}
	//경우 3
	else {
		TNode *succ_p = node;
		TNode *succ = node->right;

		// 후계자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		//succ는 node의 오른쪽 서브트리 중 제일 작은 값을 가리킴
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