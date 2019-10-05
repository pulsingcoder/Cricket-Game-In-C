// A Simple Cricket Game Program in C, this game is a single-player game consisting of one batsman,7 fielders with 1 Wicket Keeper.

//Only the batting can be done with many different types of shots can be played (on covers, mid-off, mid-on, square leg, third men and many other)



#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>
void ball(int);
void erase(int,int);
long int rate;
long int i;
int j,move,l,m,score=0,bowled,Game=1;
char dir,key;
static int map[100][100];
// Reset the cursor position
void ResetScreenPosition(X,Y){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X =X;
    Position.Y =Y;
    SetConsoleCursorPosition(hOut,Position);

}
// Begin Game State of our cricket game
void BeginGame()
{
	ResetScreenPosition(16,26);
	printf("Cricket Game BY YUVRAJ DARWANI");
	ResetScreenPosition(16,28);
	
	printf(" PRESS ANY KEY TO CONTINUE.....");
	scanf("%c",&key);
    /*
	for(i=0;i<3;i++)
	for (j=0;j<3;j++)
	arr[i][j] = 0;
	*/
}

// Initailise the whole setup
void initialization()
{
		
	
	ResetScreenPosition(20,1);
	for(i=1;i<=30;i++)
	{
		
		for(j=15;j<=85;j++)
		{
			if (i>=2 && i < 30) 
			{
				
				
				
				if (j==15|| j==85)
				printf("#");
				else 
				printf(" ");
			}
			
			else 
			printf("#");
			
		}
		
		ResetScreenPosition(20,1+i);
	}
	
}

// The Game over state of cricket game
void GameOver()
{
	Game = 0;
		
	sleep(2);
	system("Cls");
	ResetScreenPosition(35,11);
	if (bowled==1)
	printf("OH!!!    Clean Bowled");
	else 
	printf("OH!!!    Catch Out!");
	ResetScreenPosition(53,14);
	printf("Score is %d",score);
	getch();
	
	
}


// used for loading,slowing the object
void slow(long int rate)    // loop went through long integer
{
	for(i=1;i<rate;i++)
	{
		
	}
}
void loading(char c[])
{
	ResetScreenPosition(50,15);
	printf("%s>>>>>>>>>>>>",c);
	ResetScreenPosition(40,16);
	
		for(j=1;j<40;j++)
		{
			
			printf("#");
			ResetScreenPosition(40+j-1,1+16);
			printf("#");
			ResetScreenPosition(40+j,16);
			slow(70000000);
		
		
		
	}
	
}
// set fielder as -1 
void Fielders()
{
	map[30][7] = -1;
	map[36][28] = -1;
	map[22][16] = -1;
	map[79][28] = -1;
	map[80][7] = -1;
	map[75][17] = -1;
	map[55][2] = -1;
	
	
	
}
// set pitch as 1
void Pitch()
{
	map[52][10] = 1;
	map[53][10] = 1;
	map[54][10] = 1;
	map[52][20] = 2;
	map[53][20] = 2;
	map[54][20] = 2;
	
}
// used for rendering
void print()
{
	for (i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			if (map[i][j] == -1)
			{
				ResetScreenPosition(i,j);
				printf("%c",15);
			}
			if (map[i][j] == 1)
			{
				ResetScreenPosition(i,j);
				printf("| ");
				if (i==54)
				{
					ResetScreenPosition(i,j+1);
					
				}
				
			}
			if (map[i][j] == 2)
			{
				ResetScreenPosition(i,j);
				printf("| ");
				ResetScreenPosition(i,j+1);
				if (i==52)
				printf("A");
				if (i==53)
				printf("B");
				if (i==54)
				printf("C");
			}
			if (map[i][j]==5)
			{
				ResetScreenPosition(i,j);
				printf("^");
				
			}
			if (map[i][j] == 6)
			{
				ResetScreenPosition(i,j);
				printf("!");
			}
			
			if (map[i][j] == 7)
			{
				ResetScreenPosition(i,j);
				printf("\\") ;
			}
			if (map[i][j] == 8)
			{
				ResetScreenPosition(i,j);
				printf("/") ;
			}
			if (map[i][j] == -2)
			{
				ResetScreenPosition(i,j);
				printf(" ");
			}
			
		}
	}
}
// erase all bowls 

void erase(int i,int j)
{
	map[i][j]= -2;
}
// settting up the environment
void environment()
{
	system("Cls");
	initialization();
	loading("Loading Pitch");
	Pitch();
	print();
	system("Cls");
	initialization();
	print();
	loading("Loading Fielders");
	Fielders();
	initialization();
	print();
	
	

	
}
// get input from user
int get_key()
{
    if(_kbhit())
        return _getch();
    else
        return -1;
}
// create the ball function
void ball(int Y)
{
	
	
	
		
			int m=0,ne=0 ;
			
			srand(time(0));
			move = rand()%3+1; // randomly select three position
			
			switch (move)
			{
				case 1: ne = 52; break;
				case 2: ne= 53;break;
				case 3:ne= 54;break;
				default : ne = 54;
			}
			
			
			
	//	system("cls");
		while(m<=7)
	
	{
		
		
		map[ne][18-m] = 5;
		
		print();
		erase(ne,18-m);
	//	ResetScreenPosition(53,18-m);
		
		m+=2;
		
		slow(70000000);
		
		
	}


	
}
// where the ball goes after the hit
// probability of getting out is 0.2 whereas getting boundary is 0.8
void BallLeftHit()
{
	int temp;
	
	  // setting the ball towards the seven end after the hit
	srand(time(0));
	temp = rand()%7+1;
	if (temp==7)     ///OUT!
	{
		l = 50;
		m = 14;
		map[l][m] = 5;
		 
		while(l > 15 && m < 30 )
		{
				
			
			erase(l,m);
			l--;
			m++;
			if (map[l][m] == -1)
			{
				map[l][m] = 5;
			
			    print();
		
				GameOver();
				break;
				
			}
		
			map[l][m] = 5;
			
			print();
			
			slow(70000000);
		}
	}
	if (temp==6 || temp ==2)    /// BOUNDARY 
	{
		l= 35;
		m = 14;
		map[l][m] = 5;
		while(l > 15 && m < 29 )
		{
			erase(l,m);
			l--;
			m++;
			map[l][m] = 5;
			
			print();
			slow(70000000);
		}
		
		
	}
	if (temp==5 || temp ==3)  // Boundary
	{
		l= 50;
		m = 9;
		map[l][m] = 5;
		while(l > 15 && m >2 )
		{
			erase(l,m);
			l--;
			m--;
			map[l][m] = 5;
			
			print();
			slow(70000000);
		}
		
	}
	if (temp==4 || temp ==1)  /// OUT
	{
		l= 45;
		m = 15;
		map[l][m] = 5;
		while(l > 15 && m >2 )
		{
			
			erase(l,m);
			l--;
			if (l%2 == 0)
			m--;
			if (map[l][m] == -1)
			{
				map[l][m] = 5;
			
			    print();
		
				GameOver();
				break;
				
			}
		
			map[l][m] = 5;
			
			print();
			
			
			slow(70000000);
		}
		
	}	
	score = score + 4;
}
// the right shot
void BallRightHit()
{
	int temp ;
	srand(time(0));
	temp = rand()%7+1;
	if (temp==7 || temp ==3)    // BOUNDARY
	{
		l = 54;
		m = 14;
		map[l][m] = 5;
		 
		while(l < 80 && m < 30 )
		{
			erase(l,m);
			l++;
			m++;
			map[l][m] = 5;
			
			print();
			slow(70000000);
		}
	}
	if (temp == 6 || temp ==1)      // OUT
	{
		l= 65;
		m = 14;
		map[l][m] = 5;
		while(l < 80 && m < 30 )
		{
			erase(l,m);
			l++;
			m++;
			if (map[l][m] == -1)
			{
				map[l][m] = 5;
			
			    print();
		
				GameOver();
				break;
				
			}
			map[l][m] = 5;
			
			print();
		
			
			slow(70000000);
		}
	
		
	}
	if (temp == 5 || temp == 2)    // BOUNDARY 
	{
		l= 60;
		m = 9;
		map[l][m] = 5;
		while(l < 80 && m >2 )
		{
			erase(l,m);
			l++;
			m--;
			map[l][m] = 5;
			
			print();
			slow(70000000);
		}
		
	}
	if (temp ==4)    // BOUNDARY
	{
		l= 56;
		m = 10;
		map[l][m] = 5;
		while(l <90 && m <30 )
		{
			erase(l,m);
			l++;
			if (l%2 == 0)
			m++;
			map[l][m] = 5;
			
			print();
			slow(70000000);
		}
	
	}
	score =score + 4;
}
// just setting the bat
void rightHit()
{
	map[53][11] = 0;
	map[53][11] = 7;
}
// just setting the bat
void leftHit()
{
	map[53][11] = 0;
	map[53][11] = 8;
}
// bat input
int bat()
{
	
	dir = getch();
	if (dir == 'd')
	{
		rightHit();
	
	}
	if (dir == 'a')
	{
		leftHit();
	}
	
	
	
	
	
}
// time of hit 
void BallHit()
{
	if (move == 1 && dir == 'a')
	{
		
		BallLeftHit();
		bowled = 0;
	}
	else if (move ==3 && dir == 'd')
	{
		BallRightHit();
		bowled = 0;
	}
	else if (move ==1 && dir == 'd')
	{
		bowled = 1;
		GameOver();
		
	}
	else if (move == 3 && dir == 'a')
	{
		bowled = 1;
		GameOver();
		
	}
	
	else if (move == 2 && (dir =='a'||dir=='d') )
	{
		if (dir == 'a')
		BallLeftHit();
		else 
		BallRightHit();
		bowled = 0;
	}
}



int main()
{
	BeginGame();
	system("Cls");
	initialization();
	map[53][11] = 6;
	
	loading("Loading");
	environment();
	while(Game)
	{
		
		
		print();
		ball(0);
		//initialization();
		print();
		bat();
		
		print();
		BallHit();
		
		erase(53,11);
		map[53][11] = 6;
		for(i=0;i<100;i++)
		{
			for (j=0;j<100;j++)
			{
				if (map[i][j] == 5)
				map[i][j] = 15;
			}
		}
		initialization();
	ResetScreenPosition(95,5);
	printf("Score is %d",score);
	
	}
	
}
