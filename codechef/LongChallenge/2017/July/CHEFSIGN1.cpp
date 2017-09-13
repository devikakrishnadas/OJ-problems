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
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int cnt=0;
        int fin=0;
        int mi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='<') cnt++;
            else if(s[i]=='>') cnt--;
            fin=max(fin,cnt);
            mi=min(mi,cnt);
        }
        if(abs(mi)<fin)
        {
           fin=fin+abs(mi)+1;
        }
        else fin=abs(mi)+1;
        cout<<fin<<endl;
    }
	return 0;
}

