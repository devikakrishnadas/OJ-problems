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
	int ans=INT_MAX;
	int a,b;
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if((n/i)-i<ans)
			{
				a=n/i;
				b=i;
				ans=a-b;
			}
		}
	}
	cout<<b<<" "<<a<<endl;
	return 0;
}

