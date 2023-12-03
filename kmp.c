#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//next数组从1位置开始定义
void getNext(char* substr, int len, int* &next){
    int j=1;
    int t = 0;
    next[1] = 0;
    while(j < len){
        if(t ==0 || substr[t-1] == substr[j-1]){        //注意这里从字符数组的t-1处开始
            next[j+1] = t+1;
            t++;
            j++;
        }else{
            t = next[t];
        }
    }
}
//升级版next数组
void getNextval(char* substr, int len, int* &nextVal){
    int j = 1;
    int t = 0;
    nextVal[1] = 0;
    while(j < len){
        if(t == 0|| substr[t-1] == substr[j-1]){
            if(substr[t] != substr[j]){
                nextVal[j+1] = t+1;
            }else{
                nextVal[j+1] = nextVal[t+1];
            }
            j++;
            t++;
        }else{
            t = nextVal[t];
        }
    }
}
int kmp(char* mainStr, char* substr, int mainLen, int subLen){
    int *next = (int*)malloc((subLen+1)*sizeof(int));
    getNextval(substr,subLen,next);
    int i=1,j=1;
    while(i <= mainLen && j <= subLen){
        if(j == 0 || mainStr[i-1] == substr[j-1]){      //注意这里从字符数组的t-1处开始
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j > subLen){
        free(next);
        return i-subLen;
    }else{
        free(next);
        return 0;
    }
}

int main(){
    char *mainStr = "abdfsgsef";
    char subStr[5] = "sg";
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);
    int index = kmp(mainStr,subStr,mainLen,subLen);
    if(index != 0){
        printf("子串位置从第%d处开始\n",index);
    }else{
        printf("未找到子串\n");
    }
    system("pause");
    return 1;
}