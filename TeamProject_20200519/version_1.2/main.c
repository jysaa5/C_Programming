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
	fp = fopen("C:\\result\\����� ������ ���_�ѱ�ǥ����ȸ.csv", "r");


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
	


	//fileList->leader = inputData()
	for (i = 0; i < 25; i++) {
		printf("%s", student_list[i].leader);
		printf("%s", student_list[i].company);
		printf("%s", student_list[i].name);
		printf("%s", student_list[i].email);
		printf("%s", student_list[i].school);
		printf("%s", student_list[i].major);
		printf("\n");
	}

	i = 0;
	
	while (strcmp(student_list[i].leader, "") != 0) {
		list_size++;
		i++;
	}
	





	//search
	int select_num = 0;
	char input[60];
	time_t t;
	char ans = 0;


	

	while (1) {

		//�޴� ȣ��
		select_num = menu();


		switch (select_num) {


		case 1:
			t = time(NULL);


			//�˻� �Լ�
			searchingLeader(student_list, list_size, t);


			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}

			break;

		case 2:
			//�˻��� ������ �Է¹ޱ�
			printf("\n�˻��ϰ��� �ϴ� ȸ����� �Է����ּ���.\n");
			scanf("%s", &input);
			getchar();
			t = time(NULL);


			//�˻� �Լ�
			searchingCompany(student_list, list_size, input, t);

		
			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}
				

			break;

		case 3:
			//�˻��� ������ �Է¹ޱ�
			printf("\n�˻��ϰ��� �ϴ� �̸��� �Է����ּ���.\n");
			scanf("%s", &input);
			getchar();
			t = time(NULL);


			//�˻� �Լ�
			searchingName(student_list, list_size, input, t);


			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}


			break;

		case 4:
			//�˻��� ������ �Է¹ޱ�
			printf("\n�˻��ϰ��� �ϴ� E-mail�� �Է����ּ���.\n");
			scanf("%s", &input);
			getchar();
			t = time(NULL);


			//�˻� �Լ�
			searchingEmail(student_list, list_size, input, t);


			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}

			break;

		case 5:
			//�˻��� ������ �Է¹ޱ�
			printf("\n�˻��ϰ��� �ϴ� �б��� �Է����ּ���.\n");
			scanf("%s", &input);
			getchar();
			t = time(NULL);


			//�˻� �Լ�
			searchingSchool(student_list, list_size, input, t);


			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}

			break;

		case 6:
			//�˻��� ������ �Է�
			printf("\n�˻��ϰ��� �ϴ� ������ �Է����ּ���.\n");
			scanf("%s", &input);
			getchar();
			t = time(NULL);


			//�˻� �Լ�
			searchingMajor(student_list, list_size, input, t);
			
			
			//���α׷� ����
			printf("\n���α׷��� �����Ͻðڽ��ϱ�?(y/n) : ");
			ans = getchar();

			if (ans == 'y')
			{
				free(student_list);
				fclose(fp);
				return 0;
			}
				

			break;


		default:

			select_num = menu();
			break;
		}
	}


	free(student_list);
	fclose(fp);

	return 0;
;
}