import java.util.*;

class StoneGameII {
    int n;
    int[][][] dp;
    public int solve(int player, int idx, int M, int[] piles) {
        if (idx >= n) return 0;
        if (dp[player][idx][M] != -1) return dp[player][idx][M];
        int result = (player == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;
        for (int X = 1; X <= Math.min(2 * M, n - idx); X++) {
            stones += piles[idx + X - 1];
            if (player == 1) {
                result = Math.max(result, stones + solve(0, idx + X, Math.max(M, X), piles));
            }
            else {
                result = Math.min(result, solve(1, idx + X, Math.max(M, X), piles));
            }
        }
        return dp[player][idx][M] = result;
    }
    public int stoneGameII(int[] piles) {
        dp = new int[2][101][101];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 101; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        n = piles.length;
        return solve(1, 0, 1, piles);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[] piles = new int[m];
        for (int i = 0; i < m; i++) {
            piles[i] = sc.nextInt();
        }
        StoneGameII obj = new StoneGameII();
        int answer = obj.stoneGameII(piles);
        System.out.println(answer);

    }
}

