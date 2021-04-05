#include <iostream>
using namespace std;

class Node {
public:
	int score;
	Node *link;


};

Node *Head = NULL;

void insert_at_rear(Node *new_node) { //들어온 순서대로
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		//마지막 노드를 찾고, 그 뒤에 새로운 노드 연결
		Node *list = Head;
		while (list->link != NULL) {
			list = list->link;

		}
		list->link = new_node;

	}
}

void insert_node_at_front(Node *new_node) { //역순으로
	new_node->link = Head;
	Head = new_node;
}
void CircularListFront(Node *new_node) { //역순으로
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
	}
}
void CircularListRear(Node *new_node) { //역순으로
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


Node *MakeNewNode(int score) {//노드를 하나 동적 할당, 값 초기화
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

void CprintNodes() {//원형리스트의 모든 노드 출력
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
void deleteCNode(int score) {//30이란 값을 갖는 노드의 다음 노드를 삭제
	
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
	int std_num; //학생수
	cout << "Student Number:";
	cin >> std_num;
	int sum = 0;
	for (int i = 0; i < std_num; i++)
	{
		int score;
		cout << "Student #" << i + 1 << " : ";
		cin >> score;

		//노드 생성, 연결리스트에 추가
		new_node = MakeNewNode(score);
		//CircularListFront(new_node);		
		CircularListRear(new_node);

	}

	CprintNodes();
	cout << "**AFTER DELETION**" << endl;
	deleteCNode(30);//30이란 값을 갖는 노드 삭제
	CprintNodes();

}