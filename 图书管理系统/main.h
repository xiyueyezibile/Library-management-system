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
//定义图书通讯录
typedef struct Books {
	char name[NAMESPACE];//名字
	char state;//状态
	struct Books* next;
	int count;//数量
	char rent_name[NAMESPACE];// 借阅人名字
}Books;
// 暴露图书列表
extern Books* bk;
//修改输入函数
extern void changeData(char* str);
//初始化图书通讯录函数
extern void init_Books();
// 清除缓存函数
extern void clearInput();
/*学生端操作函数*/
// 查询图书
extern void check_Books(Books* bk);
// 借阅图书
extern void rent_Books(Books* bk);
// 归还图书
extern void back_Books(Books* bk);
/*管理员端*/
// 新增图书
extern void push_Books(Books* bk);
// 删除图书
extern void del_Books(Books* bk);
// 修改图书
extern void change_Books(Books* bk);
// 查询所有图书
extern void checkAllBooks(Books* bk);