#pragma once

template<int L=1010101>vector<int> sieve(int N){
    bitset<L> isp;
    int n,sq=ceil(sqrt(N));
    for(int z=1;z<=5;z+=4){
        for(int y=z;y<=sq;y+=6){
            for(int x=1;x<=sq and (n=4*x*x+y*y)<=N;++x){
                isp[n].flip();
            }
            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){
                isp[n].flip();
            }
        }
    }
    for(int z=2;z<=4;z+=2){
        for(int y=z;y<=sq;y+=6){
            for (int x=1;x<=sq and (n=3*x*x+y*y)<=N;x+=2){
                isp[n].flip();
            }
            for(int x=y+1;x<=sq and (n=3*x*x-y*y)<=N;x+=2){
                isp[n].flip();
            }
        }
    }
    for(int y=3;y<=sq;y+=6){
        for(int z=1;z<=2;++z){
            for(int x=z;x<=sq and (n=4*x*x+y*y)<=N;x+=3){
                isp[n].flip();
            }
        }
    }
    for(int n=5;n<=sq;++n)if(isp[n]){
        for(int k=n*n;k<=N;k+=n*n){
            isp[k]=false;
        }
    }
    isp[2]=isp[3]=true;

    vector<int> ret;
    for(int i=2;i<=N;i++)if(isp[i]){
        ret.push_back(i);
    }
    return ret;
}

/**
 * @brief Prime Sieve
 */