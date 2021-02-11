/*
Feladat: Adjuk meg egy eg�sz sz�mokat tartalmaz� t�mb
leggyakoribb elem�t a [0..m] intervallumon.
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
    35 <- Az intervallum fels� hat�ra, teh�t az intervallumunk [0..35]
    2 25 13 0 2 0 35 13 2 <- A t�mb elemei
    */
    if(f.fail())
    {
        cout << "Hiba a fajl nyitasakor!\n"; return 1;
    }
    int m; //Az intervallumunk fels� korl�tja (Als� korl�tja 0)
    f >> m;  //m beolvas�sa az input.txt f�jlb�l.
    if(m<0)
    {
        cout << "Nem lehet a felso korlat negativ!\n"; return 1;
    }
    vector<int> x;
    int e;
    while(f >> e)
    {
        if(e >=0 && e <=m) x.push_back(e); //A .push_back(elem) met�dussal f�zhet�nk a vektorunk v�g�re �j elemet.
    }

    if(x.size() >0) cout << "A megadott sorozat leggyakoribb eleme: " << mostFrequented(m,x) << endl;
    else cout << "A megadott sorozat ures!" << endl;
    return 0;
}


//Maximum kiv�laszt�s intervallumra alkalmazva.
//Az intervallum itt a 0 �s m k�z�tti term�szetes sz�mok halmaz�t jelenti.
//Az intervallum minden elem�nek a gyakoris�g�t le tudjuk k�rdezni a frequency(...) f�ggv�nnyel.
//A gyakoris�gok felhaszn�l�s�val meg kell adnunk az intervallum leggyakoribb elem�t.
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

//Sz�ml�l�s t�tele t�mbre alkalmazva.
//Egy adott elemnek a gyakoris�g�t kell megadnunk a t�mbben.
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
//A vector size() met�dusa el�jel n�lk�li sz�mmal t�r vissza, �gy warningot kapn�nk ha a ciklusv�ltoz�nk (i) nem unsigned lenne.

