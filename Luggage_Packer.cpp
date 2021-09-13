#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;   //Number of items
int W;   //Luggage Weight Limit

struct knapsackGreedy{
	int value;
	int weight;
	int no;
};

int comp(const void *a,const void *b)
{
    struct knapsackGreedy *x = (struct knapsackGreedy *)a;
    struct knapsackGreedy *y = (struct knapsackGreedy *)b;
    double p= (double)(x->value)/(double)(x->weight);
    double q = (double)(y->value)/(double)(y->weight);
    return p<q;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int DPKnapsack(int wt[], int val[])
{
   int i, w;
   int K[n+1][W+1]; //T-Table
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   int result = K[n][W];
   int res = result;
   w = W;
   printf("Items you must put in your luggage are : \n");
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            if(wt[i-1]==1400)
                printf("LAPTOP\n");
            else if(wt[i-1]==75)
                printf("FOOTBALL\n");
            else if(wt[i-1]==2000)
                printf("BOOKS\n");
            else if(wt[i-1]==800)
                printf("PILLOWS AND BLANKETS\n");
            else if(wt[i-1]==3500)
                printf("FOOD AND GROCERIES\n");
            else if(wt[i-1]==1500)
                printf("SOFT DRINKS\n");
            else if(wt[i-1]==4500)
                printf("CLOTHES\n");
            else if(wt[i-1]==950)
                printf("CAMERA\n");
            else if(wt[i-1]==6000)
                printf("CRICKET KIT\n");
            else if(wt[i-1]==2700)
                printf("SHOES\n");

            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    return result;
}

int GreedyKnapsack()
{
	struct knapsackGreedy k[n];
	printf("Enter the Sno. and values of all the items you wish to keep in the luggage : \n");
	for(int i=0;i<n;i++)
    {
        printf("Item %d : ",i+1);
		scanf("%d %d",&k[i].no,&k[i].value);

        if(k[i].no==1)
            k[i].weight = 1400;
        else if(k[i].no==2)
            k[i].weight = 75;
        else if(k[i].no==3)
            k[i].weight = 2000;
        else if(k[i].no==4)
            k[i].weight = 800;
        else if(k[i].no==5)
            k[i].weight = 3500;
        else if(k[i].no==6)
            k[i].weight = 1500;
        else if(k[i].no==7)
            k[i].weight = 4500;
        else if(k[i].no==8)
            k[i].weight = 950;
        else if(k[i].no==9)
            k[i].weight = 6000;
        else if(k[i].no==10)
            k[i].weight = 2700;

    }
	qsort((void*)k,n,sizeof(struct knapsackGreedy),comp);
	printf("Items you must put in your luggage are : \n");
	long long wsum=0;
	long long vsum=0;
	for(int i=0;i<n;i++)
	{
		if(wsum+k[i].weight <= W)
        {
			wsum+=k[i].weight;
			vsum+=k[i].value;
			if(k[i].no==1)
                printf("LAPTOP\n");
            else if(k[i].no==2)
                printf("FOOTBALL\n");
            else if(k[i].no==3)
                printf("BOOKS\n");
            else if(k[i].no==4)
                printf("PILLOWS AND BLANKETS\n");
            else if(k[i].no==5)
                printf("FOOD AND GROCERIES\n");
            else if(k[i].no==6)
                printf("SOFT DRINKS\n");
            else if(k[i].no==7)
                printf("CLOTHES\n");
            else if(k[i].no==8)
                printf("CAMERA\n");
            else if(k[i].no==9)
                printf("CRICKET KIT\n");
            else if(k[i].no==10)
                printf("SHOES\n");

        }
		/*else
        {
			vsum+=k[i].value*(double)(W-wsum)/(double)(k[i].weight);
            break;
        }*/
    }
    return vsum;
}

int main()
{
    printf("********************************************************************************************************************************************\n");
    printf("\tWELCOME TO OUR ITEM PICKER TOOL\n");
    printf("\tTHIS TOOL ALLOWS YOU TO PICK ITEMS AND HELPS YOU TO PACK YOUR LUGGAGE FAST AND MAXIMIZES YOUR PROFIT!!\n");
    printf("********************************************************************************************************************************************\n\n");
    printf("THE LIST OF ITEMS AVAILABLE ARE : \n");
    //Weight in grams
    printf("NO.\t\tNAME\t\t\tWEIGHT(gms)\n");
    printf("1.\t\tLAPTOP\t\t\t1400\n");
    printf("2.\t\tFOOTBALL\t\t75\n");
    printf("3.\t\tBOOKS\t\t\t2000\n");
    printf("4.\t\tPILLOWS AND BLANKETS    800\n");
    printf("5.\t\tFOOD AND GROCERIES      3500\n");
    printf("6.\t\tSOFT DRINKS\t\t1500\n");
    printf("7.\t\tCLOTHES\t\t\t4500\n");
    printf("8.\t\tCAMERA\t\t\t950\n");
    printf("9.\t\tCRICKET KIT\t\t6000\n");
    printf("10.\t\tSHOES\t\t\t2700\n");

    int choice;
    int again=0;
    while(again==0)
    {
        printf("Enter the number of items : ");
        scanf("%d",&n);
        int num[n],val[n],wt[n];
        printf("Enter the maximum capacity your luggage can carry(kgs) : ");
        scanf("%d",&W);
        W = 1000*W;
        printf("Let us resolve the issue of packing your luggage!!\n");
        printf("Enter 1 to solve by Greedy method (OR) Enter 2 to solve by Dynamic Programming : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int res = GreedyKnapsack();
            printf("Maximum profit that is possible by putting all items in the Knapsack is : %d\n",res);
        }
        if(choice==2)
        {
            printf("Enter the Snos. and values of all the items you wish to put in the bag :\n");
            for(int i=0;i<n;i++)
            {
                printf("Item %d : ",i+1);
                scanf("%d %d",&num[i],&val[i]);
                if(num[i]==1)
                    wt[i] = 1400;
                else if(num[i]==2)
                    wt[i] = 75;
                else if(num[i]==3)
                    wt[i] = 2000;
                else if(num[i]==4)
                    wt[i] = 800;
                else if(num[i]==5)
                    wt[i] = 3500;
                else if(num[i]==6)
                    wt[i] = 1500;
                else if(num[i]==7)
                    wt[i] = 4500;
                else if(num[i]==8)
                    wt[i] = 950;
                else if(num[i]==9)
                    wt[i] = 6000;
                else if(num[i]==10)
                    wt[i] = 2700;

            }
            int ans = DPKnapsack(wt,val);
            printf("Maximum profit that is possible by putting all items in the Knapsack is : %d\n",ans);
        }
        printf("Do you want to continue? Press 0 to continue and 1 to exit : ");
        scanf("%d",&again);
        if(again==1)
        {
            printf("THANK YOU FOR USING OUR TOOL!!");
            return 0;
        }
    }
}
