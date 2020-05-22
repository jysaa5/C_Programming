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
	//���� ����
	int i = 0;
	int list_size = 0;
	int line_count = 0;
	FILE* fp;
	char *dir = "C:\\result\\����� ������ ���_�ѱ�ǥ����ȸ.csv";


	//���� ��Ʈ�� ����
	fp = fopen(dir, "r");


	//���� �Ҵ��� ���� ũ��
	line_count = getFileSize(dir);

	//���� ũ�⿡ �´�
	//�޸� ���� �Ҵ�
	struct studentList* student_list = (struct studentList*)malloc(sizeof(struct studentList) * line_count);



	// ���� �о�� ����ü�� ����
	for (i = 0; i < line_count; i++)
	{
		student_list[i] = fileLineReading(fp);
	}



	//��ü ����Ʈ count
	i = 0;
	
	while (strcmp(student_list[i].leader, "") != 0) {
		list_size++;
		i++;
	}


	//�޴� ���
	menu(student_list, list_size);

	


	//�޸� ��ȯ�� ���� ��Ʈ�� �ݱ�
	free(student_list);
	fclose(fp);

	return 0;
;
}