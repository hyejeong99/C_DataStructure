#include <iostream>
using namespace std;

class Node {
public:
	int score;
	Node *link;


};

Node *Head = NULL;

void insert_at_rear(Node *new_node) { //���� �������
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		//������ ��带 ã��, �� �ڿ� ���ο� ��� ����
		Node *list = Head;
		while (list->link != NULL) {
			list = list->link;

		}
		list->link = new_node;

	}
}

void insert_node_at_front(Node *new_node) { //��������
	new_node->link = Head;
	Head = new_node;
}
void CircularListFront(Node *new_node) { //��������
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
	}
}
void CircularListRear(Node *new_node) { //��������
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node;
	}
}


Node *MakeNewNode(int score) {//��带 �ϳ� ���� �Ҵ�, �� �ʱ�ȭ
	Node *ptr;
	ptr = new Node();
	ptr->score = score;
	ptr->link = NULL;
	return ptr;
}

void printNodes() {
	for (Node *list = Head; list != NULL; list = list->link)
		cout << list->score << endl;

}

void CprintNodes() {//��������Ʈ�� ��� ��� ���
	if (Head == NULL)return;
	else {
		Node *ptr = Head;
		do {
			cout << ptr->link->score << endl;
			ptr = ptr->link;
		} while (ptr != Head);
	}

}

void removeCNode(Node *pre) {
	if (Head == NULL || Head->link == Head)
		Head = NULL;
	else {
		Node *removed = pre->link;
		pre->link = removed->link;
		if (Head == removed) Head = pre;
	}

}
void deleteCNode(int score) {//30�̶� ���� ���� ����� ���� ��带 ����
	
	if (Head == NULL)return;
	else {
		Node *ptr = Head;
		do {
		//	cout << ptr->link->score << endl;
			if (ptr->link->score == score) {
				removeCNode(ptr); return;
			}
			ptr = ptr->link;
		} while (ptr != Head);
	}
}


void findNode(int score) {
	for (Node *list = Head; list != NULL; list = list->link) {
		if (list->score == score)
			cout << "I Found it:" << list->score << endl;
		else
			cout << "I can't found it" << endl;
	}
}


void main()
{
	Node *new_node;
	int std_num; //�л���
	cout << "Student Number:";
	cin >> std_num;
	int sum = 0;
	for (int i = 0; i < std_num; i++)
	{
		int score;
		cout << "Student #" << i + 1 << " : ";
		cin >> score;

		//��� ����, ���Ḯ��Ʈ�� �߰�
		new_node = MakeNewNode(score);
		//CircularListFront(new_node);		
		CircularListRear(new_node);

	}

	CprintNodes();
	cout << "**AFTER DELETION**" << endl;
	deleteCNode(30);//30�̶� ���� ���� ��� ����
	CprintNodes();

}