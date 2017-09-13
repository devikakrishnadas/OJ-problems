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

int LIS( vi A )
{
	vi cnt((int)A.size(),1);
	int ma=0;
	for(int i=1;i<A.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[j]<A[i])
			{
				cnt[i]=max(cnt[i],1+cnt[j]);
			}
		}
		ma=max(ma,cnt[i]);
	}
	return ma;
}
int main()
{
	vi A;	
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.pb(x);
	}
	cout<< LIS(A) <<endl;
	return 0;
}

