//采用牛顿迭代法求平方根与立方根
#include<cstdio>
#include<cstring>
#include<cmath>

const int maxn=1000;
double x[maxn];

void mysqrt(int a){
	printf("------sqrt of %d ------\n",a);
	x[0]=a/2.0;
	for(int n=0;;n++){
		x[n+1]=(x[n]+a/x[n])/2;
		printf("X%d = %.9f\n",n+1,x[n+1]);
		if(fabs(x[n+1]-x[n])<1e-9)break;
	}
	printf("\n");
}

int main(){
	int a;
	while(scanf("%d",&a)==1 && a ){
		memset(x,0,sizeof(x));
		mysqrt(a);
	}
	return 0;	
}