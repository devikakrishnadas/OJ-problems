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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int A[300]={0};
        for(int i=0;i<s.length();i++)
        {
            A[s[i]]++;
        }
        int one=0;
        int two=0;
        for(char i='a';i<='z';i++)
        {
            if(A[i]%2==0) two++;
            else one++;
        }
        if(one>1)
        {
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"yes"<<endl;
        }

    }
	return 0;
}

