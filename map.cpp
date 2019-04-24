#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
    bool slot [22] = {};//เผื่อไว้
    int coin;//ว่าจะทำเป็น array แต่ติดตรงสวิตเคสว่าจรับค่าจากเจ้าของเทิร์นจะส่งค่ามายังไงเพราะตังมันมี4คน
    int position=0 ;
    int starpos = 0;

/*class Player{
    int playerstar=0;
    int coin=0;
    public:
        void getstar();
    ///อันนี้จะรวมกับโค้ด player
}*/

void Player::getstar()
{
    playerstar++;
    coin-=10;
    if(coin<0)
    coin=0;
    spawnstar();
}

void sloteffect (int p){
    switch (p)
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
        case 6:
            coin=coin+rand()%3;    
            break;    
        case 9:
            coin=coin+rand()%3;
        case 16:
            coin=coin+rand()%3;
        case 22:
            coin=coin+rand()%3;
        default:
            break;
    }
}
//ติดเรื่องตัง
void wintheminigame(int player){
    coin=coin+4;
}
void spawnstar()
{
    srand(time(0));
    starpos += (rand%6)+6;
    ///ไม่แน่ใจว่าใช้ pointer ด้วยมั้ย
}
void goldenstar(){
        char staraction;
        if (position>=starpos)
        {
            cout << "You found a star!\n";
            if(coin<=10)
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

int main(){
    char run='r';
    srand(time(0));
    spawnstar();
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
    cout << "Star position is " << starpos << endl;
    cout << "press r to roll the dice\n";
    cin>>run;
        if (run=='r') {
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
