class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int, double>>> graph(n);
    //copied
    
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];
        
        graph[u].emplace_back(v, prob);
        graph[v].emplace_back(u, prob);
    }
    
    // Priority queue for the maximum probability path
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start_node});
    
    // Distance/probability array initialized to 0
    vector<double> prob(n, 0.0);
    prob[start_node] = 1.0;
    
    while (!pq.empty()) {
        auto [curr_prob, node] = pq.top();
        pq.pop();
        
        // If we reach the end node, return the probability
        if (node == end_node) {
            return curr_prob;
        }
        
        for (const auto& [neighbor, edge_prob] : graph[node]) {
            double new_prob = curr_prob * edge_prob;
            if (new_prob > prob[neighbor]) {
                prob[neighbor] = new_prob;
                pq.push({new_prob, neighbor});
            }
        }
    }
    
    return 0.0;
}
};