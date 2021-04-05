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
		left = i;right = r;
	}
};
void inorder(TNode *root) {//중위순회
	if (root == NULL) return;
	inorder(root->left);
	if (root->data =='+'|| root->data == '-' || root->data == '*' || root->data == '/' ) 
		cout << (char)root->data << " ";
	else cout <<root->data << " ";
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
int evaluate(TNode*root) {
	if (root == NULL) return 0;
	if (root->left ==NULL&&root->right==NULL) return root->data;
	int opr1 = evaluate(root->left);
	int opr2 = evaluate(root->right);
	if (root->data == '+')return opr1 + opr2;
	if (root->data == '-')return opr1 - opr2;
	if (root->data == '*') return opr1*opr2;
	if (root->data == '/') return opr1 / opr2;
}
void main() {
	TNode *n1 = new TNode(3);
	TNode *n2 = new TNode(2);
	TNode *n3 = new TNode(15);
	TNode *n4 = new TNode(3);

	TNode *n5 = new TNode('*', n1, n2);
	TNode *n6 = new TNode('/', n3, n4);
	TNode *n7 = new TNode('+', n5, n6);
	TNode *root;
	root = n7;
	inorder(root);
	cout << "=" << evaluate(root) << endl;

	//preorder(root);
	//postorder(root);
}