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
	int n;
	cin>>n;
	queue<int>q;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		q.push(t);
	}
	q.push(INT_MIN);
	int i=0;
	int s,a;
	while(1)
	{
		i++;
		s=q.front();
		//cout<<s<<endl;
		q.pop();
		a=q.front();
		if(a!=INT_MIN)
		{
			if(i%2)
				q.push(s+a);
			else
				q.push(s-a);
		}
		else
		{
			i--;
			q.pop();
			if(q.size()<=0)
				break;
			q.push(INT_MIN);
		}
	}
	cout<<s<<endl;
	return 0;
}

