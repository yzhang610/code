#include <iostream>
#include <list>
using namespace std;
class Graph
{
	int V;             //������
	list<int> *adj;    //�ڽӱ�
	void DFSUtil(int v, bool visited[]);   //�Ӷ���v������ȱ��� 
	public:
		Graph(int V);
		void addEdge(int v, int w);        //��ͼ����ӱ�
		void DFS(int v);                   //��v��ʼ������ȱ���ͼ 
};
//���캯�� 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}
//��ӱߣ������ڽӱ�
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);                  //��w��ӵ�v������ 
}
//��v��ʼ������ȱ���
void Graph::DFSUtil(int v, bool visited[])
{
	//���ʶ���v�����
	visited[v] = true;
	cout<<v<<" ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i!= adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited); 
}
//��ͼ����������ȱ��������õݹ麯��DFSUtil()
void Graph::DFS(int v)
{
	bool *visited = new bool[v];
	for (int i = 0; i < V; ++i)
		visited[i] = false;
	DFSUtil(v, visited);
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout<<"Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);
	cout<<endl;
	return 0;
  }  
 
