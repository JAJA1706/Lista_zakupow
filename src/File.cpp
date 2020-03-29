#include "Cost.h"
#include <forward_list>
#include <fstream>

void saveData( forward_list<Cost> &costList ){
    Cost temporaryCost;
    forward_list<Cost>::iterator iter;
    fstream plik;

    plik.open( "pamiec.txt", std::ios::trunc | std::ios::out );
    for( iter = costList.begin(); iter != costList.end(); ++iter ){
        temporaryCost = *iter;

        plik << temporaryCost.returnHowMuch()<<"\n";
        plik << temporaryCost.returnPlace()<<"\n";
        plik << temporaryCost.returnThing()<<"\n";
        plik << temporaryCost.returnTypeOfThing()<<"\n";
        plik << temporaryCost.returnMonth()<<"\n";
        plik << temporaryCost.returnYear()<<"\n";
    }
    plik.close();
}

void openData( forward_list<Cost> &costList ){
    Cost a;
    int b;
    string c;
    char d[251];
    fstream plik;

    plik.open( "pamiec.txt", std::ios::in );
    while ( !plik.eof() ){ //wczytywane bedzie za kazdym razem 6 wartosci, poniewaz klasa Cost ma 6 danych
        plik.getline( d, 250 );
        if( plik.eof() ) break; //gdyby byl pusty od samego poczatku
        c = d;
        b = stoi( c );
        a.howMuch = b;
        plik.getline( d, 250 );
        c = d;
        a.place = c;
        plik.getline( d, 250 );
        c = d;
        a.thing = c;
        plik.getline( d, 250 );
        if( d[0] == 49 ) a.typeOfThing = Food;
        else if( d[0] == 50 ) a.typeOfThing = Clothes;
        else if( d[0] == 51 ) a.typeOfThing = Hobby;
        else a.typeOfThing = House;
        plik.getline( d, 250 );
        c = d;
        b = stoi( c );
        a.whenBought.tm_mon = b;
        plik.getline( d, 250 );
        c = d;
        b = stoi( c );
        a.whenBought.tm_year = b;

        costList.push_front( a );
    }

    plik.close();
}
