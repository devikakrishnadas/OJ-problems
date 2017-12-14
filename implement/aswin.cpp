#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define endl '\n'
using namespace std;
struct node
{
    int val,p,s,ls,rs;
    node *l, *r;
};
typedef node * pnode;
int getSize(pnode t)
{
    if(t)
        return t->s;
    else
        return 0;
}
void updateSize(pnode t)
{
    if(t!=NULL)
    {
        t->ls = getSize(t->l);
        t->rs = getSize(t->r);
        t->s = t->ls + t->rs +1;
    }
}
void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)
        l=r=NULL;
    else if(t->val <=key)
    {
        split(t->r,t->r,r,key);
        l=t;
    }
    else
    {
        split(t->l,l,t->l,key);
        r=t;
    }
    updateSize(t);
 
}
void merge(pnode &t, pnode l, pnode r)
{
    if(!l || !r)
        t=l?l:r;
    else
    {
        if((l->p)>(r->p))
        {
            merge(l->r,l->r,r);
            t=l;
        }
        else
        {
            merge(r->l,l,r->l);
            t=r;
        }
        updateSize(t);
    }
}
bool search(pnode t,int key)
{
    if(t==NULL)
        return false;
    else if(t->val > key)
        search(t->l,key);
    else if(t->val <key)
        search(t->r,key);
    else
        return true;
}
void insert(pnode &t, pnode it)
{
    if(!t)
        t=it;
    else if((it->p)>(t->p))
    {
        split(t,it->l,it->r,it->val);
        t=it;
    }
    else
    {
        if((t->val)>(it->val))
            insert(t->l,it);
        else
            insert(t->r,it);
    }
    updateSize(t);
}
void remove(pnode &t,int key)
{
    if(!t)
        return;
    else if((t->val)==key)
    {
        pnode tmp=t;
        merge(t,t->l,t->r);
        free(tmp);
    }
    else if((t->val)>key)
    {
        remove(t->l,key);
    }
    else
    {
        remove(t->r,key);
    }
    updateSize(t);
}
int kth(pnode t,int k)
{
    if(t->ls+1==k)
        return t->val;
    else if(t->ls+1 < k)
        return kth(t->r, k-(t->ls+1));
    else
        return kth(t->l,k);
}
int sm(pnode t,int x)
{
    int lsize=0;
    if(t==NULL)
        return 0;
    if(x<= t->val)
        return sm(t->l,x);
    lsize=t->ls;
    return (lsize + 1 +sm(t->r,x));
}
void inorder(pnode t)
{
    if(t==NULL)
        return;
    inorder(t->l);
    cout<< "(" << t->val<<","<<t->p<<","<<t->s<<") ";
    inorder(t->r);
}
int main()
{
    int q;
    pnode T=NULL;
    cin>>q;
    while(q--)
    {
        int x;
        char c;
        cin>>c>>x;
        if(c=='I')
        {
            if(!search(T,x))
            {
                pnode t=new node;
                t->val=x;
                t->ls=0;
                t->rs=0;
                t->s=1;
                t->p=rand();
                t->l=t->r=NULL;
                insert(T,t);
            }
        }
        else if(c=='D')
        {
            if(search(T,x))
                remove(T,x);
        }
        else if(c=='K')
        {
            if(!T || (T->s <x))
                cout<<"invalid"<<endl;
            else
                cout<<kth(T,x)<<endl;
        }
        else
        {
            cout<<sm(T,x)<<endl;
        }
    }
    return 0;
}
