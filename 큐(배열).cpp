#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
typedef int element;

class Queue{
public:
	element data[MAX_NUM];
	int front, rear; //두개의 인덱스 사용
	
	Queue(){
		front=rear=-1;//초기화
	}

	bool is_empty(){
		return(front==rear);//참 거짓 리턴
	}
	bool is_full(){
		return (rear==MAX_NUM-1);
	}

	void enQueue(element value){
		if(is_full()){
			cout<<"QUEUE OVERFLOW!!"<<endl;
		}
		else{
			data[++rear]=value;
		}
	}
	element deQueue(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(data[++front]);

		}
	}
	element peek(){
		if(is_empty()){
			cout<<"QUEUE UNDERFLOW!!"<<endl;
			exit(-1);
		}
		else{
			return(data[front+1]);
		}
	}
	void printQueue(){
		cout<<"###QUEUE STATUS###"<<endl;
		for(int i=front+1;i<=rear;i++){
			cout<<data[i]<<" ";
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

