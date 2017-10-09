#include <stdio.h>
#include <stdlib.h>
int rmax=3,cmax=3;
int lenarr[6];
int l=0;
int pathfinder(int matrix[rmax][cmax],int *p,int i,int j,int k)
{
    if((i+1)<rmax)
    {
        p[k]=matrix[i+1][j];
             pathfinder(matrix,p,i+1,j,k+1);
    }
    if((j+1)<cmax)
    {
        p[k]=matrix[i][j+1];
             pathfinder(matrix,p,i,j+1,k+1);
    }
    if((i+1)==rmax && (j+1)==cmax)
    {
        int a,sum=0;
        for(a=0;a<(rmax+cmax-1);a++){
            printf("%d -> ",p[a]);
            sum=sum+p[a];
        }
        lenarr[l]=sum;
        printf(" : Length= %d\n\n",lenarr[l]);
        l++;
    }
    return 1;
}
int main()
{
    int i=0,k=0,j=0;
    int matrix[3][3] = {
        {1,2,6},
        {5,4,3},
        {8,9,7}
        };
    int p[cmax+rmax];
    p[k++]=matrix[i][j]; //source
    pathfinder(matrix,p,i,j,k);
    printf("Shortest path length: \n");
    int min=lenarr[0];
    for(i=0;i<(cmax+rmax);i++)
    {
        if(lenarr[i]<min)
            min=lenarr[i];
    }
    printf("%d",min);
    return 0;
}
