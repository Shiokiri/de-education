public class GcdAndLcm {
    int n, m;
    GcdAndLcm(int n, int m)
    {
        this.n = n;
        this.m = m;
    }
    int gcd(int a, int b) {
        if(b != 0) return gcd(b, a%b);
        else return a;
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    void printGcd() {
        System.out.printf("GCD=%d\n", gcd(n, m));
    }
    void printLcm() {
        System.out.printf("LCM=%d\n", lcm(n, m));
    }
}
