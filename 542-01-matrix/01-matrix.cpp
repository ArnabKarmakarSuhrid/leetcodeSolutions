class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(m,vector<int>(n,-1));

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n;c++){

                if(mat[r][c] == 0){
                    dist[r][c] =0;

                    q.push({r,c});
                }
            }
        }
    

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!q.empty()){

        auto[r,c] = q.front();
        q.pop();


        for(int i = 0; i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= m || nc < 0 || nc>= n)
            continue;

            if(dist[nr][nc] != -1)
            continue;

            dist[nr][nc] = dist[r][c] + 1;

            q.push({nr, nc});
        }
    }
      return dist;
     }

    };