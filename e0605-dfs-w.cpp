#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<map>  
#include<stack>  
#include<queue>  
#include<set>  
#include<vector>  
#include<cmath>  
using namespace std;  
#define MAXD 20 + 10  
int n,m,k;  
int Mat[MAXD][MAXD];  
int State[21][21][21];  /*走到x，y 连穿z个墙*/  
int ans;  
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};  
void dfs(int x,int y,int step,int have_go){  
    if(x == n - 1 && y == m - 1){  
        ans = min(ans,step);  
        return ;  
    }  
    for(int i = 0 ; i < 4 ; i++){  
        int _x = x + dir[i][0];  
        int _y = y + dir[i][1];  
        int st = have_go;  
        if(Mat[_x][_y] == 1) st++;  
        else  
        st = 0;  
        if(_x >= 0 && _x < n && _y >= 0 && _y < m){  
            if((State[_x][_y][st] < 0 || State[_x][_y][st] > step + 1) && st <= k){  
                State[_x][_y][st] = step + 1;  
                dfs(_x,_y,step + 1,st);  
            }  
        }  
    }  
    return ;  
}  
int main(){ 
    freopen("e0605.in","r",stdin); 
    int T;  
    scanf("%d",&T);  
    while(T--){  
        memset(State,-1,sizeof(State));  
        ans = 1 << 30;  
        scanf("%d%d%d",&n,&m,&k);  
        for(int i = 0 ; i < n ; i++)  
          for(int j = 0 ; j < m ; j ++)  
            scanf("%d",&Mat[i][j]);  
        dfs(0,0,0,0); /*从左上角出发,当前走了0补，已经连续穿过了0层墙*/  
        if(ans != 1 << 30)printf("%d\n",ans);  
        else  
        printf("-1\n");  
    }  
    return 0;  
}