
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
        //intializing matrix with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost_ajacency[i][j]=0;
            }
        }
        int k=0;int temp=0;
        for(int i=0;i<n;i++)
        {       //here taking input from user and if user enter -1 you move to next vertex and user wants to connect to a specific vertex enter negative value of the node 
            // for example if your are entering cost of 1->5 and the next node connection is from 2->6 so you enter -6  and in the next iteration you will be entering values from 2->6
            // and 2-> further nodes
            // and if suppose 2 is only conmnected to 6 then enter -1 and this woill move your current pointerr to 3 ->6 and further on 
            for(int j=i+1;j<n;j++)
            {
                if(k<-1)
                {
                 j=Math.abs(k)-1;
                 temp=j;
                }
                else if(k==-1)
                {
                    j=temp;
                }
                System.out.println("Enter weight ffrom "+(i+1)+" Vertex to "+(j+1)+ " vertex");
                 k=sc.nextInt();
                if(k<0)
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
                dest[i]=j+1;
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
