public class Selection_Knapsack {
    int [] p1;
    int [] w1;
    public Selection_Knapsack( int p [], int w[] )
    {
        this.p1= p;
        this.w1=w;
    }
    public int [][] S_sort()
    {
        int k=(this.p1).length;
        for(int i=0;i<k;i++)
        {
            for(int j=i;j<k;j++)
            {
                if(w1[i]>w1[j])
                {
                    int temp=w1[i];
                    int temp2=p1[i];
                    w1[i]=w1[j];
                    p1[i]=p1[j];
                    w1[j]=temp;
                    p1[j]=temp2;
                }
            }
        }
        int [][] rtrn=new int[2][k];
        for (int i = 0; i < k; i++) {
            rtrn[0][i] = w1[i];
            rtrn[1][i] = p1[i];
        }
        return rtrn;
    }
    
}
