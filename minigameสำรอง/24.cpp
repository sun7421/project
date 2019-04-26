#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
class number
{
    public: 
    int x,j,k,l,e;
    int A;
    int ans;
    int answer;
    vector<int>y;
    void numb();
    void shuffle();
    int numbcal();
    void giveque();
    void Checkwin();
};

void number::Checkwin()
{
    string t;
        cout<< "\nShow your knowledge please?\n";
        
        for(int i=0;i<1;)
        {cout<<"Your answer is? = ";
        cin>>answer;

            if(ans==answer)
            {cout<<"You so genius\n";break;}
            
            else
            {
                cout<< "You are stupid\n";
                i++;
               for(int j=0;j<1;)
               {
                cout<<"Stupid do you want a solution? (yes or no ): ";
                cin>> t;
                j++;
                if(t=="yes"||t=="Yes")
                {
                cout<< "if your brain is a superhero ,You are a invisibleman\n";
                giveque();
                cout << ans << endl;
                }
                else if (t=="no"||t=="No"){i=0;}
                else {cout<<"Invalid\n";j=0;}
               }

            }
        }

}
void number::giveque()
{
    switch (A)
    {
        case 1: 
        cout <<  " ((" << y[l] <<" * " << y[e] << ") + " << y[j] <<") - " << y[k]<<"= ";
        break;
        case 2:
        cout << " ((" << y[e] <<" + " << y[l] << ") * " << y[k] <<") - " << y[j]<<"= ";
        break;
        case 3: 
        cout <<  " ((" << y[e] <<" - " << y[l] << ") * " << y[j] <<") - " << y[k]<<"= ";
        break;
        case 4:
        cout << " ((" << y[j] <<" + " << y[k] << ") * " << y[l] <<") - " << y[e]<<"= ";
        break;
    }



}
void number::numb()
{
    cout<<"I will show you a question\n";
    for(int i=0;i<4;i++)
       y.push_back(rand()%99+1);
}
void number::shuffle()
{
	for (int i = 0; i < 4; i++)
        swap(y[i],y[rand()%4]);
}
int number::numbcal()
{
    A = rand()%4+1;
    e = rand()%4;
    ans=0;
    if(e==0){ j= e+1; k=e+2;l=e+3;}
    else if (e==1){ j= e-1; k=e+1;l=e+2;}
    else if (e==2){ j= e-2; k=e-1;l=e+1;}
    else if (e==3){ j= e-3; k=e-2;l=e+1;}
    switch (A)
    {
        case 1: ans=((y[l]*y[e])+y[j])-y[k];
            return ans;
        case 2:  ans=((y[e]+y[l])*y[k])-y[j];
            return ans;
        case 3: ans=((y[e]-y[l])*y[j])-y[k];
            return ans;
        case 4:ans=((y[j]+y[k])*y[l])-y[e];
            return ans;
    }

}


int main()
{
    srand(time(0));
    number a;
    a.numb();
    a.shuffle();
    a.numbcal();
    a.giveque();
    a.Checkwin();


    return 0;
}
