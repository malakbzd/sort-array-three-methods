#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion(int t[4])
{
    int i,j,x,c=0,s=0;
    for(i=0 ; i<4 ; i++)
    {
        x=t[i];
        j=i;
        while(j>0 && t[j-1]>x)
        {
            t[j]=t[j-1];
            j--;
        }
        t[j]=x;
    }
}

int partition(int t[4] , int d , int f)
{
    int i,j,p,x;
    p=t[d];
    i=d+1;
    for(j=d+1 ; j<4 ; j++)
    {
        if(t[j]<=p)
        {
            x=t[i];
            t[i]=t[j];
            t[j]=x;
            i++;
        }
    }
    x=t[i-1];
    t[i-1]=t[d];
    t[d]=x;
    return i-1;
}

void part_r(int t[4] , int d , int f)
{
    int ip;
    if(d<f)
    {
        ip=partition(t,d,f);
        part_r(t,d,ip-1);
        part_r(t,ip+1,f);
    }
}


 void fusion(int t[4] , int d , int f)
 {
    int i,j,k=0,a[f-d+1];
    int m=(d+f)/2;
    i=d;
    j=m+1;

     while(i<=m && j<=f)
     {
        if(t[i]<t[j])
        {
            a[k]=t[i];
            k++;
            i++;
        }
        else
        {
            a[k]=t[j];
            k++;
            j++;
        }
     }

     while(i<=m)
     {
        a[k]=t[i];
            k++;
            i++;
     }

     while(j<=f)
     {
        a[k]=t[j];
            k++;
            j++;
     }

     for(i=0 ; i<(f-d+1); i++)
     {
        t[d+1]=a[i];
     }
 }

  void fus_tre (int t[4] , int d , int f)
  {
    int m=(d+f)/2;
    if(d<f)
    {
fus_tre(t,d,m);
fus_tre(t,m+1,f);
fusion(t,d,f);
    }
  }

void display(int t[4])
{
    printf("\n");
    for(int i=0 ; i<4 ; i++)
    {
        printf("%d\t",t[i]);
    }
}

int main()
{
    int x,i,j,t[4] , a[20],m;

    for(i=0 ; i<4 ; i++)
    {
        printf("enter int");
        scanf("%d",&t[i]);
    }

    insertion(t);
    display(t);
    part_r(t,0,4);
    display(t);
    fus_tre(t,0,4);
    display(t);
}
