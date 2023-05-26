#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NAMESPACE 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
enum STATE {
	Y='1',
	N='0'
};
//����ͼ��ͨѶ¼
typedef struct Books {
	char name[NAMESPACE];//����
	char state;//״̬
	struct Books* next;
	int count;//����
	char rent_name[NAMESPACE];// ����������
}Books;
// ��¶ͼ���б�
extern Books* bk;
//�޸����뺯��
extern void changeData(char* str);
//��ʼ��ͼ��ͨѶ¼����
extern void init_Books();
// ������溯��
extern void clearInput();
/*ѧ���˲�������*/
// ��ѯͼ��
extern void check_Books(Books* bk);
// ����ͼ��
extern void rent_Books(Books* bk);
// �黹ͼ��
extern void back_Books(Books* bk);
/*����Ա��*/
// ����ͼ��
extern void push_Books(Books* bk);
// ɾ��ͼ��
extern void del_Books(Books* bk);
// �޸�ͼ��
extern void change_Books(Books* bk);
// ��ѯ����ͼ��
extern void checkAllBooks(Books* bk);