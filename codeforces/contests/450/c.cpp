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
    vi a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(x);
    }
    int ma1=0;
    int ma2=1;
    int mav1=0;
    int mav2=0;
    vi x(100023,0);
    for(int i=0;i<n;i++)
    {
        if(a[i]>mav1)
        {
            mav2=mav1;
            mav1=a[i];
            ma2=ma1;
            ma1=i;
            x[a[i]]--;
        }
        else if(a[i]>mav2)
        {
            mav2=a[i];
            ma2=i;
            x[mav1]++;
        }
//        cout<<ma1<<" "<<ma2<<endl;
    }
    int ai=1;
/*    for(int i=0;i<n;i++)
    {
        cout<<x[a[i]]<<" ";
    }
    cout<<endl;
*/    for(int i=n;i>=1;i--)
    {
        if(x[i]>=x[ai])
        {
            ai=i;
        }
        //cout<<"*"<<ai<<" "<<x[i]<<" "<<x[ai]<<endl;
    }
    cout<<ai<<endl;
	return 0;
}

