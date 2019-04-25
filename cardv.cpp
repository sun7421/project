#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
class twf
{
    public: 
    double cb,ca;
    char oper;
    double c1,c2,c3,c4;
    int ans,answer,x,j,k,l,e,A,B;
    vector<int>y;
    void input();
    void showque();
    void show();
    void shuffle();
    int randnum();
    void showcase();
    double calcu(double,char,double);
};
void twf::showque()
{
    show();
    shuffle();
    randnum();
    cout<<" = "<<ans<<endl;
}
        int twf::randnum()
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
        void twf::shuffle()
        {
            for (int i = 0; i < 4; i++)
            swap(y[i],y[rand()%4]);
                
        }
        void twf::show()
        {
            cout<<"I will show you a question\n";
            for(int i=0;i<4;i++)
            {
                y.push_back(rand()%99+1);
                cout<<y[i]<<" "<<endl;
            }
        }
 void twf::showcase()
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
void twf::input()
    {
    cin>>ca;
    cin>>oper;
    cin>>cb;
    calcu(ca,oper,cb);
    showcase();
    }

        double twf::calcu(double ca, char oper, double cb)
        {
            
            switch(oper)
            {
                case '+':
                    B=ca + cb;
                    return B;
                case '-':
                    B=ca - cb;
                    return B;
                case '*':
                    B=ca * cb;
                    return B;
                case '/':
                    B=ca / cb;
                    return B;
                default:
                    return 0;
            }
        }
        void twf::showcase()
        {
            cout<<B<<endl;
        }
    

int main()
{   
    twf a;
    a.showque();
    a.input();

}