/**
* ͼ�����ϵͳ(�����ռ�)
* ������
* ����data.txt,bookdata.txt
* data.txt�������˺�����
* bookdata������ͼ����Ϣ
* ���
* ��ɫ��
*	1.ѧ��
*	2.admin
*ѧ��������
*	1.��ѯͼ��(23-5-25 finished)
*	2.����ͼ��(23-5-25 finished)
*	3.�黹ͼ��(23-5-25 finished)
* admin:
*	1.����ͼ��(23-5-25 finished)
*	2.ɾ��ͼ��(23-5-25 finished)
*	3.��ѯͼ��(23-5-25 finished)
*   4.�޸�ͼ��(23-5-25 finished)
* ��¼ģ��
*	1.�Ա��˺�������ɵ�¼(23-4-8 finished)
*	2.��admin��ѧ����������(23-5-23 finished)
* ͼ��ģ��
*	1.�ļ���ȡͼ��(23-4-8 finished)
*/
#include "main.h"
void menu() {
	printf("*********************************\n");
	printf("*********ͼ�����ϵͳ************\n");
	printf("************1.��¼***************\n");
	printf("************0.�˳�***************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void menu_books() {
	printf("*********************************\n");
	printf("**********ѧ����ͼ��ϵͳ*********\n");
	printf("************1.��ѯͼ��***********\n");
	printf("************2.����ͼ��***********\n");
	printf("************3.�黹ͼ��***********\n");
	printf("************0.�˳�***************\n");
	printf("*********************************\n");
}
void menu_admin() {
	printf("*********************************\n");
	printf("*********����Ա��ͼ��ϵͳ********\n");
	printf("************1.��ѯͼ��***********\n");
	printf("************2.����ͼ��***********\n");
	printf("************3.ɾ��ͼ��***********\n");
	printf("************4.�޸�ͼ��***********\n");
	printf("************0.�˳�***************\n");
	printf("*********************************\n");
	
}
// ��װ�������������
void clearInput() {
	while (getchar() != '\n');
}
// ���ݴ�����
void changeData(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')str[i] = '\0';
	}
}
// ��ʼ����������ϵͳ�ĳ�ʼ��
void init() {
	init_Books();
}
int main() {
	FILE* file;
	//��ʼ������
	init();
	//��¼״̬
	int isEnter = 0;
	do {
		char account[NAMESPACE] = {0};//�˺�
		char password[NAMESPACE] = { 0 };//����
		menu();
		int n = 2;
		scanf("%d", &n);//1:��¼ 0:�˳� ����:����
		clearInput();//��ջ���������
		int isAdmin = 0;
		if (n == 1) {
			printf("�������˺�: \n");
			scanf("%s",account);
			if (!strcmp(account, "admin")) {
				isAdmin = 1;
			}
			clearInput();
			printf("����������: \n");
			scanf("%s", password);
			clearInput();
			file = fopen("./data.txt", "r+");
			/*
				�ļ���ʽ
				admin
				123456
			*/
			if (file != NULL) {
				int isaccount = 0;
				char buf[NAMESPACE] = { 0 };
				while (1) {
					char* s = fgets(buf, 20, file);
					//�޸Ķ�ȡ��ʹ��ƥ��
					changeData(buf);
					// ��ȡ���ˣ�����ѭ��
					if (s == NULL)break;
					//�ж��˺��Ƿ���ȷ
					if (!strcmp(buf, account) || isaccount) {
						//����˺�������ȷ�������ж����룬��buf������벿��
						if (!isaccount) {
							isaccount = 1;
							continue;
						}
						if (!strcmp(buf, password)) {
							system("cls");
							printf("��¼�ɹ�\n");
							Sleep(1000);
							system("cls");
							if (isAdmin) {
								do {
									menu_admin();
									printf("�����룺");
									int s_p;
									scanf("%d", &s_p);
									// ��ѯͼ��
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
										printf("�����������������\n");
										clearInput();
									}
								} while (1);
							}
							else {
								do {
									menu_books();// ��ӡͼ��˵�
									printf("�����룺");
									int s_p;
									scanf("%d", &s_p);
									// ��ѯͼ��
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
										printf("�����������������\n");
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
					printf("��¼ʧ��\n");
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
			printf("�������������1/0\n");
		}
	} while (1);
	return 0;
}