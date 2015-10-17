////活动选择问题，利用动态规划方法求解
//#include <stdio.h>
//#include <stdlib.h>
//#define N 11
//void dynamic_activity_selector(int *s, int *f, int c[N + 1][N + 1], int ret[N + 1][N + 1])
//{
//	int i, j, k;
//	int temp;
//	//当i>=j时候，子问题的解为空，即c[i][j]=0;
//	for (j = 1; j <= N; j++)
//	{
//		for (i = j; i <= N; i++)
//		{
//			c[i][j] = 0;
//		}
//	}
//	//当i>j时，需要寻找子问题的最优解，找到一个k使得将问题分成两部分
//	for (j = 2; j <= N; j++)
//	{
//		for(i = 1; i < j; i++)
//		{
//			for (k = i + 1; k < j; k++)
//			{
//				if (s[k] >= f[i] && f[k] <= s[j]) //判断k活动是否满足兼容性
//				{
//					temp = c[i][k] + c[k][j] + 1;
//					if (c[i][j] < temp) 
//					{
//						c[i][j] = temp;
//						ret[i][j] = k;
//					}
//			    } 
//			} 
//		}
//	 } 
//}
//void trace_route(int ret[N + 1][N + 1], int i, int j)
//{
//	if (i < j)
//	{
//		trace_route(ret, i, ret[i][j]);
//		if (ret[i][j] != 0)
//			printf("a%d ", ret[i][j]);
//	}
//} 
//int main()
//{
//	int s[N + 1] = {-1, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
//	int f[N + 1] = {-1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
//	int c[N + 1][N + 1] = {0};
//	int ret[N + 1][N + 1] = {0};
//	int i, j;
//	dynamic_activity_selector(s, f, c, ret);
//	printf("c[i][j]的值如下所示:\n");
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			printf("%d ", c[i][j]);
//		}
//		printf("\n");
//	}
//	//包括第一个和最后一个元素
//	printf("最大子集的个数为: %d\n", c[1][N] + 2);
//	printf("ret[i][j]的值如下所示:\n");
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			printf("%d ", ret[i][j]);
//		}
//		printf("\n");
//	}
//	printf("最大子集为：{ a1 ");
//	trace_route(ret, 1, N);
//	printf("a%d}\n", N);
//	return 0; 
//}

//贪心算法实现活动选择问题
//#include <stdio.h> 
//#include <stdlib.h>
//#define N 11
//void recursive_activity_selector(int *s, int *f, int i, int n, int *ret)
//{
//	int *ptmp = ret;
//	int m = i + 1;
//	//在i和n中寻找第一个结束的活动
//	while (m <= n && s[m] < f[i])
//		m = m + 1;
//		if (m <= n)
//		{
//			*ptmp++ = m;
//			recursive_activity_selector(s, f, m, n, ptmp);
//		 } 
//}
//void greedy_activity_selector(int *s, int *f, int *ret)
//{
//	int i, m;
//	*ret++ = 1;
//	i = 1;
//	for (m = 2; m <=N; m++)
//	{
//		if (s[m] >= f[i])
//		{
//			*ret++ = m;
//			i = m;
//		}
//	}
//}
//int main()
//{
//	int s[N + 1] = {-1, 1, 3, 0, 5,3, 5, 6, 8, 8, 2, 12};
//	int f[N + 1] = {-1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
//	int c[N + 1][N + 1] = {0};
//	int ret[N] = {0};
//	int i, j;
////	greedy_activity_selector(s, f, ret);
//    recursive_activity_selector(s, f, 0, N, ret);
//	printf("最大子集为:{ ");
//	for (i = 0; i < N; i++)
//	{
//		if (ret[i] != 0)
//			printf("a%d ", ret[i]);
//	}
//	printf(" }\n");
//	return 0;
//}

//参考网址http://www.acmerblog.com/greedy-huffman-coding-5388.html
//动态规划——huffman树实现
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100
//霍夫曼树节点
struct MinHeapNode
{
	char data;        //字符
	unsigned freq;    //字符出现频率
	struct MinHeapNode *left, *right; 
};
//最小堆，作为优先队列使用
struct MinHeap
{
	unsigned size;    //最小堆元素的个数
	unsigned capacity;//最大容量
	struct MinHeapNode **array; 
};
//初始化一个最小堆节点
struct MinHeapNode *newNode(char data, unsigned freq)
{
	struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}
//创建一个容量为capacity的最小堆
struct MinHeap *createMinHeap(unsigned capacity) 
{
	struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode));
	return minHeap;
}
//交换两个堆节点
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
	struct MinHeapNode *t = *a;
	*a = *b;
	*b = t;
}
//更新最小堆
void minHeapify(struct MinHeap *minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if (smallest != idx)
	{
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest); 
	}
} 
//检测堆的大小是否为1
int isSizeOne(struct MinHeap *minHeap)
{
 	return (minHeap->size == 1);
} 
//取堆中最小的节点
struct MinHeapNode * extractMin(struct MinHeap *minHeap)
{
	struct MinHeapNode *temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
} 
//向最小堆中插入一个节点
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq)
	{
		minHeap->array[i] = minHeap->array[(i - 1)/2];
		i = (i - 1)/2;
	}
	minHeap->array[i] = minHeapNode;
} 
//构建一个最小堆
void buildMinHeap(struct MinHeap *minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1)/2; i >= 0; --i)
		minHeapify(minHeap, i);
} 
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);
	printf("\n");
}
//检查是否为叶子节点
int isLeaf(struct MinHeapNode *root)
{
	return !(root->left) && !(root->right);
} 
//创建一个容量为size的最小堆，并插入data[]中的元素到最小堆
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
	struct MinHeap *minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap; 
}
//构建霍夫曼树
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	//第一步：创建最小堆 
	struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
	//直到最小堆只有一个元素
	while(!isSizeOne(minHeap))
	{
		//第二步：取最小两个元素 
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		//第三步：根据两个最小节点，来创建一个新的内部节点,$是内部节点标志 
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top); 
	}
	//第四步：最后剩下的一个节点为根节点
	return extractMin(minHeap); 
} 
//打印霍夫曼编码
void printCodes(struct MinHeapNode *root, int arr[], int top)
{
	if (root->left)
	{
		arr[top] = 0;
		printCodes(root->left, arr, top + 1); 
	}
	if (root->right)
	{
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	//如果是叶子节点，就打印
	if (isLeaf(root))
	{
		printf("%c: ", root->data);
		printArr(arr, top);
	 } 
} 
//构建霍夫曼树，并遍历打印该霍夫曼树
void HuffmanCodes(char data[], int freq[], int size)
{
	//构建霍夫曼树
	struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
	//打印构建好的霍夫曼树
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top); 
} 
//测试
int main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size= sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0; 
 } 
