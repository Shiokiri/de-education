public class PerfectNumber {

    private int n, ans[], cnt;
    PerfectNumber(int n) {
        this.n = n;
        this.ans = new int [10];
    }
    //求完数；完数的定义：一个数恰好等于它的所有因子之和
    public void calcPerfectNumber() {
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = 1; j <= i/2; j++) {
                if(i % j == 0) {
                    sum += j;
                }
            }
            if(sum == i) {
                ans[++cnt] = i;
            }
        }
    }
    public void printPerfectNumber() {
        for(int i = 1; i <= cnt; i++) {
            System.out.printf("%d ", ans[i]);
        }
        System.out.println();
    }
}
