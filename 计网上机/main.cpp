#include <iostream>
#include <iomanip>
#include <stdio.h>
#include"dijkstra.h"
using namespace std;
void dijkstra(int v0);
int main()
{
	int n = 0;
	int i = 0;
	while (1) {
		printf("\t*********** MENU ************");
		printf("\t��ӭʹ��·�ɱ����ɳ�������������ָ��:");
		printf("\t1  ����·�ɱ���ӡ        \n");
		printf("\t2  ɾ���ڵ�         ");
		printf("\t3  ɾ����        ");
		printf("\t4  ���ӽڵ�     ");
		printf("\t5  ���ӱ�    ");
		printf("     ����������ָ��: ");
		scanf_s("%d",&n);
		if (n < 1 || n>5)   n = 6;
		switch (n) {
		case 1:;  printf("������Ҫ��ӡ��·�����ڵ㣺"); scanf_s("%d",&n); dijkstra(i);       break;
		case 2:;     break;
		case 3:;             break;
		case 4:;            break;
		case 5:;             break;
		case 6:; ;
		default: printf("����ָ��������Ϊ��������һ��"); break;
		}

	}
	return 0;
}