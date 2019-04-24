#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mine"
#include "BJfull"
using namespace std;
    bool slot [22] = {};//เผื่อไว้
    int coin;//ว่าจะทำเป็น array แต่ติดตรงสวิตเคสว่าจรับค่าจากเจ้าของเทิร์นจะส่งค่ามายังไงเพราะตังมันมี4คน
    int position=0 ;
    int starpos = 0;
    int turn=0;
class game{
    player *player;
    public:
        void wintheminigame(player *);
        void goldenstar(player *a);
        void newturn();
		bool wincheck(player *);
        void getstar(player *);
        void minigame();
        void sloteffect (player *);
}
class player{
	string name;
	int coin,playerstar=0;
	public:
		player(string);
		void showcoin();
};

void game::getstar(player *a)
{
    a->playerstar++;
    a->coin-=10;
    spawnstar();
}
player::player(string n){
		name=n;
		coin=10;
	}
    void player::showcoin(){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "COIN: " << coin<<"\tSTAR: "<<star;		
		cout << "\n---------------------------------------\n";
	}	
	
    bool player::wincheck(player *a){
		if(a->playerstar==3)return true;
		else return false;
};

void game::sloteffect (player *a){
    switch (p)
    {
        case 1:
            a->coin=a->coin-rand()%3;
            break;
        case 3:
            a->coin=a->coin-rand()%3;
            break;
        case 7:
            a->coin=a->coin-rand()%3;
            break;                
        case 12:
            a->coin=a->coin-rand()%3;
            break;
        case 15:
            a->coin=a->coin-rand()%3;
            break;
        case 18:
            a->coin=a->coin-rand()%3;
            break;        
        case 21:
            a->coin=a->coin-rand()%3;
            break;
        case 4:
            a->coin=a->coin+rand()%3;
            break;
        case 6:
            a->coin=a->coin+rand()%3;    
            break;    
        case 9:
            a->coin=a->coin+rand()%3;
            break;
        case 16:
            a->coin=a->coin+rand()%3;
            break;
        case 22:
            a->coin=a->coin+rand()%3;
            break;
        default:
            break;
    }
}
//ติดเรื่องตัง
void game::wintheminigame(player *a){
    a->coin+=4;
}
void spawnstar()
{
    srand(time(0));
    starpos += (rand%24)+1;
    ///ไม่แน่ใจว่าใช้ pointer ด้วยมั้ย
}
void game::goldenstar(player *a){
        char staraction;
            if (position>=starpos)
            {
                cout << "You found a star!\n";
                if(coin<10)
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
            else
            {
                cout << starpos-position << " slots left to the star!" << endl;
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
void game::minigame(){
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

int main(){
    srand(time(0));
    string name;	
	cout << "Please input player1 name: ";
	getline(cin,name);	
	Player player1(name);
    cout << "Please input player2 name: ";
	getline(cin,name);	
	Player player2(name);
    cout << "Please input player3 name: ";
	getline(cin,name);	
	Player player3(name);
    cout << "Please input player4 name: ";
	getline(cin,name);	
	Player player4(name);
    while(!=wincheck(&player1)||!=wincheck(&player2)||!=wincheck(&player3)||!=wincheck(&player4)){
        char run='r';
        spawnstar();
        printmap();
        cout << "Star position is " << starpos << endl;
        cout << "press r to roll the dice\n";
        cin>>run;
        if (run=='r'||run=='R') {
            int dice=rand()%6+1;
            cout <<"your roll dice is "<< dice;
        // changeposition (dice);
            position+=dice;
            cout<<"\nyou position is " << position;
            sloteffect(position);
            cout <<"\ncoin= "<< coin;
            goldenstar();
            }
    }
}
