#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//单词数量
int WordCount(char file[]) {
    FILE* p = NULL;
    int wcount = 0;
    p = fopen(file, "r");
    if (p == NULL) {
        printf("寻找文件失败\n");
        return -1;
    }
    //当前指针所指的字符
    char mychar;
    mychar = fgetc(p);
    while (mychar != -1) {
        if (mychar >= 'a' && mychar <= 'z' || mychar >= 'A' && mychar <= 'Z' || mychar >= '0' && mychar <= '9') {
            //遍历整一个单词
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
//字符(英文)数量
int CharCount(char file[]) {
    int cCount = 0;
    FILE* p = NULL;
    p = fopen(file, "r");
    if (p == NULL) {
        printf("寻找文件失败\n");
        return -1;
    }
    while (fgetc(p) != -1) {
        cCount++;
    }
    fclose(p);
    return cCount;

}
int main() {

    //测试使用git托管代码
    char input,File[100];
    while (1) {
        printf("请输入用户命令：wc.exe-");
        scanf("%s", &input);
        printf("请输入文件名：");
        scanf("%s", &File);
        if (input == 'w') {
            int wordcount = 0;
            wordcount = WordCount(File);
            printf("文件的词数为：%d\n", wordcount);
        }
        else if (input == 'c') {
            int charCount = 0;
            charCount = CharCount(File);
            printf("文件的词数为：%d\n", charCount);
        }
    }
    return 0;
}