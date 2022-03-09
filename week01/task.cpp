#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//дефиниране на enum (множество)
enum season
{
    spring = 0,
    summer = 1,
    autumn = 2,
    winter = 3
};

//създаване на обекти от тип season
season currentSeason = (season)0;
season nextSeason = summer;

//създаване на множество цвят (на карта за игра)
enum suit {
    spade,
    heart,
    diamond,
    club
};

//създаване на множество ранк (на карта за игра)
enum num {ace, two, tree, four, five, six, seven, eight, nine, ten, jack, queen, king};

//дефиниране на структура playing_card
struct playing_card
{
    suit _suit;
    num _num;
};

void print_playing_card(playing_card card)
{
    cout << "num: " << card._num << endl;
    cout << "suit: " << card._suit << endl << endl;
}

int main()
{
    int time_now = time(NULL);
    srand(time_now);

    playing_card firstCard;
    firstCard._suit = spade;
    firstCard._num = ace;

    int SIZE = 10;
    playing_card cards[10];
    for(int i = 0; i < SIZE; i++)
    {
        //cast-ване на int към обект suit
        cards[i]._suit = (suit)(rand() % 4);
        //cast-ване на int към обект num
        cards[i]._num = (num)(rand() % 13);
    }

    for(int i = 0; i < SIZE; i++)
    {
        print_playing_card(cards[i]);
    }

    return 0;
}