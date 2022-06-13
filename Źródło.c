#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dlugosc(char *lan)
{
    int w; 
    for (w = 0; lan[w] != '\0'; ++w);
        return (w-1);
}

int sprawdz(char* tekst, char* wzor)
{
    int dl_t = dlugosc(tekst);
    int dl_w = dlugosc(wzor);
    int ok = 0;
    for (int i = 0; i < dl_t - dl_w ; i++)
    {
        ok = 1;
        for (int j = 0; j < dl_w; j++)
        {
            if (tekst[i + j] != wzor[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok==1)
        return(i);
    }
    if (!ok)
return(-1);
}

int* sprawdz_w(char* tekst, char* wzor, int* ilosc)
{
    ilosc = malloc(11*sizeof(int));
    int dl_t = dlugosc(tekst);
    int dl_w = dlugosc(wzor);
    int ok = 0;
    int licz = 0;
    for (int i = 0; i <= dl_t - dl_w; i++)
    {
        ok = 1;
        for (int j = 0; j < dl_w; j++)
        {
            if (tekst[i + j] != wzor[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        { 
            *(ilosc + licz) = i;
            licz++;
        }
            
    }
    printf("wzorzec wystapil %d razy\n", licz);
    for (int i =0 ; i < licz; i++)
    {
        printf("indeksy:%d\n", *(ilosc + i));
    }
    free(ilosc);
    return(&ilosc);
}
void main()

{
    while (1)
    {
    int ilosc=11;
    int wynik2;
    int* wynik3;
    char tekst[50];
    char wzor[50];
    printf("podaj tekst: ");
    fgets(tekst,50,stdin);
    printf("podaj wzorzec: ");
    fgets(wzor,50, stdin);
    wynik2 = sprawdz(&tekst, &wzor);
 
    if (wynik2 >= 0)
        {
       printf("wzorzec wystapil pierwszy raz na pozycji: %d\n", wynik2);
       wynik3 = sprawdz_w(&tekst, &wzor, &ilosc);
       printf("adres na tablice z indeksami %d\n", wynik3);
        }
    else
        {
        printf("brak wzorca\nkoniec programu");
           break;
        }
 
    }
}