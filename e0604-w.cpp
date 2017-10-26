#include <bits/stdc++.h>  
using namespace std;  
int dir8[8][2]= {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};  
bool vis[10][10];  
int q;  
inline bool ok(int dx,int dy){  
    if(dx>=1&&dx<=8&&dy>=1&&dy<=8) return true;  
    return false;  
}  
void dfs(int px,int py,int lx,int ly,int deep){  
    if(deep>=q) return ;  
    if(px==lx&&py==ly&&deep<q){  
        q=deep;  
        return ;  
    }  
    for(int i=0; i<8; ++i){  
        int dx=px+dir8[i][0];  
        int dy=py+dir8[i][1];  
        if(ok(dx,dy)&&!vis[dx][dy]){  
        vis[dx][dy]=1;  
        dfs(dx,dy,lx,ly,deep+1);  
        vis[dx][dy]=0;  
        }  
    }  
    return ;  
}  
char c1[5],c2[5];  
int px,py,lx,ly;  
int main()  
{  
    while(~scanf("%s %s",c1,c2)){  
         px=c1[0]-'a'+1;py=c1[1]-'0';  
         lx=c2[0]-'a'+1;ly=c2[1]-'0';  
         memset(vis,0,sizeof(vis));  
         q=6;  
        vis[px][py]=1;  
        dfs(px,py,lx,ly,0);  
        printf("To get from %s to %s takes %d knight moves.\n",c1,c2,q);  
    }  
    return 0;  
}