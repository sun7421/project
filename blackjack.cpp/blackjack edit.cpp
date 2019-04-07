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
   
};
class dealer
{
    
};
class card
{   
    string card[]={ "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
public: 
int round=1;
void cardscore(string);
void drawcard(vector<int> &);

};
class rule
{

};
void card :: drawcard(vector<int> &x)
{   
    int a;
    if(round==1)
    {
    for(int i=0;i<2;i++)
        {
  x.push_back(rand()%13);
        a=x;
        }
        round++;
    }
     else
    {
        x.push_back(rand()%13);
    }
}
int main()
{


}
