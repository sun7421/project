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
    vector<int> cards;
   
    void allcard();
    void shuffler();
    void showcards();
    int  getCard();
    bool is_deck_empty();
    
};
void card::allcard()
{       
    cards = {A,2,3,4,5,6,7,8,9,10,J,Q,K,};
    for(int i=0;i<3;i++)
    {
        cards+=cards;
    }
           
           
}
void shuffler() {
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++) 
    { 
        swap(cards[i], cards[rand() % 52]);
	    cout << "******Deck Shuffled!******" << endl;
    }
}
void showcard() 
{
	cout << "card:" << endl;
	int a=0;
	for (auto i : card) {
		cout << i << " ,";
		a++;
		if (t % 13 == 0) cout << endl;
	}
}