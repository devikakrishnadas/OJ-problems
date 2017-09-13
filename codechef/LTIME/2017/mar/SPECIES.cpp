#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

ll cnt=0;
ll GB=0,BB=0,PB=0;
void func( char A[51][51],int x,int y,int n,int vis[50][50])
{
	//cout<<x<<" "<<y<<endl;
	if(x<0 || y<0 || x>=n || y>=n )
		return;
	if(vis[x][y]==1|| A[x][y]=='.')
		return;
	if(A[x][y]=='?')
	cnt++;
//	cout<<x<<" "<<y<<endl;
	//vis[x][y]=1;
	if(A[x][y]=='B') BB=1;
	else if(A[x][y]=='P') PB=1;
	else if(A[x][y]=='G') {GB++;
	}
	
	func(A,x+1,y,n,vis);
	func(A,x,y+1,n,vis);
	func(A,x-1,y,n,vis);
	func(A,x,y-1,n,vis);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		//vector <vc>A(n);
		char x[51];
		int n;
		cin>>n;
//		n=50;
		bool qm=0;
//		vector<vc>A(n);
		char A[51][51];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		//	for(int j=0;j<n;j++)
		//	{
		//		if((i+j)%2) A[i]='.';
		//		else A[i]='?';
//			}
		}
		int vis[50][50]={0};
		ll ans=1;bool no=0;
		int c=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!vis[i][j] && A[i][j]!='.')
				{
//					qm=1;
//					enter=1;
					GB=0;
					BB=0;
					PB=0;
					cnt=0;
					func(A,i,j,n,vis);
					if(!GB && !PB && !BB && cnt==1)
					{
						ans=((ans*3))%1000000007;
						c++;
					}
					else if(!GB && !PB && !BB && cnt>1)
					{
						ans=((ans*2))%1000000007;
					}
					if(GB>1)
					{
						cout<<0<<endl;no=1;
						break;
					}
					else if((GB && BB) || (GB && PB) || (BB && PB))
					{
						cout<<0<<endl;no=1;
						break;
					}
				}
			}
			if(no) break;
		}
		//cout<<c<<endl;
		if(!no )
			cout<<ans<<endl;
//		else if(!no && !qm) cout<<0<<endl;
	}
	return 0;
}

