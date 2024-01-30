// what is matter? never mind.  
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define int long long
#define ull unsigned long long
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 5005
#define inf 0x3f3f3f3f

int n,a[maxn];
modint f[maxn][maxn];
modint sf[maxn];

bool eq(int x,int y){
	return a[x]==-1 || a[x]==y;
}
int neq(int x,int y){
	if(a[x]==-1)return n-1;
	if(a[x]==y) return 0;
	return 1;
}

int tmp[5005][5005];
int get(int x,int y){
	if(x==-1)return y;
	if(y==-1)return x;
	if(x==y)return x;
	return -2;
}
bool allok(int l,int r,int x){
	return tmp[l][r]==-1 || tmp[l][r]==x;
}

signed main()
{
	n=read();
	For(i,1,n)a[i]=read();
	For(l,1,n){
		tmp[l][l]=a[l];
		For(r,l+1,n)tmp[l][r]=get(tmp[l][r-1],a[r]);
	}
	sf[0]=1;
	For(i,1,n){
		For(j,1,n)
			if(eq(i,j)){
	//			cout<<"eq "<<i<<" "<<j<<endl;
				f[i][j]=sf[i-1];
				if(i>=j+1){
					if(allok(i-j,i,j))
						f[i][j]-=sf[i-j-1]-f[i-j-1][j];
				}
			}
		For(j,1,n) sf[i]+=f[i][j];
	//	For(j,1,n) cout<<f[i][j].x<<" ";cout<<"\n";
	}
	cout<<sf[n].x;
	return 0;
}
