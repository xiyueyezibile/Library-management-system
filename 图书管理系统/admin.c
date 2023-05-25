#include "main.h"
// 新增图书
void push_Books(Books* bk) {
	printf("请输入图书名字: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	system("cls");
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("图书已存在\n");
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
		f = fopen("./bookdata.txt", "w");// 从文件中读取数据
		/*
			文件格式
			0hongloumeng 0代表已经借出，1代表还在,后面代表书的名字
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
		printf("添加成功\n");
	}
}
// 删除图书
void del_Books(Books* bk) {
	printf("请输入图书名字: ");
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
			f = fopen("./bookdata.txt", "w");// 从文件中读取数据
			/*
				文件格式
				0hongloumeng 0代表已经借出，1代表还在,后面代表书的名字
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
			printf("删除成功\n");
		}
		m = p;
		p = p->next;
	}
	if (flag) {
		printf("图书不存在\n");
	}
}
// 修改图书
void change_Books(Books* bk) {
	printf("请输入图书名字: ");
	char name[NAMESPACE];
	clearInput();
	scanf("%s", name);
	Books* p = bk->next;
	int flag = 1;
	system("cls");
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("请输入要修改的名字: ");
			clearInput();
			scanf("%s", p->name);
			FILE* f;
			f = fopen("./bookdata.txt", "w");// 从文件中读取数据
			/*
				文件格式
				0hongloumeng 0代表已经借出，1代表还在,后面代表书的名字
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
			printf("修改成功\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("图书不存在\n");
	}
}