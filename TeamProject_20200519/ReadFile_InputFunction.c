#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  


struct studentList
{
	//int leader;
    char leader[20];
	char company[20];
	char name[20];
	char email[20];
	char school[30];
	char major[60];

};

// �Լ� ����
// ���� �б�
// ��ȯ��: int
int fileReading(void);

// ������ ��ū ���� �� ����  
// arry[]: �ڸ� ������ ���� �迭
// ptr: ������
// ��ȯ��: int
int retToken(char* arry[], char* ptr);

// ����ü�� ������ ����
// ��ȯ��: studentList�� ������
struct studentList inputData(char arry[]);

// ��ü ����Ʈ ���� ��ȯ

int main(void) {

    int list_Num = 0;
    list_Num = malloc(MAX * MAX);
    // ����ü ����Ʈ ���� -> ���� �Ҵ��� ��� �ؾ� ����? 
    struct studentList fileList[100];

    // ���� �б�� ����ü�� ����
    fileReading();

    //fileList->leader = inputData()


}


// �Լ� ����
// fileReading �Լ�: ������ �д� �Լ�
int fileReading(void) {

    // ���� ������ 
    FILE* fp;

    int index = 0, data = 0;

    // ���� ������ ������
    char* inp;

    // ���� ������
    int buf_size = MAX * MAX;

    // ������
    char* ptr;

    // ���ڿ��� �� �迭 ������
    char* arry[MAX];

    // ���� ����
    //fp = fopen("C:\\result\\list2.csv", "r");
    fp = fopen("C:\\result\\����� ������ ���_�ѱ�ǥ����ȸ.csv", "r");

    // ũ�� ���� �Ҵ�
    inp = malloc(buf_size);


    // fgets: ���ڿ� �Է�
    while (fgets(inp, buf_size, fp)) {

        // �Լ��� arry �迭�� �ּҿ� �Է¹��� ��Ʈ���� ����. 
        index = retToken(arry, inp);

    }

    for (data = 0; data < index; data++) {

        printf("%s \n", arry[data]);

    }

    fclose(fp);

}

// retToken �Լ�: ��ū�� �������� ������ ����
int retToken(char* arry[], char* inp) {

    int i = 0;

    // strtok()�� �̿��Ͽ� ���ڿ��� ';' ��ū�� �������� �ڸ�
    // char* ptr = strtok(inp, ";");
    char* ptr = strtok(inp, "??,\n");

    char line[60] = {NULL};

    while (ptr != NULL) {

        arry[i] = ptr;
        //ptr = strtok(NULL, ";");
        strcpy(line[i], arry[i]);
        ptr = strtok(NULL, "??,\n");

        i++;

    }
    inputData(line, i);
    return i;

}

// inputData �Լ�: ����ü�� ������ ����
struct studentList inputData(char *line, int i) {

    struct studentList new_list = {NULL};
    char new_test[20] = {NULL};
    strcpy(new_test, line[0]);
    //newList.leader = arry[i-6];

    /**strcpy(new_list.leader, *arry[i - 6]);
    strcpy(new_list.company, *arry[i-6 + 1]);
    strcpy(new_list.name, *arry[i - 6 + 2]);
    strcpy(new_list.email, *arry[i - 6 + 3]);
    strcpy(new_list.school, *arry[i - 6 + 4]);
    strcpy(new_list.major, *arry[i - 6 + 5]);**/

   // strcpy(new_list.leader, new_arry[i - 6]);
   // *new_list.company = new_arry[i - 6 + 1];
   // *new_list.name = new_arry[i-6 + 2];
   // *new_list.email = new_arry[i-6 + 3];
   // *new_list.school = new_arry[i + 4];
   // *new_list.major = new_arry[i + 5];

    return new_list;

}