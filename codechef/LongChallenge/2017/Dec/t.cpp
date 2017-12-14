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

int mi=INT_MAX;
int x,y,z,a,b,c;
void func(int i,int j,int k,int val)
{
    if(i<0 || j<0 || k<0) return;
    if(i==0 && j==0 && k==0)
    {
        mi=min(mi,val);
        return;
    }
    func(i-1,j,k,val+a);
    func(i,j-1,k,val+a);
    func(i,j,k-1,val+a);
    func(i-1,j-1,k,val+b);
    func(i-1,j,k-1,val+b);
    func(i,j-1,k-1,val+b);
    func(i-1,j-1,k-1,val+c);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
int t;
cin>>t;
    while(t--)
    {
        cin>>x>>y>>z>>a>>b>>c;
        func(x,y,z,0);
        cout<<mi<<endl;
    }
	return 0;
}

