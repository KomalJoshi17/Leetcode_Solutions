#include <vector>

using namespace std;

class Solution {
public:
    vector<int>p, r;
    int find(int i){
        if(p[i]==i) return i;
        return p[i]=find(p[i]); 
    }

    bool Union(int x, int y){
        int px=find(x);
        int py=find(y);
        
        if(px==py) return false;

        if(r[px]>r[py]){
            p[py]=px;
        }else if(r[px]<r[py]){
            p[px]=py;
        }else{
            p[py]=px;
            r[px]++;
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        p.resize(n);
        r.resize(n,1);
        for(int i=0;i<n;i++){
            p[i]=i;
        }

        // int ans=n;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             if(Union(i,j)){
        //                 ans--;
        //             }
        //         }
        //     }
        // }
        // return ans;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    if(Union(i,j)){
                    }
                }
            }
        }
        
        unordered_set<int> leaders;
        for(int i=0;i<n;i++){
            leaders.insert(find(i)); 
        }
        return leaders.size();
    }
};
