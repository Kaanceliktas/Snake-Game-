#include<iostream>
#include<conio.h>
#include<windows.h>


using namespace std;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN}; // directions to control snake
eDirection Dir;
bool gameOver;
void setup();
void draw();
void input();
void easy();
void hard();
const int width=20; // dimension of box
const int height=20; // dimension of box
int x,y, fruitX, fruitY,score;
int tailx[100],taily[100];
int ntail;


class Setup
{
	public:
		void setup()
		{
			gameOver=false;
			Dir=STOP; // in the beginning statue of the snake
			x=width/2; // in the beginning position of the snake
			y=height/2; // in the beginning position of the snake
			fruitX=rand() % width; // foods' position
			fruitY=rand() % height; // foods' position
			score=0; 
		}
		
};	


class Draw
{
	public:
	
	void draw()
 {
	system("cls"); 
	for (int i = 0; i < width+2; i++) // to create horizontal # map
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) // to create vertical # map
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "*"; // food symbol in map
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++) // to print the tail
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
				

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
 }
	
	
};		
		
class Input

{
	public:
		
		void input()
{
	if(kbhit()) // if keyboard hit
	{
		switch(getch()) // it will begin when pushing a button
		{
		case 'a': //directions
		Dir=LEFT;
		break;
		case 'd': //directions
		Dir=RIGHT;
		break;
		case 'w': //directions
		Dir=UP;
		break;
		case 's': //directions
		Dir=DOWN;
		break;
		case ' ': //directions
		gameOver=true;
		break;
		}
	}
}
			
	
};


class Easy

{
	public:
	
	void easy()
{
	int prevX=tailx[0]; // to remember first element of position in x direction
	int prevY=taily[0]; // to remember first element of position in y direction
	int prev2X,prev2Y;
	tailx[0]=x; // to tail 
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch (Dir) // to increase or decrease which direction that you choose
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if(x>=width||x<0||y>=height||y<0) // to block the walls
	{
		gameOver=false;
	}
	if(x>=width) x=0; else if(x<0)x=width-1;
	if(y>=height) y=0; else if(y<0)y=height-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		{
		gameOver=false;
		}
	}
	if(x==fruitX&&y==fruitY)  // to increase the score
	{
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
		ntail++;
	}
 
}
	
};

class Hard

{
	public:
	
	void hard()
	
{
	
	int prevX=tailx[0]; // to remember first element of position in x direction
	int prevY=taily[0]; // to remember first element of position in y direction
	int prev2X,prev2Y;
	tailx[0]=x; // to tail 
	taily[0]=y;
	for(int i=1;i<ntail;i++) 
	{
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	
	switch (Dir) // to increase or decrease which direction that you choose
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if(x>=width||x<0||y>=height||y<0) // to block the walls
	{
		gameOver=true;
	}
	if(x>=width) x=0; else if(x<0)x=width-1; // to block tail crash
	if(y>=height) y=0; else if(y<0)y=height-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		{
		gameOver=true;
		}
	}
	if(x==fruitX&&y==fruitY)  // to increase the score
	{
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
		ntail++;
	}

}
	
};



int main() // to print opening page
{
	char ch;
	cout<<"\n\t---------------------------------------\n";
	cout<<"\t\tSnake Game - Kaan Celiktas\n";
	cout<<"\t---------------------------------------\n\n";
	cout<<"Please Enter the Game Mod Which You Want to Play:\n\n";
	cout<<"Play Hard Mode for Press : H/h\n\n";
	cout<<"Play Easy Mode for Press: E/e\n\n";
	
	cin>>ch; // to call easy or hard
	
	Setup setupObj;
	
	Draw drawObj;
	
	Hard hardObj;
	
	Easy easyObj;
	
	Input inputObj;
	
	
	switch (ch)
	{
	case 'E': 
		setupObj.setup();
		while(!gameOver)
		{
		drawObj.draw();
		inputObj.input();
		easyObj.easy();
		Sleep(30);
		}
		break;
		case 'e': 
		setupObj.setup();
		while(!gameOver)
		{
		drawObj.draw();
		inputObj.input();
		easyObj.easy();
		Sleep(30);
		}
		break;
		case 'h':
		setupObj.setup();
		while(!gameOver)
		{
		drawObj.draw();
		inputObj.input();
		hardObj.hard();
		Sleep(5);
		}
		break;
	case 'H':
		setupObj.setup();
		while(!gameOver)
		{
		drawObj.draw();
		inputObj.input();
		hardObj.hard();
		Sleep(5);
		}
		break;
		
	    default:
		cout<<"Invalid!! Please Select Given Options.";
		break;
	}
	
	getch();
	return 0;
}
