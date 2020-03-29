#ifndef COST_H
#define COST_H
#include <ctime>
#include <string>
#include <forward_list>

using namespace std;
enum entirety { Food = 1, Clothes, Hobby, House };

class Cost
{
    private:
       int howMuch;
       string place;
       string thing;
       entirety typeOfThing;
       struct tm whenBought;

    public:
        Cost( int how=0, string pla="", string thi="", entirety typOf=Food );
        Cost( const Cost& copyCost );
        Cost& operator=( const Cost& copyCost );
        bool operator<( const Cost& copyCost ) const;
        bool operator>( const Cost& copyCost ) const;
        bool operator==( const Cost& copyCost ) const;

        //odczyt skladowych
        int returnMonth();
        int returnYear();
        int returnHowMuch();
        int returnTypeOfThing();
        string returnThing();
        string returnPlace();

        //funkcje
        void writeDate(); //wypelnienie struktury tm
        static Cost newCost(); // nowy koszt

        //znajomosci
        friend void openData( forward_list<Cost> &costList ); // odczyt z pliku
        friend ostream& operator<<( ostream& os, const Cost& copyCost );
};

#endif
