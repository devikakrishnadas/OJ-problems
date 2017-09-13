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

vi A(5000023,0);
void prime()
{
	for(int i=2;i<=5000000;i++)
	{
		if(!A[i])
		{
			for(int j=1;i*j<=5000000;j++)
			{
				A[i*j]++;
			}
		}
	}
}
//vi A(5000000,0);
int main()
{
	
	prime();
	int t;
//	A[1]=0;
	cin>>t;
	while(t--)
	{
	
		ll a,b;
		cin>>a>>b;
		
		cout<<A[a]<<" "<<A[b]<<endl;
	}
	return 0;
}

