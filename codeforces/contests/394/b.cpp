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
	int n, l;
	cin>>n>>l;
	vi kefa,kefaD,sasha,sashaD;
	int x;
	int aa;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		kefa.pb(x);
	}
	for(int j=0;j<n;j++)
	{
		cin>>x;
		sasha.pb(x);
	}
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<n;j++)
		{
			kefa[j]=(kefa[j]+1)%l;
		}
		sort(kefa.begin(),kefa.end());
		if(kefa==sasha)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	

	cout<<"NO"<<endl;
	return 0;
}

