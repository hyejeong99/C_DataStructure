#include <iostream>
using namespace std;

typedef int element;

class Node{
public:
	element data;
	Node *link;

	Node(element value){
		data=value;
		link=NULL;
	}
};
Node *StackPointer=NULL; 

bool is_empty(){
	if(StackPointer==NULL) return true;
	else return false;
}
void push(element value){
	Node *new_node=new Node(value);

	new_node->link=StackPointer;
	StackPointer=new_node;
}
element pop(){
	if(StackPointer==NULL){
		cout<<"STACK UNDERFLOW!!"<<endl;
		exit(-1);
	}
	else{
		element top_value=StackPointer->data;
		StackPointer=StackPointer->link;
		return top_value;
	}
}
element peek(){
	if(StackPointer==NULL){
		cout<<"STACK UNDERFLOW!!"<<endl;
		exit(-1);
	}
	else{
		return StackPointer->data;
	}
}
void printStack(){
	cout<<"###STACK ป๓ลย###"<<endl;
	for(Node *ptr=StackPointer; ptr!=NULL;ptr=ptr->link){
		cout<<ptr->data<<endl;
	}
	if(StackPointer==NULL){
		cout<<"STACK UNDERFLOW!!"<<endl;
		exit(-1);
	}
}
void main(){
	push(100);printStack();
	push(200);printStack();
	push(300);printStack();
	push(400);printStack();
	pop();printStack();
	push(500);printStack();
	pop();printStack();
	pop();printStack();
	pop();printStack();
	pop();printStack();
}