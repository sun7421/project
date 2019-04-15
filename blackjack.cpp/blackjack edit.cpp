#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
class Player
    {
        int score;
        int bet;
    public:
        string playername;
        vector<int> playercard;
        int money;
        int firstbet();
        int doubledeal();
        int insurance();
        //int perfectpair();
        //int betbehind();
    };

class dealer
    {
        public:
            vector<int> dealercard;
            int dmoney;
    };
class allcard
    {
        string card[]={ "s","A","2","3","4","5","6","7","8","9","10","J","Q","K"};


    public:
    vector<int>scorecard;
    allcard(vector<int>);
    int round=1;
    void cardscore();
    void drawcard(vector<int> &);
    void checkcard();
    vector<int> scorecards(vector<int>);
    void blackjack();
    };

int Player::firstbet()
{
    cin>>money;
    cin>>bet;
    money-=bet;
}
int doubledeal()
{
    bet*=2;
}
int Player::insurance()
{
    int insbet;
    cin>>insbet;
    if(dealercard[0]+dealercard[1]==21)
    {
        money+=insbet;
        cout << "Dealer got a blackjack"
    }
    else
    {
        money-=insbet;
        cout << "Dealer didn't got a blackjack"
    }
    
}
int perfectpair()
{
    if(playercard[0]==playercard[1])
    {
        cout << "Perfect pair victory!!";
        money+=bet*4;
    }
}
int split()
{
    if(playercard[0]==playercard[1])
    {
        playercard.pop_back();
    }
}
/*int betbehind()
{

}*/


vector<int> allcard ::scorecards(vector <int>playercard)
{
        for(int i=0; i<playercard.size(); i++)
         scorecard.push_back(playercard[i]);
         return scorecard;
}

allcard::allcard(vector<int>x)
{

}

void allcard :: drawcard(vector<int> &x)
{

            if(round==1)
            {
            for(int i=0;i<2;i++)
            {
                x.push_back(rand()%13+1);
            }
            round++;
            }
        else
            {
            x.push_back(rand()%13+1);
            }
}

void allcard :: cardscore()
{


            /*if(a[0]==card[1]&&a[1]==card[9]||a[0]==card[1] && a[1]==card[11])
            {
                card[1]=11;
            }
            else if (a[1]==card[1]&&a[0]==card[9]||a[1]==card[1] && a[0]==card[11])
            {
            card[1]=11;
            }
            else {card[1]=1;}*/
            for(int i=2;i<10;i++)
        {
            card[i]=i;
            }
            for(int j=11;j<14;j++)
            {
                card[j]=10;
            }

}

void allcard ::blackjack()
{
    if(this->playercard[0]+this->playercard[1]==21)
    {
                        cout>>"Blackjack";

                    }

    return 0;
}


int main()
{
    Player player[4];
    cout<< scorecard[1];     /*Player p[4];
   /*for(int i=0;i<2;i++)
   {
        for(int j=0;j<4;j++)
        [
            p[j].drawcard(p[j].playercard);
        ]
   }
        */
}
