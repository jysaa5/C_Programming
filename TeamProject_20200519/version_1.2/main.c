#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>  
#include "studentP.h"

#define MAX 1024
#define DIR_SIZE 100


int main(void)
{
	//input data
	int i = 0;
	int list_size = 0;
	int line_count = 0;


	FILE* fp;
	char *dir = "C:\\result\\����� ������ ���_�ѱ�ǥ����ȸ.csv";


	//���� ����
	fp = fopen(dir, "r");


	//���� �Ҵ��� ���� ũ��
	line_count = getFileSize(dir);

	//���� ������ ����ü
	//���� �Ҵ�
	struct studentList* student_list = (struct studentList*)malloc(sizeof(struct studentList) * line_count);



	// ���� �б�� ����ü�� ����
	for (i = 0; i < line_count; i++)
	{
		student_list[i] = fileLineReading(fp);
	}



	i = 0;
	
	while (strcmp(student_list[i].leader, "") != 0) {
		list_size++;
		i++;
	}


	//�޴� ���
	menu(student_list, list_size);

	


	free(student_list);
	fclose(fp);

	return 0;
;
}