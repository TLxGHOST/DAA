import java.util.Scanner;

public class Knapsack

{
    static int[] Profit;
    static int[] weight;
    static int Knapsacak_capacity;
    static int[][] chart;
    int item;

    public Knapsack(int items, int capacity) {
        this.chart = new int[items + 1][capacity + 1];
        Knapsack.Profit = new int[items + 1];
        Knapsack.weight = new int[items + 1];
        Knapsacak_capacity = capacity;
        this.item=items;
    }

    public void fill_Knapsack() {
        Scanner sc = new Scanner(System.in);
        Profit[0] = 0;
        weight[0] = 0;
        for (int i = 1; i < weight.length; i++) {
            System.out.println("Enter Profit and weight for item " + i);
            Profit[i] = sc.nextInt();
            weight[i] = sc.nextInt();
        }

        System.out.print("Profit: ");
        for (int i = 0; i < weight.length; i++) {
            System.out.print(Profit[i] + " ");
        }
        System.out.print("\n Weight: ");
        for (int i = 0; i < weight.length; i++) {
            System.out.print(weight[i] + " ");

        }

    }

    @SuppressWarnings("static-access")
    public void Chart()
    {
        Selection_Knapsack ob=new Selection_Knapsack(Profit, weight);
        int [][]k;
        k=ob.S_sort();
        System.out.println();
        for(int i = 0; i < k.length; i++) {
            for(int j=0;j<k[0].length;j++)
            {
                if(i==0 && j==0)
                {
                    System.err.print("Weight :");
                }
                else if(i==1&& j==0)
                {
                    System.err.print("Profit :");
                }
                System.out.print(" "+k[i][j]);
            }
            System.out.println();
        }
        //Upto sorting the data structure done
        //The final calculation part


        for(int i=0;i<this.item;i++)
        {
            for(int j=0;j<this.Knapsacak_capacity;j++)
            {
                if(j==0 || i==0)
                {
                    chart[i][j]=0;
                }
                else if(k[0][i]<=j)
                {
                    double temp=(double)chart[i-1][j];
                    double temp2 = (j >= k[0][i]) ? (double)k[1][i] + chart[i-1][j-k[0][i]] : 0;
                    chart[i][j]=(int)Math.max(temp,temp2);
                }
                else
                {
                    chart[i][j]=chart[i-1][j];
                }
            }
        }
        //

        // Printing the chart

        for (int i = 0; i < chart.length; i++) {
            for (int j = 0; j < chart[i].length; j++) {
                System.err.print(" " + chart[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        System.out.printf("Enter how many items are there \n");
        int n = s1.nextInt();
        System.out.printf("Enter Size of the Knapsack\n");
        int l = s1.nextInt();
        Knapsack k = new Knapsack(n, l);
        k.fill_Knapsack();
        k.Chart();
    }

}