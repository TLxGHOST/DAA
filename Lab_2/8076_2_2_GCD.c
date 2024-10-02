// Aim  of  the  program:  Write  a  program  in  C  to  find  GCD  of  two  numbers  using  recursion. 
// Read all pair of numbers from a file and store the result in a separate file.  
//  Note#  Source  file  name  and  destination  file  name  taken  from  command  line  arguments.  The 
// source file must contain at least 20 pairs of numbers.  
// Give the contents of the input disc file “inGcd.dat” 

#include<stdio.h>
#include<stdlib.h>
int gcd_076(int a_076,int b_076)
{
    // while(a_076!=b_076)
    // {
    //     if(a_076>b_076)
    //        a_076-=b_076;
    //     else
    //        b_076-=a_076;
    // }
    // return a_076;
    if(b_076==0)
    {
        return a_076;
    }
    return gcd_076(b_076,a_076%b_076);
}
int main(int argc , char *s[])
{
    FILE *fp=fopen(s[2],"r");
    FILE *fp1=fopen(s[3],"w");
    int n_076=atoi(s[1]);
    // fscanf(fp,"%d",&n_076);
    int a_076[n_076],b_076[n_076];
    for(int i=0;i<n_076;i++)
    {
        fscanf(fp,"%d %d",&a_076[i],&b_076[i]);
    }
    for(int i=0;i<n_076;i++)
    {
        fprintf(fp1,"GCD of %d and %d is : %d\n",a_076[i],b_076[i],gcd_076(a_076[i],b_076[i]));
    }
   
    return 0;
}