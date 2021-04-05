#include<iostream>
using namespace std;
#define MAX_STACK_SIZE 100
int maze[11][8] = {//�̷θ� �����Ѵ�.
	{ 1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,1,1 },
	{ 1,1,1,1,1,1,0,1 },
	{ 1,1,0,0,0,0,1,1 },
	{ 1,0,1,1,1,1,1,1 },
	{ 1,1,0,0,0,0,1,1 },
	{ 1,1,1,1,1,1,0,1 },
	{ 1,1,0,0,0,0,1,1 },
	{ 1,0,1,1,1,1,1,1 },
	{ 1,1,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1 }
};

//�������� ����
#define EXIT_ROW 9//9��
#define EXIT_COL 6//6��

int mark[11][8];//���� ������ ���
				//�̵� ������ ����
class Offset {

public:
	int ver;
	int hor;

	Offset(int ver, int hor) {
		this->ver = ver;
		this->hor = hor;
	}

};

Offset move1[8] = {//�̵��� �� �ִ� ��� ����
	Offset(-1,0),//N����
	Offset(-1,1),//NE����
	Offset(0,1),//E����
	Offset(1,1),//SE����
	Offset(1,0),//S����
	Offset(1,-1),//SW����
	Offset(0,-1),//W����
	Offset(-1,-1) //NW����
};
class Element {//���� ��ġ ����
public:
	int row;
	int col;
	int dir;
};
//��ġ�� �����ϴ� ���� ���� 
Element stack[MAX_STACK_SIZE];
int top = -1;
int isEmpty()
{
	return (top == -1);
}
int isFull()
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(Element position) {//���� ��ġ�� �����ϴ� push �Լ�
	if (isFull()) {
		printf("stack is full\n");
		exit(-1);
	}
	else {
		stack[top].col = position.col;
		stack[top].row = position.row;
		stack[top++].dir = position.dir;
	}
}
Element pop() {//���� ��ġ�� pop�ϴ� �Լ�
	if (isEmpty()) {
		printf("stack is empty\n");
		exit(-1);
	}
	else {
		return stack[top--];
	}
}
int main() {

	//���� ����
	int row, col;
	int nextRow, nextCol;
	int dir;
	bool found = false;
	Element position;

	//���ÿ� ���� ��ġ�� ����
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	mark[1][1] = 1; //���� ��ġ�� ���� ��ġ�� �Է�

	cout << "========�̷�  ã��=========\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n��� ��ġ\n";
	cout << "(" << stack[0].row << "," << stack[0].col << ")\n";
	cout << "\n���Ա� ��ġ\n";
	cout << "(" << EXIT_ROW << "," << EXIT_COL << ")\n";
	cout << "================================\n";

	//�̷�ã�� �˰���
	while (top > -1 && !found) {
		//������ ��� pop
		position = pop();
		//pop�� ��ġ ����
		row = position.row;
		col = position.col;
		dir = position.dir;

		//dir�� 8���� �۰�, �������� �߰��Ҷ����� ����
		while (dir < 8 && !found) {
			//���� ��ġ �Է�
			nextRow = row + move1[dir].ver;
			nextCol = col + move1[dir].hor;

			//���� ��ġ�� �������� ����������
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
				found = true;
			}
			//���� ��ġ�� 1�� �ƴϰų� ���� �ʾҴ� ��ġ �϶�
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;	//���� ��ġ�� ���
				position.col = col;
				position.row = row;
				position.dir = ++dir;
				push(position);	//���� ��ġ�� ���ÿ� ����
				row = nextRow; //������ġ�� row�� ����
				col = nextCol;	//���� ��ġ�� col�� ����
				dir = 0;	//���� �ʱ�ȭ
			}
			else ++dir;	//���� �ٲ�
		}

	}
	//��θ� �߰� ���� ��
	if (found) {
		cout << "�̷� ��� ��δ�:\n";
		for (int i = 0; i < top; i++) {
			cout << "(" << stack[i].row << "," << stack[i].col << ") ";

		}
		cout << "(" << row << "," << col << ") ";
		cout << "(" << nextRow << "," << nextCol << ") ";
	}
	//��θ� �߰����� ������ ��
	else cout << "��ΰ� �������� �ʽ��ϴ�.\n";

}
