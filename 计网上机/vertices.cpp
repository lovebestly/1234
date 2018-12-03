#include"vertices.h"
#include"List.h"

//创建图A，向其中插入n个顶点和e条边
void CreatGraph(Adjaency*A, DataType v[], int n, rowcolweight w[], int e)
{
	int i, k;
	Initiate(A);
	for (i = 0; i < n; i++)
	{
		Insertvertices(A, v[i]);
	}
	for (k = 0; k < e; k++)
		Insertedge(A, w[k].row, w[k].col, w[k].weight);
}

//初始化 A为空
void Initiate(Adjaency*A) {
	int i, j;
	for (i = 0; i < Maxvertices; i++) {
		for (j = 0; j < Maxvertices; j++) {
			if (i == j) {
				A->edge[i][j] = 0;
			}
			else {
				A->edge[i][j] = Maxvertices;
			}
		}
	}
	A->num = 0;
	Initialization(&A->vertices);//顶点的顺序表初始化
}

//在A中插入顶点vertices
void Insertvertices(Adjaency*A, DataType vertices) {
	if (Insert(&A->vertices, A->vertices.size, vertices) == 0) {
		printf("插入顶点 空间已满\n");
		exit(1);
	}
}

//在A中插入一条第n1个顶点指向第n2个顶点，权值为weight的有向边
void Insertedge(Adjaency*A, int n1, int n2, int weight) {
	DataType a;
	if (n1 != n2) {
		if (Putout(&A->vertices, n1, a) == 0 || Putout(&A->vertices, n2, a) == 0) {
			printf("插入边时 参数出错\n");
			exit(1);
		}
		A->edge[n1][n2] = weight;
		A->edge[n2][n1] = weight;
		A->num++;
	}
}

// 在A中删除一条第n1个顶点指向第n2个顶点的边
void Deleteedge(Adjaency*A, int n1, int n2) {
	A->edge[n1][n2] = Maxweight;
	A->edge[n2][n1] = Maxweight;
	A->num--;
}

//在A中删除第b个顶点
void Deletevertices(Adjaency*A, int b) {
	int m, i, j;
	m = b - 1;
	{
		if (m < 0 || m >= A->vertices.size) {
			printf("路由结点不存在\n");
			exit(0);
		}
		else {
			for (i = m; i < A->vertices.size; i++) {
				for (j = 0, i = m; j < A->vertices.size; j++) {
					A->edge[j][i] = Maxweight;

				}
			}
			for (i = m; i < A->vertices.size; i++) {
				for (i = m, j = 0; j < A->vertices.size; j++) {
					A->edge[i][j] = Maxweight;
				}
			}
			for (i = m; i < A->vertices.size; i++) {
				A->vertices.list[i] = A->vertices.list[i] - 1;
			}
			A->vertices.size--;
			printf("删除结点成功\n");
		}
	}
}

//在A中取第m个顶点的第一个邻接顶点
int GetFirstvertices(Adjaency*A, int m) {
	int col;
	DataType a;
	m = m - 1;
	if (Putout(&A->vertices, m, a) == 0) {
		printf("取第一个邻接顶点时 输入出错\n");
		exit(1);
	}
	for (col = 0; col < A->vertices.size; col++) {
		if (A->edge[m][col] > 0 && A->edge[m][col] < Maxweight) {
			return col;
		}
	}
	return -1;
}

//在A中取第n1个顶点的继邻接结点第n2个顶点之后的下一个邻接结点
int GetNextvertices(Adjaency*A, int n1, int n2) {
	int col;
	DataType a;
	if ((Putout(&A->vertices, n1, a) == 0) || (Putout(&A->vertices, n2, a) == 0)) {
		printf("取下一邻接顶点 数据出错\n");
		exit(1);
	}
	if (A->edge[n1][n2] == 0) {
		printf("n2不是n1的邻接顶点\n");
		exit(1);
	}
	for (col = n2 + 1; col < A->vertices.size; col++) {
		if (A->edge[n1][col] > 0 && A->edge[n1][col] < Maxweight) {
			return col;
		}
	}
	return -1;
}

