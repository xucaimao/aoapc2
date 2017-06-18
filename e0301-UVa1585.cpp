//算法竞赛入门经典第二版 e0301.cpp UVa1585得分
//write by xucaima,20161109,10:53
//

#include<cstdio>
#include<cstring>
const int MAX=81;
char s[MAX];


int main()
{
	int T;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%s",s);
		int score=0,lo=0;
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='O'){lo++;score+=lo;}
			if(s[i]=='X') lo=0;
		}
		printf("%d\n",score);
	}
	return 0;
}