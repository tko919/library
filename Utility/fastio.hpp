#pragma once
#include <unistd.h>

class FastIO{
    static constexpr int L=1<<16;
    char rdbuf[L];
    int rdLeft=0,rdRight=0;
    inline void reload(){
        int len=rdRight-rdLeft;
        memmove(rdbuf,rdbuf+rdLeft,len);
        rdLeft=0,rdRight=len;
        rdRight+=fread(rdbuf+len,1,L-len,stdin);
    }
    inline bool skip(){
        for(;;){
            while(rdLeft!=rdRight and rdbuf[rdLeft]<=' ')rdLeft++;
            if(rdLeft==rdRight){
                reload();
                if(rdLeft==rdRight)return false;
            }
            else break;
        }
        return true;
    }
    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline bool _read(T& x){
        if(!skip())return false;
        if(rdLeft+20>=rdRight)reload();
        bool neg=false;
        if(rdbuf[rdLeft]=='-'){
            neg=true;
            rdLeft++;
        }
        x=0;
        while(rdbuf[rdLeft]>='0' and rdLeft<rdRight){
            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));
        }
        return true;
    }
    inline bool _read(__int128_t& x){
        if(!skip())return false;
        if(rdLeft+40>=rdRight)reload();
        bool neg=false;
        if(rdbuf[rdLeft]=='-'){
            neg=true;
            rdLeft++;
        }
        x=0;
        while(rdbuf[rdLeft]>='0' and rdLeft<rdRight){
            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));
        }
        return true;
    }
    inline bool _read(__uint128_t& x){
        if(!skip())return false;
        if(rdLeft+40>=rdRight)reload();
        x=0;
        while(rdbuf[rdLeft]>='0' and rdLeft<rdRight){
            x=x*10+(rdbuf[rdLeft++]^48);
        }
        return true;
    }
    template<typename T,enable_if_t<is_floating_point<T>::value,int> =0>inline bool _read(T& x){
        if(!skip())return false;
        if(rdLeft+20>=rdRight)reload();
        bool neg=false;
        if(rdbuf[rdLeft]=='-'){
            neg=true;
            rdLeft++;
        }
        x=0;
        while(rdbuf[rdLeft]>='0' and rdbuf[rdLeft]<='9' and rdLeft<rdRight){
            x=x*10+(rdbuf[rdLeft++]^48);
        }
        if(rdbuf[rdLeft]!='.')return true;
        rdLeft++;
        T base=.1;
        while(rdbuf[rdLeft]>='0' and rdbuf[rdLeft]<='9' and rdLeft<rdRight){
            x+=base*(rdbuf[rdLeft++]^48);
            base*=.1;
        }
        if(neg)x=-x;
        return true;
    }
    inline bool _read(char& x){
        if(!skip())return false;
        if(rdLeft+1>=rdRight)reload();
        x=rdbuf[rdLeft++];
        return true;
    }
    inline bool _read(string& x){
        if(!skip())return false;
        for(;;){
            int pos=rdLeft;
            while(pos<rdRight and rdbuf[pos]>' ')pos++;
            x.append(rdbuf+rdLeft,pos-rdLeft);
            if(rdLeft==pos)break;
            rdLeft=pos;
            if(rdLeft==rdRight)reload();
            else break;
        }
        return true;
    }
    template<typename T>inline bool _read(vector<T>& v){
        for(auto& x:v){
            if(!_read(x))return false;
        }
        return true;
    }

    char wtbuf[L],tmp[50];
    int wtRight=0;
    inline void flush(){
        fwrite(wtbuf,1,wtRight,stdout);
        wtRight=0;
    }
    inline void _write(const char& x){
        if(wtRight>L-32)flush();
        wtbuf[wtRight++]=x;
    }
    inline void _write(const string& x){
        for(auto& c:x)_write(c);
    }
    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline void _write(T x){
        if(wtRight>L-32)flush();
        if(x==0){
            _write('0');
            return;
        }
        else if(x<0){
            _write('-');
            if (__builtin_expect(x == std::numeric_limits<T>::min(), 0)) {
                switch (sizeof(x)) {
                case 2: _write("32768"); return;
                case 4: _write("2147483648"); return;
                case 8: _write("9223372036854775808"); return;
                }
            }
            x=-x;
        }
        int pos=0;
        while(x!=0){
            tmp[pos++]=char((x%10)|48);
            x/=10;
        }
        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];
        wtRight+=pos;
    }
    inline void _write(__int128_t x){
        if(wtRight>L-40)flush();
        if(x==0){
            _write('0');
            return;
        }
        else if(x<0){
            _write('-');
            x=-x;
        }
        int pos=0;
        while(x!=0){
            tmp[pos++]=char((x%10)|48);
            x/=10;
        }
        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];
        wtRight+=pos;
    }
    inline void _write(__uint128_t x){
        if(wtRight>L-40)flush();
        if(x==0){
            _write('0');
            return;
        }
        int pos=0;
        while(x!=0){
            tmp[pos++]=char((x%10)|48);
            x/=10;
        }
        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];
        wtRight+=pos;
    }
    template<typename T>inline void _write(const vector<T>& v){
        rep(i,0,v.size()){
            if(i)_write(' ');
            _write(v[i]);
        }
    }
public:
    FastIO(){}
    ~FastIO(){flush();}
    inline void read(){}
    template <typename Head, typename... Tail>inline void read(Head& head,Tail&... tail){
        assert(_read(head));
        read(tail...); 
    }
    template<bool ln=true,bool space=false>inline void write(){if(ln)_write('\n');}
    template <bool ln=true,bool space=false,typename Head, typename... Tail>inline void write(const Head& head,const Tail&... tail){
        if(space)_write(' ');
        _write(head);
        write<ln,true>(tail...); 
    }
};

/**
 * @brief Fast IO
 */