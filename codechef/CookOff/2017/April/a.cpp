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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		for(int i=1;;i++)
		{
			if(i%2) a=a-i;
			else b=b-i;
			if(a<0)
			{
				cout<<"Bob"<<endl;
				break;
			}
			else if(b<0)
			{
				cout<<"Limak"<<endl;
				break;
			}
		}
	}
	return 0;
}

