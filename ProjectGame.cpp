#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mine"
#include "BJfull"
using namespace std;
    bool slot [22] = {};//เผื่อไว้
    int coin;//ว่าจะทำเป็น array แต่ติดตรงสวิตเคสว่าจรับค่าจากเจ้าของเทิร์นจะส่งค่ามายังไงเพราะตังมันมี4คน
    int starpos = 0;
    int turn=0;
    int x=0;
class player{
	string name;
	int pcoin,playerstar=0,position=0,preposition;
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
        void bank();
};

void player::getstar()
{
    playerstar++;
    pcoin-=10;
    spawnstar();
}
player::player(string n){
		name=n;
		pcoin=10;
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
};
void player::bank()
{
    if(preposition<pobank)
    {
        if(position>pobank)
            {   this->pcoin-1;
                x++;
            }
        else if (position=pobank)
            {
                this+x;
                x=0;
            }
    }
}

void player::sloteffect (){
    switch (position)
    {
        case 1:
            coin=coin-rand()%3;

            break;
        case 3:
            coin=coin-rand()%3;
            break;
        case 7:
            coin=coin-rand()%3;
            break;                
        case 12:
            coin=coin-rand()%3;
            break;
        case 15:
            coin=coin-rand()%3;
            break;
        case 18:
            coin=coin-rand()%3;
            break;        
        case 21:
            coin=coin-rand()%3;
            break;
        case 4:
            coin=coin+rand()%3;
            break;
        case 6:
            coin=coin+rand()%3;    
            break;    
        case 9:
            coin=coin+rand()%3;
            break;
        case 16:
            coin=coin+rand()%3;
            break;
        case 22:
            coin=coin+rand()%3;
            break;
        default:
            break;
    }
}
//ติดเรื่องตัง
void player::wintheminigame(){
    pcoin+=4;
}
void spawnstar()
{
    srand(time(0));
    starpos += (rand%24);
    ///ไม่แน่ใจว่าใช้ pointer ด้วยมั้ย
}
void player::goldenstar(){
        char staraction;
        if(preposition<starpos){
            if (position>=starpos)
            {
                cout << "You found a star!\n";
                if(pcoin<20)
                {
                    cout << "Oh no! insufficient coin to buy a star\n";
                }
                else
                {
                    while(true)
                    {
                        cout << "[B] Buy a star for 10 coins [S] Ignore star\n"
                        cin >> staraction;
                        if(toupper(staraction)=='B')
                            this->player.getstar();
                            break;
                        else if(toupper(staraction)!='S')
                            break;
                        else 
                            cout << "Invalid input! try again";
                    }
                }
            }
        }
            else
            {   
                if(starpos-position>0){
                    cout<<starpos-position<< " slots left to the star!" << endl;
                }
                else cout <<23-(position-starposition)<< " slots left to the star!" << endl;
            }
}

void printmap(){
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|-coin| | Not | |black| |-coin| |+coin| |mine | |-coin|\n";
    cout <<"|     | |Thing| |jack | |     | |     | |sweep| |     |\n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|mine |                                         | Not | \n";
    cout <<"|sweep|                                         |Thing| \n";
    cout <<" -----                                           ----- \n";
    cout <<"| Not |                                         |black| \n";
    cout <<"|Thing|                                         |jack | \n";
    cout <<" -----                                           ----- \n";
    cout <<"|+coin|                                         |-coin| \n";
    cout <<"|     |                                         |     | \n";
    cout <<" -----                                           ----- \n";
    cout <<"|black|                                         |+coin| \n";
    cout <<"|jack |                                         |     | \n";
    cout <<" -----                                           ----- \n";
    cout <<"|-coin|                                         |mine | \n";
    cout <<"|     |                                         |sweep| \n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
    cout <<"|+coin| |mine | |+coin| |-coin| |black| |-coin| |start|\n";
    cout <<"|     | |sweep| |     | |     | |jack | |     | |     |\n";
    cout <<" -----   -----   -----   -----   -----   -----   ----- \n";
}
void minigame(){
    int randminigame;
    randminigame=rand()%1
    switch (randminigame)
    {
        case 0:BJgame()
            break;
        case 1:game()
            break;
        default:
            break;
    }
}
void player::rollthedice(){
    char run;
    preposition=position;
    cout << "press r to roll the dice\n";
    cin>>run;
    if (run=='r'||run=='R') {
        int dice=rand()%6+1;
        cout <<"your roll dice is "<< dice;
        position+=dice;
        if(position>=23)position-=23;
        cout<<"\nyou position is " << position;
}

int main(){
    srand(time(0));
    string name;	
	cout << "Please input player1 name: ";
	getline(cin,name);	
	Player p1(name);
    cout << "Please input player2 name: ";
	getline(cin,name);	
	Player p2(name);
    cout << "Please input player3 name: ";
	getline(cin,name);	
	Player p3(name);
    cout << "Please input player4 name: ";
	getline(cin,name);	
	Player p4(name);
    while(!=p1.wincheck()||!=p2.wincheck()||!=p3.wincheck()||!=p4.wincheck()){
        spawnstar();
        printmap();
        if(turn%4==0){
            p1.showcoin();
            cout << "Star position is " << starpos << endl;
            p1.rollthedice();
            p1.sloteffect();
        }
        if(turn%4==1){
            p2.showcoin();
            cout << "Star position is " << starpos << endl;
        }
        if(turn%4==2){
            p3.showcoin();
            cout << "Star position is " << starpos << endl;
        }
        if(turn%4==3){
            p4.showcoin();
            cout << "Star position is " << starpos << endl;
        }
       goldenstar();
    }
}