#include <iostream>
#include <math.h>
using namespace std;
struct Punkt {
    float x;
    float y;
};
struct Trojkat {
    Punkt w1;
    Punkt w2;
    Punkt w3;
};
bool CzyLezaNaProstej(Punkt p1, Punkt p2, Punkt p3);
float PoleTrojkata(Trojkat T);

int main()
{
    bool czyPunktyPodane = false;
    bool czyWspoliniowe = true;
    int wybor = 0;
    Punkt A = {0,0};
    Punkt B = {0,0};
    Punkt C = {0,0};
    Trojkat T;
    do
    {
        if (!czyPunktyPodane) {
            cout << "podaj punkty (1)\n";

        }
        if(czyPunktyPodane)
        {
            cout << "podaj nowe punkty(1)\n";
            cout << "sprawdz czy leza na jednej prostej(2)\n";
        }
        if (!czyWspoliniowe) {
            cout << "policz pole trojkata(3)\n";
        }
        cout << "wyjdz(4)\n";
        cin >> wybor;

        switch (wybor)
        {
        case 1: {
            cout << "Podaj punkt A(x,y): "; cin >> A.x >> A.y;
            cout << "Podaj punkt B(x,y): "; cin >> B.x >> B.y;
            cout << "Podaj punkt C(x,y): "; cin >> C.x >> C.y;
            czyPunktyPodane = true;
            czyWspoliniowe = true;
            system("cls");
            break;
        }
            case 2: {
                czyWspoliniowe = CzyLezaNaProstej(A, B, C);
                if (czyWspoliniowe) {
                    cout << "leza na jednej prostej\n";
                }
                else
                {
                    cout << "nie leza na jednej prostej\n";
                }
                
                break;
            }
            case 3: {
                if (czyWspoliniowe || !czyPunktyPodane) break;
                T.w1 = A;
                T.w2 = B;
                T.w3 = C;
                cout << "Pole trojkata = " << PoleTrojkata(T) <<"\n";
                
                break;
            }
            case 4: {
                cout << "koniec programu";
                break;
            }
        default:
            cout << "zly wybor";
          
            break;
        }
        
    } while (wybor != 4);
   
    
    return 0;
}
    bool CzyLezaNaProstej(Punkt p1, Punkt p2, Punkt p3) {
    if ((p2.x - p1.x) * (p3.y - p1.y) == (p2.y - p1.y) * (p3.x - p1.x)) {
        return true;
    }
    return false;
    }

    float PoleTrojkata(Trojkat T) {
        float wyz = (T.w2.x - T.w1.x) * (T.w3.y - T.w1.y) - (T.w3.x - T.w1.x) * (T.w2.y - T.w1.y);
        return 0.5 * abs(wyz);
    }

    
