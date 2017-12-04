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
    string s;
    cin>>s;
    if(s.length()<7)
    {
        cout<<"no"<<endl;
        return 0;
    }
    int z=0,o=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='0') z++;
        else if(z>=6)
        {
            cout<<"yes"<<endl;
            return 0;
        }
    }
    cout<<"no"<<endl;
	return 0;
}

