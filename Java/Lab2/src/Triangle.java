public class Triangle {
    private double sideA;
    private double sideB;
    private double sideC;
    private double Area;
    private double Perimeter;
    private  boolean Judge;
    Triangle(double sideA,double sideB,double sideC) {
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
        Judge_Triangle();
        if(Judge == false) {
            System.out.println("error!");
            this.sideA = 0;
            this.sideB = 0;
            this.sideC = 0;
        }
        else {
            System.out.println("created!");
            ComputePerimeter();
            ComputeArea();
        }
    }
    public void Judge_Triangle()
    {
        boolean a,b,c;
        a=(sideA+sideB>sideC);
        b=(sideA+sideC>sideB);
        c=(sideB+sideC>sideA);
        if(a&&b&&c)
            Judge=true;
        else
            Judge=false;
    }
    public double getArea() {
        return Area;
    }
    public double getPerimeter() {
        return Perimeter;
    }
    public void setSideA(double sideA) {
        double a = this.sideA;
        this.sideA = sideA;
        Judge_Triangle();
        if(Judge == false) {
            System.out.println("error to change sideA!");
            sideA = a;
        }
        else {
            System.out.println("succeed to change sideA!");
        }

    }
    public void setSideB(double sideB) {
        double b = this.sideB;
        this.sideB = sideB;
        Judge_Triangle();
        if(Judge == false) {
            System.out.println("error to change sideB!");
            sideB = b;
        }
        else {
            System.out.println("succeed to change sideB!");
        }
    }
    public void setSideC(double sideC) {
        double c = this.sideC;
        this.sideC = sideC;
        Judge_Triangle();
        if(Judge == false) {
            System.out.println("error to change sideC!");
            sideC = c;
        }
        else {
            System.out.println("succeed to change sideC!");
        }
    }
    public double ComputeArea() {
        double p = getPerimeter()/2;
        Area = Math.sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
        return Area;
    }
    public double ComputePerimeter() {
        Perimeter = sideA + sideB + sideC;
        return Perimeter;
    }

}
