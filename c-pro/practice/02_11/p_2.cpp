#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
using ll=long long;

struct Edge{
 ll to; ll cost; 
};

using Graph = std::vector<std::vector<Edge>>;

using Pair = std::pair<long long, int>;

void Dijkstra(const Graph& graph, vector<long long>& distances, int startIndex)
{
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty())
	{
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from] < distance)
		{
			continue;
		}

		// 現在の頂点からの各辺について
		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

int main(){
  ll n; cin>>n;
  
Graph graph(n);

for(int i=0;i<n-1;++i){
 ll a,b,x; cin>>a>>b>>x;
 x--;
 graph.at(i).push_back({x,b});

 graph.at(i).push_back({i+1,a});   
}

vector<long long> costfrom1(n, INF);

Dijkstra(graph,costfrom1,0);

cout<<costfrom1.at(n-1)<<endl;
}
