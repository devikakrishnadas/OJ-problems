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


void unitens(vector<string> &B,ll a,string units[],string tens[])
{
    if(a%100 == 0 ) 
        return;
    if(a%100 > 20)
        {
            int t=a%100;
            t=t/10;
            if(a%10)
                B.pb(units[a%10]);
            if(t)
                B.pb(tens[t]);
        }
        else
        {
            B.pb(units[a%100]);
        }
}
void hundred(vector<string> &B, ll a)
{
    B.pb("Hundred");
    string A[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    B.pb(A[a]);
}

void thousand(vector<string> &B, ll a,string units[],string tens[])
{
    B.pb("Thousand");
    /*string A[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    B.pb(A[a]);*/
    unitens(B,a,units,tens);
}

void lakh(vector<string> &B, ll a,string units[],string tens[])
{
    B.pb("Lakh");
    /*string A[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    B.pb(A[a]);*/
    unitens(B,a,units,tens);
}

void crore(vector<string> &B, ll a,string units[],string tens[])
{
    B.pb("Crore");
    /*string A[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    B.pb(A[a]);*/
    unitens(B,a,units,tens);
    a=a/100;
    if(a%10)
        hundred(B,a%10);
    a=a/10;
    if(a%100)
        thousand(B,a%100,units,tens);
    a=a/100;
    if(a%100)
        lakh(B,a%100,units,tens);
    a=a/100;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        ll a;
        cin>>a;
        vector<string>B;
        //unitens(B,a,unit,tens);
        //a=a/100;
        if(!a)
        {
            cout<<"Zero Only"<<endl;
            continue;
        }
        string unit[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
        string tens[]={"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred"};
            unitens(B,a,unit,tens);
            a=a/100;
            if(a%10)
                hundred(B,a%10);
            a=a/10;
            if(a%100)
                thousand(B,a%100,unit,tens);
            a=a/100;
            if(a%100)
                lakh(B,a%100,unit,tens);
            a=a/100;
            //cout<<a<<endl;
            if(a%100)
                crore(B,a,unit,tens);
        for(int i=B.size()-1;i>=0;i--)
            cout<<B[i]<<" ";
        cout<<"Only";
        cout<<endl;
    }
	return 0;
}

