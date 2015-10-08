#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#define ALPHABET_SIZE 26
typedef struct trie_node
{
	int count;//��¼�ýڵ����ĵ��ʵĸ���
	trie_node *children[ALPHABET_SIZE];//�����ӽڵ� 
}*trie;
trie_node *create_trie_node()
{
	trie_node *pNode = new trie_node();
	pNode->count = 0;
	for (int i = 0; i < ALPHABET_SIZE; ++i)
		pNode->children[i] = NULL;
	return pNode; 
} 
void trie_insert(trie root, char *key)
{
	trie_node *node = root;
	char *p = key;
	while (*p)
	{
		if (node->children[*p - 'a'] == NULL)
		{
			node->children[*p - 'a'] = create_trie_node();
		}
		node = node->children[*p - 'a'];
		++p; 
	}
	node->count += 1;
}
//��ѯ�������ڷ���0�����ڷ��س��ֵĴ���
int trie_search(trie root, char *key)
{
	trie_node *node = root;
	char *p = key;
	while (*p && node != NULL)
	{
		node = node->children[*p - 'a'];
		++p;
	}
	if (node == NULL)
		return 0;
	else
		return node->count;
}
int main()
{
	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	trie root = create_trie_node();
	//����trie��
	for (int i = 0; i < 8; i++)
		trie_insert(root, keys[i]);
	char s1[][32] = {"Present in trie", "Not present in trie"};
	printf("%s --- %s\n", "the", trie_search(root, "the") > 0 ? s1[0] : s1[1]); 
	printf("%s --- %s\n", "these", trie_search(root, "these") > 0 ? s1[0] : s1[1]); 
	printf("%s --- %s\n", "their", trie_search(root, "their") > 0 ? s1[0] : s1[1]); 
	printf("%s --- %s\n", "thaw", trie_search(root, "thaw") > 0 ? s1[0] : s1[1]); 
	return 0;
 } 

