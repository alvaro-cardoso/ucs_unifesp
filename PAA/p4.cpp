    #include <bits/stdc++.h>
    using namespace std;
     
    typedef struct {
    int r;
    int s;
    } Cel;
     
    int max(int a, int b) {
       if(a>b){
          return a;
       } else {
          return b;
       }
    }
     
     
    int CBL(int N, int C, Cel v[])
    {
       int K[N+1][C+1];
        
       for (int i = 0; i <= N; i++)
       {
           for (int j = 0; j <= C; j++)
           {
               if (i==0 || j==0)
                   K[i][j] = 0;
                else if (v[i-1].s > j)
                     K[i][j] = K[i-1][j];
                else 
                     K[i][j] = max(v[i-1].r + K[i-1][j-v[i-1].s],  K[i-1][j]);
           }
       }
       return K[N][C];
    }
     
    int main() { 
        int N, C;
        cin >> N;
        cin >> C;
        Cel v[N];
        for(int i=0; i<N; i++){
            cin >> v[i].r >> v[i].s;
        }
        cout << CBL(N, C, v);
     
        return 0;
    }