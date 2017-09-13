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

int lis(vll A,int n)
{

        vll tail(n);
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
	ll n,m;
	cin>>n>>m;
	vll a(n);
	float t;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>t;
		a[i]*=10000;
		a[i]+=2;
	}
	for(int i=0,j=1;i<n;i++,j++)
	{
		a[i]+=j;
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	cout<<n-lis(a,n)<<endl;
	return 0;
}

