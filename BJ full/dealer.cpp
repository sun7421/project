#include "card.cpp"
#include "player.cpp"
class dealer{
	vector<int>hand;
	vector<Player*>playerSet;

public:
	void setPlayerSet(vector<Player*>& playerSet);
	vector<Player*> getPlayerSet();
	void Draw2();
	void draw();
	int CheckHand();

};
void dealer::setPlayerSet(vector<Player*>& playerSet) {
	this->playerSet = playerSet;
}

vector<Player*> dealer::getPlayerSet() {
	return this->playerSet;
}

void dealer::Hit() {
	this->hand.push_back(drawcard());
}
void dealer::Draw2() {
	
	this->draw();
	this->draw();

	for (auto p : this->playerSet) {
		p->draw();
		p->draw();
	}
}
int dealer::CheckHand() {
	int sum = 0;
	cout << "Dealer Hand:" << endl;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}