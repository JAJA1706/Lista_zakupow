#include "Purchases.h"
#include "Funkcje.h"
#include <forward_list>
#include <iostream>
#include <fstream>

using namespace std;

void Purchases::howMuchForPeriod(){
    cout<<"Jaki okres Cie interesuje?: 1.miesiac  2.rok\n";
        int a;
        int sum = 0;
        int year;
        int month;
        Cost temporaryCost;

        writeInt( a );
        if( a == 1 ){
            cout<<"Podaj rok i miesiac\n";
            writeInt( year );
            writeInt( month );
            for( iter = costList.begin(); iter != costList.end(); ++iter ){
                temporaryCost = *iter;
                if ( (temporaryCost.returnYear() == year+100) && (temporaryCost.returnMonth() == month-1) ){
                    sum += temporaryCost.returnHowMuch();
                }
            }
            cout<<"Wydano: "<<sum<<"zl\n";
        }
        else if ( a == 2){
            cout<<"Podaj rok\n";
            writeInt( year );
            for( iter = costList.begin(); iter != costList.end(); ++iter ){
                temporaryCost = *iter;
                if( temporaryCost.returnYear() == year+100 ){
                    sum += temporaryCost.returnHowMuch();
                }
            }
            cout<<"Wydano: "<<sum<<"zl\n";
        }
    else{
        cout<<"Sprobuj ponownie\n";
    }
}

void Purchases::howMuchForGroupOfProducts(){
    cout<<"Jaka grupa produktow Cie interesuje?: 1.Jedzenie  2.Ubrania  3.Hobby  4.Dom\n";
    int x;
    int sum = 0;
    Cost temporaryCost;
    bool loop = true;
    while ( loop ){
        writeInt( x );
        if( x>0 && x<5 ){
            loop = false;
        }
        else{
            cout<<"Podales zla liczbe\n";
        }
    }

    for( iter = costList.begin(); iter != costList.end(); ++iter ){
        temporaryCost = *iter;
        if( x == temporaryCost.returnTypeOfThing() ){
            sum += temporaryCost.returnHowMuch();
        }
    }
    switch( x ){
    case 1: cout<<"Wydano "<<sum<<"zl na jedzenie\n";
    break;
    case 2: cout<<"Wydano "<<sum<<"zl na ubrania\n";
    break;
    case 3: cout<<"Wydano "<<sum<<"zl na hobby\n";
    break;
    case 4: cout<<"Wydano "<<sum<<"zl na dom\n";
    break;
    }

}

void Purchases::whereBuy(){
    cout<<"Jaki przedmiot Cie interesuje?\n";
    string item;
    bool nothing = true;
    Cost temporaryCost;

    cin>>item;
    cout<<"Przedmiot znajdziesz w: \n";
    for( iter = costList.begin(); iter != costList.end(); ++iter ){
        temporaryCost = *iter;
        if( item == temporaryCost.returnThing() ){
            cout<<temporaryCost.returnPlace()<< " za "<<temporaryCost.returnHowMuch()<<"zl"<<"\n";
            nothing = false;
        }
    }
    if( nothing ){
        cout<<"Niestety nie wiadomo, takiego przedmiotu nie kupowales\n";
    }
}
