import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        int n, m;
        Scanner scanner = new Scanner(System.in);
        // Lab1.1
        System.out.println("Lab1.1");
        n = scanner.nextInt();
        PrimeNumber primeNumber = new PrimeNumber(n);
        primeNumber.calcPrimeNumber();
        primeNumber.printPrimeNumber();
        // Lab1.2
        System.out.println("Lab1.2");
        NarcissisticNumber narcissisticNumber = new NarcissisticNumber();
        narcissisticNumber.calcNarcissisticNumber();
        narcissisticNumber.printNarcissisticNumber();
        // Lab1.3
        System.out.println("Lab1.3");
        n = scanner.nextInt();
        PerfectNumber perfectNumber = new PerfectNumber(n);
        perfectNumber.calcPerfectNumber();
        perfectNumber.printPerfectNumber();
        // Lab1.4
        System.out.println("Lab1.4");
        n = scanner.nextInt();
        m = scanner.nextInt();
        GcdAndLcm gcdAndLcm = new GcdAndLcm(n, m);
        gcdAndLcm.printGcd();
        gcdAndLcm.printLcm();
        // Lab1.5
        System.out.println("Lab1.5");
        Matrix A = new Matrix();
        Matrix B = new Matrix();
        A.setMatrix();
        B.setMatrix();
        Matrix C = A.multiply(B);
        C.printMatrix();
    }
}
