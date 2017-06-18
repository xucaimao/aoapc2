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
		int k=1;
		for(int i=1;i<D;i++){
			if(I%2){k=k*2;I=(I+1)/2;}//偶数往左
			else{k=k*2+1;I/=2;}
		}
		printf("%d\n",k/2);
	}
	return 0;
}