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
    int cnt=0;
    while(t--)
    {
        cnt++;
        string s;
        int count[300]={0};
        while(1)
        {
            cin>>s;
            if(s=="*")
            {
                break;
            }
            for(int i=0;i<s.length();i++)
            {
                count[toupper(s[i])]++;
            }
        }
        vector<pair<int,int> >A;
        for(int i='A';i<='Z';i++)
        {
            A.pb(mp(count[i],i-'A'));
            //cout<<count[i]<<" ";
        }
        //cout<<endl;
        sort(all(A));
        reverse(all(A));
        int ans=0;
        int temp[1000000]={0};
        int i=0;
        int cc=0;
        for(int i=0;i<5;i++)
        {
            if(A[i].ff==0)
                continue;
            //cout<<(char)(A[i].ss+'A')<<" "<<A[i].ff<<" "<<A[i].ss<<endl;
            ans+=A[i].ss;   
        }
        //cout<<A[i].ff<<" "<<A[i].ss<<endl;
        cout<<"Case "<<cnt<<": ";
        if(ans>62)
        {
            cout<<"Effective"<<endl;
        }
        else
        {
            cout<<"Ineffective"<<endl;
        }
    }
	return 0;
}

