#include"card.cpp"
using namespace std;

class Player {
private:
	vector<int>hand;
	int playermoney;
	int playerbet;
public:
	void Draw();
	void Stand();
	void Double();
	void Split();
	int findcardscore();
	char playeraction();
};


void Player::Draw(){
	this->hand.push_back(drawcard());
}

void Player::Stand(){
	
}

void Player::Double(){
    this->bet *= 2;
}

void Player::Split(){
    
}

int Player::findcardscore() {
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