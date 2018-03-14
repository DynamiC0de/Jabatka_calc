#include "header.h"
using namespace std;

//globális változók:
    int elem=0, ido=0, i=0;
    float jabatka=0, szorzo=1;
    const int s=1000, o=2;
    string vegzett_tev[s][o], tev = "";
    char igennem = 'n';

int main()
{
    setlocale(LC_ALL,"hun");
    do
    {
        cout << "Írd be az elvégzett tevékenység nevét: ";
        cin >> tev;
    //töltse fel a mátrixot a fájl adataival
        ifstream fbe;
        fbe.open("adatbazis.jab");
        while(!fbe.eof())
        {
            fbe >> vegzett_tev[elem][0];
            fbe >> vegzett_tev[elem][1];
            if(!fbe.eof())
            {
                cout << elem << ". tevékenység: " << vegzett_tev[elem][0] << endl;
                elem++;
            }
        }
        fbe.close();
        cout << endl;
        cout << "Elemek száma az adatbázisban: " << elem << endl;

    //keresse ki a beírt tevékenységet a mátrixból
        while(vegzett_tev[i][0]!=tev && i<=elem)
        {
            i++;
        }
        if(i<=elem)
        {
            cout << "Megtaláltam a keresett tevékenységet! Tevékenységed sorszáma: " << i
            << " Tartalma: " << vegzett_tev[i][0] << " Tevékenység 1 órás értéke: " << vegzett_tev[i][1]<< endl;
            cout << "Mennyi idõt töltöttél " << tev <<" tevékenység végzésével? (perc)" << endl;
            cin >> ido;

            //string konvertálása int-re
            int tev_ertekInt=0;
            stringstream(vegzett_tev[i][1])>> tev_ertekInt;
            cout << "Tevékenység 1 órás értéke: " << tev_ertekInt << endl;

            //jabatka kiszámítása
            jabatka = ido * tev_ertekInt;
            jabatka = jabatka/60 * szorzo;
            int jabatkaInt;
            jabatkaInt = (int)(jabatka+0.5);
            cout << ido << " perc " << tev << "ért cserébe " << jabatka << " ,kerekítve " << jabatkaInt << " Jabatkát kapsz!" << endl;
        }
        else
        {
            cout << "Nincs ilyen tevékenység!" << endl;
        }
        cout << "Szeretnél még számolni? (i/n)";
        cin >> igennem;
        cout << endl;
    }while(igennem=='i'||igennem=='I');
    return 0;
}

