#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
class number
{
    public: 
    int x; 
    int answer;
    int ans;
    vector<int>y;
    void numb();
    void shuffle();
    int numbcal();
    void solution();
    void Checkwin();
};
void number::Checkwin()
{   
    char t;
        cout<< "Show your knowledge please?\n";
        cout<<"Your answer is? = ";
        cin>>answer;
        for(int i=0;i<1;i++)
        {
            if(answer=ans)
            {cout<<"You so genius";}
            else 
            {   
                cout<< "ํYou are stupid";
               for(int j=0;j<1;j++)
               {
                cout<<"Stupid do you want a solution? (yes or no ): ";
                cin>> t;
                if(t='yes'||'Yes'){cout<< "if your brain is a superhero ,You are a invisibleman\n"<<solution;}
                else if (t='no'||'No'){i=0;}
                else {cout<<"Invalid";j=0;}
               }

            }
        }

}
void number::solution()
{





}
void number::numb()
{
 for(int i=0;i<4;i++)
    {   y.push_back(rand()%99+1);
        cout<<y<<" ";
    }
}
void number::shuffle()
{
	for (int i = 0; i < 4; i++)
    {
        swap(y[i],y[rand()%4]);
    }
}
int number::numbcal()
{   
    int j,k,l;
    int i = rand()%4;
    ans=0;
    if(i=0){ j= i+1; k=i+2;l=i+3;}
    else if (i=1){ j= i-1; k=i+1;l=i+2;}
    else if (i=2){ j= i-2; k=i-1;l=i+1;}
    else if (i=3){ j= i-3; k=i-2;l=i+1;}
    switch (rand()%4)
    {
        case 1: ans=((y[l]*y[i])+y[j])-y[k];
            return ans;
        case 2:  ans=((y[i]+y[l])*y[k])-y[j];
            return ans;
        case 3: ans=((y[i]-y[l])*y[j])-y[k];
            return ans;
        case 4:ans=((y[j]+y[k])*y[l])-y[i];
            return ans;
    }
   
   }


int main()
{
    srand(time(0));
    return 0;
}
