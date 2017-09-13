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
	int n,q;
	cin>>n>>q;
	int A[200]={0};
//	vector< pair<int,pair<int,int> > >A;
	int t,k,d;
	int tn=n;
	int ans[100023]={0};
	for(int i=0;i<q;i++)
	{
		cin>>t>>k>>d;
		for(int j=1;j<=n;j++)
		{
			if(A[j]<t && A[j])
			{
				A[j]=0;
				tn++;
			}
		}
//		cout<<"*"<<tn<<" "<<k<<endl;
		if(k<=tn)
		{
			tn=tn-k;
			int ansval=0;
			for(int j=1;j<=n ;j++)
			{
				if(!A[j] && k--)
				{
					A[j]=t+d-1;
					ansval+=j;
					
				}
				if(k==0) break;
				
			}
			ans[i]=ansval;
		}
		else ans[i]=-1;
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

