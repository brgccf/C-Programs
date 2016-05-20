//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12160 - Unlock the Lock
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10000

int st, nd, n, d[maxN], a[11];

int main() {
	int caseNo = 0;
	while (scanf("%d %d %d", &st, &nd, &n) && (st | nd | n)) {
	    rep(i, n) scanf("%d", &a[i]);
	    rep(i, maxN) d[i] = INF;
	    d[st] = 0;
	    queue<int> q;
	    q.push(st);
	    while (!q.empty()) {
	        int u = q.front(); q.pop();
	        if (d[nd] != INF) break;
	        rep(i, n) {
	            int v = (u + a[i]) % 10000;
	            if (d[v] == INF) {
	                d[v] = d[u] + 1;
	                q.push(v);
	            }
	        }
	    }
	    printf("Case %d: ", ++caseNo);
	    if (d[nd] == INF) puts("Permanently Locked");
	    else printf("%d\n", d[nd]);
	}
	return 0;
}


// #include "bits/stdc++.h"

// int main(int argc, char const *argv[])
// {
// 	int L, U, R;
// 	while(1)
// 	{
// 		scanf("%d%d%d", &L, &U, &R);
// 		if(!(L&R&U)) break;
// 		int vec[R];
// 		for(int i = 0; i < R; i++)
// 		{
// 			scanf("%d", &vec[i]);
// 		}
// 		bool possible = true;
// 		//fazendo para cada chave
// 		for (int i = 0; i < R; ++i)
// 		{
// 			if(!possible) break;
// 			int bit1 = U&1;
// 			int bit2 = U&2;
// 			int bit3 = U&4;
// 			int bit4 = U&8;
// 			if(vec[i]&bit1==0)
// 			{
// 				possible = false;
// 			}

// 		}
// 	}
// 	return 0;
// }