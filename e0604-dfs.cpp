#include <iostream>  
using namespace std;  
  
string beginstr;  
string endstr;  
int endx;  
int endy;  
int minstep;  
int direct[8][2]={{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};  
  
void dfs(int x,int y,int step){  
    if(step>=minstep)  
        return;  
    if(x>=8||x<0||y>=8||y<0)  
        return;  
    if(x==endx&&y==endy){  
        if(step<minstep)  
            minstep=step;  
        return;  
    }  
      
    for(int i=0;i<8;i++){  
        int dx=x+direct[i][0];  
        int dy=y+direct[i][1];  
        dfs(dx,dy,step+1);  
    }  
      
}  
  
  
int main(){  
      
    while(cin>>beginstr>>endstr){  
          
        minstep=999;  
        int x=8-(beginstr[1]-'0');  
        int y=beginstr[0]-'a';  
          
        endx=8-(endstr[1]-'0');  
        endy=endstr[0]-'a';  
          
        dfs(x,y,0);  
        cout<<minstep<<endl;  
          
    }  
    return 0;  
} 