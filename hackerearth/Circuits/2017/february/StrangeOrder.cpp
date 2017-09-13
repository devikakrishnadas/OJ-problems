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
	set<int>A;
	for(int i=1;i<=n;i++)
		A.insert(i);
	set<int>::iterator it=A.end();
	it--;
	for(;*it!=1;it--)
	{
		cout<<*it<<" ";
		set<int>::iterator it1=it;
		it1--;
		for(;*it1!=1;it1--)
		if(__gcd(*it,*it1)!=1)
		{
			cout<<*it1<<" ";
			A.erase(it1);
		}
	}
	cout<<1<<endl;
	return 0;
}

