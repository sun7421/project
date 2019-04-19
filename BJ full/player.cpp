#include"card.cpp"
class Player {
	vector<int>Pycard;

public:
    
	void Pycard();
	void Stand();
	void Double();
	void Split();
	int CheckHand();
	char choice();
};
void Player::Pycard() {
	this->Pycard.push_back(drawcard());
}