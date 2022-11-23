public class NarcissisticNumber {
    private int n, ans[], cnt, x[], p;
    NarcissisticNumber() {
        ans = new int[10];
        x = new int [10];
    }
    public void calcNarcissisticNumber() {
        for(int i = 100; i <= 999; i++)
        {
            int a = i; p = 0;
            while(a != 0) {
                x[++p] = a % 10;
                a /= 10;
            }
            if(x[1]*x[1]*x[1] + x[2]*x[2]*x[2] + x[3]*x[3]*x[3] == i) {
                ans[++cnt] = i;
            }
        }
    }
    public void printNarcissisticNumber() {
        for(int i = 1; i <= cnt; i++) {
            System.out.printf("%d ", ans[i]);
        }
        System.out.println();
    }
}
