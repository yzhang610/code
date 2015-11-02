/******************************************************************
 ******************************************************************
 *****************    Adaboost�㷨ʵ��      ***********************
 *****************    write by yzhang       ***********************
 *****************      2014/11/2           ***********************
 ******************************************************************
 ******************************************************************/ 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
//����ѵ�������ṹ�� 
struct Sample
{
	int number;
	int feature;
	int label;
	float weight; 
};
//��������������Ϣ 
struct BoostNode
{
	int index;            //������������Ŀ 
	float threshold;      //ÿ������������Ӧ����ֵ
	int p;                //ÿ������������Ӧ�Ĳ��Ⱥŷ���
	float alpha;          //ÿ������������Ȩ��alpha 
	BoostNode *next;      //��һ���ڵ�    	 
}; 
//��ȡѵ���������� 
void readSample(Sample *sam, int n)
{
	fstream file;
	file.open("train.txt", ios::in);
	if (file.fail())	
	{
		cout << "�ļ�������" << endl;
		file.close(); 
	}
	else
	{
		int i = 0;
		while (!file.eof())
		{
			file >> sam[i].number;
			file >> sam[i].feature;
			file >> sam[i].label;
			sam[i].weight = (float) (1.0 / n);
			i++; 
		}
		file.close();   //�ر��ļ� 
	}
}
//��ʾѵ���������� 
void showSample(Sample *sam, int n)
{
	cout << "������ϸ��Ϣ���£�" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << sam[i].number << "\t" ;
		cout << sam[i].feature << "\t" ;
		cout << sam[i].label << "\t" ;
		cout << sam[i].weight << "\t" ;
		cout << endl;
	}
}
//����G(x)������pΪȷ������ʽ����Ĭ�ϳ�ʼֵΪ����1�� 
int generate_gfunc(float threshold, int x, int p)
{
	if (x * p < threshold * p)
		return 1;
	else
		return -1;	
} 
//������ֵthreshold��ȡֵ��Χ
void generate_threshold(float *threshold, Sample *sam, int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		if (i == 0)
		{
			threshold[i] = (float) (sam[i].feature - 0.5);
		}
		else if (i == n)
		{
			threshold[i] = (float) (sam[i - 1].feature + 0.5);
		}
		else
		{
			threshold[i] = (float) ((sam[i].feature + sam[i - 1].feature) / 2.0);
		}
	}
//	for (int j = 0; j < n + 1; j++)
//	{
//		cout << threshold[j] << " " ;
//	}
} 
//����ÿ����ֵ��Ӧ�Ĵ�����
void compute_error(Sample *sam, float *threshold, int *p, float *error, int n) 
{
	int estimated; 
	int result;
	float thred;
	int feature;
	float err;
	for (int i = 0; i < n + 1; i++)    //���ÿ����ֵ�����������   
	{
		err = 0;
		for (int j = 0; j < n; j++)    //����ÿ�������Ĵ�����
		{
			thred = threshold[i];
			feature = sam[j].feature;
			result = generate_gfunc(thred, feature, p[i]);
			if (result != sam[j].label)
			{
				err += sam[j].weight;
			}
		}
		if (err > 0.5)
		{		
			error[i] = 1 - err;
			p[i] = -1; 
		}
		else
		{
			error[i] = err;
		}
	}
//	for (int i = 0; i < n + 1; i++)
//	{
//		cout << threshold[i] << "\t" << p[i] << "\t" << error[i] << endl;
//	}
} 
//�ҳ���������С����ֵ��Ӧ����� 
int findMinerror(float *error, int n)
{
	int result;
	float minerr = 1.0; 
	for (int i = 0; i < n + 1; i ++)
	{
		if (error[i] < minerr)
		{
			minerr = error[i];
			result = i;
		}	
	} 
	return result;
}
//����alpha����
double compalpha(float error)
{
	const double eps = 1e-5;
	error = MAX(error, eps);
	error = MIN(error, 1.0 - eps);
//	cout << error << endl;
//	cout << log ((1.0 - error) / error) << endl;
	double err = (double) ((1.0 / 2.0) * (log ((1.0 - error) / error)));
	return err;	
} 
//����Ȩ�غ���
void update(Sample *sam, int numminerr, float *threshold, float *error, float *est, int *p, double alpha, int n)
{
//	cout << "Ȩ��Ϊ:" << alpha << endl;
	float tmpthred = threshold[numminerr];
//	cout<<tmpthred << endl; 
	int tmpp = p[numminerr];
//	cout << tmpp << endl;
	float sumZ = 0.0;
	int estimate;
//	cout << error[numminerr] << endl;
	for (int i = 0; i < n; i++)
	{ 
		estimate = generate_gfunc(tmpthred, sam[i].feature, tmpp);
//		cout << "������labelΪ��" << estimate << endl;
		est[i] += alpha * estimate;
		sam[i].weight = sam[i].weight * exp(-1 * alpha * sam[i].label * estimate); 
		sumZ += sam[i].weight;
	}
	for (int i = 0; i < n; i++)
	{
		sam[i].weight /= sumZ;
	}	
}
//�����Ƿ�����������������ȷ
int judgeclassify(Sample *sam, float *est, int n)
{
	int label; 
	int count = 0;                    //�ִ���������Ŀ 
	for (int i = 0; i < n; i++)
	{
		if (est[i] >= 0 && sam[i].label == -1)
		{ 
			count++;
		}
		else if (est[i] < 0 && sam[i].label == 1)
		{
			count++;
		} 
	}
	return count;
 } 
//Adaboost�������㷨 
BoostNode *adaboost(Sample *sam, int n)
{
	int ind = 0;
	float minerror = 1.0;
	int couerrsam = n;                //ͳ�Ʒִ������� 
	BoostNode *head = (BoostNode *) malloc (sizeof(BoostNode));     //ͷָ����һ����־ָ�룬δ����ʵ�ʵ�ֵ 
	head->alpha = -1.0;
	head->index = 0;
	head->p = 0;
	head->threshold = 0.0;
	BoostNode *tp = head; 
	BoostNode *tmp; 
	float *threshold = (float *) malloc ((n + 1) * sizeof(float));
	generate_threshold(threshold, sam, n);			      //�����е���ֵ 
	float *error = (float *) malloc ((n + 1) * sizeof(float)); 		
	int numminerr; 	
	double alp;	 
	int *p = (int *) malloc ((n + 1) * sizeof(int));
	float *est = (float *) malloc (n * sizeof(float));    //������ȷ�ʣ�
	for (int i = 0; i < n; i++)
	{
		est[i] = 0.0;
	} 
	while (ind < 10 && couerrsam > 0)
	{
		ind++;
		for (int i = 0; i < n + 1; i++)
		{
			p[i] = 1;
		} 
		compute_error(sam, threshold, p, error, n);
		numminerr = findMinerror(error, n);             //��������С��Ӧ����ֵ���
	//	cout << numminerr << endl;
	//	cout << error[numminerr] << endl;
		alp = compalpha(error[numminerr]);
    //	cout << alp << endl;
		tmp = (BoostNode *) malloc (sizeof(BoostNode));
		tmp->alpha = alp;
		tmp->threshold = threshold[numminerr];
		tmp->index = ind;
		tmp->p = p[numminerr];
		tp->next = tmp;
		tp = tp->next;
		update(sam, numminerr, threshold, error, est, p, alp, n);
		couerrsam = judgeclassify(sam, est, n); 	   //ʹ��sign(���ź���)�ж�ǿ����ִ��������Ŀ
//		cout << "���º������Ȩ��Ϊ:" << endl;
//		for (int i = 0; i < n; i++)
//		{
//			cout << sam[i].weight << " ";
//		}
//		cout << endl; 
	}
	tp->next = NULL;
	return head;
} 
//��ʾǿ��������Ϣ 
void showclassify(BoostNode *head)
{
	BoostNode *tmp;
	tmp = head->next;
	while (tmp != NULL)
	{
		cout << "��" << tmp->index << "������������Ϣ����ֵ������alpha) ���£�" ;
		cout << tmp->threshold << "\t" << tmp->p << "\t" << tmp->alpha << endl;
		tmp = tmp->next;
	}
} 
int main()
{
	cout << "������������������" << endl;
	int n;
	cin >> n;
	Sample *sam = (Sample *)malloc(n * sizeof(Sample));
	readSample(sam, n);
	showSample(sam, n);
	BoostNode *head = adaboost(sam, n);
	showclassify(head);
	return 0; 
}

