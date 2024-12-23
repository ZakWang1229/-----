#include<bits/stdc++.h>
#define ci const int
#define ll long long
#define ls x<<1
#define rs x<<1|1 
using namespace std;
ci N=1.5e5+5,M=N<<2;
const ll inf=1e17;
int n,m;
struct node{
	int x,y;
	inline bool operator < (const node &t)const{
		return x<t.x;
	}
}nd[N];
int l[M],r[M],id[M];
ll t[M],mx[M],ad[M],k[N];
ll Calc(ll y,ll k){
	if(k<=0)return inf;
	return (y+k-1)/k;
}
void upd(ci x){
	if(mx[ls]>mx[rs])
		mx[x]=mx[ls],id[x]=id[ls],
		t[x]=min(min(t[ls],t[rs]),Calc(mx[ls]-mx[rs],k[id[rs]]-k[id[ls]]));
	else
		mx[x]=mx[rs],id[x]=id[rs],
		t[x]=min(min(t[ls],t[rs]),Calc(mx[rs]-mx[ls],k[id[ls]]-k[id[rs]]));
}
void add(ci x,ll v){
	ad[x]+=v,t[x]-=v,mx[x]+=(ll)k[id[x]]*v;
}
void pushdown(ci x){
	if(ad[x]!=0)add(ls,ad[x]),add(rs,ad[x]),ad[x]=0;
}
void build(ci x,ci L,ci R){
	l[x]=L,r[x]=R;
	if(L==R){
		t[x]=inf,id[x]=L;
		return;
	}
	ci mid=L+R>>1;
	build(ls,L,mid),build(rs,mid+1,R),upd(x);
}
void modify(ci x,ci L,ci R,ll v){
	if(L>r[x]||R<l[x])return;
	if(L<=l[x]&&r[x]<=R&&v<t[x]){
		add(x,v);
		return;
	}
	pushdown(x),modify(ls,L,R,v),modify(rs,L,R,v),upd(x);
}
int main(){
    freopen("starrail.in","r",stdin);
    freopen("starrail.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&nd[i].x,&nd[i].y),
		k[i]=nd[i].y;
	sort(k+1,k+n+1);
	for(int i=1;i<=n;++i)
		if(i==1||k[i]!=k[i-1])
			k[++m]=k[i];
	sort(nd+1,nd+n+1);
	build(1,1,m);
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,(ll)nd[i].x*(n-i+1)+mx[1]),
		modify(1,1,lower_bound(k+1,k+m+1,nd[i].y)-k,1);
	}
	printf("%lld",ans);
	return 0;
}