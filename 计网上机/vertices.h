#pragma once
#define Max 10000
#define Maxvertices 10000
#define Maxweight 10000
#include<stdio.h>
#include<stdlib.h>

//定义邻接矩阵的储存类型
typedef struct {
	List vertices;//定义存放顶点的顺序表
	int edge[Maxvertices][Maxvertices];//定义存放边的矩阵
	int num;//定义边的数目
}Adjaency;

//定义边的结构体
typedef struct {
	int row;//定义行下标
	int col;//定义列下标
	int weight;//定义权值
}rowcolweight;

void CreatGraph(Adjaency*A, DataType v[], int n, rowcolweight w[], int e);//创建图A，向其中插入n个顶点和e条边
void Initiate(Adjaency*A);//初始化A为空图
void Insertvertices(Adjaency*A, DataType vertices);//在A中插入顶点vertices
void Insertedge(Adjaency*A, int n1, int n2, int weight); //在A中插入一条第n1个顶点指向第n2个顶点，权值为weight的有向边
void Deleteedge(Adjaency*A, int n1, int n2);// 在A中删除一条第n1个顶点指向第n2个顶点的边。
void Deletevertices(Adjaency*A, int b);//在A中删除第b个顶点
int GetFirstvertices(Adjaency*A, int m);//在A中取第m个顶点的第一个邻接顶点
int GetNextvertices(Adjaency*A, int n1, int n2);//在A中取第n1个顶点的继邻接结点第n2个顶点之后的下一个邻接结点

