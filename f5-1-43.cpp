//算法竞赛入门经典（第二版）5.1.4结构体例题
#include<iostream>
using namespace std;

struct Point{
private:
	int x,y;
public:
	Point(int x=0,int y=0):x(x),y(y) {}
	Point operator + (const Point & B){
		return Point(x+B.x,y+B.y);
	}
	friend ostream & operator << (ostream &out,const Point & p){
		out<<"("<<p.x<<","<<p.y<<")";
		return out;
	}
	
};





int main(){
	Point a(3,0),b(1,2);
	cout<<"a+b= "<<a+b<<endl;
}