#pragma once
#define Max 10
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct {
	DataType list[Max];
	int size;
}List;

void Initialization(List*L);//˳����ʼ��
int Length(List*L);//��˳����еĸ���
int Insert(List*L, int i, DataType a);//����˳���
int Delete(List*L, int i, DataType a);//ɾ��˳���
int Putout(List*L, int i, DataType a);//ȡ��˳����е�����
