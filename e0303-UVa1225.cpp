//算法竞赛入门经典第二版 e0303.cpp UVa1225数数字
//write by xucaima,20161109,13:20
//时间限制:3s

#include<cstdio>
#include<cstring>

int main()
{
	int ans[10];
	int n,T;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%d",&n);
		for(int i=0;i<=9;i++)  //初始化数组
			ans[i]=0;
		for(int i=1;i<=n;i++){
			int t=i,d;
			while(t>0){  //统计每一个数，各个字符的出现频次
				d=t%10;
				ans[d]++;
				t=t/10;
			}
		}
		int first=1;  //行首标志
		for(int i=0;i<10;i++){
			if(first) first=0;
			else printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}