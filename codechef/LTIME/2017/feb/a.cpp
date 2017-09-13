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
	int t,n;
	cin>>t;
	char A[100023];
	while(t--)
	{
		cin>>n;
		int c=0;
		bool no=0;
		for(int i=0;i<n;i++)
		{
			cin>>A;
			if( strcmp(A,"cookie")==0)
			{
				if(c==1)
					no=1;
				
				c=1;
			}
			else c=0;
		}
		if(no || c) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

