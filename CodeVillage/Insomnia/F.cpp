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
	ll n;
	cin>>n;
	vll a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.begin()+n);
	ll bunk=n/4;
	ll time=INT_MAX,s=-1,e=-1;
	for(int i=0,j=n-bunk-1;j<n;j++,i++)
	{
		int temp=a[j]+1-a[i];
		if(temp<=time)
		{	
			time=temp;
			s=a[i];
			e=a[j]+1;
		}
	}
	cout<<s<<" "<<e<<endl;
	return 0;
}

