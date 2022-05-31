#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
char data[5];
int encoded[8],edata[7],syndrome[3];
int hmatrix[3][7] = {
1,0,0,0,1,1,1,
0,1,0,1,0,1,1,
0,0,1,1,1,0,1
};
char gmatrix[4][8]={"0111000","1010100","1100010","1110001"};
int main()
{
    int i,j;
    system("clear");
    printf("\nHamming code----- Encoding\n");
    printf("Enter 4 bit data : ");
    scanf("%s",data);
    printf("\nGenerator matrix\n");
    for(i=0;i<4;i++)
        printf("%s\n",gmatrix[i]);
    printf("\nEncoded data ");
    for(i=0;i<7;i++)
    {
        for(j=0;j<4;j++)
        encoded[i]+=((data[j]-'0')*(gmatrix[j][i]-'0'));
        encoded[i]=encoded[i]%2;
        printf("%d ",encoded[i]);
    }
    printf("\nHamming code----- Decoding\n");
    printf("Enter encoded bits as recieved : ");
    for(i=0;i<7;i++)
        scanf("%d",&edata[i]);
    for(i=0;i<3;i++)
    {
        for(j=0;j<7;j++)
        syndrome[i]+=(edata[j]*hmatrix[i][j]);
        syndrome[i]=syndrome[i]%2;
    }
    for(j=0;j<7;j++)
        if((syndrome[0]==hmatrix[0][j]) && (syndrome[1]==hmatrix[1][j])&& (syndrome[2]==hmatrix[2][j]))
            break;
        if(j==7)
            printf("\nError free\n");
        else
        {
            printf("\nError recieved at bit number %d of data\n",j+1);
            edata[j]=!edata[j];
            printf("\nCorrect data should be : ");
            for(i=0;i<7;i++)
                printf("%d",edata[i]);
        }
	printf("\n");
        return 0;
}
