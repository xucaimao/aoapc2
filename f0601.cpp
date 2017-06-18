//算法竞赛入门经典第二版 例题6-1 UVa210 并行程序模拟
//write by xucaimao,20161224-23：00开始编程，20161218-测试通过


#include<cstdio>
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct PROG{
    vector<string> pdoc;//存储程序格式化文本
    int PID;//程序编号
    int pline;//运行到当前行的指针ß
};

int var[26]={0};//变量列表
int ltime[5],Q;
int ptime=0;//程序总的运行时间
bool LOCK=false;
vector<PROG> program;//静态储存程序
deque<int> qwait,block;//等待队列、阻止队列

void init(int n){
    for(int i=0;i<n;i++){//读入n个程序
        PROG prog;
        prog.PID=i;
        prog.pline=0;
        string s;
        for(int line=0;;line++){
            getline(cin,s);
            prog.pdoc.push_back(s);
            if(s=="end")break;
        }
        program.push_back(prog);//储存程序
		qwait.push_back(i);//生成等待队列
    }
}

void print(){
	for(int i=0;i<program.size();i++){
		cout<<"PROGRAM "<<i+1<<" :"<<endl;
		cout<<"PID : "<<program[i].PID<<" ,  pline : "<<program[i].pline<<endl;
		for(int j=0;j<program[i].pdoc.size();j++)
			cout<<program[i].pdoc[j]<<endl;
		cout<<"------------------"<<endl;
	}
}

void myrun(){
    while(!qwait.empty()){ //qwait队列不为空
        PROG* p;
		int pn_act=qwait.front();//取得活动程序的id
		p=& program[pn_act];
		int t=0;
		bool stat=true;
        for(;stat;){//开始执行队首程序
			string s;
			s=(*p).pdoc[(*p).pline];//取得当前执行的程序语句
			cout<<"PROGRAM "<<pn_act+1<<" ;  "<<s<<" : "<<endl;
			(*p).pline++;//语句指针后移
            if(s=="end"){
				ptime+=ltime[4];
				t+=ltime[4];
				qwait.pop_front();
				stat=false;
			}//当前程序执行完成
            else if(s=="unlock"){
				LOCK=false;
				ptime+=ltime[3];t+=ltime[3];
				if(!block.empty()){
					int t=block.front();
					qwait.push_front(t);
					block.pop_front();
					stat=false;
				}
				
			}
            else if(s=="lock"){//
            	ptime+=ltime[2];
				t+=ltime[2];
				if(LOCK){block.push_back(pn_act);qwait.pop_front();stat=false;}
				LOCK=true;	
            }
            else if(s[2]=='='){ //赋值语句
            	ptime+=ltime[0];
				t+=ltime[0];
				string ns=s.substr(4);
				int num=0;
				for(int j=0;j<ns.size();j++)num=num*10+ns[j]-'0';//字符转数字
				var[s[0]-'a']=num;//变量数组赋值
			}
            else {//打印语句
            	ptime+=ltime[1];
				t+=ltime[1];
				int num=s[6]-'a';
				cout<<pn_act+1<<": "<<var[num]<<endl;
            }
			if(t>=Q){
				int t=qwait.front();
				qwait.push_back(t);
				qwait.pop_front();
				stat=false;
			}

			cout<<"----------------------"<<endl;
        }
    }
}

int main(){
    freopen("f0601.in","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<5;i++)
        cin>>ltime[i];
    cin>>Q;
    cin.get();//行尾处理
    init(n);
	//print();
	myrun();
    return 0;
}
