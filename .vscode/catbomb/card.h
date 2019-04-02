#ifndef card_h
#define card_h
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;
class Card {
private:
    string m_type;
    bool m_inHand;
public:
    Card(string type);
    ~Card();
    string getType();
    void setType(string password);
    void setInHand(bool isInHand);
    bool getInHand();
};
#endif Card_h