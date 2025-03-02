#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[int(1e6)+10],bef[int(1e6)+10];
int mp[int(1e6)+10];
vector<int>t[4000010];
inline void creat(int l,int r,int root){
	if(l==r){
		t[root].push_back(bef[l]);
		return;
	}
	int mid=l+r>>1;
	creat(l,mid,root*2);
	creat(mid+1,r,root*2+1);
	int i=0,j=0;
	while(i<t[root*2].size() && j<t[root*2+1].size())
		if(t[root*2][i]<t[root*2+1][j]) t[root].push_back(t[root*2][i++]);
		else t[root].push_back(t[root*2+1][j++]);
	while(i<t[root*2].size()) t[root].push_back(t[root*2][i++]);
	while(j<t[root*2+1].size()) t[root].push_back(t[root*2+1][j++]);
}
inline int ask(int l,int r,int x=1,int y=n,int root=1){
	if(l<=x && y<=r) return lower_bound(t[root].begin(),t[root].end(),l)-t[root].begin();
	int mid=x+y>>1,tot=0;
	if(l<=mid) tot+=ask(l,r,x,mid,root*2);
	if(mid<r) tot+=ask(l,r,mid+1,y,root*2+1);
	return tot;
}
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		bef[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	creat(1, n, 1);
	cin >> m;
	while (m--) {
		int l = read(), r = read();
		cout << ask(l, r) << "\n";
	}
	return 0;
}