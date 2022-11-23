public class PrimeNumber {

    private int n, cnt, prime[];
    private boolean vis[];
    PrimeNumber(int n) {
        this.n = n;
        vis = new boolean[n+5];
        prime = new int[n+5];
    }
    public void calcPrimeNumber() {
        for(int i = 2; i <= n; i++) {
            if(!vis[i]) {
                prime[++cnt] = i;
                for(int j = 1; i * j <= n; j++) {
                    vis[i * j] = true;
                }
            }
        }
    }
    public void printPrimeNumber() {
        for(int i = 1; i <= cnt; i++) {
            System.out.printf("%d ", prime[i]);
        }
        System.out.println();
    }

}
