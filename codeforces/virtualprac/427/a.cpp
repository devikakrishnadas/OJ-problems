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
    ll s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    ll first=s*v1 + 2*t1;
    ll sec=s*v2 + 2*t2;
    if(first<sec)
        cout<<"First"<<endl;
    else if(sec<first)
        cout<<"Second"<<endl;
    else
        cout<<"Friendship"<<endl;
	return 0;
}

