#pragma once
#define Max 10000
#define Maxvertices 10000
#define Maxweight 10000
#include<stdio.h>
#include<stdlib.h>

//�����ڽӾ���Ĵ�������
typedef struct {
	List vertices;//�����Ŷ����˳���
	int edge[Maxvertices][Maxvertices];//�����űߵľ���
	int num;//����ߵ���Ŀ
}Adjaency;

//����ߵĽṹ��
typedef struct {
	int row;//�������±�
	int col;//�������±�
	int weight;//����Ȩֵ
}rowcolweight;

void CreatGraph(Adjaency*A, DataType v[], int n, rowcolweight w[], int e);//����ͼA�������в���n�������e����
void Initiate(Adjaency*A);//��ʼ��AΪ��ͼ
void Insertvertices(Adjaency*A, DataType vertices);//��A�в��붥��vertices
void Insertedge(Adjaency*A, int n1, int n2, int weight); //��A�в���һ����n1������ָ���n2�����㣬ȨֵΪweight�������
void Deleteedge(Adjaency*A, int n1, int n2);// ��A��ɾ��һ����n1������ָ���n2������ıߡ�
void Deletevertices(Adjaency*A, int b);//��A��ɾ����b������
int GetFirstvertices(Adjaency*A, int m);//��A��ȡ��m������ĵ�һ���ڽӶ���
int GetNextvertices(Adjaency*A, int n1, int n2);//��A��ȡ��n1������ļ��ڽӽ���n2������֮�����һ���ڽӽ��

