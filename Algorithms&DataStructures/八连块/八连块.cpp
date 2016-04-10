#include <stdio.h>
#include <string.h>
const int MAXN=1000+10;
char s[MAXN];
int n,i,j;
int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x,int y)
 {
  if(!mat[x][y]||vis[x][y]) return;
  vis[x][y]=1;
  dfs(x-1,y-1); dfs(x-1,y); dfs(x-1,y+1);
  dfs(x,y-1);               dfs(x,y+1);
  dfs(x+1,y-1); dfs(x+1,y); dfs(x+1,y+1);
  }
int main()
{
	 scanf("%d",&n);
	 memset(mat,0,sizeof(mat));
	 memset(vis,0,sizeof(vis));
	 for(i=0;i<n;i++)
	 {
		scanf("%s",s);
	    for(j=0;j<n;j++)
		mat[i+1][j+1]=s[j]-'0';
	 }
	 int count=0;
	 for(i=0;i<=n;i++)
	     for(j=0;j<=n;j++)
		    if(!vis[i][j]&&mat[i][j]){count++;dfs(i,j);}
	printf("%d\n",count);
	return 0;
}
