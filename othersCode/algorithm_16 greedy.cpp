////�ѡ�����⣬���ö�̬�滮�������
//#include <stdio.h>
//#include <stdlib.h>
//#define N 11
//void dynamic_activity_selector(int *s, int *f, int c[N + 1][N + 1], int ret[N + 1][N + 1])
//{
//	int i, j, k;
//	int temp;
//	//��i>=jʱ��������Ľ�Ϊ�գ���c[i][j]=0;
//	for (j = 1; j <= N; j++)
//	{
//		for (i = j; i <= N; i++)
//		{
//			c[i][j] = 0;
//		}
//	}
//	//��i>jʱ����ҪѰ������������Ž⣬�ҵ�һ��kʹ�ý�����ֳ�������
//	for (j = 2; j <= N; j++)
//	{
//		for(i = 1; i < j; i++)
//		{
//			for (k = i + 1; k < j; k++)
//			{
//				if (s[k] >= f[i] && f[k] <= s[j]) //�ж�k��Ƿ����������
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
//	printf("c[i][j]��ֵ������ʾ:\n");
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			printf("%d ", c[i][j]);
//		}
//		printf("\n");
//	}
//	//������һ�������һ��Ԫ��
//	printf("����Ӽ��ĸ���Ϊ: %d\n", c[1][N] + 2);
//	printf("ret[i][j]��ֵ������ʾ:\n");
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= N; j++)
//		{
//			printf("%d ", ret[i][j]);
//		}
//		printf("\n");
//	}
//	printf("����Ӽ�Ϊ��{ a1 ");
//	trace_route(ret, 1, N);
//	printf("a%d}\n", N);
//	return 0; 
//}

//̰���㷨ʵ�ֻѡ������
//#include <stdio.h> 
//#include <stdlib.h>
//#define N 11
//void recursive_activity_selector(int *s, int *f, int i, int n, int *ret)
//{
//	int *ptmp = ret;
//	int m = i + 1;
//	//��i��n��Ѱ�ҵ�һ�������Ļ
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
//	printf("����Ӽ�Ϊ:{ ");
//	for (i = 0; i < N; i++)
//	{
//		if (ret[i] != 0)
//			printf("a%d ", ret[i]);
//	}
//	printf(" }\n");
//	return 0;
//}

//�ο���ַhttp://www.acmerblog.com/greedy-huffman-coding-5388.html
//��̬�滮����huffman��ʵ��
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100
//���������ڵ�
struct MinHeapNode
{
	char data;        //�ַ�
	unsigned freq;    //�ַ�����Ƶ��
	struct MinHeapNode *left, *right; 
};
//��С�ѣ���Ϊ���ȶ���ʹ��
struct MinHeap
{
	unsigned size;    //��С��Ԫ�صĸ���
	unsigned capacity;//�������
	struct MinHeapNode **array; 
};
//��ʼ��һ����С�ѽڵ�
struct MinHeapNode *newNode(char data, unsigned freq)
{
	struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}
//����һ������Ϊcapacity����С��
struct MinHeap *createMinHeap(unsigned capacity) 
{
	struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode));
	return minHeap;
}
//���������ѽڵ�
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
	struct MinHeapNode *t = *a;
	*a = *b;
	*b = t;
}
//������С��
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
//���ѵĴ�С�Ƿ�Ϊ1
int isSizeOne(struct MinHeap *minHeap)
{
 	return (minHeap->size == 1);
} 
//ȡ������С�Ľڵ�
struct MinHeapNode * extractMin(struct MinHeap *minHeap)
{
	struct MinHeapNode *temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
} 
//����С���в���һ���ڵ�
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
//����һ����С��
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
//����Ƿ�ΪҶ�ӽڵ�
int isLeaf(struct MinHeapNode *root)
{
	return !(root->left) && !(root->right);
} 
//����һ������Ϊsize����С�ѣ�������data[]�е�Ԫ�ص���С��
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
	struct MinHeap *minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap; 
}
//������������
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	//��һ����������С�� 
	struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
	//ֱ����С��ֻ��һ��Ԫ��
	while(!isSizeOne(minHeap))
	{
		//�ڶ�����ȡ��С����Ԫ�� 
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		//������������������С�ڵ㣬������һ���µ��ڲ��ڵ�,$���ڲ��ڵ��־ 
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top); 
	}
	//���Ĳ������ʣ�µ�һ���ڵ�Ϊ���ڵ�
	return extractMin(minHeap); 
} 
//��ӡ����������
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
	//�����Ҷ�ӽڵ㣬�ʹ�ӡ
	if (isLeaf(root))
	{
		printf("%c: ", root->data);
		printArr(arr, top);
	 } 
} 
//����������������������ӡ�û�������
void HuffmanCodes(char data[], int freq[], int size)
{
	//������������
	struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
	//��ӡ�����õĻ�������
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top); 
} 
//����
int main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size= sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0; 
 } 
