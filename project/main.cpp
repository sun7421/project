#include"main.h"
#include<iostream>
using namespace std;
int main(){
    srand(time(0));
    string name;	
	cout << "Please input player1 name: ";
	getline(cin,name);	
	player p1(name);
    cout << "Please input player2 name: ";
	getline(cin,name);	
	player p2(name);
    cout << "Please input player3 name: ";
	getline(cin,name);	
	player p3(name);
    cout << "Please input player4 name: ";
	getline(cin,name);	
	player p4(name);
    spawnstar();
    while(p1.wincheck()==false&&p2.wincheck()==false&&p3.wincheck()==false&&p4.wincheck()==false){
            printmap();
            p1.playgame();
            if(p1.wincheck()){
                cout << "\n*******************************************************\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*                   P1 WIN!!!                         *\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*******************************************************\n";
                break;
            }
            printmap();
            p2.playgame();
            if(p2.wincheck()){
                cout << "\n*******************************************************\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*                   P2 WIN!!!                         *\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*******************************************************\n";
                break;
            }
            printmap();
            p3.playgame();
            if(p3.wincheck()){
                cout << "\n*******************************************************\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*                   P3 WIN!!!                         *\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*******************************************************\n";
                break;
            }
            printmap();
            p4.playgame();
            if(p4.wincheck()){
                cout << "\n*******************************************************\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*                   P4 WIN!!!                         *\n";
	            for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	            cout << "*******************************************************\n";
                break;
            }
            minigame();
            if(randminigame==0){
                if(checkp1==true)p1.wintheminigame();
                if(checkp2==true)p2.wintheminigame();
                if(checkp3==true)p3.wintheminigame();
                if(checkp4==true)p4.wintheminigame();
            }
            else if(randminigame==1){
                if(game_lose_p1==false)p1.wintheminigame();
                if(game_lose_p2==false)p2.wintheminigame();
                if(game_lose_p3==false)p3.wintheminigame();
                if(game_lose_p4==false)p4.wintheminigame();
            }
            else if(randminigame==2){
                if(x1==true)p1.wintheminigame();
                if(x2==true)p2.wintheminigame();
                if(x3==true)p3.wintheminigame();
                if(x4==true)p4.wintheminigame();

            }
            
        }
    }