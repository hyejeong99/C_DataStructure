#include <iostream>
using namespace std;
const int MAX_NUM = 100; //#define MAX_NUM = 100;
typedef int element;

class Stack{
public:
	element data[MAX_NUM];
	int top; //������ ���Ҹ� ����Ű�� �ε��� 

	Stack() {top=-1;} //�ʱ�ȭ

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
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') //�����ڶ��
			PStack.push(ch);
		else if(ch==')'){
			postfix[j++]=PStack.pop();
		}
		else //�ǿ�����
			postfix[j++]=ch;
	}
	postfix[j]='\0';
}

void main(){
	char infix[100];
	char postfix[100];

	cout<<"���� ������ �Է��ϼ���:";
	//cin>>infix; ���� ������ �ܾ�� ����
	cin.getline(infix,100); //���� �־ �ٺ��� ����

	convert_postfix(infix, postfix);

	cout<<"��ȯ�� ���� ǥ�����:" << postfix<<endl;
}