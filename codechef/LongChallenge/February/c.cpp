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
		int o1,o2;
		cin>>o1>>o2;
		int n=o1*o2;
		vi A;
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			A.pb(x);
		}
//		vi B(2*n);
		int z=0,o=0;
		for(int i=0;i<o2;i++)
		{
			if(A[i]==0) z++;
			else o++;
		}
		vi B;
		if(z>o) B.pb(0);
		else B.pb(1);
		ll l=o2-1;
		for(int i=1;i<n;i++)
		{
			if(A[i-1]==0) z--;
			else o--;
			l++;
			l=l%n;
			if(A[l]==0) z++;
			else o++;
			if(z>o) B.pb(0);
			else B.pb(1);
		}
//		for(int i=0;i<n;i++)
//		{
//			cout<<B[i]<<" ";
//		}
//		cout<<endl;
		vi C(o2,0);
		for(int i=0;i<B.size();i++)
		{
			C[i%o2]+=(B[i]);
		}
		bool enter=0;
		for(int i=0;i<o2;i++)
		{
			if(C[i]>o1/2)
			{
				enter=1;
				cout<<1<<endl;
				break;
			}
		}
		if(enter==0) cout<<0<<endl;
	}
	return 0;
}

