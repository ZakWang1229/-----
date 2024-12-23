#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
int MOD,G;
int rev[N],inv[N],fac[N],ifac[N],w[N<<1];
int ksm(int a,int b=MOD-2) {
	int ret=1;
	for(;b;a=1ll*a*a%MOD,b=b>>1) if(b&1) ret=1ll*ret*a%MOD;
	return ret;
}
void poly_init() {
	vector <int> fr;
	for(int i=2,z=MOD-1;i*i<=z;++i) if(z%i==0) fr.push_back(i),fr.push_back(z/i);
	for(G=2;;++G) {
		bool ok=true;
		for(int z:fr) if(ksm(G,z)==1) { ok=false; break; }
		if(ok) break;
	}
	inv[1]=1;
	for(int i=2;i<N;++i) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=ifac[0]=1;
	for(int i=1;i<N;++i) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
	for(int k=1;k<=N;k<<=1) {
		int x=ksm(G,(MOD-1)/k); w[k]=1;
		for(int i=1;i<k;++i) w[i+k]=1ll*x*w[i+k-1]%MOD;
	}
}
int plen(int x) { int y=1; for(;y<x;y<<=1); return y;  }
void ntt(int *f,bool idft,int n) {
	for(int i=0;i<n;++i) {
		rev[i]=(rev[i>>1]>>1);
		if(i&1) rev[i]|=n>>1;
	}
	for(int i=0;i<n;++i) if(rev[i]<i) swap(f[i],f[rev[i]]);
	for(int k=2,x,y;k<=n;k<<=1) {
		for(int i=0;i<n;i+=k) {
			for(int j=i;j<i+k/2;++j) {
				x=f[j],y=1ll*f[j+k/2]*w[k+j-i]%MOD;
				f[j]=(x+y>=MOD)?x+y-MOD:x+y,f[j+k/2]=(x>=y)?x-y:x+MOD-y;
			}
		}
	}
	if(idft) {
		reverse(f+1,f+n);
		for(int i=0,x=ksm(n);i<n;++i) f[i]=1ll*f[i]*x%MOD;
	}
}
int f[18][18][N],g[18][18][N],a[N],b[N];
int C(int x,int y) { return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD; }
void add(int &x,int y) { x=(x+y>=MOD)?x+y-MOD:x+y; }
signed main() {
    freopen("zzz.in","r",stdin);
    freopen("zzz.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>MOD,poly_init();
	for(int i=1;i<18;++i) {
		int s=1<<(i-1),len=s<<1;
		memset(a,0,sizeof(int)*len);
		for(int k=0;k<s;++k) a[k]=C(s-1,k);
		ntt(a,0,len);
		for(int j=0;j<i-1;++j) {
			int *F=f[i][j],*G=g[i][j];
			memset(b,0,sizeof(int)*len);
			for(int k=0;k<s;++k) b[k]=f[i-1][j][k];
			ntt(b,0,len);
			for(int k=0;k<len;++k) b[k]=1ll*a[k]*b[k]%MOD;
			ntt(b,1,len);
			for(int k=0;k<len;++k) add(G[k],b[k]),add(F[k],b[k]),add(F[k+1],b[k]);
			for(int k=0;k<s;++k) add(F[k+s],f[i-1][j][k]),add(F[k+s],g[i-1][j][k]),add(G[k+s],g[i-1][j][k]);
		}
		if(i==1) f[1][0][1]=g[1][0][1]=1;
		else for(int k=0;k<s-1;++k) f[i][i-1][k+s]=g[i][i-1][k+s]=C(s-2,k);
	}
	int T; cin>>T;
	for(int k,n,p;T--;) {
		cin>>k>>n>>p;
		if(n==(1<<k)) cout<<(p==n)<<"\n";
		else cout<<(p==(p&-p)?f[k][__lg(p)][n]:0)<<"\n";
	}
	return 0;
}