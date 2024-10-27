
import java.util.Arrays;
import java.util.Scanner;

public class Knapsack {
    static int m;
    static int [] profit;
    static int [] weight;
    static int [][] chart;
    // static Knapsack k;
    // public Knapsack() {
        
    // }
    static void fill_items()
    {
        System.err.println("Enter how many items you have");
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
         profit = new int[m];
         weight= new int[m];
        System.err.println("Enter profit and weight of each item");
        for(int i=0;i<m;i++)
        {
            profit[i] = sc.nextInt();
            weight[i] = sc.nextInt();
        }
    }

    static void print_KnapSack()
    {
        for(int i=0;i<m;i++)
        {
            System.out.println("Profit: "+profit[i]+" Weight: "+weight[i]);
        }
    }
   
    static void Knapsack_chart()
    {
        int k = Arrays.stream(weight).max().getAsInt(); 
    }
    

    public static void main(String[] args) {
        fill_items();
        print_KnapSack();
    }
    
}
