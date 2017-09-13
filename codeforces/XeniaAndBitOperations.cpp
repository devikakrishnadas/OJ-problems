#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int maketreeutil(vll &tree,ll s, ll e, ll p, vll &a,ll h)
{
	
	if(s==e)
	{
		//cout<<"r1"<<endl;
		tree[p]=a[s];
		//cout<<"r2"<<endl;
		return tree[p];
	}
	ll m=(s+e)/2;
	tree[2*p]=maketreeutil(tree,s,m,2*p,a,h-1);
	//cout<<"r3"<<endl;
	tree[2*p+1]=maketreeutil(tree,m+1,e,2*p+1,a,h-1);
	//cout<<"r4"<<endl;
	if(h%2)
	{
		tree[p]=tree[2*p]|tree[2*p+1];
	}
	else
	{
		tree[p]=tree[2*p]^tree[2*p+1];
	}
	return tree[p];
}

int updatetree(vll &tree,ll s,ll e,ll p,ll pos,ll item,ll h)
{
	if(s==e )
	{
		if(s==pos)
		{
			tree[p]=item;
//			cout<<"Pos "<<pos<<endl;
			return tree[p];
		}
		return tree[s];
	}
	
	ll m=(s+e)/2;
	if(pos<=m)
	{
		tree[2*p]=updatetree(tree,s,m,2*p,pos,item,h-1);
	}
	else
	{
		tree[2*p+1]=updatetree(tree,m+1,e,2*p+1,pos,item,h-1);
	}
	if(h%2)
        {
                tree[p]=tree[2*p]|tree[2*p+1];
        }
        else
        {
                tree[p]=tree[2*p]^tree[2*p+1];
        }
	return tree[p];
}
vll maketree(vll &a, ll n, ll tn)
{
	vll tree(655360,0);
	maketreeutil(tree,1,n,1,a,tn);//segment tree, start, end, pointer, arr
	//cout<<"r5"<<endl;
	return tree;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll tn=n;
	n=pow(2,n);
	vll a(n+10);
	for(int i=1;i<=n;i++) cin>>a[i];
	vll tree=maketree(a,n,tn);
//	for(int i=1;i<=7;i++)
//	{
//		cout<<tree[i]<<" ";
//	}
//	cout<<endl;
//	vll tree=maketree(a,n);
	//cout<<"r6"<<endl;
	while(m--)
	{
		ll p,b;
		cin>>p>>b;
//		cout<<"pos "<<p<<endl;
		updatetree(tree,1,n,1,p,b,tn);
		//for(int i=1;i<=3;i++)
		//{
		//	cout<<tree[i]<<" ";
		//}
		//cout<<endl;
		cout<<tree[1]<<endl;
	}
	return 0;
}
