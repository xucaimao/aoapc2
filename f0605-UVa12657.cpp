//算法竞赛入门经典第二版 例题6-5 UVa12657 移动盒子
//write by xucaimao,20161231-21：00开始编程，20170101-13:10测试通过
//所有的操作都是对索引列表进行的，不能改变原始数据数组，否则整个逻辑就乱了
//通过指针对左右两个索引列表进行互换，简化了程序设计，条理更清晰。
//同时需注意：指针与数组的表达方式的变化使用
//xy互换时，要注意二者相邻的两种特殊情况的处理。

#include<cstdio>
const int maxn=100000+10;
int box[maxn];
int pt[2][maxn];//索引列表
int *left=& pt[0][0];
int *right=& pt[1][0];

//把编号为L和R的两个盒子连接在一起
void link(int L,int R){
	right[L]=R;left[R]=L;
}

//dir=-1,在y左侧插入x;dir=1,在y右侧插入x
void insert(int x,int y,int dir){
	link(left[x],right[x]);//删除x
	if(dir==-1){link(left[y],x);link(x,y);}
	else if(dir==1){link(x,right[y]);link(y,x);}//两步顺序不能反，不然会造成越界
	else printf("Error!\n");
}

void myprint(int *dir){
	printf("The data after change: \n");
	for(int i=dir[0];i!=0;i=dir[i])
		printf("%d ",box[i]);
	printf("\n------------------------\n");
}

int main(){
    freopen("f0605-1.in","r",stdin);
    int n,m;
	int T=0;//数据组的数量
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=n;i++){
            box[i]=i;
            left[i]=i-1;
            right[i]=(i+1)%(n+1);//right[n]=0
        }
        right[0]=1;//首指针
        left[0]=n;//首指针
		//myprint(right);
		//myprint(left);
		//printf("****** end of init ******\n");
        while(m--){//开始读入命令
            int op;
            scanf("%d",&op);
            if(op==4){int *t=left;left=right;right=t;}//索引列表互换
            else{
                int x,y;
                scanf("%d%d",&x,&y);
				if(op==1){//x移动到y左边(相邻)
					if(left[y]==x)continue;//x已经在y左边(相邻)
					else insert(x,y,-1);
				}
				else if(op==2){//x移动到y右边(相邻)
					if(right[y]==x)continue;//x已经在y右边(相邻)
					else insert(x,y,1);
				}
				else if(op==3){//xy互换
					int lx=left[x],rx=right[x],ly=left[y],ry=right[y];
					if(rx==y){link(lx,y);link(y,x);link(x,ry);}//x在y左边(相邻)
					else if(ry==x){link(ly,x);link(x,y);link(y,rx);}//y在x左边(相邻)
					else{link(lx,y);link(y,rx);link(ly,x);link(x,ry);}//二者不相邻
				}

            }
			//myprint(right);
        }
		long sum=0;
		for(int i=right[0],j=1;i!=0;i=right[i],j++)
			if(j%2 ==1) sum+=box[i];
		T++;
		printf("Case %d: %ld\n",T,sum);
    }
	return 0;
}
