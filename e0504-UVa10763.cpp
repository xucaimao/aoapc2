//算法竞赛入门经典第二版 习题5-4 UVa10763 交换学生
//write by xucaimao,20161218-13:40开始编程，20161218-15:00测试通过
//A学校有人要求交换出去，必然有其他人要求交换进入A学校，才能满足题目的条件
//生成出和进两个学校编号的序列，并对二者排序。

#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

vector<int> sa;//要求出的学校
vector<int> sb;//要求进的学校

int main(){
	int n;
	freopen("e0504.in","r",stdin);
	while(scanf("%d",&n) && n!=0){
		sa.clear();sb.clear();
		for(int i=0;i<n;i++){ //读入n行数据
			int a,b;
			scanf("%d%d",&a,&b);
			sa.push_back(a);
			sb.push_back(b);
		}
		if(sa.size() != sb.size()) //二者人数不匹配
			{printf("NO\n");break;}
		sort(sa.begin(),sa.end());
		sort(sb.begin(),sb.end());
		bool cmp=true;
		for(int i=0;i<sa.size();i++)
			if(sa[i]!=sb[i]){cmp=false;break;}
		if(cmp) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}