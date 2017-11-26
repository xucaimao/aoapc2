//算法竞赛入门经典第二版 例题7-4 UVa524 素数环
//write by xucaimao,20171126-21:10开始编程，20171126-22:17测试通过
//最后不能有空行，因为这个，PE了几次

#include<cstdio>
#include <cmath>
#include <cstring>

const int maxn=20;
bool isp[maxn*2];
int ans[maxn];//
int vis[maxn];
int n;

void initprime(){
	for(int i=2;i<=maxn*2;i++)
		isp[i]=1;
	int sq=sqrt(maxn*2)+1;
	for(int i=2;i<sq;i++)
		for(int j=i*i;j<=maxn*2;j+=i)
			isp[j]=0;
}

void solve(int cur){
	//在素数环ans[0..cur-1]的后一个元素ans[cur]中填入一个[1..n]之间的数，
	//使得数组ans[0..cur]仍然是一个素数环
	if(cur==n && isp[ans[0]+ans[n-1]] ){
		for(int i=0;i<n;i++){
			if(i>0)printf(" ");
			printf("%d",ans[i] );
		}
		printf("\n");
	}
	else{
		for(int i=2;i<=n;i++)//尝试放2..n的各个数
			if(!vis[i] && isp[ i+ans[cur-1] ]){
				ans[cur]=i;
				vis[i]=1;//注意是i
				solve(cur+1);
				vis[i]=0;
			}
	}
}

int main(){
	freopen("f0704.in","r",stdin);
	int T=0;
	initprime();
	while(scanf("%d",&n)!=EOF){
		if(T>0)printf("\n");
		printf("Case %d:\n",T+1);
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		ans[0]=1;vis[1]=1;
		solve(1);
		T++;
	}
	return 0;
}