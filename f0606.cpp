//算法竞赛入门经典第二版 例题6-6 UVa679 小球下落
//write by xucaimao,20170101-15：00开始编程，20170101-测试通过
#include<cstdio>
#include<cstring>
const int maxd=20;
const int maxn=1<<20;
bool tree[maxn];

int main(){
	freopen("f0606.in","r",stdin);
	int tcase;
	scanf("%d",&tcase);
	while(tcase--){
		int D,I;
		scanf("%d%d",&D,&I);
		memset(tree,0,sizeof(tree));//init tree
		int k,n=(1<<D)-1;
		for(int i=0;i<I;i++){
			k=1;
			for(;;){
				k=tree[k] ? k*2+1 : k*2;//关闭往左走
				tree[k]=!tree[k];//改变开关状态
				if(k>n)break;
			}
		}
		printf("%d\n",k/2);
	}
	return 0;
}