#include "header.h"
using namespace std;

//glob�lis v�ltoz�k:
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
        cout << "�rd be az elv�gzett tev�kenys�g nev�t: ";
        cin >> tev;
    //t�ltse fel a m�trixot a f�jl adataival
        ifstream fbe;
        fbe.open("adatbazis.jab");
        while(!fbe.eof())
        {
            fbe >> vegzett_tev[elem][0];
            fbe >> vegzett_tev[elem][1];
            if(!fbe.eof())
            {
                cout << elem << ". tev�kenys�g: " << vegzett_tev[elem][0] << endl;
                elem++;
            }
        }
        fbe.close();
        cout << endl;
        cout << "Elemek sz�ma az adatb�zisban: " << elem << endl;

    //keresse ki a be�rt tev�kenys�get a m�trixb�l
        while(vegzett_tev[i][0]!=tev && i<=elem)
        {
            i++;
        }
        if(i<=elem)
        {
            cout << "Megtal�ltam a keresett tev�kenys�get! Tev�kenys�ged sorsz�ma: " << i
            << " Tartalma: " << vegzett_tev[i][0] << " Tev�kenys�g 1 �r�s �rt�ke: " << vegzett_tev[i][1]<< endl;
            cout << "Mennyi id�t t�lt�tt�l " << tev <<" tev�kenys�g v�gz�s�vel? (perc)" << endl;
            cin >> ido;

            //string konvert�l�sa int-re
            int tev_ertekInt=0;
            stringstream(vegzett_tev[i][1])>> tev_ertekInt;
            cout << "Tev�kenys�g 1 �r�s �rt�ke: " << tev_ertekInt << endl;

            //jabatka kisz�m�t�sa
            jabatka = ido * tev_ertekInt;
            jabatka = jabatka/60 * szorzo;
            int jabatkaInt;
            jabatkaInt = (int)(jabatka+0.5);
            cout << ido << " perc " << tev << "�rt cser�be " << jabatka << " ,kerek�tve " << jabatkaInt << " Jabatk�t kapsz!" << endl;
        }
        else
        {
            cout << "Nincs ilyen tev�kenys�g!" << endl;
        }
        cout << "Szeretn�l m�g sz�molni? (i/n)";
        cin >> igennem;
        cout << endl;
    }while(igennem=='i'||igennem=='I');
    return 0;
}

