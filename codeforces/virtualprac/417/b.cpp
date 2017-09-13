#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	int ans=0;
	cin>>n>>m;
	int A[100][100]={0};
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m+2;j++)
		{
			A[i][j]=s[j]-'0';
		}
	}
	//cout<<"r1"<<endl;
	int l=0,r=0;
	for(int i=n-1;i>=0;i--)
	{
		int e=0;
		if(!i)
		{
			for(int j=1;j<m-1;j++)
			{
				if(A[i][j])
					e=j;
			}
			l=2*e+1;
			r=m+2;
		}
		else
		{
			for(int j=1;j<m-1;j++)
                        {
                                if(A[i][j])
                                        e=j;
                        }
			ans=ans+min(l+e,m-e);
			if(l+e<m-e)
			{
				l=2*e+1;
				r=m;
			}
			else
			{
				l=m;
				r=2*(m-e)+1;
			}
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

