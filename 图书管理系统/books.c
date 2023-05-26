#include "main.h"

//创建图书通讯录
Books* create_Books() {
	Books* bk = (Books*)malloc(sizeof(Books));
	bk->count = 0;
	bk->next = NULL;
	bk->state = 0;
	return bk;
}
Books* bk = NULL;
//已有增添图书通讯录
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
// 测试函数
void test_Books(Books* bk) {
	Books* n = bk->next;
	while (n != NULL) {
		printf("%s\n", n->name);
		n = n->next;
	}
}
// 查询图书
void check_Books(Books* bk) {
	Books* p = bk->next;
	printf("请输入图书名字：");
	clearInput();
	char name[NAMESPACE];
	scanf("%s", name);
	int flag = 1;
	while (p != NULL && flag) {
		if (!strcmp(name, p->name)) {
			flag = 0;
			printf("图书名字: %s 借阅状态: %s\n", p->name, p->state == Y ? "未借阅" : "已借阅");
		}
		p = p->next;
	}
	if (flag) {
		printf("图书不存在\n");
	}
}
// 查询所有图书
void checkAllBooks(Books* bk) {
	Books* p = bk->next;
	while (p != NULL) {
		printf("图书名字: %s 借阅状态: %s\n", p->name, p->state == Y ? "未借阅" : "已借阅");
		p = p->next;
	}
}
// 借阅图书
void rent_Books(Books* bk) {
	printf("请输入要借阅的图书名字: ");
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
				
				printf("%s 借阅成功\n", p->name);
				p->state = N;
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
			}
			else printf("这本书已经被借阅，操作失败!!!\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("图书不存在\n");
	}
}
// 归还图书
void back_Books(Books* bk) {
	printf("请输入要归还的图书名字: ");
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
				printf("%s 归还成功\n", p->name);
				p->state = Y;
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
			}
			else printf("这本书未被借阅，操作失败!!!\n");
		}
		p = p->next;
	}
	if (flag) {
		printf("图书不存在\n");
	}
}
void init_Books() {
	FILE* f;
	char name[NAMESPACE] = { 0 };
	bk = create_Books();// 创建通讯录
	f = fopen("./bookdata.txt", "r+");// 从文件中读取数据
	/*
		文件格式
		0hongloumeng 0代表已经借出，1代表还在,后面代表书的名字
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