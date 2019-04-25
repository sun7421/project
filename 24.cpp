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
    vector<int>y;
    void numb();
    void shuffle();
    void numbcal();
};
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
void number::numbcal()
{
    for(int i=0;i<4;i++)
   {    int j= i+1;int b;
        y[i]+y[j];
   }
}


int main()
{
    srand(time(0));
    return 0;
}
