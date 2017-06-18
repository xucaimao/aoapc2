//算法竞赛入门经典第二版 习题3-9 UVa10340 子序列
//write by xucaima,开始于20161117,23:00.2016118,14:14测试通过.
//时间限制:3s
//数组开小了也会出现RE错误

#include<cstdio>
#include<cstring>
const int MAXN=100002; //数组开小了也会出现RE错误
char s[MAXN],t[MAXN];

bool judge(char * s,char * t)
{
    int ls=strlen(s);
    int lt=strlen(t);
    if(ls>lt) return false;//s串比t串长，直接返回false
    int i,j;
    for(i=0,j=0;i<ls && j<lt;){
        if(s[i]==t[j]){i++;j++;} //在t串内找到s[i]相同的字符，搜索下一个s[i]
        else
        	while(s[i]!=t[j] && j<lt) //在t串内找与s[i]相同的字符
        		j++;
		}
    if(i==ls)return true;//s串内字符都已搜索完毕，没有出现异常情况
    else return false;
}

int main()
{
	freopen("e0309.in","r",stdin);
	while((scanf("%s%s",s,t))==2){
        if(judge(s,t)) printf("Yes\n");
        else  printf("No\n");
	}

	return 0;
}
