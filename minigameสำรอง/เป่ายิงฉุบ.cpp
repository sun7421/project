#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
class player
{
     vector<string> z;
    public:
    char bot[10];
    char player1[10];
    void chub();
    void check();
    void bot1();
};
void player:: bot1()
{   
    z.push_back("scissors");
    z.push_back("paper");
    z.push_back("rock");
    string a  = z[rand()%3];
    char char_array[ a.length()+ 1];
    strcpy(char_array, a.c_str());
    strcpy(bot,char_array) ;
    cout<<"bot= "<<bot<<"\n";
}
void player:: chub()
{
    cout<<"choose paper,scissors or rock :";
        scanf("%s" ,player1);
}
void player:: check()
{
        if(!strcmp(bot,player1))
            {cout<<"Draw\n";}
         else if(!strcmp("paper",player1))
            {
                    if(!strcmp("rock",bot))
                    cout<<"player1 win\n";
                    else cout<<"bot win\n";
            }
         else if(!strcmp("scissors",player1))
            {
                    if(!strcmp("paper",bot))
                    cout<<"player1 win\n";
                    else  cout<<"bot win\n";
            }
         else if(!strcmp("rock",player1))
            {
                    if(!strcmp("paper",bot))
                    cout<<"bot win\n";
                    else cout<<"player1 win\n";
            }
        
    }
    int main()
    {
        srand(time(0));
        player a;
        a.chub();
        a.bot1();
        a.check();
        return 0;
    }

