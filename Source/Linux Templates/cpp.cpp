#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

inline int gi()
{
    char ch; int ret = 0,f = 1;
    do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
    if (ch == '-') f = -1,ch = getchar();
    do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
    return ret*f;
}

int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    fclose(stdin); fclose(stdout);
    return 0;
}
