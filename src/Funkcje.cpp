#include <iostream>
#include "Funkcje.h"
#include "Cost.h"
#include <forward_list>
#include "Purchases.h"
#include "File.h"


using namespace std;

void clearBuffor(){
    cin.clear();
    cin.ignore( 1000, '\n' );
}

void writeInt( int &a ){
    bool loop = true;
    while( loop ){
        if( cin>>a ){
            clearBuffor();
            loop = false;
        }
        else{
            cout<<"Podaj cyfre nuub\n";
            clearBuffor();
        }
    }
}

void shell( void ){
    bool x = true;
    string napis;
    Purchases purchases;
    openData( purchases.costList );
    Cost a;

    while( x ){
        int switcher;
        cout<<"Co chcesz zrobic?"<<endl<<"1. Dodaj obiekt\n2. Wypisz liste\n3. Wydatki za dany okres\n4. Wydatki na okreslona grupe produktow\n5. Gdzie kupic dany przedmiot?\n6. Wyczysc liste\n7. Exit\n";
        cin>>switcher;
        switch ( switcher ){
            case 1:
            {
                a = Cost::newCost();
                purchases.costList.push_front( a );
                purchases.costList.sort();
            }
            break;

            case 2:
            {
                for( purchases.iter = purchases.costList.begin(); purchases.iter != purchases.costList.end(); ++purchases.iter ){
                    cout<<*purchases.iter;
                }
            }
            break;

            case 3:
            {
                purchases.howMuchForPeriod();
            }
            break;

            case 4:
            {
                purchases.howMuchForGroupOfProducts();
            }
            break;

            case 5:
            {
                purchases.whereBuy();
            }
            break;

            case 6:
            {
                purchases.costList.clear();
            }
            break;

            case 7:
            {
                x = false;
                saveData( purchases.costList );
            }
            break;

            default:
            {
                cout<<"cos nie tak"<<endl;
            }
            break;
        }
    }
}
