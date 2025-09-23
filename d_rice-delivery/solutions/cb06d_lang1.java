import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long[] S = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            S[i] = scanner.nextLong();
        }
        List<List<Pair>> G = new ArrayList<>((int) n + 1);
        for (int i = 0; i <= n; i++) {
            G.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            long u = scanner.nextLong();
            long v = scanner.nextLong();
            long w = scanner.nextLong();
            G.get((int) u).add(new Pair(v, w));
            G.get((int) v).add(new Pair(u, w));
        }
        long[] ans = {0};
        dfs(G, S, ans, 0, -1, k);
        System.out.println(ans[0]);
    }

    private static void dfs(List<List<Pair>> G, long[] S, long[] ans, long v, long p, long k) {
        for (Pair pair : G.get((int) v)) {
            long u = pair.node;
            long w = pair.weight;
            if (u != p) {
                dfs(G, S, ans, u, v, k);
                ans[0] += 2 * w * ((S[(int) u] + k - 1) / k);
                S[(int) v] += S[(int) u];
            }
        }
    }

    static class Pair {
        long node;
        long weight;

        Pair(long node, long weight) {
            this.node = node;
            this.weight = weight;
        }
    }
}

