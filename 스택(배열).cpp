#include <iostream>
using namespace std;
const int MAX_NUM = 100;
//#define MAX_NUM = 100;
typedef int element;

class Stack{
public:
	element data[MAX_NUM];
	int top; //마지막 원소를 가리키는 인덱스 

	Stack() {top=-1;} //초기화

	bool is_empty(){
		return(top==-1);
		//if(top==-1) return true;
		//else return false;
	}
	bool is_full(){
		return (top==MAX_NUM-1);
		//if(top==MAX_NUM-1) return true;
		//else return false;
	}
	void push(element value){
		if(is_full()){
			cout<<"STACK OVERFLOSW!!"<<endl;
		}
		else{
			data[++top]=value;
			//top++;
			//data[top]=value;
		}
	}
	element pop(){
		if(is_empty()){
			cout<<"STACK UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(data[top--]);
			//element x=data[top];
			//top--;
			//return (x);
		}
	}
	element peek(){
		if(is_empty()){
			cout<<"STACK UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(data[top]);
		}
	}
	void printStack(){
		cout<<"###STACK STATUS###"<<endl;
		for(int i=top;i>=0;i--)
			cout<<data[i]<<endl;
	}
};

void main(){
	Stack MyStack;

	MyStack.push(100);MyStack.printStack();
	MyStack.pop();MyStack.printStack();
	MyStack.push(200);MyStack.printStack();
	MyStack.push(300);MyStack.printStack();
	MyStack.push(400);MyStack.printStack();
	element key=MyStack.pop();MyStack.printStack();
	MyStack.push(500);MyStack.printStack();
	MyStack.printStack();
}