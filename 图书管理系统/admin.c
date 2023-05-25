#include "main.h"
// ����ͼ��
void push_Books(Books* bk) {
	printf("������ͼ������: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	system("cls");
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("ͼ���Ѵ���\n");
		}
		p = p->next;
	}
	if (flag) {
		Books* m = (Books*)malloc(sizeof(Books));
		int i = 0;
		while (name[i] != '\0') {
			m->name[i] = name[i];
			i++;
		}
		m->name[i] = '\0';
		m->state = '1';
		m->next = bk->next;
		bk->next = m;
		FILE* f;
		f = fopen("./bookdata.txt", "w");// ���ļ��ж�ȡ����
		/*
			�ļ���ʽ
			0hongloumeng 0�����Ѿ������1������,��������������
		*/
		if (f != NULL) {
			Books* b = bk->next;
			while (b != NULL) {
				fprintf(f, "%c%s\n", b->state, b->name);
				b = b->next;
			}
			fclose(f);
			f = NULL;
		}
		printf("��ӳɹ�\n");
	}
}
// ɾ��ͼ��
void del_Books(Books* bk) {
	printf("������ͼ������: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	Books* m = bk;
	int flag = 1;
	system("cls");
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			m->next = p->next;
			free(p);
			FILE* f;
			f = fopen("./bookdata.txt", "w");// ���ļ��ж�ȡ����
			/*
				�ļ���ʽ
				0hongloumeng 0�����Ѿ������1������,��������������
			*/
			if (f != NULL) {
				Books* b = bk->next;
				while (b != NULL) {
					fprintf(f, "%c%s\n", b->state, b->name);
					b = b->next;
				}
				fclose(f);
				f = NULL;
			}
			printf("ɾ���ɹ�\n");
		}
		m = p;
		p = p->next;
	}
	if (flag) {
		printf("ͼ�鲻����\n");
	}
}
// �޸�ͼ��
void change_Books(Books* bk) {
	printf("������ͼ������: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	system("cls");
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("������Ҫ�޸ĵ�����: ");
			clearInput();
			scanf("%s", p->name);
			FILE* f;
			f = fopen("./bookdata.txt", "w");// ���ļ��ж�ȡ����
			/*
				�ļ���ʽ
				0hongloumeng 0�����Ѿ������1������,��������������
			*/
			if (f != NULL) {
				Books* b = bk->next;
				while (b != NULL) {
					fprintf(f, "%c%s\n", b->state, b->name);
					b = b->next;
				}
				fclose(f);
				f = NULL;
			}
			printf("�޸ĳɹ�\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("ͼ�鲻����\n");
	}
}