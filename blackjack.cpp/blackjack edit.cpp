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
{   int round=1;
    string card[]={ "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
public: 
void cardscore(string);
void drawcard(vector<int> &);

};
class rule
{

};
void card :: drawcard(vector<int> &x)
{   
    if(round==1)
    {
    for(int i=0;i<2;i++)
        {
  x.push_back(rand()%13);
        }
    }
}
int main()
{


}
