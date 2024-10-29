
import java.util.Scanner;

public class MAtrix_chain {
    static int number;
    static int [][] order;
    static int [][] m;
    static int [][] s;
    static int [] d;


    public static void MatrixEntery()
    {
        Scanner sc=new Scanner(System.in);
      
        System.err.println("Enter number of matrix present ");
         MAtrix_chain.number=sc.nextInt();
         order = new int[number][2];
         m=new int[number][number];
         s=new int[number][number];
         
       
     // MAtrix order entery 
         for (int i=0;i<number;i++) {
             System.err.println("Enter dimensions for  mAtrix "+(i+1));
             order[i][0]=sc.nextInt();
             order[i][1]=sc.nextInt();
         }
         System.out.println("\n The matrix of order is as follows ");
         for (int i=0;i<number;i++) {
             System.err.println(order[i][0]+" X "+order[i][1]);
                 }

    CalculateD();
     CalculateMandS();           
    }

    public static void CalculateD()
    {
        // d calculation and view 
        d = new int[number + 1];
                
        for(int i=0;i<number;i++)
        {
            d[i]=order[i][0];
        }
        d[number]=order[number-1][1];
        System.out.print("\n The d values are : \n");
        int i1=0;
    for (Object elem : d) {
        System.err.println("d"+i1+" "+elem);
        i1++;
        
    }
    }

    public static void CalculateMandS()
    {
        int n=number;
        // calculation for m and s charts
        for (int i = 0; i < n; i++) {
            m[i][i] = 0;
        }
        
        // Calculate minimum cost for chains of increasing length
        for (int len = 2; len <= n; len++) {  // len is the chain length
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                m[i][j] = Integer.MAX_VALUE;  // Initialize to a large value
                
                for (int k = i; k < j; k++) {
                   
                    int temp = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                    
                    
                    if (temp < m[i][j]) {
                        m[i][j] = temp;
                        s[i][j] = k;  
                    }
                }
            }
        }
    }
    
    public static void main(String[] args) {
      
        MatrixEntery();

    
       
     
for (int i = 0; i < m.length; i++) {
    for (int j = 0; j < m[i].length; j++) {
        System.err.print(m[i][j] + "    ");
    }
    System.err.println("");
}
System.err.println("\n *************** \n");
for (int i = 0; i < m.length; i++) {
    for (int j = 0; j < m[i].length; j++) {
        System.err.print(s[i][j] + " ");
    }
    System.err.println("");
}

    }
}
