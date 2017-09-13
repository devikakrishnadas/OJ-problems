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
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cout<<n<<" ";
		n--;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i;
		if(i!=n) cout<<" ";
	}
	cout<<endl;
	return 0;
}

