    #include <iostream>
    #include <set>
    #include <queue>
    #include <climits>
    using namespace std;
     
    int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
     
     
    bool isValid(int x, int y, int N) {
        return (x >= 0 && x < N) && (y >= 0 && y < N);
    }
     
    struct Node
    {
        int x, y, dist;
        Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
     
        bool operator<(const Node& o) const {
            return x < o.x || (x == o.x && y < o.y);
        }
    };
     
    int findShortestDistance(int N, Node src, Node dest)
    {
        set<Node> visited;
     
        queue<Node> q;
        q.push(src);
     
        while (!q.empty())
        {
            Node node = q.front();
            q.pop();
     
            int x = node.x;
            int y = node.y;
            int dist = node.dist;
     
            if (x == dest.x && y == dest.y) {
                return dist;
            }
     
            if (!visited.count(node))
            {
                visited.insert(node);
     
                for (int i = 0; i < 8; i++)
                {
     
                    int x1 = x + row[i];
                    int y1 = y + col[i];
     
                    if (isValid(x1, y1, N)) {
                        q.push({x1, y1, dist + 1});
                    }
                }
            }
        }
     
        return INT_MAX;
    }
     
    int main()
    {
        int N = 8;
        int K, P, sum = 0;
        cin >> P;
        int *arr = new int(P);
        for (int i = 0; i < P; i++){
            cin >> arr[i];
        }
        cin >> K;
        
        Node src = {K/8, K%8-1};
     
        Node dest = {arr[0]/8, arr[0]%8-1};
        
        int c = findShortestDistance(N, src, dest);
        for (int i = 0; i < P; i++){
            if(arr[i]>=57 && findShortestDistance(N, src, {arr[i]/8, arr[i]%8-1}) > 1){
            cout << "impossible";
            return 0;}
        }
        cout << c;
     
        return 0;
    }