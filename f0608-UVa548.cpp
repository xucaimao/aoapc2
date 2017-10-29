//算法竞赛入门经典第二版 例题6-8 UVa548 树
//write by xucaimao,20170105-18:30开始编程，20170114-20:50测试通过
//在书上程序的基础上增加了记录并打印路径的功能
//静态数据结构

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxv=10000+10;
int inorder[maxv],postorder[maxv],lch[maxv],rch[maxv];
int n;//树的节点数-1
int best,best_sum;//最优解及相应的权和
vector<int> way_best,way_temp;

//读入一行字符串，分解成整形值存储在数组a中，数组元素个数存在全局变量n中
bool readlist(int * a){
	string line;
	if(!getline(cin,line)) return false;
	stringstream ss(line);
	n=0;
	int x;
	while(ss>>x) a[n++]=x;
	return n>0;
}

//根据inorder[l1..r1] 和 postorder[l2..r2]中的数据建成一颗二叉树，返回树的根
//递归函数，程序中重点是四个边界条件的维护
int build(int l1,int r1,int l2,int r2){
	if(l1>r1)return 0;
	int root=postorder[r2];//树(子树)的根
	int p=l1;
	//找到中序遍历中根节点的下标。因为下标从0开始，要注意与节点数量转化
	while(inorder[p]!=root) p++;
	int cnt=p-l1;//左子数节点的数量+1
	lch[root]=build(l1,p-1,l2,l2+cnt-1);//重建左子树
	rch[root]=build(p+1,r1,l2+cnt,r2-1);//重建右子树
	return root;
}

//前序遍历：查找根节点u的树中，权值最小的路径
//deepth为二叉树的深度，最小值从1开始
void dfs(int u,int sum,int deepth){
	if(way_temp.size()>=deepth){//已经记录过这一层
		way_temp[deepth-1]=u;//直接覆盖数据
		if(way_temp.size()>deepth)
			way_temp.resize(deepth);//考虑不平衡二叉树的情况，确保记录层级与vector的长度一致
	}
	else way_temp.push_back(u);//没有记录过这一层，追加数据

	sum+=u;
	if(!lch[u] && !rch[u]){//节点u的左右孩子都为空，即u是叶子
		if(sum<best_sum || (sum==best_sum && u<best) ){
			best=u;
			best_sum=sum;
			way_best=way_temp;//保存最优路径
		}	
	}
	
	deepth++;//开始遍历下一层，深度增加
	if(lch[u]) dfs(lch[u],sum,deepth);//存在左子树，则遍历左子树
	if(rch[u]) dfs(rch[u],sum,deepth);//存在右子树，则遍历右子树
}

int main(){
	freopen("f0608.in","r",stdin);
	while(readlist(inorder)){
		readlist(postorder);
		build(0,n-1,0,n-1);
		best_sum=1000000000;
		way_best.clear();
		way_temp.clear();
		dfs(postorder[n-1],0,1);
		cout<<best<<endl;
		cout<<"The best way is: ";
		for(int i=0;i<way_best.size();i++)
			cout<<way_best[i]<<" ";
		cout<<endl;
	}
	return 0;
}