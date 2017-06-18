//算法竞赛入门经典第二版 习题5-6 UVa1595 对称轴
//write by xucaimao,20161218-19:50开始编程，20161218-测试通过

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Point{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y) {}
	
	bool operator < (const Point & b) const {
		if(x==b.x) return y<b.y;
		else return x<b.x;
	}
	bool operator == (const Point & b) const {
		return x==b.x && y==b.y;
	}
	Point mirror(int mid){ //以mid为对称轴的对称点
		if(x!=mid) x=2*mid-x;
		return Point(x,y);
	}
	friend ostream & operator << (ostream & out,const Point & p){
		out<<"("<<p.x<<","<<p.y<<")";
		return out;
	}
};

vector<Point> pp;
vector<Point> pl,pr;

int main(){
	int T,N;
	freopen("e0506.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		pp.clear();
		pl.clear();
		pr.clear();
		scanf("%d",&N);
		while(N--){  //读入N个点的坐标
			int x,y;
			scanf("%d%d",&x,&y);
			Point p(x,y);
			pp.push_back(p);
		}
		sort(pp.begin(),pp.end());//从小到大排列
		int mid=(pp[N-1].x-pp[0].x)/2+pp[0].x;//计算对称轴
		for(int i=0;i<pp.size();i++){ //将对称轴两侧的点分开放置
			if(pp[i].x<mid) pl.push_back(pp[i]);
			else if(pp[i].x>mid) pr.push_back(pp[i]);
		}
		
		for(int i=0;i<pp.size();i++) cout<<pp[i];
		cout<<endl;
		cout<<"The mirror axis : "<<mid<<endl;
		for(int i=0;i<pl.size();i++) cout<<pl[i];
		cout<<endl;
		for(int i=0;i<pr.size();i++) cout<<pr[i];
		cout<<endl;
		
		if(pl.size()!=pr.size()){printf("NO\n");continue;}//对称轴两侧点的数量不同
		bool mirr=true;
		for(int i=0,j=pr.size()-1;i<pl.size() && j>0;)
			if(pl[i].mirror(mid)==pr[j]){i++;j--;}
			else{mirr=false;}
		if(mirr)printf("YES\n");
		else printf("NO\n");
		printf("------------------------\n");	
	}
	return 0;
}
