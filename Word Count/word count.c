#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��������
int WordCount(char file[]) {
    FILE* p = NULL;
    int wcount = 0;
    p = fopen(file, "r");
    if (p == NULL) {
        printf("Ѱ���ļ�ʧ��\n");
        return -1;
    }
    //��ǰָ����ָ���ַ�
    char mychar;
    mychar = fgetc(p);
    while (mychar != -1) {
        if (mychar >= 'a' && mychar <= 'z' || mychar >= 'A' && mychar <= 'Z' || mychar >= '0' && mychar <= '9') {
            //������һ������
            while (mychar >= 'a' && mychar <= 'z' || mychar >= 'A' && mychar <= 'Z' || mychar >= '0' && mychar <= '9' || mychar == '_') {
                mychar = fgetc(p);
            }
            wcount++;
            mychar = fgetc(p);
        }
        mychar = fgetc(p);
    }
    fclose(p);
    return wcount;
}
//�ַ�(Ӣ��)����
int CharCount(char file[]) {
    int cCount = 0;
    FILE* p = NULL;
    p = fopen(file, "r");
    if (p == NULL) {
        printf("Ѱ���ļ�ʧ��\n");
        return -1;
    }
    while (fgetc(p) != -1) {
        cCount++;
    }
    fclose(p);
    return cCount;

}
int main() {

    //����ʹ��git�йܴ���
    char input,File[100];
    while (1) {
        printf("�������û����wc.exe-");
        scanf("%s", &input);
        printf("�������ļ�����");
        scanf("%s", &File);
        if (input == 'w') {
            int wordcount = 0;
            wordcount = WordCount(File);
            printf("�ļ��Ĵ���Ϊ��%d\n", wordcount);
        }
        else if (input == 'c') {
            int charCount = 0;
            charCount = CharCount(File);
            printf("�ļ��Ĵ���Ϊ��%d\n", charCount);
        }
    }
    return 0;
}