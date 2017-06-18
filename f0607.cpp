//算法竞赛入门经典第二版 例题6-7 UVa122 树的层次遍历
//write by xucaimao,20170101-21：00开始编程，20170101-测试通过
//采用结构体及指针的形式，属于动态存储结构
//BFS搜索是重点
//如果没有cstring(strlen,strcmp,strchr)头文件，mac上能编译通过，UVa上编译通不过
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int maxn=300;
struct NODE{
	bool have_value;
	int value;
	NODE *left, *right;
	NODE(){//构造函数
		this->have_value=false;
		this->left=NULL;
		this->right=NULL;
	}
};

NODE *root;
bool failed;
char s[maxn];

NODE * newnode(){return new NODE();}

void addnode(int v,const char * s){
	int len=strlen(s);
	failed=false;
	NODE * p=root;//从根节点开始
	for(int i=0;i<len;i++){
		if(s[i]=='L'){//往左
			if(p->left==NULL)//左节点不存在，新建节点
				p->left=newnode();
			p=p->left;
		}
		else if(s[i]=='R'){//往右
			if(p->right==NULL)//左节点不存在，新建节点
				p->right=newnode();
			p=p->right;
		}//对')'不做处理。若','后没有数据，则等于为根节点进行操作
	}
	if(p->have_value)failed=true;//已经赋值，表明输入有误
	p->value=v;
	p->have_value=true;
}

bool read_input(){
	failed=false;//此次是坑，少了这一行
	root=newnode();//创建根节点
	for(;;){
		if(scanf("%s",s) !=1)return false;//数据输入结束
		if(!strcmp(s,"()"))break;//一组数据结束，跳出循环
		int v;
		sscanf(&s[1],"%d",&v);//
		addnode(v,strchr(s,',')+1);
	}
	return true;
}

bool bfs(vector<int> & ans){
	queue<NODE *> q;
	ans.clear();
	q.push(root);//根节点入队列
	while(!q.empty()){//队列不空则一直进行
		NODE * p=q.front();
		q.pop();
		if(!p->have_value) return false;//节点没有赋值，说明输入有误
		ans.push_back(p->value);//节点值进入输出序列尾部
		if(p->left !=NULL) q.push(p->left);//左子节点(如果有)入队列
		if(p->right !=NULL) q.push(p->right);//右子节点(如果有)入队列
	}
	return true;
}

int main(){
	freopen("f0607.in","r",stdin);
	while(read_input()){
		vector<int> answer;
		if(!failed && bfs(answer)){
			printf("%d",answer[0]);
			for(int i=1;i<answer.size();i++)
				printf(" %d",answer[i]);
			printf("\n");
		}
		else printf("not complete\n");
	}
	return 0;
}