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
	int n,k;
	cin>>n>>k;
	vi a(n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=a[i]*10;
		sum=sum+a[i];
	}
	int i=n;
	while((sum/i)<k*10-5)
	{
		i++;
		sum+=(k*10);
	}
	cout<<i-n<<endl;
	return 0;
}

