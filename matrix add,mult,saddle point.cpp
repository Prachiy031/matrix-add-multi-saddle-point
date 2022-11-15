
/******************************************************************************
o/p:
Enter your choice 3
Enter array elements a : 
10 5 8
3 4 5
5 2 3
5 is saddle point at position 0 1 
*******************************************************************************/

#include <stdio.h>

int main()
{
    int a[3][3],b[3][3],c[3][3],d[3][3],s[2][2],min,max,i,j,k;  //a,b taken as input array c:sum,d:multiplication
    int *p,*q;                                                // s for storing saddle point index
    int num;    //for choice
    p = &a[0][0];
    q = &b[0][0];
    
    int cho;
   do{
       printf("\nEnter your choice ");
    scanf("%d",&num);
    printf("Enter array elements a : \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",(p+(i*3)+j));
        }
    }
    switch(num)
    {
       case 1:               // for sum case
  
    printf("Enter array elements b : \n"); 
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",(q+(i*3)+j));
        }
    }
    
      printf("\nSum of arrays is : \n");
       for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j] = *(p+(i*3)+j) + *(q+(i*3)+j);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    break;
   
    case 2:
     
    printf("\nMultiplication of arrays is :\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            d[i][j] =0;
            for(int k=0;k<3;k++)
            {
                d[i][j] = d[i][j] + *(p+(i*3)+k) * *(q+(k*3)+j);
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
    break;
    
    case 3:                    //for saddle point case
    for(i=0;i<2;i++)
    {
        min = a[i][0];              //min is always considered as 1st element of array
        for(j=0;j<2;j++)
        {
            if(min >=a[i][0])
            {
                min = a[i][j];
                s[0][0] =i;
                s[0][1] = j;
            }
        }
        j = s[0][1];                //scanning for column
        max = a[0][j];              // max is considered as 1st element of respective colm
        for(k=0;k<3;k++)
        {
            if(max<=a[k][j])
            {
                max = a[k][j];
                s[1][0] = k;
                s[1][1] = j;
            }
        }
        if(min == max)
        {
            if(s[0][0] == s[1][0] && s[0][1]== s[1][1]) //for sake of same element is present in coloumn
            {
                printf("\n%d is saddle point at position %d %d ",a[i][j],i,j);
            }
        }
         
    }
        break;
       
    } 
    printf("Do you want to continue?\n");
    scanf("%d",&cho);
   }while(cho==1);
    
    return 0;
}
