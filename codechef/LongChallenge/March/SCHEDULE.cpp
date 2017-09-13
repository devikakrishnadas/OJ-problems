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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vi A(n);
		char temp[1000023];
		cin>>temp;
		vi B;
		int cnt=1;
		for(int i=0;i<n;i++)
		{
			A[i]=temp[i]-'0';
			if(i)
			{
				if(A[i]!=A[i-1])
				{
					B.pb(cnt);
					cnt=1;
				}
				else cnt++;
			}
		}
		B.pb(cnt);
		sort(B.begin(),B.end());
		vi x(n,0);
		vi y(n,1);
		for(int i=1;i<n;i+=2)
		{
			x[i]=1;
			y[i]=0;
		}
		int xc=0,yc=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]!=x[i]) xc++;
			if(A[i]!=y[i]) yc++;
		}
		if(xc<=k || yc<=k)
		{
			cout<<1<<endl;
			continue;
		}
		//bool ans=0;
		cnt=0;
//		cout<<"r1"<<endl;
		for(int w=2;w<=1000000;w++)
		{
			cnt=0;
			for(int i=0;i<B.size();i++)
				cnt+=(B[i]/(w+1));
			if(cnt<=k)
			{
				cout<<w<<endl;
			//	ans=1;
				break;
			}
		}
	}
	return 0;
}
