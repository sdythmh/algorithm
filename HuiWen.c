#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//https://leetcode.cn/problems/longest-palindromic-substring/?envType=study-plan-v2&envId=top-interview-150
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) {          //如果长度小于2，则为回文直接返回
        return s;
    }

    int maxLen = 1;
    int begin = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    bool dp[len][len];
    // 初始化：所有长度为 1 的子串都是回文串
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
             dp[i][j] = (i ==j) ? true : false;
        }
    }

    // 先枚举子串长度
    for (int L = 2; L <= len; L++) {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < len; i++) {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;
            // 如果右边界越界，就可以退出当前循环
            if (j >= len) {
                break;
            }

            if (s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if (j - i < 3) {            //j到i总共3个元素
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen) {       //用于接下来构建回文字符串
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }

    // 构建回文字符串
    char* result = (char*)malloc(maxLen + 1);
    strncpy(result, s + begin, maxLen);
    result[maxLen] = '\0';

    return result;
}

int expandFromCenter(char*s, int left, int right){
    while(left >=0 && right < strlen(s) && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left -1;
}

char* longestPalindrome2(char* s){
    int start = 0;
    int end = 0;
    int len = 0;
    int maxLen = 0;                 //还要单独定义一个maxLen
    for(int i=0;i<strlen(s);i++){
        int len1 = expandFromCenter(s,i,i);
        int len2 = expandFromCenter(s,i,i+1);
        len = (len1 > len2) ? len1 : len2;
        if(len > end - start){
            start = i - (len-1)/2;
            end = i + len/2;
            maxLen = len;
        }
    }
    char* result = (char*)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}

int main() {
    char input[] = "a";
    char* result = longestPalindrome2(input);
    printf("%s\n", result);
    free(result); // 释放内存
    system("pause");
    return 0;
}
