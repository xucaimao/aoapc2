//算法竞赛入门经典第二版 例题6-9 UVa699 The Falling Leaves 
//write by xucaimao,20171102-21:30开始编程，20171102-22:20测试通过

#include<cstdio>
#include<cstring>
const int maxn=10000;
int sum[maxn];

void build(int p){
	int n;
	scanf("%d",&n);
	if(n==-1)return;
	sum[p]+=n;
	build(p-1);
	build(p+1);
}

//计算一行
bool solve(){
	memset(sum,0,sizeof(sum));
	int node;
	scanf("%d",&node);
	if(node==-1) return false;
	int p=maxn/2;
	sum[p]=node;
	build(p-1);
	build(p+1);
	return true;
}

int main(){
	freopen("f0610.in","r",stdin);
	int T=0;
	for(;;){
		bool ok=solve();
		if(!ok)break;
		T++;
		//开始打印
		printf("Case %d:\n",T);
		int i=0;
		while(sum[i]==0) i++;
		printf("%d",sum[i]);//打印行首元素
		i++;
		for(;i<maxn;i++){
			if(sum[i]==0)continue;
			else printf(" %d",sum[i]);
		}
		printf("\n\n");
	}
	return 0;
}