#include<iostream>
using namespace std;
bool x1,x2,x3,x4;
int p[4]={};

void naango(){
    cout << "Rule\n";
    cout << "any pleyer choose No. between 1-3\n";
    cout << "ifyou No. have no copy you win\n";
    do
    {
        cout << "P1 choose No. between 1-3\n";
        cin >> p[0];
    } while (p[0]>4&&p[0]<0);
    do
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nP2 choose No. between 1-3\n";
        cin >> p[1];
    } while (p[1]>4&&p[1]<0);
    do
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nP3 choose No. between 1-3\n";
        cin >> p[2];
    } while (p[2]>4&&p[2]<0);
    do
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nP4 choose No. between 1-3\n";
        cin >> p[3];
    } while (p[3]>4&&p[3]<0);
    if(p[0]==p[1]||p[0]==p[2]||p[0]==p[3]) {
    x1 = false;
    }else x1=true;
    if(p[0]==p[1]||p[1]==p[2]||p[1]==p[3]) {
    x2 = false;
    }else x2=true;
    if(p[2]==p[1]||p[2]==p[0]||p[2]==p[3]) {
    x3 = false;
    }else x3=true;
    if(p[0]==p[3]||p[3]==p[2]||p[3]==p[1]) {
    x4 = false;
    }else x4=true;
    if (x1==true) {
        cout << "P1 WIN!!";
    } 
    if (x2==true){
        cout << "P2 WIN!!";
    }
    if (x3==true){
        cout << "P3 WIN!!";
    }
    if (x4==true){
        cout << "P4 WIN!!";
    }
}