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
queue<int>q;
int ans=0;
int n,m;
int A[300][300]={0};
int cnt=0;
void funct(int a,int root)
{
	
	for(int i=1;i<=n;i++)
	{
//		cout<<a<<" "<<i<<endl;
		if(!A[a][i]) continue;
		funct(i,root);
		cnt++;
		if(a==root)
		{
			q.push(i);
			if(cnt%2==0 && cnt!=0)
			{
				A[a][i]=0;
				ans++;
			}
			cnt=0;
		}
	}
}
int main()
{

	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		A[y][x]=1;
	}
	q.push(1);
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		funct(a,a);
	}
	cout<<ans<<endl;
	return 0;
}

