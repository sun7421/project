#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
using namespace std;

class card
{
int A = 1;
int J = 10;
int Q = 10;
int K = 10;
public:
    int round=1;
    vector<int> cards;
   
    void allcard();
    void shuffler();
    void showcards();
   // friend int drawcard();
    bool cardempty();
    
};
void card::allcard()
{       
    cards = {A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K, 
             A,2,3,4,5,6,7,8,9,10,J,Q,K};
    
           
           
}
void card::shuffler() {
	srand(time(0));
	for (int i = 0; i < 52; i++) 
    { 
        swap(cards[i], cards[rand() % 52]);
	    cout << " Deck Shuffled!******" << endl;
    }
}
void card::showcards() 
{
	cout << "card:" << endl;
	for (int i=0;i<round;i++)
     {
		cout << this->cards << " ,";
	 }
}
bool card:: cardempty()
{
    return cards.empty();
}

/*int drawcard() 
{
    
	int c= cards.front();
	card.erase(cards.begin());
	return c;
    
}*/

int drawcard(vector<int> & cards) 
{
    
	int c= cards.front();
	cards.erase(cards.begin());
	return c;
    
}

class Player {
private:
	vector<int>hand;
	int pmoney;
	int bet=0;
	int sidebet=0;
public:
	void Draw();
	void Stand();
	void Double();
	//void Split();
	int Checkscore();
	char playeraction();
};


void Player::Draw(){
	this->hand.push_back(drawcard());
}

void Player::Stand(){
	//Do nothing
}

void Player::Double(){
    this->bet *= 2;
}

/*void Player::Split(){
    this->pmoney -= this->bet;
}*/

int Player::Checkscore() {
	int sum = 0;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}

char Player::playeraction() {
	cout << "Non Blackjack, Hit or Stand?" << endl;
	cout << "Press H to draw a card, press S to stand." << endl;
	char c = ' ';
	cin >> c;
	return c;
}

class dealer{
	public:
	vector<int>hand;
	vector<Player*>playerSet;
	card draws;
	void setPlayerSet(vector<Player*>& playerSet);
	vector<Player*> getPlayerSet();
	void Draw2();
	int Checkdscore();
	void draw();

};

void dealer::setPlayerSet(vector<Player*>& playerSet) {
	this->playerSet = playerSet;
}

vector<Player*> dealer::getPlayerSet() {
	return this->playerSet;
}

void dealer::draw() {
	this->hand.push_back(drawcard(draws.cards));
}
void dealer::Draw2() {
	//int collect;
	for(int i=0; i<2; i++){
	//	collect = drawcard(draws.cards);
		hand.push_back(drawcard(draws.cards));
	}

	for (auto p : this->playerSet) {
		p->draw();
		p->draw();
	}
}
int dealer::Checkdscore() {
	int sum = 0;
	cout << "Dealer Hand:" << endl;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}

class game
{
    public:
        void addDealer();
        void addPlayer();
        void start();
        void checkWin();
        void turn();
}

//vector<Dealer*>dealerSet;
//vector<Player*>playerSet;

void game::addDealer() 
	{
		dealer* d = new Dealer();
		dealerSet.push_back(d);
	}
void game::addPlayer()
	{		
		Player* d = new Player();
		playerSet.push_back(d);
	}
void game::start() {
	cout << "******Game Start!******"<<endl;
	allcard();
	showcards();
	shuffle();
	showcards();
	Dealer* d = dealerSet.front();
	d->setPlayerSet(playerSet);
	d->Draw2();
}

void game::checkWin() {
	cout << "******Check Win******" << endl;
	Dealer* d = dealerSet.front();
	int dealerHand=d->CheckHand();
	int player = 0;

	string res = "";
	for (auto p : d->getPlayerSet()) {
		player++;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->CheckHand();
		if (playerHand == 21 && dealerHand == 21) {
			res += "Player";
			res += (char)(player + '0');
			res+=" Blackjack Push!\n";
		}else
		if (playerHand == 21 && dealerHand != 21) {
			res += "Player";
			res += (char)(player + '0');
			res += " Wins, Blackjack!\n";
		}else
		if(playerHand != 21 && dealerHand == 21) {
			res+= "Dealer Wins, Blackjack!\n";
		}else
		if (playerHand <21 && playerHand > dealerHand) {
			res+= "Player";
			res+= (char)(player + '0');
			res += " Wins!\n";
		}else
		if (playerHand > 21) {
			res+= "Player";
			res+= (char)(player + '0');
			res += " Bust, lose!\n";
		}else
		if (dealerHand > 21) {
			res+= "Dealer Bust, Player Wins!\n";
		}else
		if (playerHand == dealerHand) {
			res += "Player";
			res += (char)(player + '0');
			res+= " Push!\n";
		}else
		if (playerHand < dealerHand) {
			res += "Player";
			res += (char)(player + '0');
			res += " lose!\n";
		}
	}
		cout << res << endl;
}
void game::turn() {
	Dealer* d = dealerSet.front();
	int player = 0;
	for (auto p : d->getPlayerSet()) {
		player++;
		cout << endl;
		cout << "******Player" << player << "'s move*******" << endl;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->CheckHand();
		char c = ' ';
		while (c != 'S' && playerHand < 21) {
			c = p->choice();
			if (c == 'H') 
				p->draw();
			else if (c == 'S') 
				/*Stand, do nothing*/;
			else 
				cout << "Invalid input, try again." << endl;
			playerHand = p->CheckHand();
		}
	}
	cout << "******Turns end!******" << endl;
	while (d->CheckHand() < 17) 
		d->draw();
}

int main() {
	addDealer();
	addPlayer();
	addPlayer();
	addPlayer();
	addPlayer();
	
	start();
	turn();
	checkWin();
	
	system("pause");
    return 0;
}