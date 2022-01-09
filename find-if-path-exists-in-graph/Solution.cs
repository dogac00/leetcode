
// LeetCode: https://leetcode.com/problems/find-if-path-exists-in-graph

public class Solution
{
    public bool ValidPath(int n, int[][] edges, int start, int end)
    {
        if (n == 1 || edges.Length == 1)
            return true;
        var graph = new Dictionary<int, List<int>>();
        foreach (var edge in edges)
        {
            graph[edge[0]] = new List<int>();
            graph[edge[1]] = new List<int>();
        }
        foreach (var edge in edges)
        {
            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        return DFS(graph, start, end);
    }

    private static bool DFS(Dictionary<int, List<int>> graph,
        int start,
        int end)
    {
        var visited = new HashSet<int>();
        return DFS(graph, visited, start, end);
    }

    private static bool DFS(Dictionary<int, List<int>> graph,
        HashSet<int> visited,
        int start,
        int end)
    {
        if (!graph.ContainsKey(start))
            return false;
        if (visited.Contains(start))
            return false;
        var neighbors = graph[start];
        if (neighbors.Contains(end))
            return true;
        visited.Add(start);
        return neighbors
            .Any(n => DFS(graph, visited, n, end));
    }
}
