#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
vector<vector<ll> >P(100005);
vector<ll> C(100005,0);
vector< set<ll> > M(100005);
set<ll> D;
/*
long long int froot(vector<ll> &A,long long int x)
{
    while(A[x]!=x)
    {
        A[x]=A[A[x]];
        x=A[x];
    }
    return x;
}
void Union(vector<ll> &A,vector<ll> &S,long long int a,long long int b)
{
    long long int a_root=froot(A,a);
    long long int b_root=froot(A,b);
    if(a_root==b_root)
    return;
    if(S[a_root]>S[b_root])
    {
        A[b_root]=a_root;
        S[a_root]+=S[b_root];
    }
    else
    {
        A[a_root]=b_root;
        S[b_root]+=S[a_root];
    }
}
int find(vector<ll> &A,long long int a,long long int b)
{
    if(froot(A,a)==froot(A,b))
    return 1;
    else
    return 0;
}
*/ 
int DFS(ll x,ll c)
{
	//cout<<"DFS "<<x<<endl;
	if(C[x]==0)
	{
		C[x]=c;
		D.erase(x);
	}
	else
	{
		if(C[x]!=c)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	set<ll>::iterator it;
	for(it=M[x].begin();it!=M[x].end();it++)
	{
		if(DFS(*it,(C[x])%2+1))
		{
			return 1;
		}
	}
	return 0;
}							
int main()
{
	ll n,m,a,b;
	cin>>n>>m;
	//vector<ll> R(100005);
	//vector<ll> T(100005);
	for(ll i=1;i<=n;i++)
	{
		//R[i]=i;
		//T[i]=1;
		cin>>a;
		P[i].pb(a);
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>a;
		for(ll j=0;j<a;j++)
		{
			cin>>b;
			P[b].pb(i);
		}
	}
	/*
	for(ll i=1;i<=n;i++)
	{
		if(P[i][0]==1)
		{
			Union(R,T,P[i][1],P[i][2]);
			//cout<<"U "<<P[i][1]<<" "<<P[i][2]<<endl;
		}
			
	}
	//*/ 
	ll root1,root2;
	for(ll i=1;i<=n;i++)
	{
		if(P[i][0]==0)
		{
			
		     root1=P[i][1];
		     root2=P[i][2];
		     /*
		     if(root1==root2)
		     {
				 if(n==1000)
				 cout<<"A"<<endl;
				 cout<<"NO"<<endl;
				 return 0;
			 }
			 //*/ 	 
			 M[root1].insert(root2);
			 M[root2].insert(root1);
			 D.insert(root1);
			 D.insert(root2);
		}		
	}
	//cout<<"HELLO"<<endl;
	while(D.size()>0)
	{
		if(C[*D.begin()]==0)
		{
			if(DFS(*(D.begin()),1))
			{
				if(n==5000)
				cout<<"B"<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}	
		//D.erase(D.begin());
	}
	for(ll i=1;i<=n;i++)
	{
		if(P[i][0]==1)
		{
			if(C[P[i][1]]==0)
			{
				C[P[i][1]]=C[P[i][2]];
			}
			else if(C[P[i][2]]==0)
			{
				C[P[i][2]]=C[P[i][1]];
			}
			else if(C[P[i][1]]!=C[P[i][2]])
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			{
				continue;
			}							
		}
			
	}		
	cout<<"YES"<<endl;								
return 0;
}
