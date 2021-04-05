#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
typedef int element;
typedef int element2;
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
class IntStack{
public:
	element2 data[MAX_NUM];
	int top; //마지막 원소를 가리키는 인덱스 

	IntStack() {top=-1;} //초기화

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

	void push(element2 value){
		if(is_full()){
			cout<<"STACK OVERFLOSW!!"<<endl;
		}
		else{
			data[++top]=value;
			//top++;
			//data[top]=value;
		}
	}
	element2 pop(){
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
	element2 peek(){
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
		if(ch=='('||ch==' ') continue;
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') //연산자라면
			PStack.push(ch);
		else if(ch==')'){
			postfix[j++]=PStack.pop();
		}
		else //피연산자
			postfix[j++]=ch;
	}
	while(!PStack.is_empty()){ //스택 안에 남아있는 경우
		postfix[j++]=PStack.pop();
	}
	postfix[j]='\0';
}

int claculate_postfix(char *postfix){
	IntStack CStack;
	for(int i=0;i<strlen(postfix);i++)	{
		char ch=postfix[i];
		int opr1,opr2;

		if(ch=='+'){
			opr2=CStack.pop();	
			opr1=CStack.pop();
			CStack.push(opr1+opr2);
		}
		else if(ch=='*'){
			opr2=CStack.pop();	
			opr1=CStack.pop();
			CStack.push(opr1*opr2);
		}
		else if(ch=='-'){
			opr2=CStack.pop();	
			opr1=CStack.pop();
			CStack.push(opr1-opr2);
		}
		else if(ch=='/'){
			opr2=CStack.pop();	
			opr1=CStack.pop();
			CStack.push(opr1/opr2);
		}
		else{
			CStack.push(ch-'0');
		}
	}
	return (CStack.pop());
}
void main(){
	char infix[100];
	char postfix[100];

	cout<<"중위 수식을 입력하세요:";
	//cin>>infix; 띄어쓰기 있으면 단어별로 읽음
	cin.getline(infix,100); //띄어쓰기 있어도 줄별로 읽음

	convert_postfix(infix, postfix);
	cout<<"변환된 후위 표기식은:" << postfix<<endl;

	int result=claculate_postfix(postfix);
	cout<< infix<< "=" << result <<endl;
}