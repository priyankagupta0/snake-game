#include<iostream>
#include <windows.h>
#include<cstdlib>/* srand, rand */
#include<time.h>/* time */
#include<conio.h>//kbhit(if our keyboard has been hit)
using namespace std;

//  initialization

bool gamecondition; //if game is running or not
const int width = 25; 
const int height = 25;
int x, y, speed=1; //info of coordinates of snake
int firstposx,firstposy,secposx,secposy;//tail coordinates
int tailx[100],taily[100],taillength;
int targetx, targety;
int score;
enum directions {STOP =0, UP,DOWN,LEFT,RIGHT};
directions dir;

void gamesetup(){
   
    gamecondition= true;
    //at start the snake is not moving
    dir = STOP;
    x= rand() % width;
    y= rand()  % height;
    targetx= rand()  % width;
    targety= rand()  % height;
    // bug if target and player are on top of each other

   while(x==targetx && y==targety){
    x= rand()  % width;
    y= rand() % height;
    targetx= rand() % width;
    targety= rand() % height; 
    }
    score=0;
    
}

void window(){
system("cls"); //everytime we do something it will clear the above task
// ****************************************** top border***************
for (int i = 0; i < width; i++)
{
   cout<<"*";
}
    cout<<endl;
// *********************************body**************************************
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        if (j == 0 || j == width-1)
        {
           cout<<"*";
        }
        else if(i==y && j==x){
            cout<<"S";
        }
        else if (i==targety && j==targetx){
            cout<<"O";
        }
        else {
            bool tail= false;
            for (int k = 0; k < taillength; k++)
            {
                if (j==tailx[k] && i==taily[k])
                {
                   cout<<"s";
                   tail=true;
                }
                
            }if (!tail)
                {
                   cout<<" ";
                }
        }
        
    } cout<<endl;
} 
// *******************************bottom border***********************************
for (int i = 0; i < width; i++)
{
   cout<<"*";
}
        cout<<endl;
        cout<<"SCORE:"<<score;
}

void input(){
if (_kbhit()){
   switch (_getch())
   {
   case 'a':
   if (dir!= RIGHT)
   {
      dir= LEFT;
      } break;
   
   case 's':
   if (dir!= UP)
   {
      dir= DOWN;
      } break;
   
   case 'd':
   if (dir!= LEFT)
   {
      dir= RIGHT;
      } break;
   
   case 'w':
   if (dir!= DOWN)
   {
      dir= UP;
      } break;
   
    case '0':
    gamecondition = false;
       break;

   }
    
}
}
void program(){
    //tail
    firstposx=tailx[0];
    firstposy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    
    for(int i=1; i< taillength; i++){
        secposx=tailx[i];
        secposy=taily[i];
        tailx[i]=firstposx;
        taily[i]=firstposy;
        firstposx=secposx;
        firstposy=secposy;
    }
    //movement of snake
    switch (dir)
    {
    case RIGHT:
       x +=speed;
        break;
        
    case LEFT:
       x -=speed;
        break;
    
    case UP:
       y -=speed;
        break;
    
    case DOWN:
       y +=speed;
        break;
    
    default:
        break;
    }
    if (x <= 0 || x >= width-1 || y < 0 || y > height-1)
    {
        gamecondition = false;
      //if snake hits the target.  
    } if (x==targetx && y==targety){
         targetx= rand() % width;
         targety= rand() % height; 
        score++;
        taillength++;
     }
  

}
int main(){
    Sleep(25);
    unsigned seed = time(0);
srand(seed);
    gamesetup();
    while(gamecondition==true){window();
     input();
    program();}
}
