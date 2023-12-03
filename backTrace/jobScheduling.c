/*回溯法之流水作业调度问题*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define max(x,y) ((x)>(y)? (x):(y))		//自定义max函数，求解x,y中的最大值
int n=4;								//作业数
int a[MAX]={0,5,12,4,8};				//作业在M1上的执行时间，从数组下标1开始
int b[MAX]={0,6,2,14,7};				//作业在M2上的执行时间，从数组下标1开始
int bestf;								//存放最优的调度时间
int f1;
int f2[MAX];
int x[MAX];								//当前的调度方案 
int bestx[MAX];							//存放当前作业的最优调度方案
int sum = 10000000;

void swap(int &x,int &y)				//交换x,y
{
	int temp=x;
	x=y;
	y=temp;
 }
void dfs(int i)						//从第i层开始使用深度优先遍历
{
	if(i>n)							//达到叶子节点，产生一种调度方案 
	{
		if(f2[n]<bestf)
		{
			bestf=f2[n];
			int temp = 0;
			for(int i=1;i<=n;i++){
				temp += f2[i];
			}
			if(temp < sum){
				sum = temp;
			}
			for(int j=1;j<=n;j++)
			{
				bestx[j]=x[j];
			}
		 } 
	 }
	else{
		for(int j=i;j<=n;j++)			//未达到叶子节点，考虑其他方案 
		{
			swap(x[i],x[j]);			//先进行交换，第一次是自己和自己交换，即最左边的节点
			f1+=a[x[i]];				//在第i层选择执行作业x[i],在M1上的执行时间 
			f2[i]=max(f1,f2[i-1])+b[x[i]];
			if(f2[i]<bestf)
			{
				dfs(i+1);				//仅仅扩展调度时间小于bestf(最优调度时间)的节点 
			 } 
			f1-=a[x[i]];				//回溯，撤销对作业x[i]的选择，重新考虑其他作业
			swap(x[i],x[j]); 
		}
	} 
 } 
int main()
{
	f1=0;
	bestf=0x3f3f3f3f;					//初始时的作业最优调度时间为无穷大
	memset(f2,0,sizeof(f1));			//初始f2数组中的执行时间为0
	for(int k=1;k<=n;k++)				//初始时作业的执行顺序：1，2、、、n 
	{
		x[k]=k;
	 } 
	dfs(1);								//从作业1开始调度
	printf("最优调度时间为：%d,\n最优调度方案为：",sum);
	for(int j=1;j<=n;j++)
	{
		printf("%d ",bestx[j]);
	 }
	printf("\n");
	system("pause");
	return 0;
}