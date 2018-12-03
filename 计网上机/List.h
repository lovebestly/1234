#pragma once
#define Max 10
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct {
	DataType list[Max];
	int size;
}List;

void Initialization(List*L);//顺序表初始化
int Length(List*L);//求顺序表中的个数
int Insert(List*L, int i, DataType a);//插入顺序表
int Delete(List*L, int i, DataType a);//删除顺序表
int Putout(List*L, int i, DataType a);//取出顺序表中的数据
