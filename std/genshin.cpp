#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=6000010;
int h,m,tot=1,ch[MAXN][2],dp[MAXN][2],dx[70][2];
ll n,x,ans;
void ins (ll x) {
	int p=1;
	for (int i=h-1;i>=0;i--) {
		int tmp=((x>>i)&1);
		if (!ch[p][tmp]) {ch[p][tmp]=++tot;}
		p=ch[p][tmp];
	}
	return;
}
void dfs (int x,int d) {
	if (ch[x][0]) {dfs(ch[x][0],d+1);}
	if (ch[x][1]) {dfs(ch[x][1],d+1);}
	if (d==h) {dp[x][0]=0,dp[x][1]=1;}
	else {
		if (dx[d][0]==dx[d+1][0]+dx[d+1][0]) {dp[x][0]=dp[ch[x][0]][0]+dp[ch[x][1]][0];}
		else {dp[x][0]=max(dp[ch[x][0]][0]+dp[ch[x][1]][1],dp[ch[x][0]][1]+dp[ch[x][1]][0]);}
		if (dx[d][1]==dx[d+1][1]+dx[d+1][1]) {dp[x][1]=dp[ch[x][0]][1]+dp[ch[x][1]][1];}
		else {dp[x][1]=max(dp[ch[x][0]][0]+dp[ch[x][1]][1],dp[ch[x][0]][1]+dp[ch[x][1]][0]);} 
	}
	return;
}
int main () {
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	scanf("%d%d%lld",&h,&m,&n);
	for (int i=1;i<=m;i++) {
		scanf("%lld",&x);
		x--;
		ins(x);
	}
	ans=(n/(1ll<<h))*m;
	n%=(1ll<<h);
	for (int i=0;i<=h;i++) {
		dx[i][0]=n/(1ll<<i);
		dx[i][1]=dx[i][0]+1;
	}
	dfs(1,0);
	printf("%lld\n",ans+dp[1][0]);
	return 0;
}
