#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

template<typename T>struct LCT{
   struct Node{
      Node *lp=nullptr,*rp=nullptr,*par=nullptr;
      T val,sum,dat; int idx,sz=1; bool rev=0;
      Node(){}
      Node(int idx,T val):idx(idx),val(val),sum(val){}
      void eval(){
         if(rev){
            if(lp)swap(lp->lp,lp->rp),lp->sum.inv(),lp->rev^=1;
            if(rp)swap(rp->lp,rp->rp),rp->sum.inv(),rp->rev^=1;
            rev=0;
         }
      }
      void update(){
         sz=1; if(lp)sz+=lp->sz; if(rp)sz+=rp->sz;
         sum=val+dat; if(lp)sum+=lp->sum; if(rp)sum+=rp->sum;
      }
      bool is_root(){
         return !par||(par->lp!=this&&par->rp!=this);
      }
      void rotate(){
         Node *pp,*p,*c;
         p=par,pp=p->par;
         if(p->lp==this){c=rp; rp=p; p->lp=c;}
         else{c=lp; lp=p; p->rp=c;}
         if(pp){
            if(pp->lp==p)pp->lp=this;
            if(pp->rp==p)pp->rp=this;
         }
         par=pp; p->par=this; if(c)c->par=p;
         p->update(); update();
      }
      void splay(){
         eval();
         while(!is_root()){
            Node *q=par;
            if(q->is_root()){
               q->eval(); eval();
               if(q->lp==this)rotate();
               else rotate();
            }else{
               Node *r=q->par;
               r->eval(); q->eval(); eval();
               if(r->lp==q){
                  if(q->lp==this){q->rotate(); rotate();}
                  else{rotate(); rotate();}
               }else{
                  if(q->rp==this){q->rotate(); rotate();}
                  else{rotate(); rotate();}
               }
            }
         }
      }
   };
   LCT(){}
   Node *make(int idx,T val){return new Node(idx,val);}
   Node *expose(Node *v){
      Node *pre=nullptr;
      for(Node *cur=v;cur;cur=cur->par){
         cur->splay();
         //if(cur->rp)cur->dat+=cur->rp->sum; //Subtree
         cur->rp=pre;
         //if(cur->rp)cur->dat-=cur->rp->sum; //Subtree
         cur->update(); pre=cur;
      } v->splay(); return pre;
   }
   void link(Node *c,Node *p){
      expose(c); expose(p); c->par=p; p->rp=c; p->update();
   }
   void cut(Node *c){
      expose(c); c->lp->par=nullptr; c->lp=nullptr; c->update();
   }
   void evert(Node *v){expose(v); swap(v->lp,v->rp); v->sum.inv();v->rev^=1; v->eval();}
   Node *lca(Node *u,Node *v){expose(u); return expose(v);}
   Node *root(Node *v){expose(v); while(v->lp)v->eval(),v=v->lp; return v;}
   void set(Node *v,T t){expose(v); v->val=t; v->update();}
   T &query(Node *v){expose(v); return v->sum;}
};
struct X{
   ll v=0;
   X(){}
   X(ll v):v(v){}
   void inv(){}
   X operator+(const X& x){return X(v+x.v);}
   X& operator+=(const X& x){v+=x.v;}
   X& operator-=(const X& x){v-=x.v;}
}; using V=LCT<X>::Node*;
//verified:https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum

int main(){
   int n,q; scanf("%d%d",&n,&q);
   LCT<X> tree; vector<V> vs(n); vector<ll> v(n);
   rep(i,0,n){
      scanf("%lld",&v[i]);
      vs[i]=tree.make(i,v[i]);
   }
   rep(i,0,n-1){
      int x,y; scanf("%d%d",&x,&y);
      tree.evert(vs[x]);
      tree.link(vs[x],vs[y]);
   }
   rep(i,0,q){
      int t; scanf("%d",&t);
      if(t==0){
         int x,y; scanf("%d%d",&x,&y);
         tree.evert(vs[x]); tree.cut(vs[y]);
         scanf("%d%d",&x,&y);
         tree.evert(vs[x]); tree.link(vs[x],vs[y]);
      }
      if(t==1){
         int p,x; scanf("%d%d",&p,&x);
         v[p]+=x; tree.set(vs[p],v[p]);
      }
      if(t==2){
         int x,y; scanf("%d%d",&x,&y);
         tree.evert(vs[x]); tree.expose(vs[y]);
         printf("%lld\n",vs[y]->sum.v);
      }
   }
   return 0;
}
