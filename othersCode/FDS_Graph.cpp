#include <iostream>
#include <list>
using namespace std;
class Graph
{
	int V;             //顶点数
	list<int> *adj;    //邻接表
	void DFSUtil(int v, bool visited[]);   //从顶点v深度优先遍历 
	public:
		Graph(int V);
		void addEdge(int v, int w);        //向图中添加边
		void DFS(int v);                   //从v开始深度优先遍历图 
};
//构造函数 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}
//添加边，构造邻接表
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);                  //将w添加到v的链表 
}
//从v开始深度优先遍历
void Graph::DFSUtil(int v, bool visited[])
{
	//访问顶点v并输出
	visited[v] = true;
	cout<<v<<" ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i!= adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited); 
}
//对图进行深度优先遍历，调用递归函数DFSUtil()
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
 
