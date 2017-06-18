//算法竞赛入门经典第二版 例题7-3 UVa10976 分数拆分
//write by xucaimao,20170212-23:00开始编程，20170212-23:50测试通过
//重点是对数学公式的推导，找出边界条件

#include<cstdio>
const int maxn=10000;
int ans[maxn][2];

int main(){
	freopen("f0703.in","r",stdin);
	int k;
	while(scanf("%d",&k)==1){
		int x,y;
		int n=0;
		for(y=k+1;y<=2*k;y++){//y边界的确定是重点
			int a=k*y;//x=k*y/(y-k)
			int b=y-k;
			if(a%b==0){
				x=a/b;
				ans[n][0]=x;
				ans[n][1]=y;
				n++;
			}		
		}
		
		printf("%d\n",n);
		for(int i=0;i<n;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,ans[i][0],ans[i][1]);		
	}
	return 0;
}