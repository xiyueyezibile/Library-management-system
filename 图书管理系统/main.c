/**
* 图书管理系统(开发日记)
* 启动：
* 创建data.txt,bookdata.txt
* data.txt里面存放账号密码
* bookdata里面存放图书信息
* 大纲
* 角色：
*	1.学生
*	2.admin
*学生操作：
*	1.查询图书(23-5-25 finished)
*	2.借阅图书(23-5-25 finished)
*	3.归还图书(23-5-25 finished)
* admin:
*	1.增加图书(23-5-25 finished)
*	2.删除图书(23-5-25 finished)
*	3.查询图书(23-5-25 finished)
*   4.修改图书(23-5-25 finished)
* 登录模块
*	1.对比账号密码完成登录(23-4-8 finished)
*	2.对admin和学生进行区分(23-5-23 finished)
* 图书模块
*	1.文件读取图书(23-4-8 finished)
*/
#include "main.h"
void menu() {
	printf("*********************************\n");
	printf("*********图书借阅系统************\n");
	printf("************1.登录***************\n");
	printf("************0.退出***************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void menu_books() {
	printf("*********************************\n");
	printf("**********学生端图书系统*********\n");
	printf("************1.查询图书***********\n");
	printf("************2.借阅图书***********\n");
	printf("************3.归还图书***********\n");
	printf("************0.退出***************\n");
	printf("*********************************\n");
}
void menu_admin() {
	printf("*********************************\n");
	printf("*********管理员端图书系统********\n");
	printf("************1.查询图书***********\n");
	printf("************2.增加图书***********\n");
	printf("************3.删除图书***********\n");
	printf("************4.修改图书***********\n");
	printf("************0.退出***************\n");
	printf("*********************************\n");
	
}
// 封装清除缓存区函数
void clearInput() {
	while (getchar() != '\n');
}
// 数据处理函数
void changeData(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')str[i] = '\0';
	}
}
// 初始化函数，对系统的初始化
void init() {
	init_Books();
}
int main() {
	FILE* file;
	//初始化配置
	init();
	//登录状态
	int isEnter = 0;
	do {
		char account[NAMESPACE] = {0};//账号
		char password[NAMESPACE] = { 0 };//密码
		menu();
		int n = 2;
		scanf("%d", &n);//1:登录 0:退出 其他:错误
		clearInput();//清空缓存区函数
		int isAdmin = 0;
		if (n == 1) {
			printf("请输入账号: \n");
			scanf("%s",account);
			if (!strcmp(account, "admin")) {
				isAdmin = 1;
			}
			clearInput();
			printf("请输入密码: \n");
			scanf("%s", password);
			clearInput();
			file = fopen("./data.txt", "r+");
			/*
				文件格式
				admin
				123456
			*/
			if (file != NULL) {
				int isaccount = 0;
				char buf[NAMESPACE] = { 0 };
				while (1) {
					char* s = fgets(buf, 20, file);
					//修改读取，使得匹配
					changeData(buf);
					// 读取完了，跳出循环
					if (s == NULL)break;
					//判断账号是否正确
					if (!strcmp(buf, account) || isaccount) {
						//如果账号输入正确则跳过判断密码，让buf变成密码部分
						if (!isaccount) {
							isaccount = 1;
							continue;
						}
						if (!strcmp(buf, password)) {
							system("cls");
							printf("登录成功\n");
							Sleep(1000);
							system("cls");
							if (isAdmin) {
								do {
									menu_admin();
									printf("请输入：");
									int s_p;
									scanf("%d", &s_p);
									// 查询图书
									if (s_p == 1) {
										check_Books(bk);
										continue;
									}
									else if (s_p == 2) {
										push_Books(bk);
										continue;
									}
									else if (s_p == 3) {
										del_Books(bk);
										continue;
									}
									else if (s_p == 4) {
										change_Books(bk);
										continue;
									}
									else if (s_p == 0) {
										break;
									}
									else {
										printf("输入错误，请重新输入\n");
										clearInput();
									}
								} while (1);
							}
							else {
								do {
									menu_books();// 打印图书菜单
									printf("请输入：");
									int s_p;
									scanf("%d", &s_p);
									// 查询图书
									if (s_p == 1) {
										check_Books(bk);
										continue;
									}
									else if (s_p == 2) {
										rent_Books(bk);
										continue;
									}
									else if (s_p == 3) {
										back_Books(bk);
										continue;
									}
									else if (s_p == 0) {
										break;
									}
									else {
										printf("输入错误，请重新输入\n");
										clearInput();
									}
								} while (1);
							}
							isEnter = 1;
							break;
						}
					}
				}
				if (!isEnter) {
					system("cls");
					printf("登录失败\n");
					Sleep(1000);
					system("cls");
				}
				fclose(file);
				file = NULL;
			}
		}
		else if (n == 0) {
			break;
		}
		else {
			printf("输入错误，请输入1/0\n");
		}
	} while (1);
	return 0;
}