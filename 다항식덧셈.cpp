#include<iostream>
using namespace std;
struct Node { //��� ����
	int coef; //����
	int expon; //���
	Node *link; //���� ��� �ּҸ� ����Ű��
};
//���� ����Ʈ ���
struct List_Header {
	int size;
	Node *head; //����
	Node *tail; //��
};
//���� ����Ʈ ��� ����
//�ʱ�ȭ �Լ�
List_Header *create() {
	List_Header *plist = (List_Header*)malloc(sizeof(List_Header)); //�����޸��Ҵ� //plist�� ���� ����Ʈ ��� ����Ű�� ������
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//����Ʈ ���� �Լ�
void insert_last(List_Header *plist, int coef, int expon) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) cout << "�޸� �Ҵ翡��" << endl;
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL; //������ ������ NULL
	if (plist->tail == NULL) {//���� list�� ����ִٸ�
		plist->head = plist->tail = temp;
	}
	else {//���� list�� �̹� ���� �ִٸ�
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;//list ���� �߰�

}
//���׽� ���� �����ϴ� �Լ�
void add(List_Header *plist1, List_Header* plist2, List_Header* plist3) {
	Node *A = plist1->head;
	Node *B = plist2->head;
	
	while (A&&B) {//A��B�� NULL�� ����Ű�� ������
		if (A->expon == B->expon) { //A����=B����
			int sum = A->coef + B->coef;
			if (sum != 0) {
				insert_last(plist3, sum, A->expon);
				A = A->link;
				B = B->link; //A��B ��� ���� ĭ����
			}
		}
		else if((A->expon) > (B->expon)){ //A����>B����
			insert_last(plist3, A->coef, A->expon);
			A = A->link; //A�� ���� ĭ���� �ű�
		}
		else{ //A����<B����
			insert_last(plist3, B->coef, B->expon);
			B = B->link; //B�� ���� ĭ���� �ű�
		}
	}
	//A�� B�� �ϳ��� ���� ���� ��
	for (; A != NULL; A = A->link)
		insert_last(plist3, A->coef, A->expon);
	for (; B != NULL; B = B->link)
		insert_last(plist3, B->coef, B->expon);
}
//��� ���
void print(List_Header* plist) {
	Node* p = plist->head;
	cout << "���׽�:";
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	cout << endl;
}
int main() {
	List_Header *list1, *list2, *list3;
	//���Ḯ��Ʈ ��� ����
	list1=create();
	list2=create();
	list3=create();
	
	//���׽�1
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	//���׽�2
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	//���׽�1, ���׽�2 ���
	print(list1);
	print(list2);
	//���׽�3=���׽�1+���׽�2
	add(list1, list2, list3);
	print(list3);
	delete list1; delete list2; delete list3;
}
