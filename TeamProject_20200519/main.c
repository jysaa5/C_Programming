#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "studentP.h"

#define MAX 1024

void main(void)
{
	//input data
	int list_Num = 0;
	list_Num = malloc(MAX * MAX);
	// ����ü ����Ʈ ���� -> ���� �Ҵ��� ��� �ؾ� ����? 
	struct studentList fileList[100];

	// ���� �б�� ����ü�� ����
	struct studentList *student_list = fileReading();

	int select_num = 0;
	char input[60];
	int list_size = 2;
	time_t t;

	while (1) {

		select_num = menu();

		switch (select_num) {

		case 0:

			select_num = menu();
			break;

		case 1:
			t = time(NULL);
			searchingLeader(student_list, list_size, t);
			break;

		case 2:

			printf("�˻��ϰ��� �ϴ� ȸ����� �Է����ּ���.\n");
			scanf("%s", &input);
			t = time(NULL);
			searchingCompany(student_list, list_size, input, t);
			break;

		case 3:

			printf("�˻��ϰ��� �ϴ� �̸��� �Է����ּ���.\n");
			scanf("%s", &input);
			t = time(NULL);
			searchingName(student_list, list_size, input, t);
			break;

		case 4:

			printf("�˻��ϰ��� �ϴ� E-mail�� �Է����ּ���.\n");
			scanf("%s", &input);
			t = time(NULL);
			searchingEmail(student_list, list_size, input, t);
			break;

		case 5:

			printf("�˻��ϰ��� �ϴ� �б��� �Է����ּ���.\n");
			scanf("%s", &input);
			t = time(NULL);
			searchingSchool(student_list, list_size, input, t);
			break;

		case 6:

			printf("�˻��ϰ��� �ϴ� ������ �Է����ּ���.\n");
			scanf("%s", &input);
			t = time(NULL);
			searchingMajor(student_list, list_size, input, t);
			break;


		default:

			select_num = menu();
			break;
		}
	}
	return 0;
	

	return 0;
}