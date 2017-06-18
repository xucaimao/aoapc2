//算法竞赛入门经典第二版 习题5-5 UVa10391 复合词
//write by xucaimao,20161218-19:00开始编程，20161218-19:35测试通过

#include<set>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

set<string> dict;


int main(){
	freopen("e0505.in","r",stdin);
	string s;
	while(cin>>s) dict.insert(s); //读入字典
	set<string>::iterator it;
	for(it=dict.begin();it!=dict.end();it++){
		s=*it;
		for(int i=1;i<=s.size()-1;i++){ //逐个单词处理
			string s1=s.substr(0,i);//返回从0开始的i个字符组成的字符串
			string s2=s.substr(i,s.size()-i);//返回剩余的字符串
			//cout<<s<<"= "<<s1<<" + "<<s2<<endl;
			set<string>::iterator it2,it3;
			it2=dict.find(s1);
			it3=dict.find(s2);
			if(it2!=dict.end() && it3!=dict.end()){//两个单词都在set内找到
				cout<<s<<endl;
				break;
			}	
		}			
	}
	return 0;
}

