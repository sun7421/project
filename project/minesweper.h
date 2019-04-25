#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include <time.h>

using namespace std;

void reveal(int, int);
void create_mine_positions(); 
void cell_number();
void create_table();
void open_cell();
void game(); 
void print_table(char);

char table[4][4];
char table_mine_positions[4][4];
int miturn=0;
int dead_counter=0;
int flag_counter=0;
int mines_flagged_counter=0;
bool game_lose_p1=false;
bool game_lose_p2=false;
bool game_lose_p3=false;
bool game_lose_p4=false;
time_t time_since_epoch = time(0);
time_t game_time;

void cell_number(int i,int j)
{
if(i>=0&&i<4&&j>=0&&j<4&&table_mine_positions[i][j]!='X')
table_mine_positions[i][j]++;
}

void create_mine_positions()
{
int counter=0;
srand(time(NULL));

for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            table_mine_positions[i][j]='0';

        int i=0;
        int j=0;
 while(counter<3)
    {
        int i=rand()%4;
        int j=rand()%4;
        if(table_mine_positions[i][j]=='0'){
            table_mine_positions[i][j]='X';
            counter++;
        }
    }
}

void create_table()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            table[i][j]='*';
}

void print_table(char arr[4][4])
{
    cout<<"    ";
    for(int i=0;i<4;i++)
        cout<<setw(3)<<i;

    cout<<endl<<"  ";
    for(int i=0;i<32;i++)
        cout<<"_";
        cout<<endl;

    for(int i=0;i<4;i++){
            cout<<setw(3)<<i<<"|";
        for(int j=0;j<4;j++)
            cout<<setw(3)<<arr[i][j];
            cout<<endl;
    }
}

void open_cell(int turn)
{
int i,j;

do
cin>>i>>j;
while(i<0||i>3||j<0||j>3);

if(table_mine_positions[i][j]=='X')
    {
        table[i][j]='X';
        if(turn%4==0){
			game_lose_p1=true;
			dead_counter++;
		}
        else if(turn%4==1){
			game_lose_p2=true;
			dead_counter++;
		}
        else if(turn%4==2){
			game_lose_p3=true;
			dead_counter++;
		}
        else if(turn%4==3){
			game_lose_p4=true;
			dead_counter++;
		}
    }
    else
        reveal(i,j);
}

void reveal(int i,int j)
{
if (table[i][j]=='*'&&table_mine_positions[i][j]!='X'&&i>=0&&i<4&&j>=0&&j<4)
    {
    table[i][j]=table_mine_positions[i][j];
    }
}

void game()
{
    game_lose_p1=false;
    game_lose_p2=false;
    game_lose_p3=false;
    game_lose_p4=false;
    cout
    <<"Rules:"
    <<endl<<"Enter value of i and j to open cell[i][j]."
    <<endl<<endl;
    create_table();
    create_mine_positions();

	while(dead_counter!=3)
    {
    game_time=time(0);
    print_table(table);
    if(miturn%4==0)cout<<"Turn P1:";
    else if(miturn%4==1)cout<<"Turn P2:";
    else if(miturn%4==2)cout<<"Turn P3:";
    else if(miturn%4==3)cout<<"Turn P4:";
    open_cell(miturn);
    miturn++;
    if(game_lose_p1&&miturn%4==0){
	miturn++;
    }
    if(game_lose_p2&&miturn%4==1){
	miturn++;
    }
    if(game_lose_p3&&miturn%4==2){
	miturn++;
    }
    if(game_lose_p4&&miturn%4==3){
	miturn++;
    }
	}
    if(game_lose_p1&&game_lose_p2&&game_lose_p3){
    	print_table(table);
    	cout<<endl<<"PLAYER 4 WIN!!!"<<endl;
    }
    else if(game_lose_p1&&game_lose_p2&&game_lose_p4){
    	print_table(table);
    	cout<<endl<<"PLAYER 3 WIN!!!"<<endl;
    }
	else if(game_lose_p1&&game_lose_p3&&game_lose_p4){
    	print_table(table);
    	cout<<endl<<"PLAYER 2 WIN!!!"<<endl;
    }
	else if(game_lose_p2&&game_lose_p3&&game_lose_p4){
    	print_table(table);
    	cout<<endl<<"PLAYER 1 WIN!!!"<<endl;
    }

}