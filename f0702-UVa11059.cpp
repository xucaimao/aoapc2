//算法竞赛入门经典第二版 例题7-2 UVa11059 最大乘积
//write by xucaimao,20170212-22:00开始编程，20170212-22:50测试通过
//注意起点和终点可以重合，也就是说，最大序列可以仅仅是一个数

#include<cstdio>
#include<cstring>

const int maxn=18+2;
int data[maxn];

int main(){
	freopen("f0702.in","r",stdin);
	int T=0,n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		long long m,mmax=data[0];
		int imax,jmax;
		for(int i=0;i<n;i++)//枚举起点
			for(int j=i;j<n;j++){//枚举终点
				m=1;
				for(int k=i;k<=j;k++)//从起点到终点连乘
					m*=data[k];
				if(m>mmax){mmax=m;imax=i;jmax=j;}	
			}
		if(mmax<0)mmax=0;
		printf("Case #%d: The maximum product is %lld.\n\n",++T,mmax);
		//printf("From %d to %d .\n",imax+1,jmax+1);
	}
	return 0;
}