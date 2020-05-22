#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>  
#include "studentP.h"

#define MAX 1024
#define COL 6



int menu()
{
	int num = 0;
	printf("���Ͻô� �޴��� �������ּ���\n");
	printf("1. ���� �˻�\n");
	printf("2. ȸ��� �˻�\n");
	printf("3. �̸� �˻�\n");
	printf("4. Email �˻�\n");
	printf("5. �б� �˻�\n");
	printf("6. ���� �˻�\n");
	scanf("%d", &num);
	getchar();

	return num;
}


//���� ���� ũ�⸦ ��ȯ�ϴ� �Լ�
int getFileSize(char* dir)
{
	//���� ����
	FILE* fp = fopen(dir, "r");
	char* str = 0 ;
	int buf_size = MAX * MAX;
	int line_count = 0;

	// ũ�� ���� �Ҵ�
	str = (char*)malloc(buf_size);

	//���� �Ҵ翡 ����� ���� ũ�� ����
	while (fgets(str, buf_size, fp)) {

		line_count++;

	}

	free(str);
	fclose(fp);
	return line_count;

}


// �Լ� ����
// fileReading �Լ�: ������ �д� �Լ�
struct studentList fileLineReading(FILE* fp) {

	//���� ����
	// ���� ������ ������
	char* str;

	// ���� ������
	int buf_size = MAX * MAX;

	// ������
	char* ptr;

	int line_count = 0;


	int i = 0;

	//���� ����
	//fp = fopen(dir, "r");


	// ũ�� ���� �Ҵ�
	str = (char*)malloc(buf_size);
	

	//��ȯ�� ������ ���
	struct studentList line;


	ptr = fgets(str, buf_size, fp);
	//getchar();
	line = retToken(ptr);



	free(str);

	return line;

}

// retToken �Լ�: ��ū�� �������� ������ ����
struct studentList retToken(char* ptr) {

	int i = 0;

	// strtok()�� �̿��Ͽ� ���ڿ��� ';' ��ū�� �������� �ڸ�
	// char* ptr = strtok(inp, ";");
	char* ptoken = strtok(ptr, "??,\n");
	char* line[COL] = { NULL };
	struct studentList list_line;



	while (ptoken != NULL) {

		//arry[i] = ptr;

		if (i == 0 && (strcmp(ptoken, "����") != 0) && strcmp(ptoken, "���� ����") != 0) {
			line[0] = "����";
			line[i + 1] = ptoken;
			/*
			strcpy(line[0], "����");
			strcpy(line[i + 1], token);
			*/
		}
		else if (i == 0 && strcmp(ptoken, "����") == 0 || strcmp(ptoken, "���� ����") == 0) {
			line[i] = ptoken;
		}
		else if (strcmp(line[0], "����") == 0) {
			line[i + 1] = ptoken;
			//strcpy(line[i + 1], token);
		}
		else {
			line[i] = ptoken;
			//strcpy(*line[i], token);
		}

		ptoken = strtok(NULL, "??,\"\n");

		i++;

	}


	list_line = inputData(line);

	return list_line;
}



// inputData �Լ�: ����ü�� ������ ����
struct studentList inputData(char** line) {


	struct studentList list_line;


	strcpy(list_line.leader, line[0]);
	strcpy(list_line.company, line[1]);
	strcpy(list_line.name, line[2]);
	strcpy(list_line.email, line[3]);
	strcpy(list_line.school, line[4]);
	strcpy(list_line.major, line[5]);


	return list_line;
}






void searchingLeader(struct studentList* student_list, int list_size, time_t t) {

	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].leader, "����") == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");



	//�˻� ����� ������
	//�޸� ���� �Ҵ�
	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);

	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].leader, "����") == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);

			j++;
		}
	}


	//�˻� ��� ���
	searchResultPrintf(result_list, count);


	//���� ���
	fileWriting(result_list, t, count);


	//�޸� ��ȯ
	free(result_list);
}

void searchingCompany(struct studentList* student_list, int list_size, char *input, time_t t) {

	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].company, input) == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");

	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);


	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].company, input) == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);
			
			j++;
		}
	}

	
	//�˻� ��� ���
	searchResultPrintf(result_list, count);

	//���� ���
	fileWriting(result_list, t, count);

	//�޸� ��ȯ
	free(result_list);
}

void searchingName(struct studentList* student_list, int list_size, char *input, time_t t) {

	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].name, input) == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");

	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);

	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].name, input) == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);

			j++;

		}
	}

	//�˻� ��� ���
	searchResultPrintf(result_list, count);

	//���� ���
	fileWriting(result_list, t, count);

	//�޸� ��ȯ
	free(result_list);
}

void searchingEmail(struct studentList* student_list, int list_size, char *input, time_t t) {

	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].email, input) == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");

	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);

	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].email, input) == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);

			j++;
		}
	}

	//�˻� ��� ���
	searchResultPrintf(result_list, count);

	//���� ���
	fileWriting(result_list, t, count);

	//�޸� ��ȯ
	free(result_list);
}

void searchingSchool(struct studentList* student_list, int list_size, char *input, time_t t) {

	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].school, input) == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");

	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);

	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].school, input) == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);

			j++;
		}
	}

	//�˻� ��� ���
	searchResultPrintf(result_list, count);

	//���� ���
	fileWriting(result_list, t, count);

	//�޸� ��ȯ
	free(result_list);
}



//���� �˻� �Լ�
void searchingMajor(struct studentList* student_list, int list_size, char *input, time_t t) 
{
	//���� ����
	int count = 0;
	int i, j = 0;

	for (int i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].major, input) == 0) {
			count++;
		}
	}

	if (count == 0)
		printf("����� �����ϴ�.\n");


	//�˻� ��� ũ�⿡ �´�
	//�޸� ���� �Ҵ�
	struct studentList* result_list = (struct studentList*) malloc(sizeof(struct studentList) * count);

	for (i = 0; i < list_size; i++) {

		if (strcmp(student_list[i].major, input) == 0) {

			strcpy(result_list[j].leader, student_list[i].leader);
			strcpy(result_list[j].company, student_list[i].company);
			strcpy(result_list[j].name, student_list[i].name);
			strcpy(result_list[j].email, student_list[i].email);
			strcpy(result_list[j].school, student_list[i].school);
			strcpy(result_list[j].major, student_list[i].major);

			j++;
		}
	}


	//�˻� ��� ���
	searchResultPrintf(result_list, count);


	//���� ���
	fileWriting(result_list, t, count);


	//�޸� ��ȯ
	free(result_list);
}



//�˻� ��� ��� �Լ�
void searchResultPrintf(struct studentList *result_list, int count)
{
	//���� ����
	int i = 0;


	//�˻� ����� ����ϴ� �ݺ���
	for (i; i < count; i++)
	{
		printf("\n%s %s %s %s %s %s\n", result_list[i].leader, result_list[i].company, result_list[i].name, result_list[i].email, result_list[i].school, result_list[i].major);
	}
}



//���� ��� �Լ�
void fileWriting(struct studentList *list, time_t time, int count)
{
	//���� ����
	FILE* ofp;
	int i= 0;


	//����� ����
	ofp = fopen("C:\\result\\result.txt", "w");

	if (ofp == NULL)
	{
		printf("��� ������ ���� ���߽��ϴ�\n");
	}


	//�˻��� ����� �˻��ð���
	//���Ϸ� ���
	for (i = 0; i < count; i++)
	{
		fprintf(ofp, "%s %s %s %s %s %s %s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major, ctime(&time));

	};

	//������ ��ȯ
	fclose(ofp);
}