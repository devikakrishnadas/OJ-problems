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
		int c,d,l;
		cin>>c>>d>>l;
		if((l%4)!=0)
		{
			cout<<"no"<<endl;
			continue;
		}
		l=l/4;
		
		if(l>(c+d))
		{
			cout<<"no"<<endl;
			continue;
		}
		int mi=d;
		if(c-d-d>0)
			mi=mi+(c-d-d);
		if(l<mi)
		{
			cout<<"no"<<endl;
		}
		else cout<<"yes"<<endl;
	}
	return 0;
}

