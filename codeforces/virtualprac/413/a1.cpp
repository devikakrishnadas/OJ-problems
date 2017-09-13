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
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int i=1;
	int cycles=(n/k);
	if(n%k)
		cycles++;
	int time=cycles*t;
	while(i)
	{
		
		if(i%t==0)
		{
			n-=k;
		}
		if((i-d)%t==0 && i>d)
		{
			n-=k;
		}
		if(n<=0)	
		{
			if(i<time)
			{
				//cout<<i<<" "<<n<<endl;
				cout<<"YES"<<endl;
			}
			else
			{
				//cout<<i<<" "<<n<<" "<<endl;
				cout<<"NO"<<endl;
			}
			return 0;
		}
		i++;
	}
	//cout<<n<<" "<<i<<endl;
	
	return 0;
}

