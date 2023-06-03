vector<ll> dist(n, -inf);
dist[0] = 0;
for (int t=0;t<n;t++){
	for (int i=0;i<m;i++){
		auto [a,b,w] = edges[i];
		if (dist[a] != -inf)
			dist[b] = max(dist[b], dist[a]+w);
	}
}
vector<bool> neg(n,false);
for (int t=0;t<n;t++){
	for (int i=0;i<m;i++){
		auto [a,b,w] = edges[i];
		if (dist[a] != -inf && dist[b] < dist[a]+w) {
			neg[a] = true;
		}
		neg[b] = neg[b] || neg[a];
	}
}