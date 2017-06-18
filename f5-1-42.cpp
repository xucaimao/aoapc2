//算法竞赛入门经典（第二版）5.1.4结构体例题
//采用类改写。学习了成员函数与非成员函数，参数数量的不同
//(成员函数有一个参数通过this指针默认传递，非成员函数则没有此功能)
//同时<<运算符的重载，是个比较麻烦的特例，目前理解不了，先死记一下。
#include<iostream>
using namespace std;

class Point{
private:
	int x,y;
public:
	Point(int x=0,int y=0):x(x),y(y) {}
	Point operator+(const Point & B){
		return Point(x+B.x,y+B.y);
	}

	friend ostream & operator<<(ostream & myout,const Point & p){
		myout<<"("<<p.x<<","<<p.y<<")";
		return myout;
	}
	
};


int main(){
	Point a(3,0),b(1,2),c;
	cout<<"a+b= "<<a+b<<endl;
	cout<<"a+c= "<<a+c<<endl;
}