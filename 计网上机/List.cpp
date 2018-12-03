#include"List.h"

//˳����ʼ��
void Initialization(List*L) {
	L->size = 0;
}

//��˳����еĸ���
int Length(List*L) {
	return L->size;
}

//����˳���
int Insert(List*L, int i, DataType a) {         //��˳���ĵ�i��λ�ò���a
	int j;
	if (L->size >= Max) {
		printf("˳������� �޷�����\n");
		return 0;
	}
	else if (i<0 || i>L->size) {
		printf("���ݲ����� ����������\n");
		return 0;
	}
	else {
		for (j = L->size; j > i; j--) {
			L->list[j] = L->list[j - 1];
			L->list[i] = a;
			L->size++;
		}
		return 1;
	}
}

//ɾ��˳���
int Delete(List*L, int i, DataType a) {        //ɾ��˳���iλ�õ����ݲ���ŵ���ַa��
	int j;
	if (L->size <= 0) {
		printf("˳���Ϊ�� �޷�����\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1) {
		printf("���ݲ����� ����������\n");
		return 0;
	}
	else {
		a = L->list[i];    //��ɾ�������ݱ��浽��ַa
		for (j = i + 1; j <= L->size - 1; j++) {
			L->list[j - 1] = L->list[j];
			L->size--;
		}
		return 1;
	}
}

//ȡ��˳����е�����
int Putout(List*L, int i, DataType a) {           //��˳����еĵ�i������ȡ������ڵ�ַa
	if (i<0 || i>L->size - 1) {
		printf("���ݲ����� ����������\n");
		return 0;
	}
	else {
		a = L->list[i];
		return 1;
	}
}