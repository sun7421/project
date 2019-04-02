#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;

//vector<string> aic,p1c,p2c,p3c,p4c;
//int pcard[4][100],acard[100];
vector<int> aic,p1c,p2c,p3c,p4c;
string card[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cs[]={1,2,3,4,5,6,7,8,9,10,10,10,10},stay[4];

void drawcard(vector<int> &);
void gamestart();
//void insurance();
//void perfectpair();
void findaction(vector<int> &);
bool allstay(int []);
void findscore(vector<int> &,int &);
void change21(vector<int> &);
void scoreall(int []);
void checkwinner(int []);
void resetcard(vector<int> &);

int main()
{
    srand(time(0));
    p1c.push_back(1);
    p2c.push_back(2);
    p3c.push_back(3);
    p4c.push_back(4);

    int money[4],bet[4],sumcard[5]={};

    for(int i=0;i<4;i++)
    {
        money[i]=10000;
        cin >> bet[i];
        money[i]-=bet[i];
    }

    gamestart();
    //if(aic.at(0)=="A")
        //insurance();
    gamestart();

    //perfectpair();
    while(allstay(stay)!=true)
    {
        if(sumcard[0]<17)
        drawcard(aic);
        findaction(p1c);
        findaction(p2c);
        findaction(p3c);
        findaction(p4c);
    }

    scoreall(sumcard);
    checkwinner(sumcard);


    return 0;
}

void drawcard(vector<int> &x)
{
    x.push_back(rand()%13);
}

void gamestart()
{
    drawcard(aic);
    drawcard(p1c);
    drawcard(p2c);
    drawcard(p3c);
    drawcard(p4c);
}

/*void insurance()
{
    cout << "Dealer got an A card,\nDo you want to make an Insurance for half of your bet?";
    cin >> ans;
}*/

void findaction(vector<int> &x)
{
    int action;
    while(true)
    {
        cin >> action;
        if(action==1){
            drawcard(x);
            break;
        }
        else if(action==2){
            stay[x[0]]=1;
            break;
        }
        else
            cout << "Please in put again.../n";
    }
}

bool allstay(int stay [])
{
    for(int i=0;i<4;i++)
    {
        if(stay[i]==0);
        return false;
    }
    return true;
}

void findscore(vector<int> &x,int &score)
{
    int sumscore=0;
    for(int i=1;i<x.size();i++)
    {
        if(x[i]==1 && score>21)
            sumscore+=11;
        else
            sumscore+=cs[x[i]];
    }
    score=sumscore;
}

void change21(vector<int> &x,int &score)
{
    if(score>21)
        findscore(x,score);
}

void scoreall(int sumcard [])
{
    findscore(aic,sumcard[0]);
    findscore(p1c,sumcard[1]);
    findscore(p2c,sumcard[2]);
    findscore(p3c,sumcard[3]);
    findscore(p4c,sumcard[4]);
    change21(p1c,sumcard[1]);
    change21(p2c,sumcard[2]);
    change21(p3c,sumcard[3]);
    change21(p4c,sumcard[4]);
}

void cheackwinner(int sumcard [])
{
    int winnerscore,N=0;
    vector<int> winrightnow;
    winnerscore=sumcard[0];
    winrightnow[N]=0;
    for(int i=0;i<4;i++)
    {
        if(sumcard[i]>winnerscore)
        {
            winnerscore=sumcard[i];
            winrightnow[N]=i;
        }
        else if(sumcard[i]==winrightnow && winrightnow!=0;)
        {
            winrightnow[N]=i;
        }
        else if(sumcard[i]==winrightnow)
        {
            N++
            winrightnow[N]=i;
        }
    }

    if(winrightnow=5)
    cout << "Match Draw!! with player";
    for(int i=0;i<)
    //cout << "Player " << winrightnow << "won !! with score" << winnerscore;
}

void resetcard(vector<string> &x)
{
    for(int i=0;i<x.size();i++)
        x.pop_back();
}
