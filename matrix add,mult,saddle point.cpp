/******************************************************************************
o/p:
Enter your choice:
1.Addition 2.Multiplication 3.Saddle point
1
Enter matrix elements for a:
1 2 3
4 5 6
1 9 0
Enter matrix elements for b:
3 0 9
5 0 4
2 7 3

sum of matrix:
4 2 12 
9 5 10 
3 16 3 
Do you want to continue?
1
Enter your choice:
1.Addition 2.Multiplication 3.Saddle point
2
Enter matrix elements for a:
4 5 7
2 3 4
9 0 8

Multiplication of matrix :
51 49 77 
29 28 42 
43 56 105 
Do you want to continue?
1
Enter your choice:
1.Addition 2.Multiplication 3.Saddle point
3
Enter matrix elements for a:
10 5 7
3 4 7
5 8 0
No saddle point
Do you want to continue?
0

      

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],s[2][2],i,j,k,min,max;
    int *p,*q;
    int num;
    p = &a[0][0];
    q = &b[0][0];
    int ch;
    int flag =0;
    do
    {
        printf("Enter your choice:\n");
        printf("1.Addition 2.Multiplication 3.Saddle point\n"); //a,b taken as input array c:sum,d:multiplication
        scanf("%d",&num);                                    // s for storing saddle point index
        printf("Enter matrix elements for a:\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",(p+(i*3)+j));  //p:base address
            }
        }
        
        switch(num)
        {
            case 1:    // for sum case
            {
                printf("Enter matrix elements for b:\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                       scanf("%d",(q+(i*3)+j)); 
                    }
                }
                
            printf("\nsum of matrix:\n");
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
            }
            break;
            case 2:
            {
                
               for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                      d[i][j] = 0;       //for sum
                      for(int k=0;k<3;k++)
                      {
                        d[i][j] = d[i][j] + *(p+(i*3)+k) * *(q+(k*3)+j);  
                      }
                    }
                }
                printf("\nMultiplication of matrix is:\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        printf("%d ",d[i][j]);
                    }
                    printf("\n");
                }
                
            }
            break;
            case 3:      //for saddle point case
            {
                for(i=0;i<2;i++)    //for s matrix in which indices of saddle point gonna be inserted
                {                   //so thats whi i=0 - i=2
                    min = a[i][0];  //always consider first element as minimum element
                    
                    for(j=0;j<2;j++)
                    {
                        if(min >= a[i][0])
                        {
                            min = a[i][j];
                            s[0][0] = i;
                            s[0][1] = j;
                        }
                    }
                    j = s[0][1];
                    max = a[0][j]; //here also consider 1st element of that coloumn as max ele      //as minimum element found then search for max element in same coloumn
                    for(int k=0;k<3;k++)
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
                        if(s[0][0] == s[1][0] && s[0][1] == s[1][1])
                        {
                            printf("%d is saddle point at position %d %d",a[i][j],i,j);
                            flag ==1;
                        }
                    }
                   
                }
                if(flag==0)
                    {
                        printf("No saddle point\n");
                    }
            }
            break;
        }
        printf("Do you want to continue?\n");
        scanf("%d",&ch);
        
        
    }while(ch==1);

    return 0;
}
