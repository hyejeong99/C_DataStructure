#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
typedef int element;

class QNode{
public:
	element data;
	QNode *link;

	QNode(element value){
		data=value;
		link=NULL;
	}
};
class Queue{
public:

	QNode *front, *rear; //두개의 포인터 사용
	
	Queue(){
		front=rear=NULL;//초기화
	}

	bool is_empty(){
		return(front==NULL);
	}


	void enQueue(element value){
		QNode *new_node=new QNode(value);
		if(is_empty()){//if(rear==NULL) 비었을 때
			front=rear=new_node; //새로 들어온 노드가 첫 노드
		}
		else{
			rear->link=new_node;//new_node를 마지막으로 삽입
			rear=new_node;//rear를 new_node
		}	
	}
	element deQueue(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			element x=front->data; //x는 맨 앞에있는 원소
			front=front->link;
			if(front==NULL)rear=NULL;
			return(x);
		}
	}
	element peek(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(front->data);
		}
	}
	void printQueue(){
		cout<<"###QUEUE STATUS###"<<endl;
		for(QNode *ptr=front;ptr!=NULL;ptr=ptr->link){
			cout<<ptr->data<<" ";
		}
			cout<<endl;
	}
};

void main(){
	
	Queue MyQueue;

	MyQueue.enQueue(10);MyQueue.printQueue();
	MyQueue.enQueue(20);MyQueue.printQueue();
	MyQueue.deQueue();MyQueue.printQueue();
	MyQueue.enQueue(10);MyQueue.printQueue();
	MyQueue.enQueue(20);MyQueue.printQueue();
	MyQueue.deQueue();MyQueue.printQueue();
	MyQueue.deQueue();MyQueue.printQueue();
	MyQueue.deQueue();MyQueue.printQueue();
	MyQueue.deQueue();MyQueue.printQueue();
}

