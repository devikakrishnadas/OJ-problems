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
#define ALPHABETS 26
#define CASE 'a'

using namespace std;


// Implementation of a prefix trie

class node
{
        public:
        node *children[ ALPHABETS ];
        node()
        {
                for(int i=0;i<ALPHABETS;i++)
                {
                        children[i]=NULL;
                }
        }
};

class trie
{
        private:
                node *root;
                vector< node* > activePoints;
        public :
                int ans;

                trie()
                {
                        root=new node;
                        ans=0;
                }

                node* retRoot()
                {

                        return root;
                }

                void addWordUtil(char *word);
                //void searchUtil(int k,int countBadWords[ALPHABETS],int badCount,node *key);
};

void trie::addWordUtil(char *word)
{
        while(*word != '\0')
        {
                activePoints.pb(root);
                for(int i=0;i<activePoints.size();i++)
                {
                        if(activePoints[i]->children[*word-CASE]==NULL)
                        {
                                node *p=new node;
                                activePoints[i]->children[*word-CASE]=p;
                        }
                        activePoints[i]=activePoints[i]->children[*word-CASE];
                }
                ++word;
        }
}

/*

Function written for the question Good Substring - Codeforces

void trie::searchUtil(int k,int countBadWords[ALPHABETS],int badCount,node *key)
{
        for(int i=0;i<ALPHABETS;i++)
        {
                if(key->children[i]!=NULL && countBadWords[i]+badCount<=k)
                {
                        ans++;
                        searchUtil(k,countBadWords,badCount+countBadWords[i],key->children[i]);
                }
        }
}
*/
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        return 0;
}
