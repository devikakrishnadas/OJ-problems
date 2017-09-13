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
	int n;
	cin>>n;
	vector< vc >A(n);
	char t[500023];
	int leng[500023];
	for(int i=0;i<n;i++)
	{
		cin>>t;
		leng[i]=strlen(t);
		for(int j=0;j<leng[i];j++)
		{
			A[i].pb(t[j]);
		}
	}
	for(int i=n-2;i>=0;i--)
	{
//		leng[i]=min(leng[i],leng[i+1]);
		int j=0;
		for(j=1;j<min(leng[i],leng[i+1]);j++)
		{
			if(A[i][j]<A[i+1][j])
				break;
			if(A[i][j]>A[i+1][j])
			{
				leng[i]=j;
				break;
			}
		}
		//if(i==0) cout<<j<<" "<<leng[i]<<" "<<leng[i+1]<<endl;
		if(j==min(leng[i],leng[i+1])) 
		{
			
			leng[i]= min(leng[i],leng[i+1]);
		//	cout<<j<<"*"<<endl;
		}
	}
//	cout<<leng[0]<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<leng[i];j++)
		{
			cout<<A[i][j];
		}
		cout<<endl;
	}
	return 0;
}

