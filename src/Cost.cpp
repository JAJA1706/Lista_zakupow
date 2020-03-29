#include "Cost.h"
#include "Funkcje.h"
#include <iostream>
#include <fstream>
using namespace std;

Cost::Cost( int how, string pla, string thi, entirety typOf ): howMuch(how), place(pla), thing(thi), typeOfThing(typOf){
    whenBought.tm_mon = 0;
    whenBought.tm_year = 0;
}

Cost::Cost( const Cost& copyCost ){
    howMuch = copyCost.howMuch;
    place = copyCost.place;
    thing = copyCost.thing;
    typeOfThing = copyCost.typeOfThing;

    whenBought.tm_mon = copyCost.whenBought.tm_mon;
    whenBought.tm_year = copyCost.whenBought.tm_year;
}

Cost& Cost::operator=( const Cost& copyCost ){
    if( this != &copyCost ){
        howMuch = copyCost.howMuch;
        place = copyCost.place;
        thing = copyCost.thing;
        typeOfThing = copyCost.typeOfThing;
        whenBought.tm_mon = copyCost.whenBought.tm_mon;
        whenBought.tm_year = copyCost.whenBought.tm_year;
    }
    return *this;
}

bool Cost::operator<( const Cost& copyCost ) const{
    if( howMuch < copyCost.howMuch ) return true;
    else return false;
}

bool Cost::operator>( const Cost& copyCost ) const{
    if( howMuch > copyCost.howMuch ) return true;
    else return false;
}

bool Cost::operator==( const Cost& copyCost ) const{
    if( howMuch == copyCost.howMuch ) return true;
    else return false;
}

void Cost::writeDate(){
    cout<<"Aby wpisac obecna date wcisnij 1.\nAby wpisac date recznie (miesiac/rok) wcisnij 2.\n";
    bool loop = true;
    short int a;

    while( loop ){
        cin>>a;
        switch( a ){
            case 1:
            {
                struct tm* tempPointer;
                time_t seconds;
                time( &seconds );
                tempPointer = localtime( &seconds );
                whenBought.tm_mon = tempPointer->tm_mon;
                whenBought.tm_year = tempPointer->tm_year;
                loop = false;
            }
            break;
            case 2:
            {
                bool loop2 = true;
                while( loop2 ){
                    cout<<"Podaj miesiac i rok(tylko 2 ostatnie cyfry)\n";
                    writeInt( whenBought.tm_mon );
                    //clearBuffor();
                    if( (whenBought.tm_mon < 1) || (whenBought.tm_mon > 12) ){
                        cout<<"Podales zly miesiac, sprobuj jeszcze raz\n";
                    }
                    else{
                        loop2 = false;
                    }
                }
                writeInt( whenBought.tm_year );
                whenBought.tm_year += 100;
                --whenBought.tm_mon;

                loop = false;
            }
            break;
            default:
                cout<<"???\n";
                clearBuffor();
            break;
        }
    }
}

Cost Cost::newCost(){
    Cost a;
    int y;

    cout<<"Co kupiono?\n";
    cin>>a.thing;
    cout<<"Wybierz rodzaj produktu:\n1. Jedzenie\n2. Ubrania\n3. Hobby\n4. Dom\n";

    bool loop = true;
    while( loop ){
        loop = false;
        writeInt( y );
        switch( y ){
            case 1:
                a.typeOfThing = Food;
            break;
            case 2:
                a.typeOfThing = Clothes;
            break;
            case 3:
                a.typeOfThing = Hobby;
            break;
            case 4:
                a.typeOfThing = House;
            break;
            default:
                {
                    cout<<"Podaj liczbe z zakresu 1-4\n";
                    loop = true;
                }
            break;
        }
    }
    cout<<"Ile wydano?\n";
    writeInt( a.howMuch );
    cout<<"Gdzie zakupiono przedmiot?\n";
    cin>>a.place;
    a.writeDate();
    return a;
}

int Cost::returnMonth(){
    return whenBought.tm_mon;
}

int Cost::returnYear(){
    return whenBought.tm_year;
}

int Cost::returnHowMuch(){
    return howMuch;
}

int Cost::returnTypeOfThing(){
    return typeOfThing;
}

string Cost::returnPlace(){
    return place;
}

string Cost::returnThing(){
    return thing;
}

ostream& operator<<( ostream& out, const Cost& copyCost ){
    out<<copyCost.thing<<"\n";
    out<<copyCost.howMuch<<"\n";
    out<<copyCost.whenBought.tm_mon+1<<"\n";
    out<<copyCost.whenBought.tm_year+1900<<"\n";
    return out;
}
