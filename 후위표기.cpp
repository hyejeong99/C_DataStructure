#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
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

void convert_postfix(char *infix, char *postfix)
{
	Stack PStack;
	int j=0;

	for(int i=0;i<strlen(infix);i++){
		char ch=infix[i];
		if(ch=='('||ch=='') continue;
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') //연산자라면
			PStack.push(ch);
		else if(ch==')'){
			postfix[j++]=PStack.pop();
		}
		else //피연산자
			postfix[j++]=ch;
	}
	postfix[j]='\0';
}

void main(){
	char infix[100];
	char postfix[100];

	cout<<"중위 수식을 입력하세요:";
	//cin>>infix; 띄어쓰기 있으면 단어별로 읽음
	cin.getline(infix,100); //띄어쓰기 있어도 줄별로 읽음

	convert_postfix(infix, postfix);

	cout<<"변환된 후위 표기식은:" << postfix<<endl;
}