//算法竞赛入门经典第二版 例题6-9 UVa839 Not so Mobile
//write by xucaimao,20171102-20:30开始编程，20171102-21:10测试通过
//没有采用书上的引用参数的方式，感觉那样不容易理解。
//考虑到重量不会有负值，故而采用-1作为天平不平衡的状态标志。

#include<cstdio>

int solve(){
	int wl,dl,wr,dr;
	scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
	if(wl==0)wl=solve();
	if(wr==0)wr=solve();
	if(wl>0 && wr>0 && wl*dl==wr*dr) return wl+wr;
	else return -1;
}

int main(){
	freopen("f0609.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int re=solve();
		if(re>0) printf("YES\n");
		else printf("NO\n");
		if(T>0)printf("\n");
	}
	return 0;
}