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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int lis(vi A,int n)
{

	vi tail(n);
	tail[0]=A[0];
	int len=1;
	for(int i=1;i<A.size();i++)
	{
		if(A[i]<tail[0])//If the element is the least, replaces the first element of all lists
		{
			tail[0]=A[i];
		}
		if(A[i]>tail[len-1]) //If the element is greater than all other, then appends to all the list
		{
			tail[len++]=A[i];
		}
		else
		{
			*lower_bound(tail.begin(),tail.begin()+len,A[i])=A[i]; //Finds the lower bound of the index and replaces it with A[i]
		}
	}
	return len;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi a(n);
    REP(i,n) cin>>a[i];
    reverse(all(a));
    int val = lis(a,n);
    cout<<abs(val-2)<<endl;
	return 0;
}

