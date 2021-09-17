#include<iostream>
#include<conio.h>
#include <windows.h>
#include <unistd.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 

using namespace std;

bool gameOver;
const int width =50;
const int height =20;
int x,y, fruitx, fruity;
int tailx[100], taily[100];
int nTail; 

enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir; 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','±','±',' ', 
					'±','±','±','±', 
					' ','±','±',' ',
					'±','±','±','±' }; 
					
int carPos = WIN_WIDTH/2;
int score = 0; 

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitx = rand()% width;
	fruity = rand()%height; 
	score = 0;
}
void Draw()
{
    system("cls"); 
	for(int i = 0;i<width+2; i++)
	cout<<"_";
	cout<<endl;
	for(int i = 0;i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(j==0)
			   cout<<"|";
			 if(i==y && j==x) 
			 cout<<"O";
			 else if(i==fruity && j==fruitx)
			 cout<<"@";
			 else
			 {
			 	bool print = false;
			 	
			 	for(int k=0;k< nTail;k++)
			 	{
			 		if(tailx[k]==j && taily[k]==i)
			 		{
			 			cout<<"o"; 
			 		    print = true;
					 }	 
				 }
				 if(!print)
			        	cout<<" ";
				
			 }
			
		    if(j==width-1) 
			   cout<<"|";			   
		}
		cout<<endl;

	}
	for(int i=0; i< width+2; i++)
	cout<<"_";
	cout<<endl;
			cout<<"Score: "<<score<<endl;	
}
void Input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir = LEFT; 
				break;
			case 'd':
				dir = RIGHT; 
				break;
			case 'w':
				dir = UP; 
				break;
			case 's':
				dir = DOWN; 
				break;
			case 'x':
				gameOver= true; 
				break;
		}
	}   	
}
void Logic()
{
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2X, prev2Y;
	tailx[0]=x;
	taily[0]=y;	
	for(int i=1;i<nTail; i++)
	{
		prev2X= tailx[i];
		prev2Y= taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
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
	if(x>width || x<0 || y> height || y<0)
	gameOver = true;
//	if(x>=width)x=0; else if(x<0) x = width-1;
//	if(y>=height)y=0; else if(y<0) y = height-1;
	for(int i=0; i<nTail; i++)
	if(tailx[i]==x && taily[i]==y)
	gameOver = true;
	if(x==fruitx && y==fruity)
	{
		score+=50;
	fruitx = rand()% width;
	fruity = rand()%height; 
	nTail++;
	}
}
void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void drawBorder(){  
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j<17; j++){
			gotoxy(0+j,i); cout<<"±";
			gotoxy(WIN_WIDTH-j,i); cout<<"±";
		}
	} 
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(SCREEN_WIDTH,i); cout<<"±";
	} 
}
void genEnemy(int ind){
	enemyX[ind] = 17 + rand()%(33);  
}
void drawEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]);   cout<<"****";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"|**|"; 
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"|**|"; 
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"****";  
	} 
}
void eraseEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]); cout<<"    ";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    "; 
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    "; 
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    "; 
	} 
}
void resetEnemy(int ind){
	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}

void drawCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<car[i][j];
		}
	}
}
void eraseCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<" ";
		}
	}
}
 
int collision(){
	if( enemyY[0]+4 >= 23 ){
		if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  ){
			return 1;
		}
	}
	return 0;
} 
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}

void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Avoid Cars by moving left or right. ";
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	carPos = -1 + WIN_WIDTH/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;
	  
	system("cls"); 
	drawBorder(); 
	updateScore();
	genEnemy(0);
	genEnemy(1);
	
	gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key - Right"; 
	
	gotoxy(18, 5);cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='a' || ch=='A' ){
				if( carPos > 18 )
					carPos -= 4;
			}
			if( ch=='d' || ch=='D' ){
				if( carPos < 50 )
					carPos += 4;
			} 
			if(ch==27){
				break;
			}
		} 
		
		drawCar(); 
		drawEnemy(0); 
		drawEnemy(1); 
		if( collision() == 1  ){
			gameover();
			return;
		} 
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);   
		
		if( enemyY[0] == 10 )
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;
		
		if( enemyFlag[0] == 1 )
			enemyY[0] += 1;
		
		if( enemyFlag[1] == 1 )
			enemyY[1] += 1;
		 
		if( enemyY[0] > SCREEN_HEIGHT-4 ){
			resetEnemy(0);
			score++;
			updateScore();
		}
		if( enemyY[1] > SCREEN_HEIGHT-4 ){
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board()
{
    system("cls");
    cout << "\n\n.........................   CIRCLE or CROSS   .........................\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
int createZombie() {
    if (rand() % 67 < 10)
        return 11;
    else
        return rand() % 10 + 1;
}

int main()
{
	int u;
	Mainmenu:
	system("cls");
	cout<<"\n...........................WELCOME TO PLAYING STATION ..........................."<<endl;
	cout<<"\n   Here is the list of games you can play: \n\n     Single Player Games: \n       1. Car Game\n       2. Snake Game\n       3. Zombie Game\n\n     Multi-Player Games: \n       4. Circle or Cross\n\n   ENTER 0 IF YOU WANT TO EXIT\n"<<endl;
	cout<<"Enter your choice : ";
	cin>>u;
		if(u==1)
			{
					setcursor(0,0); 
	//srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |        Car Game        | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') goto Mainmenu;//exit(0);
		
	}while(1);
				goto Mainmenu;
			}
		else if(u==2)
			{
				cout<<"Basic Rules Before Playing : \n1. Do not touch the boundary \n2. Do not eat your self \nLoading..."<<endl;
				sleep(10);
				Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		//Sleep(10);
	}
	cout<<" GAME OVER ! \n Taking you back to the home screen..."<<endl;
	            sleep(10);
				goto Mainmenu;
			}
		else if(u==3)
			{
				//srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerSkill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;

    // title
    cout << "Welcome to Zombie War Game." << endl << "Press [ENTER] to start.";
    cin.get();

    // player name
    cout << "Please enter your name: ";
    cin >> playerName;

    // ask how many zombies
    cout << "How many zombies do you wish to fight? ";
    cin >> zombieCount;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (playerAlive && zombiesKilled < zombieCount) {
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 10) {
            cout << endl << "Here comes a huge zombie!" << endl;
        }
        else {
            cout << endl << "Here comes zombie " << zombiesKilled + 1 << endl;
        }

        cout << "Fighting..." << endl;
        sleep(2);

        // zombie killed the player
        if (playerSkill < zombieSkill) {
            playerAlive = false;
            cout << "You have died." << endl;
        }

        // player killed the zombie
        else {
            if (playerSkill - zombieSkill > 7) {
                cout << "You wasted the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 5) {
                cout << "You decapitated the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else if (playerSkill - zombieSkill > 0) {
                cout << "You killed the zombie!" << endl;
                playerScore = playerScore * 2;
            }

            else {
                cout << "You killed the zombie, but suffered injuries." << endl;
            }

            zombiesKilled++;
        }

        cout << endl;
        sleep(1);
    }

    // end game
    if (zombiesKilled == zombieCount) {
        // victory
        cout << "You have survived the onslaught!" << endl;
    }
    else {
        // lost
        cout << "You did not survive the zombie war." << endl;
    }

    cout << "Zombies killed: " << zombiesKilled << endl;
    cout << "Final score: " << playerScore << endl << endl;
    sleep(10);
				goto Mainmenu;
			}
		else if(u==4)
			{
				int player = 1,i,choice;

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    }while(i==-1);
    board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
				goto Mainmenu;
			}
		else if(u==0)
			{
				cout<<" IT WAS FUN PLAYING WITH YOU :) \n SEE YOU SOON ..... "<<endl;
				return 0;
			}
		else
			{
				cout<<"You selected none of the above :( "<<endl;
				goto Mainmenu;
			}		
}
