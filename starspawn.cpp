#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//star จะอิงกับโค้ดแมพ ต้องรอส่วนนั้นด้วย
int starpos = 0;
void spawnstar()
{
    srand(time(0));
    starpos += (rand%10)+20;
    ///เดี๋ยวมาแก้ ตามจำนวนช่องเดิน
    ///อาจจะใช้ pointer ด้วย
}

class Player{
    int playerstar;
    public:
        void getstar();
}

void Player::getstar()
{
    playerstar++;
    playermoney-=20;
    if(playermoney<0)
    playermoney=0;
    spawnstar();
}

/*class star{
    int starpos=0;
    ///จริงๆเอาไว้นอกคลาสได้ ไม่จำเป็นต้องใช้คลาสเลย แต่กันงงเขียนไว้ก่อน
    ///ไม่แน่ใจว่าต้องใช้ pointer หรือ vector มั้ย
    public:
        void spawnstar();
};*/

/*void star::spawnstar()
{
    srand(time(0));
    starpos += (rand%10)+20;
}*/
