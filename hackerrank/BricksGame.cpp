#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int map1=0,map2=0;
void func(vi a,int n, bool p,int p1,int p2)
{
	if(n==0){
	map1=max(map1,p1);
	map2=max(map2,p2);
	}
	if(p==0)
	{
		p=1;
		if(n>0)
		func(a,n-1,p,p1+a[n-1],p2);
		if(n>1)
		func(a,n-2,p,p1+a[n-1]+a[n-2],p2);
		if(n>2)
		func(a,n-3,p,p1+a[n-1]+a[n-2]+a[n-3],p2);
		
	}
	else
	{
		p=0;
		if(n>2)
		func(a,n-3,p,p1,p2+a[n-1]+a[n-2]+a[n-3]);
		else if(n>1)
                func(a,n-2,p,p1,p2+a[n-1]+a[n-2]);
		else if(n>0)
                func(a,n-1,p,p1,p2+a[n-1]);

	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map1=map2=0;
		int n;
		cin>>n;
		vi a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		reverse(all(a));
		func(a,n,0,0,0);
		cout<<map1<<endl;
	}
	return 0;
}

