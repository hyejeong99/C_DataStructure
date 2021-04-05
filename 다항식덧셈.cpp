#include<iostream>
using namespace std;
struct Node { //노드 생성
	int coef; //차수
	int expon; //계수
	Node *link; //다음 노드 주소를 가리키는
};
//연결 리스트 헤더
struct List_Header {
	int size;
	Node *head; //시작
	Node *tail; //끝
};
//연결 리스트 헤더 생성
//초기화 함수
List_Header *create() {
	List_Header *plist = (List_Header*)malloc(sizeof(List_Header)); //동적메모리할당 //plist는 연결 리스트 헤더 가리키는 포인터
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//리스트 생성 함수
void insert_last(List_Header *plist, int coef, int expon) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) cout << "메모리 할당에러" << endl;
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL; //마지막 공간에 NULL
	if (plist->tail == NULL) {//받은 list가 비어있다면
		plist->head = plist->tail = temp;
	}
	else {//받은 list에 이미 값이 있다면
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;//list 길이 추가

}
//다항식 덧셈 수행하는 함수
void add(List_Header *plist1, List_Header* plist2, List_Header* plist3) {
	Node *A = plist1->head;
	Node *B = plist2->head;
	
	while (A&&B) {//A나B가 NULL을 가리키기 전까지
		if (A->expon == B->expon) { //A차수=B차수
			int sum = A->coef + B->coef;
			if (sum != 0) {
				insert_last(plist3, sum, A->expon);
				A = A->link;
				B = B->link; //A와B 모두 다음 칸으로
			}
		}
		else if((A->expon) > (B->expon)){ //A차수>B차수
			insert_last(plist3, A->coef, A->expon);
			A = A->link; //A만 다음 칸으로 옮김
		}
		else{ //A차수<B차수
			insert_last(plist3, B->coef, B->expon);
			B = B->link; //B만 다음 칸으로 옮김
		}
	}
	//A나 B중 하나가 먼저 끝날 때
	for (; A != NULL; A = A->link)
		insert_last(plist3, A->coef, A->expon);
	for (; B != NULL; B = B->link)
		insert_last(plist3, B->coef, B->expon);
}
//결과 출력
void print(List_Header* plist) {
	Node* p = plist->head;
	cout << "다항식:";
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	cout << endl;
}
int main() {
	List_Header *list1, *list2, *list3;
	//연결리스트 헤더 생성
	list1=create();
	list2=create();
	list3=create();
	
	//다항식1
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	//다항식2
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	//다항식1, 다항식2 출력
	print(list1);
	print(list2);
	//다항식3=다항식1+다항식2
	add(list1, list2, list3);
	print(list3);
	delete list1; delete list2; delete list3;
}
