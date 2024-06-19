import java.util.*;

public class BFS_graphs {
  public ArrayList<Integer> BfsTraversal(int v, ArrayList<ArrayList<Integer>> adj) {
    boolean[] visited = new boolean[v];
    ArrayList<Integer> bfs = new ArrayList<>();
    Queue<Integer> q = new LinkedList<>();

    q.add(0);
    visited[0] = true;

    while (!q.isEmpty()) {
      int node = q.poll();
      bfs.add(node);

      for (Integer it : adj.get(node)) {
        if (!visited[it]) {
          visited[it] = true;
          q.add(it);
        }
      }
    }
    return bfs;
  }
}