#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;

int A = 1;
int J = 10;
int Q = 10;
int K = 10;

vector<int> cards;


void allcard();
void shuffler();
void showcards();
int drawcard();
bool cardempty();


void allcard()
{
    cards = {A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K};



}
void shuffler() {
	srand(time(0));
	for (int i = 0; i < 52; i++)
    {
        swap(cards[i], cards[rand() % 52]);
	    cout << " Deck Shuffled!******" << endl;
    }
}

/*void showcards()
{
	cout << "card:" << endl;

	for (int i=0;i<=cards.size();i++) {
		int x=cards.size();
		cout << x << " ,";
		if (x% 13 == 0) cout << endl;
	}
}*/


void showcards()
{
	cout << "card:" << endl;
	int t=0;
	for (auto i : cards) {
		cout << i << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
}
bool cardempty()
{
    return cards.empty();
}

/*int drawcard()
{

	int c= cards.front();
	card.erase(cards.begin());
	return c;

}*/

//int drawcard(vector<int> & cards)
int drawcard()
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
	//public:
	vector<int>hand;
	vector<Player*>playerSet;
	//card draws;
	public:
	void setPlayerSet(vector<Player*>& playerSet);
	vector<Player*> getPlayerSet();
	void Draw2();
	int checkscore();
	void draw();

};

void dealer::setPlayerSet(vector<Player*>& playerSet) {
	this->playerSet = playerSet;
}

vector<Player*> dealer::getPlayerSet() {
	return this->playerSet;
}

void dealer::draw() {
	this->hand.push_back(drawcard());
}
void dealer::Draw2() {
	//int collect;
	//for(int i=0; i<2; i++){
	//	collect = drawcard(draws.cards);
		//hand.push_back(drawcard());
		this->draw();
		this->draw();
	//}

	for (auto p : this->playerSet) {
		//this->draw();
		//this->draw();
		p->Draw();
		p->Draw();
	}
}
int dealer::checkscore() {
	int sum = 0;
	cout << "Dealer Hand:" << endl;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}

	void createDealer();
	void createPlayer();
	void start();
	void checkWin();
	void turn();
	vector<dealer*>dealerSet;
	vector<Player*>playerSet;
	
	void createDealer()
	{
		dealer* d = new dealer();
		dealerSet.push_back(d);
	}
void createPlayer()
	{
		Player* d = new Player();
		playerSet.push_back(d);
	}
void start() {
	cout << "******Blackjack Game Start!******"<<endl;
	allcard();
	showcards();
	shuffler();
	showcards();
	dealer* d = dealerSet.front();
	d->setPlayerSet(playerSet);
	d->Draw2();
}

void checkWin() {
	cout << "******Match Result******" << endl;
	dealer* d = dealerSet.front();
	int dealerHand=d->checkscore();
	int player = 0;

	string bjresult = "";
	for (auto p : d->getPlayerSet()) {
		player++;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->Checkscore();
		if (playerHand == 21 && dealerHand == 21) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult +=" Blackjack Tie!\n";
		}else
		if (playerHand == 21 && dealerHand != 21) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult += " Wins, Blackjack!\n";
		}else
		if(playerHand != 21 && dealerHand == 21) {
			bjresult += "Dealer Wins, Blackjack!\n";
		}else
		if (playerHand <21 && playerHand > dealerHand) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult += " Wins!\n";
		}else
		if (playerHand > 21) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult += " Bust, lose!\n";
		}else
		if (dealerHand > 21) {
			bjresult += "Dealer Bust, Player\n";
			bjresult += (char)(player + '0');
			bjresult += " Wins!\n";
		}else
		if (playerHand == dealerHand) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult += " Tie!\n";
		}else
		if (playerHand < dealerHand) {
			bjresult += "Player";
			bjresult += (char)(player + '0');
			bjresult += " lose!\n";
		}
	}
		cout << bjresult << endl;
}
void turn() {
	dealer* d = dealerSet.front();
	int player = 0;
	for (auto p : d->getPlayerSet()) {
		player++;
		cout << endl;
		cout << "******Player" << player << "'s move*******" << endl;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->Checkscore();
		char c = ' ';
		while (c != 'S' && playerHand < 21) {
			c = p->playeraction();
			if (c == 'H')
				p->Draw();
			else if (c == 'S')
				/*Do nothing*/;
			else
				cout << "Invalid input, try again." << endl;
			playerHand = p->Checkscore();
		}
	}

	cout << "******Turns end!******" << endl;
	while (d->checkscore() < 17)
		d->draw();
}
int main() {
    srand(time(0));
	createDealer();
	for(int i=0;i<4;i++)
	createPlayer();
	
	start();
	turn();
	checkWin();

	system("pause");
	return 0;
}
