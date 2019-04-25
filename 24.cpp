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
    int A=rand()%4+1; 
    int ans;
    vector<int>y;
    void numb();
    void shuffle();
    int numbcal();
    void solution();
};
void number::solution(int a)
{
    switch (A)
    {
        case 1: 
        cout << ans << " = ((" << y[l] <<" * " << y[i] << ") + " << y[j] <<") - " << y[k];
        break;
        case 2:
        cout << ans << " = ((" << y[i] <<" + " << y[l] << ") * " << y[k] <<") - " << y[j];
        break;
        case 3: 
        cout << ans << " = ((" << y[i] <<" - " << y[l] << ") * " << y[j] <<") - " << y[k];;
        break;
        case 4:
        cout << ans << " = ((" << y[j] <<" + " << y[k] << ") * " << y[l] <<") - " << y[i];
        break;
    }



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
    switch (A)
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
