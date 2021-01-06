#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fx,fy,score;
enum edir { STOP=0,LEFT,RIGHT,UP,DOWN
};
edir dir;
int tailx[100],taily[100];//x and y coordinates of the tail

int ntail;//length of the tail

/*about the tail section which is much complicated
suppose the snake has the followng sturtcure
Ooooo
moving down it will look like
oo
o
o   *The second segment follows the first the third segment follows the second and so on
O    will use for loop to display the segments*
moving right it will look like
 ooo
Oo
and so on*/
void setup()
{ gameover=false;
  	dir=STOP;
  	x=width/2;
  	y=height/2;
  	fx=rand()%width;//it will place fruit at any location between o to width-1;
    fy=rand()%height;
}
void draw()                    
{                       
//	system("cls");
	for(int i=0;i<width;i++)
	cout<<"#";
		
	for(int i=0;i<height;i++)
	{
		
		for(int j=0;j<width;j++)    //####
		{                           //#  #
			if(j==0)                //####
			cout<<"#"<<"\n";
			
			if(i==y&&j==x)
			cout<<"O";
			else if(i==fy&&j==fx)
			cout<<"F";
            else
            { bool print = false;
			for(int k=0;k<ntail;k++)
			{
				if(tailx[k]==j && taily[k]==i)
				{
					cout<<"o";
					print=true;
				}
			}
			if(!print)
			cout<<" ";			
			}
			if(j==width-1)
			cout<<"#";
		}
	cout<<"\n";	
	}

	for(int i=0;i<width;i++)
	cout<<"#";
	cout<<"\n";
	cout<<"score:"<<score<<"\n";

}
void input()
{
	if(_kbhit())//it will return true if character in the keyboaard is pressed
	{
	switch(_getch())
	{
      case 'a':
	  dir=LEFT;
	  break;
	  case 'd':
	  dir=RIGHT;
	  break;
	  case  'w':
	  dir=UP;
	  break;
	  case 's':
	  dir=DOWN;
	  break;
	  case 'x':
	  gameover=true;
	  break;		
		
		
		
		
		}	
	
	
	
	}
	
}

void logic()
{  int prevx = tailx[100];
    int prevy = taily[100];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ntail;i++)
    {
    	prev2x=tailx[i];
    	prev2y = taily[i];
    	tailx[i]=prevx;
    	taily[i]=prevy;
    	prevx=prev2x;
    	prevy=prev2y;
    
	}
	switch(dir)
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
       if(x>width || x<0 || y>height || y<0)
       gameover=true;
       if(x==fx && y==fy)
       { ntail++;//length of the tail increases if it eats the fruit
       	score=score+10;
       		fx=rand()%width;//it will place fruit at any location between o to width-1;
    fy=rand()%height;
	   }

}
int main()
{
	
setup();
while(!gameover)
{
	draw();
	input();
	logic();
	sleep(1);
	
	}	
	
	
	
} 
