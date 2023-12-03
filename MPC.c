#include <stdio.h>
#include <stdlib.h>

int c[6][6] = {0};
int kay[6][6] = {0};
int r[7] = {0};

int RC(int i, int j){
    if(c[i][j] > 0){
        return c[i][j];
    }
    if(i == j){//one matrix
        return 0;
    }
    if( j-i == 1){//two matrices
        kay[i][i+1] = i;
        c[i][j] = r[i]*r[i+1]*r[i+2];
        return c[i][j];
    }
    int u = RC(i,i) + RC(i+1,j) + r[i]*r[i+1]*r[j+1];
    kay[i][j] = i;
    for(int tt = i+1;tt < j;tt++){
        int temp = RC(i,tt) + RC(tt+1,j) + r[i]*r[tt+1]*r[j+1];     //注意这里是tt+1
        if(temp < u){
            u = temp;
            kay[i][j] = tt;
        }
    }
    c[i][j] = u;
    return u;
}

void TraceBack(int i, int j){
    if(i == j){
        return;
    }
    TraceBack(i,kay[i][j]);
    TraceBack(kay[i][j] + 1, j);
    printf("Multiply M %d , %d",i+1,kay[i][j]+1);       //这里整体+1是为了最小从1开始
    printf(" and M %d, %d\n",kay[i][j]+2, j+1);
}

int main(){
    r[0] = 5;
    r[1] = 10;
    r[2] = 3;
    r[3] = 12;
    r[4] = 5;
    r[5] = 50;
    r[6] = 6;
    RC(0,5);
    TraceBack(0,5);
    printf("%d\n",c[0][5]);
    system("pause");
    return 0;
}