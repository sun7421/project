#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
class card
{
int A = 1;
int J = 10;
int Q = 10;
int K = 10;
public:
    vector<int>cards;
    string card;
    void allcard();
    void shuffler();
    
};
void card::allcard()
{       
            cards={A,2,3,4,5,6,7,8,9,10,J,Q,K,};
           
           
}
void shuffler() {
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++) 
    { 
        swap(cards[i], cards[rand() % 52]);
	    cout << "******Deck Shuffled!******" << endl;
    }
}