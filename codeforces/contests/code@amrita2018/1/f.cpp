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
    string s,t;
    cin>>s>>t;
    int j=0;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]==s[j])
            j++;
    }
    cout<<j+1<<endl;
	return 0;
}

