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
		int n;
		cin>>n;
		vector<int>A(n+5);
		int fine=0;
		bool enter=0;
		int count=0;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
			if(!A[i] )
			{
				if(!enter)
				{
					enter=1;
					fine=n-i;
				}
				count++;
			}
		}
		cout<<count*1000+fine*100<<endl;
		
	}
	return 0;
}

