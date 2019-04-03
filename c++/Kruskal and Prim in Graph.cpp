#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

constexpr const auto IUNF = 100000;


int vexs[10001];
int arcs[10001][10001];

struct MGraph {
	int vexnum;
	int arcnum;
};

struct Assist {
	int adjvex;
	int lowcost;
};

struct Queue {
	int vex1;
	int vex2;
	Queue* next;
};

bool InitQueue(Queue* &que)
{
	que = new Queue;
	que->vex1 = -1;
	que->vex2 = -1;
	que->next = nullptr;
	return true;
}

bool Enqueue(Queue* &que, int v1, int v2)
{
	Queue* p = que;
	for (p = que; p->next != nullptr; p = p->next);
	Queue* q = new Queue;
	q->vex1 = v1; q->vex2 = v2;
	q->next = nullptr;
	p->next = q;
	return true;
}

bool Create_MGraph(MGraph &G)
{
	//cout << "Please enter the number of vertexs and arcs: " << endl;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i != 10001; i++)
		for (int j = 0; j != 10001; j++)
			arcs[i][j] = IUNF;
	int m = G.arcnum;
	while (m--)
	{
		//cout << "Please enter the two vertexs of the arc and the weight of the arc: " << endl;
		//cout << "Weight is an integer less than 10000" << endl;
		int i, j, w;
		cin >> i >> j >> w;
		arcs[i][j] = arcs[j][i] = w;
	}
	return true;
}

int MinofArray(Assist* closedge, MGraph G)
{
	int start = 0;
	for (int i = 1; i <= G.vexnum; ++i)
	{
		if (closedge[i].lowcost != 0)
		{
			start = i;
			//cout << start << " ";
			break;
		}
	}
	int min = closedge[start].lowcost;
	int index = start;
	for (int j = start; j <= G.vexnum; ++j)
	{
		if (closedge[j].lowcost > 0)
		{
			if (closedge[j].lowcost < min)
			{
				index = j;
				min = closedge[j].lowcost;
			}
		}
	}
	return index;
}

int Prim_MiniSpanTree(MGraph G, int u, Queue* &que)
{
	Assist closedge[10001] = { 0 };
	int k = u;
	int re = 0;
	for (int j = 1; j <= G.vexnum; j++)
	{
		if (j != u)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = arcs[k][j];
		}
	}															// initializing the assiting array 
	closedge[u].lowcost = 0;									// u is the initial point that is selected
	for (int i = 1; i < G.vexnum; i++)
	{
		k = MinofArray(closedge, G);
		//cout << k << endl;
		re += closedge[k].lowcost;
		//Enqueue(que, closedge[k].adjvex, k);
		closedge[k].lowcost = 0;						//已经被找到的顶点lowcost置0
		for (int j = 1; j <= G.vexnum; ++j)
		{
			if (arcs[k][j] < closedge[j].lowcost)
			{
				closedge[j].adjvex = k;
				closedge[j].lowcost = arcs[k][j];
			}
		}
	}
	return re;
}

bool QueueSort(Queue* &que)
{
	for (Queue* r = que->next; r != nullptr; r = r->next)
		if (r->vex1 > r->vex2)
		{
			int temp = r->vex1; r->vex1 = r->vex2; r->vex2 = temp;
		}
	Queue *p, *q;
	for (p = que->next; p->next != nullptr; p = p->next)
		for (q = p->next; q->next != nullptr; q = q->next)
		{
			if (q->vex1 < p->vex1)
			{
				int temp1 = q->vex1; q->vex1 = p->vex1; p->vex1 = temp1;
				int temp2 = q->vex2; q->vex2 = p->vex1; p->vex1 = temp2;
			}
		}
	for (p = que->next; p->next != nullptr; p = p->next)
		for (q = p->next; (q->next != nullptr) && (q->next->vex1 == p->vex1); q = q->next)
		{
			if (q->vex2 < p->vex2)
			{
				int temp = q->vex2; q->vex2 = p->vex2; p->vex2 = temp;
			}
		}
	return true;
}

bool ShowQueue(Queue* que)
{
	for (Queue* p = que->next; p != nullptr; p = p->next)
		cout << p->vex1 << " " << p->vex2 << endl;
	return true;
}

int AddQueue(Queue* que)
{
	int total_weight = 0;
	for (Queue* p = que->next; p != nullptr; p = p->next)
		if (p->vex1 != 0 && p->vex2 != 0)
			total_weight += arcs[p->vex1][p->vex2];
	return total_weight;
}

bool FindLowCost(MGraph G, int &vex1, int &vex2)
{
	int flag = 1; int min = 0;
	for (int i = 1; i <= G.vexnum; i++)
		for (int j = i; j <= G.vexnum; j++)
		{
			if ((vexs[i] == 1 || vexs[j] == 1) && flag == 1)
			{
				flag = 0;
				min = arcs[i][j];
				vex1 = i; vex2 = j;
			}
			if ((vexs[i] == 1 || vexs[j] == 1) && arcs[i][j] < min)
			{
				vex1 = i;
				vex2 = j;
				min = arcs[i][j];
			}
		}
	cout << vex1 << "," << vex2 << endl;
	return true;
}

bool Kruskal_MiniSpanTree(MGraph G, Queue* &que)
{
	int vex1, vex2;
	for (int i = 0; i <= 10000; i++)
		vexs[i] = 10;
	for (int i = 1; i <= G.vexnum; i++)
		vexs[i] = 1;							// 1 stands for this vex hasn't yet been add to the minitree 
	for (int i = 1; i <= G.vexnum - 1; i++)
	{
		FindLowCost(G, vex1, vex2);
		Enqueue(que, vex1, vex2);
		vexs[vex1] = vexs[vex2] = 0;
	}
	return true;
}

int CalculatePath(MGraph G)
{
	int vertexs[10001] = { 0 };
	int min;
	int re = 0;		//结果
	int count = 1;	//连通片编号
	int v1, v2;		//最小的边顶点号
	int k = 1;
	while (k <= G.vexnum - 1)
	{
		min = IUNF;
		for (int i = 1; i <= G.vexnum - 1; ++i)
			for (int j = i + 1; j <= G.vexnum; ++j)
			{
				if (arcs[i][j] < min)
				{
					min = arcs[i][j];
					v1 = i; v2 = j;
				}
			}
		if (vertexs[v1] == 0 && vertexs[v2] == 0)
		{
			vertexs[v1] = vertexs[v2] = count++;
			re += arcs[v1][v2];
			arcs[v1][v2] = arcs[v2][v1] = IUNF;
			++k;
		}
		else if (vertexs[v1] == 0 && vertexs[v2] != 0)
		{
			vertexs[v1] = vertexs[v2];
			re += arcs[v1][v2];
			arcs[v1][v2] = arcs[v2][v1] = IUNF;
			++k;
		}
		else if (vertexs[v2] == 0 && vertexs[v1] != 0)
		{
			vertexs[v2] = vertexs[v1];
			re += arcs[v1][v2];
			arcs[v1][v2] = arcs[v2][v1] = IUNF;
			++k;
		}
		else
		{
			if (vertexs[v1] != vertexs[v2])
			{
				int index = vertexs[v2];
				for (int m = 1; m <= G.vexnum; ++m)
				{
					if (vertexs[m] == index)
						vertexs[m] = vertexs[v1];
				}
				re += arcs[v1][v2];
				arcs[v1][v2] = arcs[v2][v1] = IUNF;
				++k;
			}
			else
			{
				arcs[v1][v2] = arcs[v2][v1] = IUNF;
			}
		}
	}
	return re;
}

bool CalculateDir(MGraph G)
{
	int div[10001] = { 0 };
	for (int i = 1; i <= G.vexnum; ++i)
		for (int j = 1; j <= G.vexnum; ++j)
		{
			if (arcs[i][j] != IUNF)
			{
				div[i]++;
				div[j]++;
			}
		}
	for (int i = 1; i <= G.vexnum; ++i)
	{
		cout << i << "  " << div[i] << endl;
	}
	return true;
}
//_CRT_SECURE_NO_WARNINGS
int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("pt2out9.txt", "w", stdout);
	MGraph graph;
	Create_MGraph(graph);
	/*Queue* que = nullptr;
	InitQueue(que);
	Prim_MiniSpanTree(graph, 1, que);
	int a = AddQueue(que);
	cout << a << endl;	*/			//Prim
	Queue* que;
	InitQueue(que);
	int a = Prim_MiniSpanTree(graph,1,que);
	cout << a << endl;						//Kruskal
	//cin.get();  cin.get();
	return 0;
}