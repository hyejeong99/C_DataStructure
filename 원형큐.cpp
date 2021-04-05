#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
typedef int element;

class CQueue{
public:
	element data[MAX_NUM];
	int front, rear; //두개의 인덱스 사용
	
	CQueue(){
		front=rear=0;//초기화
	}

	bool is_empty(){
		return (front==rear);
	}
	bool is_full(){
		return(front==(rear+1)%MAX_NUM);
	}

	void enQueue(element value){
		if(is_full()){
			cout<<"QUEUE OVERFLOW!!"<<endl;
		}
		else{
				rear=(rear+1)%MAX_NUM;
				data[rear]=value;
		}
	}
	element deQueue(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			front=(front+1)%MAX_NUM;
			return(data[front]);

		}
	}
	element peek(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(data[(front+1)%MAX_NUM]);
		}
	}
	void printQueue(){
		cout<<"---CQueq  "<<endl;
		if(front<=rear){
			for(int i=front+1;i<=rear;i++)
				cout<<data[i]<<endl;
		}
		else{
			for(int i=front+1;i<=rear+MAX_NUM;i++)
				cout<<data[i+MAX_NUM]<<endl;
		}
		cout<<"FRONT:"<<front<<" , "<<"REAR:"<<rear<<endl;
	}
};

void main(){
	
	CQueue MyQueue;

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

