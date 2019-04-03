#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

// using adjacency list to handle this problem
struct ArcNode {
	int adjvex;																		// the vertex this arc points to
	ArcNode *nextarc;																// this ptr points to the next arc
};

typedef struct VNode {
	int data;																		// the index of this vertex
	ArcNode *firstarc;																// points to the first arc related to this vertex
}VNode, AdjList[81];

struct ALGraph {
	AdjList vertices;																// the array of vertices
	int vexnum;																		// the number of vertexs in the graph
	int arcnum;																		// the number of arcs in the graph
};																					// graph

struct QNode {
	int data;
	QNode* next;
};

bool CreateGraph(ALGraph &graph)
{
	int vex, arc;																	// used to store the value temporarily
	// initilizing the number of arcs and vertexs
	//cout << "Please enter the number of vertexs and arcs: " << endl;
	cin >> vex >> arc;
	while (arc > (0.5 * vex * (vex - 1)))
	{
		cout << "The arcs are too much for the given number of vertexs!" << endl;
		cout << "Please choose the legal input: (ENTER AGAIN) " << endl;
		cin >> vex >> arc;
	}
	graph.vexnum = vex; graph.arcnum = arc;
	for (int i = 0; i != 81; i++)
	{
		graph.vertices[i].data = 0;
	}
	//initilizing the adjacent list
	int vex1, vex2;
	while (graph.arcnum--)
	{
		//cout << "Please enter the two vertexs of the arc: " << endl;
		cin >> vex1 >> vex2;
		if (!graph.vertices[vex1].data)
		{
			graph.vertices[vex1].firstarc = new ArcNode;
			graph.vertices[vex1].firstarc->adjvex = vex2;
			graph.vertices[vex1].firstarc->nextarc = NULL;
			graph.vertices[vex1].data = 1;
		}
		else
		{
			ArcNode* p = new ArcNode;
			p->adjvex = vex2;
			p->nextarc = graph.vertices[vex1].firstarc;
			graph.vertices[vex1].firstarc = p;
		}
		if (!graph.vertices[vex2].data)
		{
			graph.vertices[vex2].firstarc = new ArcNode;
			graph.vertices[vex2].firstarc->adjvex = vex1;
			graph.vertices[vex2].firstarc->nextarc = NULL;
			graph.vertices[vex2].data = 1;
		}
		else
		{
			ArcNode* p = new ArcNode;
			p->adjvex = vex1;
			p->nextarc = graph.vertices[vex2].firstarc;
			graph.vertices[vex2].firstarc = p;
		}
	}
	for (int v = 1; v <= graph.vexnum; v++)
		for (ArcNode* w1 = graph.vertices[v].firstarc; w1->nextarc != NULL; w1 = w1->nextarc)
			for (ArcNode* w2 = w1->nextarc; w2 != NULL; w2 = w2->nextarc)
				if (w2->adjvex <= w1->adjvex)
				{
					int temp = w2->adjvex; w2->adjvex = w1->adjvex; w1->adjvex = temp;
				}
	return true;
}

bool GetStartPoint(int &startpoint, ALGraph graph)
{
	//cout << endl;
	//cout << "Please enter the start point of the search: " << endl;
	cin >> startpoint;
	while (startpoint > graph.vexnum || startpoint < 1)
	{
		cout << "Index out of range!" << endl;
		cout << "Please give the correct index! " << endl;
		cin >> startpoint;
	}
	return true;
}

bool visited[81] = { false };

bool DFS(ALGraph G, int v)
{
	visited[v] = true;
	cout << v << " ";
	for (ArcNode* w = G.vertices[v].firstarc; w != nullptr; w = w->nextarc)
	{
		int vex = w->adjvex;
		if (!visited[vex]) DFS(G, vex);
	}
	return true;
}

bool DFSTraverse(ALGraph G, int startpoint)
{
	for (int i = 0; i <= 80; i++)
		visited[i] = false;
	if (startpoint == 1)
	{
		for (int v = 1; v <= G.vexnum; ++v)
		{
			if (!visited[v]) DFS(G, v);
		}
	}
	else
	{
		for (int v = startpoint; v != startpoint - 1; ++v)
		{
			if (v == G.vexnum + 1)
			{
				v = 1;
			}
			if (!visited[v]) DFS(G, v);
			if (startpoint == 2)
				break;
		}
		if (!visited[startpoint - 1]) DFS(G, startpoint - 1);
	}
	cout << endl;
	return true;
}

bool QueueEmpty(QNode* que)
{
	return ((que->next == nullptr) ? true : false);
}

bool EnQueue(QNode* que, int v)
{
	QNode* rear = que;
	while (rear->next != nullptr)
	{
		rear = rear->next;
	}
	rear->next = new QNode;
	rear = rear->next;
	rear->data = v; rear->next = nullptr;
	return true;
}

bool DeQueue(QNode* que, int &u)
{
	QNode* p = que->next;
	if (p != nullptr)
	{
		que->next = p->next;
	}
	u = p->data;
	free(p);
	return true;
}

bool BFSTraverse(ALGraph G, int startpoint)
{
	int u;
	for (int i = 0; i <= 80; i++)
		visited[i] = false;
	QNode* que = new QNode;
	que->next = nullptr; que->data = 0;
	if (startpoint == 1)
	{
		for (int v = 1; v <= G.vexnum; ++v)
		{
			if (!visited[v])
			{
				visited[v] = true;
				cout << v << " ";
				EnQueue(que, v);
				while (!QueueEmpty(que))
				{
					DeQueue(que, u);
					for (ArcNode* w = G.vertices[u].firstarc; w != nullptr; w = w->nextarc)
					{
						int temp = w->adjvex;
						if (!visited[temp])
						{
							visited[temp] = true;
							cout << temp << " ";
							EnQueue(que, temp);
						}
					}
				}
			}
		}
	}
	else
	{
		for (int v = startpoint; v != startpoint - 1; ++v)
		{
			if (v == G.vexnum + 1)
			{
				v = 1;
			}
			if (!visited[v])
			{
				visited[v] = true;
				cout << v << " ";
				EnQueue(que, v);
				while (!QueueEmpty(que))
				{
					DeQueue(que, u);
					for (ArcNode* w = G.vertices[u].firstarc; w != nullptr; w = w->nextarc)
					{
						int temp = w->adjvex;
						if (!visited[temp])
						{
							visited[temp] = true;
							cout << temp << " ";
							EnQueue(que, temp);
						}
					}
				}
			}
			if (startpoint == 2)
				break;
		}
		if (!visited[startpoint - 1])
		{
			visited[startpoint - 1] = true;
			cout << startpoint - 1 << " ";
			EnQueue(que, startpoint - 1);
			while (!QueueEmpty(que))
			{
				DeQueue(que, u);
				for (ArcNode* w = G.vertices[u].firstarc; w != nullptr; w = w->nextarc)
				{
					int temp = w->adjvex;
					if (!visited[temp])
					{
						visited[temp] = true;
						cout << temp << " ";
						EnQueue(que, temp);
					}
				}
			}
		}
	}
	cout << endl;
	return true;
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	//freopen("t1out7.txt", "w", stdout);
	ALGraph graph;	CreateGraph(graph);									// initializing the graph
	int startpoint;	GetStartPoint(startpoint, graph);					// initializing the startpoint
	DFSTraverse(graph, startpoint);
	BFSTraverse(graph, startpoint);
	//cout << "Please choose the search method you want to perform: " << endl;
	//cout << "1. Depth First Search " << endl;
	//cout << "2. Broadth First Search " << endl;
	//cout << "3. Quit " << endl;
	/*int choice;	cin >> choice;
	while (choice != 3)
	{
		switch (choice)
		{
		case 1:
		{
			DFSTraverse(graph, startpoint);
			break;
		}
		case 2:
		{
			BFSTraverse(graph, startpoint);
			break;
		}
		default: break;
		}
		cout << "Please choose the search method you want to perform: " << endl;
		cout << "1. Depth First Search " << endl;
		cout << "2. Broadth First Search " << endl;
		cout << "3. Quit " << endl;
		cin >> choice;
	}
	cin.get();
	cin.get();*/
	return 0;
}