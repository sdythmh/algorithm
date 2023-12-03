#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* manacher(char* s){
    int* p = (int*)malloc(sizeof(int)*(2*strlen(s)+2));
    char* t = (char*)malloc(2*strlen(s)+3);
    int m = 0;
    int maxP = 0;
    t[++m] = '?';       //m从1开始
    for(int i=0;i<strlen(s);i++){
        t[++m] = s[i];
        t[++m] = '?';
    }
    t[++m] = '\0';
    int M = 0, R = 0;//M为最大回文中心，R最右边界
    for(int i=1;i<=m-1;i++){
        if(i > R){
            p[i] = 1;
        }else{
            p[i] = p[2*M-i] < R-i+1 ? p[2*M-i] : R-i+1;
        }
        while((i-p[i]) >= 1 && (i+p[i]) <= m-1 && (t[i-p[i]] == t[i+p[i]])){
            p[i]++;
        }
        if(maxP < p[i]){
            maxP = p[i];        //这里要添加一个maxP保存最大的p[i]值
            M = i;
            R = i+p[i]-1;
        }
    }
    char* result = (char*)malloc(R-M+1);
    int qaq = 0;
    for(int i=2*M-R;i<= R;i++){     //R-(2M-R)+1
        if(t[i] != '?'){
            result[qaq++] = t[i];
        }
    }
    result[qaq] = '\0';
    return result;
}

int main(){
    char input[] = "abab";
    char* result = manacher(input);
    printf("%s\n", result);
    free(result); // 释放内存
    system("pause");
    return 0;
}