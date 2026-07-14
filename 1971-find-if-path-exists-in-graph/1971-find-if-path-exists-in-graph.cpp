class Solution {
public:
    vector<int>p,r;

    int find(int i){
        if(p[i]==i) return i;
        return p[i]=find(p[i]);
    }

    void Union(int x, int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return;

        if(r[px]>r[py]){
            p[py]=px;
        }else if(r[px]<r[py]){
            p[px]=py;
        }else{
            p[py]=px;
            r[px]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        p.resize(n+1);
        r.resize(n+1,1);

        for(int i=0;i<n;i++){
            p[i]=i;
        }

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            Union(u,v);
        }

        return find(s)==find(d);
    }
};