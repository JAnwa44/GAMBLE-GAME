#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <math.h>
/***********************************************************************/
#define Number 10
#define Number_power 8
/***********************************************************************/
int value[5];
int value1[5];
int value2[5];
int value3[5];
int luck_random,Choose_luck,Select_picture,checkluck,check,x,y;
int choice = 4;
int players;
long money;

/***********************************************************************/
int Random();
void Delay();
int income();
void start_screen();
int Show_screen();
void Show_screen1();
void Show_screen2();
void Show_screen3();
void Show_screen4();
void Show_screencheck(int,int,long);
FILE *info;
void file_show1();
void file_show2();
void file_show3();
void file_show4();
/***********************************************************************/
int main()
{
	time_t mytime;
    mytime = time(NULL);
    info=fopen("GAMBLE.txt","a+");
    fscanf(info,"%d",&players);
	fclose(info);
	
	players++;
	
	info=fopen("GAMBLE.txt","w+");
	fclose(info);
	
	info=fopen("GAMBLE.txt","a");
	fprintf(info,"%d\n",players);
	fprintf(info,"Played Date:%s\n",ctime(&mytime));
	fclose(info);
	/*
	info=fopen("GAMBLE.txt","a");
	fclose(info);
	*/
	start_screen();
	money = income();
	Select_picture = Show_screen();
	luck_random = Random();	
	Show_screencheck(luck_random,Select_picture,money);

	return 0;
}

void start_screen()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWelcome to Gamble game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\n\n\n\n\t\t\t\t\tHow to play ? \n");
    printf("\t\n\t\t--> Allows the user to recharge and select the image that the user wants to select. (To risk your luck) \t\n\t\t    You can check your luck and your heart with this game. \n");
    printf("\t\n\t\t--> The program will run a number and check if the picture chosen by the user matches the picture \t\n\t\t    set by the program.\n");
    printf("\t\n\t\t--> If the images match, the user will get 1/3 of the jackpot \n");
    printf("\t\n\t\t--> If the program runs the same number on all 3 channels, the user \t\n\t\t    will receive 2/3 of the jackpot \n");
    printf("\t\n\t\t--> If the user has match results and numbers match on all 3 boxes, the user will get a jackpot !!");
    printf("\t\n\t\t--> If after checking the program the user does not have the same number or the image specified \t\n\t\t    by the program, You will lose the money you invest.  ");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to play game...");
    if(getch())
        system("cls");
}

int income()
{
	
	printf("Money you want to invest :");
	scanf("%d",&money);
	system("cls");
	
	info=fopen("GAMBLE.txt","a");
	fprintf(info,"The amount of money the player has investe >%d\n\n\n",money);
	fclose(info);
	
	
	return money;
}

int Random()
{
	int rnd=3;
	int x,i,j,z;
	int r=10;
	int line = 17;

	srand(time(NULL));
	for(i = 1; i<=rnd; i++)
	{
		x = rand();
		value1[i-1] = x%10; 
	}
	for(j = 1; j<=r; j++)	
	{
		system("cls");
		for(i = 1; i<=rnd; i++)
		{
			printf("%d\n",value1[i-1]);
			if(i == 1 || i == 2)
			{
					for(z = 0; z<=line; z++)
				{
					printf("-");
				}
			}
			printf("\n");
		}
		
		Delay();
		
		for(i = 1; i<=3; i++)
		{
		value1[i-1] = value1[i];
			if(i == 3 )
			{
				x = rand();
				value1[i-1] = x%10;
			}
		}
	}
	
	for(i = 1; i<=rnd; i++)
	{
		x = rand();
		value2[i-1] = x%10;
	}
	
	for(j = 1; j<=r; j++)	
	{
		system("cls");
		for(i = 1; i<=rnd; i++)
		{
			printf("%d\t%d\n",value1[i-1],value2[i-1]);
			if(i == 1 || i == 2)
			{
					for(z = 0; z<=line; z++)
				{
					printf("-");
				}
			}
			printf("\n");
		}
		
		Delay();
		
		for(i = 1; i<=3; i++)
		{
		value2[i-1] = value2[i];
			if(i == 3 )
			{
				x = rand();
				value2[i-1] = x%10;
			}
		}
	}
	
	for(i = 1; i<=rnd; i++)
	{
		x = rand();
		value3[i-1] = x%10;
	}
	
	for(j = 1; j<=r; j++)	
	{
		system("cls");
		for(i = 1; i<=rnd; i++)
		{
			printf("%d\t%d\t%d\n",value1[i-1],value2[i-1],value3[i-1]);
			if(i == 1 || i == 2)
			{
					for(z = 0; z<=line; z++)
				{
					printf("-");
				}
			}
			printf("\n");
		}
		
		Delay();

		for(i = 1; i<=3; i++)
		{
		value3[i-1] = value3[i];
			if(i == 3 )
			{
				x = rand();
				value3[i-1] = x%10;
			}
		}
	}
	
	luck_random = (value1[1]+value2[1]+value3[0])%choice;

	info=fopen("GAMBLE.txt","a");
	for(i = 1; i<=rnd; i++)
		{
			fprintf(info,"%d\t%d\t%d\n",value1[i-1],value2[i-1],value3[i-1]);
			if(i == 1 || i == 2)
			{
					for(z = 0; z<=line; z++)
				{
					fprintf(info,"-");
				}
			}
			fprintf(info,"\n");
		}
	fprintf(info,"\n\n\n");	
	fclose(info);
	
	return luck_random;	
}



int Show_screen()
{
	int button;
	int picture=0;
	while(button!=13)
	{
		system("cls");
		if(picture == 0)
		{	
			printf("\n");
			printf("\t\t\t\t\t    if you want This Shapes Please Enter.\n\n\n");	
			Show_screen1();
			button = getch();
			if(button == 54)
			{
				picture++;
			}
			if(button == 13)
			{
				break;
			}
			
		}else if(picture == 1)
		{
			printf("\n");
			printf("\t\t\t\t\t    if you want This Shapes Please Enter.\n\n\n");
			Show_screen2();
			button = getch();
			if(button == 54)
			{
				picture++;
			}
			if(button == 52)
			{
				picture--;
			}
			if(button == 13)
			{
				break;
			}
			
		}else if(picture == 2)
		{
			printf("\n");
			printf("\t\t\t\t\t    if you want This Shapes Please Enter.\n\n\n");
			Show_screen3();
			button = getch();
			if(button == 54)
			{
				picture++;
			}
			if(button == 52)
			{
				picture--;
			}
			if(button == 13)
			{
				break;
			}
			
		}else if(picture == 3)
		{
			printf("\n");
			printf("\t\t\t\t\t    if you want This Shapes Please Enter.\n\n\n");
			Show_screen4();
			button = getch();
			if(button == 52)
			{
				picture--;
			}
			if(button == 13)
			{
				break;
			}
			
		}
			
	}
	/******************************************************************************/
	if(picture == 0)
	{
		fprintf(info,"Players select this picture.\n");
		file_show1();
		
	}else if(picture == 1) 
	{
		fprintf(info,"Players select this picture.\n");
		file_show2();
		
	}else if(picture == 2)
	{
		fprintf(info,"Players select this picture.\n");
		file_show3();
		
	}else if(picture == 3)
	{
		fprintf(info,"Players select this picture.\n");
		file_show4();
	}
	
	Select_picture = picture;
	return Select_picture;
}

void Show_screen1()
{	

	
	//Shape Heart.
	int n=15;
	
	for(x=(n/2); x<=n; x+=2)
    	{
    	printf("\t\t\t\t\t\t");
    
        for(y=1; y<(n-x); y+=2)
        {
            printf(" ");
          
        }
        for(y=1; y<=x; ++y)
        {
            printf("*");
   
        }
        for(y=1; y<=(n-x); ++y)
        {
            printf(" ");
       
        }
        for(y=1; y<=x; ++y)
        {
            printf("*");
   
        }
        printf("\n");
        
    }
    
    for(x=n; x>=1; --x)
    {
    	printf("\t\t\t\t\t\t");
    	
        for(y=x; y<n; ++y)
        {
            printf(" ");
         
        }
        for(y=1; y<=(x*2)-1; ++y)
        {
            printf("*");
       
        }
        printf("\n");
        
    }
    printf("\n\n\n");
    
  
  
}

void Show_screen2()
{

	int n=8,m;
	
    m=n;  
   for(int i=1;i<=n;i++)  
   {  
   		printf("\t\t\t\t\t\t\t");
       for(int j=1;j<=m-1;j++)  
       	{  
           printf(" ");  
       	}  
       for(int k=1;k<=2*i-1;k++)  
       {  
         printf("*");  
       }  
       m--;  
      printf("\n");  
    }
    
    n=14;   
    for(int i=1;i<=n;i++)  
    {  
    	printf("\t\t\t\t\t\t\t");
        for(int j=1;j<=n;j++)  
        {  
            if(i==1 ||i==n||j==1||j==n-i+1||i==j||j==n)  
            {  
            printf("*");  
            }  
            else  
            printf(" ");  
        }  
     printf("\n");  
    }  
    printf("\n");
    
	//Shape House.  
}

void Show_screen3()
{
	printf("\t\t\t\t\t	        ++++++\n");
	printf("\t\t\t\t\t	     ++++++++++++\n");
	printf("\t\t\t\t\t	  ++++++++++++++++++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++           +\n");
	printf("\t\t\t\t\t    ++++++++++++++++++++++++++++++      ++\n");
	printf("\t\t\t\t\t  ++++++++++++++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t+++++   ++++++++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t  ++++++++++++++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t    ++++++++++++++++++++++++++++++      ++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++           +\n");
	printf("\t\t\t\t\t	  ++++++++++++++++++\n");
	printf("\t\t\t\t\t	     ++++++++++++\n");
	printf("\t\t\t\t\t	        ++++++\n");
	printf("\n\n\n");
}

void Show_screen4()
{
	
	printf("\t\t\t\t\t             	+++++++\n");
	printf("\t\t\t\t\t             	++   ++\n");
	printf("\t\t\t\t\t             	++   ++\n");
	printf("\t\t\t\t\t                ++   ++  ++++++\n");
	printf("\t\t\t\t\t        ++++++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");	
	printf("\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	printf("\t\t\t\t\t          ++  ++++   ++++  ++\n");
	printf("\t\t\t\t\t            ++  ++   ++  ++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	printf("\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	printf("\n\n\n");
}


void Show_screencheck(int Random,int user,long income)
{
	
	system("cls");
	luck_random = Random;
	Select_picture = user;
	money = income;
	
	if(luck_random == 0)
	{
		printf("\n\n\n");
		Show_screen1();
		fprintf(info,"The result of the random numbering\n");
		file_show1();
		
	}else if(luck_random == 1)
	{
		printf("\n\n\n");
		Show_screen2();
		fprintf(info,"The result of the random numbering\n");
		file_show2();
		
	}else if(luck_random == 2)
	{
		printf("\n\n\n");
		Show_screen3();
		fprintf(info,"The result of the random numbering\n");
		file_show3();
		
	}else if(luck_random == 3)
	{
		printf("\n\n\n");
		Show_screen4();
		fprintf(info,"The result of the random numbering\n");
		file_show4();
		
	}

	/***********************************************************************/
	//jackpot
	
	if(value1[1]==value2[1] && value1[1]==value3[0] && Random == Select_picture)
	{
		money = money*2;
		printf("jackpot = %d",money);
		fprintf(info,"jackpot = %d",money);
		
	}else if(value1[1]==value2[1] && value1[1]==value3[0])
	{
		money = money+(income*(66.66/100));
		printf("jackpot = %d",money);
		fprintf(info,"jackpot = %d",money);
		
	}else if(Random == Select_picture)
	{
		money = money+(income*(33.33/100));
		printf("jackpot = %d",money);
		fprintf(info,"jackpot = %d",money);
		
	}else{
		printf("\nYou unlucky bui bui\n");
		fprintf(info,"\nYou unlucky bui bui\n");
	}
	
	
	/***********************************************************************/
	

}

void Delay()
{
	long delay,i;
	
	delay = pow(Number,Number_power);
//	printf("%d",delay);
	delay = delay/2;
	for(i = 0; i<=delay; i++)
	{
	}
}

void file_show1()
{
		info=fopen("GAMBLE.txt","a");
	
	//Shape Heart.
	int n=15;
	
	for(x=(n/2); x<=n; x+=2)
    	{
    	fprintf(info,"\t\t\t\t\t\t");
        for(y=1; y<(n-x); y+=2)
        {
            fprintf(info," ");
        }
        for(y=1; y<=x; ++y)
        {
            fprintf(info,"*");
        }
        for(y=1; y<=(n-x); ++y)
        {   
            fprintf(info," ");
        }
        for(y=1; y<=x; ++y)
        {
            fprintf(info,"*");
        }
        fprintf(info,"\n");
    }
    
    for(x=n; x>=1; --x)
    {
    	printf("\t\t\t\t\t\t");
    	fprintf(info,"\t\t\t\t\t\t");
        for(y=x; y<n; ++y)
        {
            printf(" ");
            fprintf(info," ");
        }
        for(y=1; y<=(x*2)-1; ++y)
        {
            printf("*");
            fprintf(info,"*");
        }
        printf("\n");
        fprintf(info,"\n");
    }
    printf("\n\n\n");
    fprintf(info,"\n\n\n");
    
    fclose(info);
}

void file_show2()
{
	info=fopen("GAMBLE.txt","a");
	
	int n=8,m;
	
    m=n;  
   for(int i=1;i<=n;i++)  
   {  
   		
   		fprintf(info,"\t\t\t\t\t\t\t");
       for(int j=1;j<=m-1;j++)  
       	{  
           
           fprintf(info," ");
       	}  
       for(int k=1;k<=2*i-1;k++)  
       {  
         
		 fprintf(info,"*");  
       }  
       m--;  
      
	  fprintf(info,"\n");  
    }
    
    n=14;   
    for(int i=1;i<=n;i++)  
    {  
    	
    	fprintf(info,"\t\t\t\t\t\t\t");
        for(int j=1;j<=n;j++)  
        {  
            if(i==1 ||i==n||j==1||j==n-i+1||i==j||j==n)  
            {  
            	fprintf(info,"*");  
            }  
            else  
            fprintf(info," ");  
        }  
     fprintf(info,"\n");  
    }  
    fprintf(info,"\n");
    
    fclose(info);
}

void file_show3()
{
	info=fopen("GAMBLE.txt","a");
	
	
	fprintf(info,"\t\t\t\t\t	        ++++++\n");
	fprintf(info,"\t\t\t\t\t	     ++++++++++++\n");
	fprintf(info,"\t\t\t\t\t	  ++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++           +\n");
	fprintf(info,"\t\t\t\t\t    ++++++++++++++++++++++++++++++      ++\n");
	fprintf(info,"\t\t\t\t\t  ++++++++++++++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t+++++   ++++++++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t  ++++++++++++++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t    ++++++++++++++++++++++++++++++      ++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++           +\n");
	fprintf(info,"\t\t\t\t\t	  ++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t	     ++++++++++++\n");
	fprintf(info,"\t\t\t\t\t	        ++++++\n");
	fprintf(info,"\n\n\n");
	
	fclose(info);
}

void file_show4()
{
	info=fopen("GAMBLE.txt","a");
	
	fprintf(info,"\t\t\t\t\t             	+++++++\n");
	fprintf(info,"\t\t\t\t\t             	++   ++\n");
	fprintf(info,"\t\t\t\t\t             	++   ++\n");
	fprintf(info,"\t\t\t\t\t                ++   ++  ++++++\n");
	fprintf(info,"\t\t\t\t\t        ++++++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");	
	fprintf(info,"\t\t\t\t\t        ++  ++  ++   ++  ++  ++\n");
	fprintf(info,"\t\t\t\t\t          ++  ++++   ++++  ++\n");
	fprintf(info,"\t\t\t\t\t            ++  ++   ++  ++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	fprintf(info,"\t\t\t\t\t       ++++++++++++++++++++++++++\n");
	fprintf(info,"\n\n\n");
	
	fclose(info);
}
