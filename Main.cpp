#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string.h>

using namespace std;

void wybieranie(int tablica[], int rozmiar)         //Sortowanie przez wybieranie
{
    int a;
    for(int b=0; b<rozmiar; b++)
    {
        a=b;
        for(int c=b+1; c<rozmiar; c++)
        {
            if(tablica[c]<tablica[a])
            {
                a=c;
            }
        }
        swap(tablica[a],tablica[b]);
    }
}



int podzial(int tablica[], int p, int r)
{
    int x = tablica[p];
    int a = p;
    int b = r;
    int w;

    while(1)
    {
        while(tablica[b]>x)
        {
            b--;
        }

        while(tablica[a]<x)
        {
            a++;
        }

        if(a<b)
        {
            w = tablica[a];
            tablica[a] = tablica[b];
            tablica[b] = w;
            a++;
            b--;
        }

        else
        {
            return b;
        }
    }
}
                                                    //Sortowanie szybkie
void szybkie(int tablica[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = podzial(tablica,p,r);
        szybkie(tablica, p, q);
        szybkie(tablica, q+1, r);
    }
}



void scal(int *tabwej, int *tabwyj, int a, int b, int r)
{
    int i = a;
    int j = b;
    int d = a;
    while (d<r)
    {
        if (j<r && (i==b || tabwej[i]>tabwej[j]) )
        {
            tabwyj[d] = tabwej[j++];
        }

        else
        {
        tabwyj[d] = tabwej[i++];
        }

        ++d;
    }
}
                                                    //Sortowanie przez scalanie
void scalanie(int *tab, int n)
{
    int dyst = 1;
    int *tabwe = tab;
    int *tabwy = new int[n];

    for (dyst=1; dyst<n; dyst*=2)
    {
        int i;
        for (i=0; i<n; i+=dyst*2)
            {
                scal(tab, tabwy, i, i + dyst, min(i + 2 * dyst, n));
            }
        int *chw = tabwy;
        tabwy = tab;
        tab = chw;
    }

    if (tab!=tabwe)
    {
        memcpy(tabwe, tab, n*sizeof(int));
        delete []tab;
    }

    else
    {
        delete []tabwy;
    }
}




int main()
{
    int tab1[1500];
    int tab2[15000];
    int tab3[150000];

    double czas;
    cout.setf(ios::fixed);
    cout.precision(5);
    clock_t start, finish;

    fstream plik1;
    fstream plik2;
    fstream plik3;

    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

{
    plik1.open("WE_NP_1500.txt", ios::in);      // PRZY ZMIANIE PLIKU ZMIENIC SRODKOWY CZLON NAZWY PLIKU(NP: PO; OD; PP; PK; NP)
    while(!plik1.eof())
    {
        plik1 >> tab1[a];
        a++;
    }
    plik1.close();

    plik2.open("WE_PO_15000.txt", ios::in);     // PRZY ZMIANIE PLIKU ZMIENIC SRODKOWY CZLON NAZWY PLIKU(NP: PO; OD; PP; PK; NP)
    while(!plik2.eof())
    {
        plik2 >> tab2[b];
        b++;
    }
    plik2.close();

    plik3.open("WE_PO_150000.txt", ios::in);    // PRZY ZMIANIE PLIKU ZMIENIC SRODKOWY CZLON NAZWY PLIKU(NP: PO; OD; PP; PK; NP)
    while(!plik3.eof())
    {
        plik3 >> tab3[c];
        c++;
    }
    plik3.close();
}

    start=clock();

    //wybieranie(tab1, 1500);
    //szybkie(tab1, 0, 1500);      // PRZY ZMIANIE PLIKU ZMIENIC NUMER I ROZMIAR TABLICY DO KTOREJ JEST WCZYTANY(TAB1 = 1500; TAB2=15000; TAB3=150000) ORAZ USUNAC KOMENTARZE ABY WYBRAC SORTOWANIE
    //scalanie(tab1, 1500);

    finish=clock();

    czas=(finish-start)/(double)CLOCKS_PER_SEC;

    for(int i=0; i<1500; i++)                 // PRZY ZMIANIE PLIKU ZMIENIC ROZMIAR TABLICY DO KTOREJ JEST WCZYTANY(TAB1 = 1500; TAB2 = 15000; TAB3 = 150000)
    {
        cout << tab1[i] << endl;              // PRZY ZMIANIE PLIKU NALEZY ZMIENIC NUMER TABLICY DO KTOREJ JEST WCZYTANY(TAB1 = 1500; TAB2=15000; TAB3=150000)
    }                                         // OPCJONALNIE MOZNA ZAKOMENTOWAC WYSWIETLANIE POSORTOWANEJ TABLICY, PRZYSPIESZY TO OTRZYMANIE CZASU OPERACJI

    cout << endl << endl;
    cout<<"Czas wykonania: "<<czas<<endl;

    return 0;
}

