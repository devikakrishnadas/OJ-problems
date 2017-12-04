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

int val=24;
vi a(val+1,0);

int eq(int aa,int bb,int cc,int dd)
{
    if(a[aa]==a[bb] && a[aa]==a[cc] && a[aa]==a[dd]) return 1;
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    for(int i=1;i<=val;i++)
    {
        cin>>a[i];
    }

    if(eq(1,3,21,23))
    {
        if(eq(5,7,2,4))
        {
            if(eq(9,11,6,8))
            {
                 if(eq(10,12,22,24))
                {
                    if(eq(13,14,15,16))
                    {    
                        if(eq(17,18,19,20))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(eq(1,3,6,8))
    {
        if(eq(5,7,10,12))
        {
            if(eq(9,11,21,23))
            {
                 if(eq(2,4,22,24))
                {
                    if(eq(13,14,15,16))
                    {    
                        if(eq(17,18,19,20))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(eq(13,14,7,8))
    {
        if(eq(5,6,19,20))
        {
            if(eq(17,18,23,24))
            {
                 if(eq(21,22,15,16))
                {
                    if(eq(1,2,3,4))
                    {    
                        if(eq(9,10,11,12))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(eq(15,16,5,6))
    {
        if(eq(7,8,17,18))
        {
            if(eq(19,20,21,22))
            {
                 if(eq(23,24,13,14))
                {
                    if(eq(1,2,3,4))
                    {    
                        if(eq(9,10,11,12))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(eq(14,16,1,2))
    {
        if(eq(3,4,18,20))
        {
            if(eq(17,19,11,12))
            {
                 if(eq(9,10,13,15))
                {
                    if(eq(21,22,23,24))
                    {    
                        if(eq(5,6,7,8))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(eq(14,16,11,12))
    {
        if(eq(9,10,20,18))
        {
            if(eq(1,2,17,19))
            {
                 if(eq(3,4,13,15))
                {
                    if(eq(21,22,23,24))
                    {    
                        if(eq(5,6,7,8))
                        {
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    /*if(eq(1,2,3,4) && eq(5,6,7,8) && eq(9,10,11,12) && eq(13,14,15,16) && eq(17,18,19,20) && eq(21,22,23,24))
    {
        cout<<"YES"<<endl;
        return 0;
    }*/
    cout<<"NO"<<endl;
    return 0;
}

