#include <iostream>
#include <cmath>

using namespace std;

bool provjeraBroja(int);
void stanje(double);
void dopuna(double &);
void slanje(double &, double);
void meni();

int main()
{
    long int broj;
    char operacija[5];
    double kredit = 5.0, slanjeK;
    
    cout << "Unesite broj telefona:\n+387";
    cin >> broj;
    
    if(provjeraBroja(broj))
    {
        
        do
        {
            meni();
            for(int i = 0; i < 5; i++)
            {
                cin >> operacija[i];
                if(operacija[0] == '1' || operacija[0] == '2' || operacija[0] == '3') break;
                if(operacija[0] != '1' || operacija[0] != '2' || operacija[0] != '3' || operacija[0] != '*') break;
                
            }
            
            //for(int i = 0; i < 5; i++) cout << operacija[i];
            system("CLS");
            if(operacija[0] == '*' && operacija[1] == '1' && operacija[2] == '0' && operacija[3] == '0' && operacija[4] == '#')
            {
                stanje(kredit);
            }
            else if(operacija[0] == '1')
            {
                dopuna(kredit);
            }
            else if(operacija[0] == '2')
            {
                cout << "Koliko kredita zelite poslati: " << endl;
                cin >> slanjeK;
                slanje(kredit, slanjeK);
            }
            else if(operacija[0] == '3') break;
            else cout << "Pogresna operacija" << endl;
            
        }while(0 == 0);
            
    }
}

bool provjeraBroja(int broj)
{
    //treba imati 8-9 cifri
    int temp = broj;
    int duzina = 0;
    do
    {
        broj = broj / 10;
        duzina++;
        
    }while(broj > 0);

    //treba pocinjati sa 60 / 61 / 62
    int x  = temp / pow(10, duzina - 2);
    int y  = temp / pow(10, duzina - 1);
    if(duzina > 9 || duzina < 7) return 0;
    else
    {
        if(y != 6) return 0;
        else if(x == 60 || x == 61 || x == 62) return 1;
        else return 0;
    }
    
    
}

void meni()
{
    cout << "Izaberite opciju: " << endl
        << "*100# - Provjeru stanja " << endl
        << "1 - Dopunu kredita" << endl
        << "2 - Slanje kredita" << endl
        << "3 - Zavrsi izbor" << endl;
}

void stanje(double kredit)
{
    cout << "Stanje na vasem racunu je: " << kredit << endl;
}

void dopuna(double &kredit)
{
    double dopunaK;
    cout << "Koliko kredita zelite dopuniti?" << endl;
    cin >> dopunaK;
    
    kredit += dopunaK;
}

void slanje(double &kredit, double slanjeK)
{
    if(slanjeK > kredit - slanjeK) cout << "Nemate dovoljno kredita" << endl;
    else kredit -= slanjeK;
}