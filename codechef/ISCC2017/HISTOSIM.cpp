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
        string a,b;
        cin>>a>>b;
        bool enter=0;
        int cnt=0;
        int c[100023]={0};
        int d[100023]={0};
        int isused[100023]={0};
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i]) continue;
            if(c[a[i]]==0)
            {
                c[a[i]]=b[i];
            }
            else if(c[a[i]]!=b[i])
            {
                cout<<"NO"<<endl;
                enter=1;
                break;
            }
            if(d[b[i]]==0)
            {
                d[b[i]]=a[i];
            }
            else if(d[b[i]]!=a[i])
            {
                cout<<"NO"<<endl;
                enter=1;
                break;
            }
            if(isused[a[i]]==0)
                cnt++;
            isused[a[i]]=1;
        }
        if(enter)
            continue;
        if(cnt==26)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
	return 0;
}

