public class Pay {
    private double price;
    private double withhold_rate;
    private double pay_rate;
    private double payment;
    public Pay(double p)
    {
        price=p;
    }
    public void computePayment(int hour,double withhold_rate,double pay_rate)
    {
        payment=hour*price*(1-withhold_rate)*(1-pay_rate);
        System.out.println("payment:"+payment);
    }
    public void computePayment(int hour,double pay_rate)
    {
        payment=hour*price*(1-0.15)*(1-pay_rate);
        System.out.println("payment:"+payment);
    }
    public void computePayment(int hour)
    {
        payment=hour*price*(1-0.15)*(1-0.0465);
        System.out.println("payment:"+payment);
    }
}
