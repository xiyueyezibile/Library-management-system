#include "main.h"

//����ͼ��ͨѶ¼
Books* create_Books() {
	Books* bk = (Books*)malloc(sizeof(Books));
	bk->count = 0;
	bk->next = NULL;
	bk->state = 0;
	return bk;
}
Books* bk = NULL;
//��������ͼ��ͨѶ¼
int add_Books(Books* bk, char* name) {
	Books* n = (Books*)malloc(sizeof(Books));
	for (int i = 1; *(name + i) != '\0'; i++) {
		n->name[i - 1] = *(name + i);
		n->name[i] = '\0';
	}
	n->state = *(name);
	n->next = bk->next;
	bk->next = n;
	bk->count++;
	return 1;
}
// ���Ժ���
void test_Books(Books* bk) {
	Books* n = bk->next;
	while (n != NULL) {
		printf("%s\n", n->name);
		n = n->next;
	}
}
// ��ѯͼ��
void check_Books(Books* bk) {
	Books* p = bk->next;
	printf("������ͼ�����֣�");
	clearInput();
	char name[NAMESPACE];
	scanf("%s", name);
	int flag = 1;
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("ͼ������: %s ����״̬: %s\n", p->name, p->state == Y ? "δ����" : "�ѽ���");
		}
		p = p->next;
	}
	if (flag) {
		printf("ͼ�鲻����\n");
	}
}
// ��ѯ����ͼ��
void checkAllBooks(Books* bk) {
	Books* p = bk->next;
	while (p != NULL) {
		printf("ͼ������: %s ����״̬: %s\n", p->name, p->state == Y ? "δ����" : "�ѽ���");
		p = p->next;
	}
}
// ����ͼ��
void rent_Books(Books* bk) {
	printf("������Ҫ���ĵ�ͼ������: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			system("cls");
			if (p->state == Y) {
				
				printf("%s ���ĳɹ�\n", p->name);
				p->state = N;
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
			}
			else printf("�Ȿ���Ѿ������ģ�����ʧ��!!!\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("ͼ�鲻����\n");
	}
}
// �黹ͼ��
void back_Books(Books* bk) {
	printf("������Ҫ�黹��ͼ������: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			system("cls");
			if (p->state == N) {
				printf("%s �黹�ɹ�\n", p->name);
				p->state = Y;
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
			}
			else printf("�Ȿ��δ�����ģ�����ʧ��!!!\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("ͼ�鲻����\n");
	}
}
void init_Books() {
	FILE* f;
	char name[NAMESPACE] = { 0 };
	bk = create_Books();// ����ͨѶ¼
	f = fopen("./bookdata.txt", "r+");// ���ļ��ж�ȡ����
	/*
		�ļ���ʽ
		0hongloumeng 0�����Ѿ������1������,��������������
	*/
	if (f != NULL) {
		while (1) {
			char* s = fgets(name, 20, f);
			if (s == NULL)break;
			changeData(name);
			add_Books(bk, name);
		}
		fclose(f);
		f = NULL;
	}
	//test_Books(bk);
}