#include<iostream>
#include <cstdlib>
#include <ctime>
#include "minesweper.h"
#include "BJgame.h"
#include "cardnaango.h"
using namespace std;
    bool slot [22] = {};
    int coin;
    int starpos = 0;
    int mainturn=0;
    void spawnstar();
    int preposition;
    int money_bank;
    int randminigame;
class player{
	string name;
	int pcoin;
    int playerstar;
    int position;
	public:
		player(string);
		void showcoin();
        void wintheminigame();
        void goldenstar();
        void newturn();
		bool wincheck();
        void getstar();
        void sloteffect ();
        void rollthedice();
        void toss();
        void badslot();
        void goodslot();
        void bank();
        void playgame();
};

void player::getstar()
{
    playerstar++;
    pcoin-=20;
    spawnstar();
}
player::player(string n){
		name=n;
		pcoin=10;
        playerstar =0;
        position=0;
	}
    void player::showcoin(){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "COIN: " << pcoin<<"\tSTAR: "<<playerstar;		
		cout << "\n---------------------------------------\n";
	}	
	
    bool player::wincheck(){
		if(playerstar==3)return true;
        else return false;
}

void player::sloteffect (){
    switch (position)
    {
        case 1:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;
        case 3:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;
        case 7:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;                
        case 12:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;
        case 15:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;
        case 18:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;        
        case 21:
            cout << "you lose coin";
            pcoin=pcoin-rand()%4;
             if(pcoin<=0) pcoin = 0;
            cout<< "total coin = " << pcoin;
            break;
        case 4:
            cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;
        case 6:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;    
            break;    
        case 9:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;
        case 14:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 16:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;
        case 22:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;
        case 17:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 8:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 10:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 20:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 23:
        cout << "you get 3 coin";
            pcoin=pcoin+3;
            cout<< "total coin = " << pcoin;
            break;    
        case 5:
            goodslot();
            break;    
        case 11:
            badslot();
            break;
        case 2:
            toss();
            break;
        case 19:
            toss();
            break;    
        case 13:
            cout<<"you get "<<money_bank<<"coin";
            pcoin+=money_bank;
            money_bank=0;
            cout<< "total coin = " << pcoin;
            default:
                    break;
    }
}
void player::wintheminigame(){
    pcoin+=5;
}
void spawnstar()
{
    srand(time(0));
    starpos = rand()%8+6;
}
void player::goldenstar(){
        char staraction;
        if(preposition<starpos && position>=starpos){
                cout << "You found a star!\n";
                if(pcoin<20)
                {
                    cout << "Oh no! insufficient coin to buy a star\n";
                }
                else
                {
                    do
                    {
                        cout << "[B] Buy a star for 10 coins [S] Ignore star\n";
                        cin >> staraction;
                        if(toupper(staraction)=='B')
                            getstar();
                        else if(toupper(staraction)=='S')staraction='S';
                        else cout << "Invalid input! try again";
                    }while(staraction!='B'&&staraction!='S'&&staraction!='b'&&staraction!='s');
                    
                }
            }
            else
            {   
                if(starpos-position>0){
                    cout<<starpos-position<< " slots left to the star!" << endl;
                }
                else cout <<23-(position-starpos)<< " slots left to the star!" << endl;
            }
}
void printmap(){
  cout <<"\n -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|-coin| |bank | |+coin| |-coin| |+coin| |+coin| |-coin|\n";
    cout <<"|     | |     | |     | |     | |     | |     | |     |\n";
    cout <<"| [12]| | [13]| | [14]| | [15]| | [16]| | [17]| | [18]|\n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|bad  |                                         |toss | \n";
    cout <<"|slot |                                         |coin | \n";
    cout <<"| [11]|                                         | [19]| \n";
    cout <<" -----                                           ----- \n";
    cout <<"|+coin|                                         |+coin| \n";
    cout <<"|     |                                         |     | \n";
    cout <<"| [10]|                                         | [20]| \n";
    cout <<" -----                                           ----- \n";
    cout <<"|+coin|                                         |-coin| \n";
    cout <<"|     |                                         |     | \n";
    cout <<"| [9] |                                         | [21]| \n";
    cout <<" -----                                           ----- \n";
    cout <<"|+coin|                                         |+coin| \n";
    cout <<"|     |                                         |     | \n";
    cout <<"| [8] |                                         | [22]| \n";
    cout <<" -----                                           ----- \n";
    cout <<"|-coin|                                         |+coin| \n";
    cout <<"|     |                                         |     | \n";
    cout <<"| [7] |                                         | [23]| \n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|+coin| |good | |+coin| |-coin| |toss | |-coin| |start|\n";
    cout <<"|     | |slot | |     | |     | |coin | |     | |     |\n";
    cout <<"| [6] | | [5] | | [4] | | [3] | | [2] | | [1] | | [0] |\n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
}
void minigame(){
    randminigame=rand()%3;
    switch (randminigame)
    {
        case 0:BJgame();
            break;
        case 1:game();
            break;
        case 2:naango();
            break;
        default:
            break;
    }
}
void player::rollthedice(){
    string run;
    cout<<"your position is "<<position<<"\n";
    cout << "press any word to roll the dice\n";
    cin>>run;
        int dice=rand()%6+1;
        preposition = position;
        cout <<"your roll dice is "<< dice;
        position+=dice;
        if(position>=23)position-=23;
        cout<<"\nyou position is " << position <<"\n";
}
void player::badslot(){
    string anykey;
    int destiny;
    cout << "Press you lucky word\n";
    cin>>anykey;
    destiny=rand()%5;
    switch (destiny)
    {
        case 0:
            cout << "you loose nothing\n" ;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;
        case 1:
            cout << "you loose 20 coin\n" ;
            pcoin -= 20;
            if(pcoin<=0) pcoin = 0;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;
        case 2:
            pcoin -= 100;
            if(pcoin<=0) pcoin = 0;
            cout << "you lose 100 coin\n" ;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;  
        case 3:
            cout << "you lose one star\n" ;
            playerstar -= 1;
            if(playerstar<=0) playerstar = 0;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;      
        case 4:
            cout << "you loose two star\n" ;
            playerstar -= 2;
            if(playerstar<=0) playerstar = 0;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;
        default:
            break;
    }
}
void player::toss(){
    int bet,HT,ran;
    ran=rand()%2;
    cout << "Enter your Bet : " ;
    cin >> bet;
    do
    {
        cout << "choose your destiny drawwwwwww : ";
    cout << "[0]choose Head [1] choose Tail\n" ;
    cin >> HT;
        
    } while (HT!=0&&HT!=1);
    
    if(HT==ran){
        cout << "you got coin = " << bet*2;
        pcoin+=bet*2;
        cout << "you total coin = " << pcoin;
    }else
    {
        cout << "you loose coin = " << bet;
        pcoin-=bet;
        cout << "you total coin = " << pcoin;
    }
}
void player::goodslot(){
    string anykey;
    int destiny;
    cout << "Press you lucky word\n";
    cin>>anykey;
    destiny=rand()%4;
    switch (destiny)
    {
        case 0:
            cout << "you get nothing\n" ;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;
        case 1:
            cout << "you get 20 coin\n" ;
            pcoin += 20;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;
        case 2:
            pcoin += 10;
            cout << "you get 10 coin\n" ;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;  
        case 3:
            cout << "you get one star\n" ;
            playerstar += 1;
            cout << "coin = " << pcoin << " star = " << playerstar;
            break;      
        
        default:
            break;
    }
}
void player::bank(){
    if(preposition<13 && position>13){
        money_bank++;
        pcoin--;
        cout<<"you loss 1 coin to bank\n";
    }
}
void player::playgame(){
    showcoin();
    cout << "Star position is " << starpos << endl;
    rollthedice();
    goldenstar();
	bank();
    sloteffect();
}
