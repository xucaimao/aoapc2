//算法竞赛入门经典第二版 习题5-10 UVa1597 在WEB中搜索
//write by xucaimao,20161221-07:30开始编程，20161218-测试通过

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct Node{
	int doc_num,row_num;
	bool operator <(const Node & b) const { //先以文章编号排序，再以行号排序
		if(doc_num==b.doc_num) return row_num<b.row_num;
		return doc_num<b.doc_num;
	}
};

vector< vector<string> > docu; //用于储存所有的文章
map<string,set<Node> > myindex;

//判断一个字符
bool isalpha(char c){
	if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') ) return true;
	else return false;
}
//单词变小写
void lowcase(string & s){
	for(int i=0;i<s.size();i++)
		if(s[i]>='A' && s[i]<='Z') s[i]+=32;
}
//把输入的一行字符串line转化成vector<string>, 除了‘0’~’9‘与’a'~'z',其他的字符忽略
//通过参数st控制,st=0全部转化成小写，st=1不转化大小写
vector<string> line2words(string & line,int st){
	vector<string> s;
	for(int i=0;i<line.size();){
		string word;
		while(!isalpha(line[i]) ) i++;
		while(isalpha(line[i]) ) { //生成一个单词
			word.push_back(line[i]);
			i++;
		}
		if(word.size()>0){ //非空单词
			if(st==0) lowcase(word);
			s.push_back(word);
		}
	}
	return s;
}

//判断是*号行
bool is_star(string & s){
	//if(s.size()<11 ) return false;
	for(int i=0;i<10;i++)
		if(s[i]!='*') return false;
	return true;
}

void printmap(){
	map<string,set<Node> >::iterator itm;
	set<Node>::iterator its;
	for(itm=myindex.begin();itm!=myindex.end();itm++){
		cout<< itm->first <<"  :"<<endl;
		for(its=(itm->second).begin();its!=(itm->second).end();its++)
			cout<<"("<<(*its).doc_num<<","<<(*its).row_num<<")";
		cout<<endl;
	}
}

int main(){
	freopen("e0510.in","r",stdin);
	int T;
	int doc_num=0;
	int row_num=0;//单词在总文章docu这个vector里的行号,从0开始
	cin>>T;
	while(T--){  //输入T篇文章并生成索引
		doc_num++;
		while(true){ //对一篇文章进行操作
			vector<string> ln;
			string line;
			getline(cin,line);
			if(is_star(line)){
				cout<<"End of doc!!!"<<endl;
				break;//一篇文章处理结束
			} 
			else{
				Node nod;
				set<Node> ts;
				nod.doc_num=doc_num;
				nod.row_num=row_num;
				ln=line2words(line,0);//行转小写单词
				docu.push_back(ln);//插入总文章
				for(int i=0;i<ln.size();i++){
					if(myindex.count(ln[i])==0) //如果string ln[i]在map内不存在，生成键值
						myindex[ln[i]]=ts;
					myindex[ln[i]].insert(nod);//插入
				}
				row_num++;
			}
	
		}
		
	}
	 //printmap();
	//开始读入搜索命令并查找输出
	
	
	return 0;
}