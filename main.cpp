/*
Feladat: Adjuk meg egy egész számokat tartalmazó tömb
leggyakoribb elemét a [0..m] intervallumon.
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int mostFrequented (int m, const vector<int> &x);
int frequency (const vector<int> &x, int e);


int main()
{
    ifstream f ("input.txt");
    /*input.txt tartalma:
    35 <- Az intervallum felsõ határa, tehát az intervallumunk [0..35]
    2 25 13 0 2 0 35 13 2 <- A tömb elemei
    */
    if(f.fail())
    {
        cout << "Hiba a fajl nyitasakor!\n"; return 1;
    }
    int m; //Az intervallumunk felsõ korlátja (Alsó korlátja 0)
    f >> m;  //m beolvasása az input.txt fájlból.
    if(m<0)
    {
        cout << "Nem lehet a felso korlat negativ!\n"; return 1;
    }
    vector<int> x;
    int e;
    while(f >> e)
    {
        if(e >=0 && e <=m) x.push_back(e); //A .push_back(elem) metódussal fûzhetünk a vektorunk végére új elemet.
    }

    if(x.size() >0) cout << "A megadott sorozat leggyakoribb eleme: " << mostFrequented(m,x) << endl;
    else cout << "A megadott sorozat ures!" << endl;
    return 0;
}


//Maximum kiválasztás intervallumra alkalmazva.
//Az intervallum itt a 0 és m közötti természetes számok halmazát jelenti.
//Az intervallum minden elemének a gyakoriságát le tudjuk kérdezni a frequency(...) függvénnyel.
//A gyakoriságok felhasználásával meg kell adnunk az intervallum leggyakoribb elemét.
int mostFrequented(int m, const vector<int> &x)
{
    int max = frequency(x,0);
    int elem = 0;
    for(int i=1;i<=m;i++)
    {
        int c = frequency(x, i);
        if(max < c)
        {
            max = c;
            elem = i;
        }
    }
    return max;
}

//Számlálás tétele tömbre alkalmazva.
//Egy adott elemnek a gyakoriságát kell megadnunk a tömbben.
int frequency (const vector<int> &x, int e)
{
    int c = 0;
    for(unsigned int i=0; i<x.size();i++)
    {
        if(x[i] == e)
        {
            c++;
        }
    }
    return c;
}
//A vector size() metódusa elõjel nélküli számmal tér vissza, így warningot kapnánk ha a ciklusváltozónk (i) nem unsigned lenne.

