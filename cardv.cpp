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
    string dore;
    double c1,c2,c3,c4;
    vector<int>z;
    int ans,answer,x,j,k,l,e,A,B;
    vector<int>y;
    void input();
    void showque();
    void show();
    void shuffle();
    int randnum();
    void showcase();
    void answers();
    void next2();
    void how2win();
    void resign();
    void input2();
    void save();
    void copyshow();
    double calcu(double,char,double);
    
};
void twf::showque()
{
    show();
    shuffle();
    randnum();
     copyshow();
    cout<<" = "<<ans<<" (You can't do it to 0)"<<endl;

}
        int twf::randnum()
        {
            A = rand()%4+1;
            e = rand()%4;
            ans=0;
            if(e==0){ j= e+1; k=e+2;l=e+3;}
            else if (e==1){ j= e-1; k=e+1;l=e+2;}
            else if (e==2){ j= e-2; k=e-1;l=e+1;}
            else if (e==3){ j= e-3; k=e-2;l=e-1;}
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
        void twf::copyshow()
        {
            c1=y[e];
            c2=y[l];
            c3=y[j];
            c4=y[k];
        }
        void twf::shuffle()
        {
            for (int i = 0; i < 4; i++)
            swap(y[i],y[rand()%4]);
                
        }
        void twf::save()
        {
            for(int i=0;i<4;i++)cout <<z[i]<<" ";
        }
        void twf::show()
        {
            srand(time(0));
            cout<<"I will show you a question\n";
                for(int i=0;i<4;i++)  y.push_back(rand()%9+1);
                        for(int h=0;h<4;h++)
                        {
                        for(int j=h+1;j<6;)
                            {
                                j++;
                            if(y[h]==y[j])
                                {
                                    y.erase(y.begin()+j);
                                    y.push_back(rand()%9+1);
                                    j--;
                                }
                            }  
                        } 
                        for(int i=0;i<4;i++){cout <<y[i]<<" ";z.push_back(y[i]);}
                    
        }
        
    
 void twf::answers()
        {

            switch (A)
            {
                case 1: 
                cout <<  " ((" << c2 <<" * " << c1 << ") + " << c3 <<") - " << c4<<" = ";
                break;
                case 2:
                cout << " ((" << c1 <<" + " << c2 << ") * " << c4 <<") - " << c3<<" = ";
                break;
                case 3: 
                cout <<  " ((" << c1 <<" - " << c2 << ") * " << c3 <<") - " << c4<<" = ";
                break;
                case 4:
                cout << " ((" << c3 <<" + " << c4 << ") * " << c2 <<") - " << c1<<" = ";
                break;
            }
        }
void twf::input()
    {
        for(int i=0;i<1;)
   {
        i++;
        cout<<"input firstnum only ("<<y[e]<<","<<y[j]<<","<<y[k]<<","<<y[l]<<")\n";
        cin>>ca;
        if(ca==0){cout<<"invalid";i--;}
        else if(ca==y[e]||ca==y[j]||ca==y[k]||ca==y[l]) break;
        else
            {
                cout<<"invalid";
                i--;
            }
   }
     for(int i=0;i<1;)
   {
        i++;
        cout<<"input operator only (+,-,*,/)\n";
        cin>>oper;
        if(oper== '+'||oper== '-'||oper== '*'||oper== '/') break;
        else {
                cout<<"invalid";
                i--;
             }
   }
     for(int i=0;i<1;)
   {
        i++;
         cout<<"input secondnum only ("<<y[e]<<","<<y[j]<<","<<y[k]<<","<<y[l]<<") (*except "<<ca<<")\n";
         cin>>cb;
         if(cb==0){  cout<<"invalid"; i--;}
        else if(cb==y[e]||cb==y[j]||cb==y[k]||cb==y[l])break;
        else {
                cout<<"invalid";
                i--;
             }
        
   }
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
            cout<<ca<<oper<<cb<<" = "<<B<<endl;
        }
void twf::input2()
{
for(int i=0;i<1;)
   {
        i++;
        cout<<"input firstnum only ("<<y[e]<<","<<y[j]<<","<<y[k]<<","<<y[l]<<")(*except 0)\n";
        cin>>ca;
        //if(ca==0){cout<<"invalid ";i--;}
         if(ca==y[e]||ca==y[j]||ca==y[k]||ca==y[l]) break;
        else
            {
                cout<<"invalid ";
                i--;
            }
   }
     for(int i=0;i<1;)
   {
        i++;
        cout<<"input operator only (+,-,*,/)\n";
        cin>>oper;
        if(oper== '+'||oper== '-'||oper== '*'||oper== '/') break;
        else {
                cout<<"invalid ";
                i--;
             }
   }
     for(int i=0;i<1;)
   {
        i++;
         cout<<"input secondnum only ("<<y[e]<<","<<y[j]<<","<<y[k]<<","<<y[l]<<") (*except "<<ca<<",0)\n";
         cin>>cb;
        // if(cb==ca||cb==0){  cout<<"invalid "; i--;}
         if(cb==y[e]||cb==y[j]||cb==y[k]||cb==y[l])break;
        else {
                cout<<"invalid ";
                i--;
             }
        
   }
    calcu(ca,oper,cb);
    showcase();
}
void twf::next2()
{
    for(int i=0;i<4;i++)
    {if(ca==y[i])y[i]=B;
    }
    for(int j=0;j<4;j++)
    {if(cb==y[j])y[j]=0;}
    for(int k=0;k<4;k++)
    cout<<y[k]<<" ";
    input2();
}
void twf ::how2win()
{
    if(B==ans){cout<<"You are inteligent";}
    else {
            //for(int j=0;j<1;)
           // {
                //j++;
                cout<< "Your answer is wrong\n";resign();
                /*<<"Do it again or resigned(do,re)= ";
                cin>>dore;
                   /* if(dore=="do"||dore=="DO"||dore=="Do"||dore=="dO")
                    {
                        save(); input();next2();next2();next2();how2win();
                    }
                    else if(dore=="re"||dore=="RE"||dore=="Re"||dore=="rE"){resign();}
                    else {cout<<"Invalid\n";j=0;}*/
         // }
        }
}
void twf::resign()
{
     cout<< "if your brain is a superhero ,You are a invisibleman\n";
                answers();
                cout<<ans;
}

int main()
{   
    twf a;
    a.showque();
    a.input();
    a.next2();
    a.next2();
    a.how2win();
    return 0;

}