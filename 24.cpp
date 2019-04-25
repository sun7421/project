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
    int A;
    for(int i=0;i<3;i++)
   {    int j= i+1;int k=i+2;int l=i+3;
        switch (A)
            case 1: ((y[l]*y[i])+y[j])-y[k];
            case 2:  ((y[i]+y[l])*y[k])-y[j];
            case 3: ((y[i]-y[l])*y[j])-y[k];
            case 4:((y[j]+y[k])*y[l])-y[i];
   }
}


int main()
{
    srand(time(0));
    return 0;
}
