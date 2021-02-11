/*
Feladat: Adjuk meg egy egesz szamokat tartalmazo tomb
leggyakoribb elemet a [0..m] intervallumon.
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int MostFrequent (int m, const vector<int> &x);
int frequency (const vector<int> &x, int e);


int main()
{
    ifstream f ("input.txt");
    /*input.txt tartalma:
    35 <- Az intervallum felso hatara, tehat az intervallumunk [0..35]
    2 25 13 0 2 0 35 13 2 <- A tomb elemei
    */
    if(f.fail())
    {
        cout << "Hiba a fajl nyitasakor!\n"; return 1;
    }
    int m; //Az intervallumunk felso korlatja (Also korlatja 0)
    f >> m;  //m beolvasasa az input.txt fajlbol.
    if(m<0)
    {
        cout << "Nem lehet a felso korlat negativ!\n"; return 1;
    }
    vector<int> x;
    int e;
    while(f >> e)
    {
        if(e >=0 && e <=m) x.push_back(e); //A .push_back(elem) metodussal fuzhetunk a vektorunk vegere uj elemet.
    }

    if(x.size() >0) cout << "A megadott sorozat leggyakoribb eleme: " << mostFrequented(m,x) << endl;
    else cout << "A megadott sorozat ures!" << endl;
    return 0;
}


//Maximum kivalasztas intervallumra alkalmazva.
//Az intervallum itt a 0 es m kozotti termeszetes szamok halmazat jelenti.
//Az intervallum minden elemenek a gyakorisagat le tudjuk kerdezni a frequency(...) fuggvennyel.
//A gyakorisagok felhasznalasaval meg kell adnunk az intervallum leggyakoribb elemet.
int MostFrequent(int m, const vector<int> &x)
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
    return elem;
}

//Szamlalas tetele tombre alkalmazva.
//Egy adott elemnek a gyakorisagat kell megadnunk a tombben.
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
//A vector size() metodusa elojel nelkuli szammal ter vissza, igy warningot kapnank ha a ciklusvaltozonk (i) nem unsigned lenne.

