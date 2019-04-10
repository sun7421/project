#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
using namespace std;
class Player
    {
        int score;
    public:
        string playername;
        vector<int> playercard;
    };
    
    
class dealer
    {
        
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
