
import java.util.*;
public class multistage
{
    static int vertex;
    static int stages;
    int d[];
    int cost[];
    Scanner sc=new Scanner(System.in);
    int [][] cost_ajacency;

    public multistage(int vertex) {
        this.vertex = vertex;
        cost_ajacency = new int[vertex][vertex];
        d=new int[this.vertex];
        cost=new int[this.vertex];
    }
    public void input_matrix(int n)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost_ajacency[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {   
            for(int j=i+1;j<n;j++)
            {
                System.out.println("Enter weight ffrom "+(i+1)+" Vertex to "+(j+1)+ " vertex");
                int k=sc.nextInt();
                if(k==-1)
                {
                    break;
                }
                else
                cost_ajacency[i][j]=k;
            }
        }
    }
  public void print_cost_matrix(int k[][])
  {
    
    for(int i=0;i<k.length;i++)
    {
        for(int j=0;j<k[0].length;j++)
        {
            System.out.print(cost_ajacency[i][j]);
            
        }
        System.out.println();
    }
  }
  public void calculations(int mtrx[][],int cost[],int dest[])
  {
    int n=cost.length;
    dest[n-1]=n;
    cost[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        int min=999;
        for(int j=i+1;j<n;j++)
        {
            if(mtrx[i][j]!=0 && mtrx[i][j]+cost[j]<min)
            {
                min=mtrx[i][j]+cost[j];
                dest[i]=j;
            }
        }
        cost[i]=min;
    }
}
  public static void main(String args[])
  {Scanner sc=new Scanner(System.in);
    System.out.println("ENter number of verticies you want ");
    vertex=sc.nextInt();
    multistage obj=new multistage(vertex);
    obj.input_matrix(vertex);
    obj.print_cost_matrix(obj.cost_ajacency);
    obj.calculations(obj.cost_ajacency,obj.cost,obj.d);
    System.out.print("Cost:-  ");
    
    for (int elem : obj.cost) {
        System.out.print(elem+" ");
        
    }
    System.out.print(" \n D :-  ");
    for (int elem : obj.d) {
        System.out.print(elem+" ");
        
    }
   
  }
}
