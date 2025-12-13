#include <iostream>
#include <math.h>
using namespace std;
bool CzyLezaNaProstej(float x1,float y1, float x2, float y2, float x3, float y3);
float PoleTrojkata(float x1, float y1, float x2, float y2, float x3, float y3);

int main()
{
    bool czyPunktyPodane = false;
    bool czyWspoliniowe = true;
    int wybor = 0;
    float A[2] = {0,0};
    float B[2] = {0,0};
    float C[2] = {0,0};
    do
    {
        if (!czyPunktyPodane) {
            cout << "podaj punkty (1)\n";

        }
        if (czyPunktyPodane)
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
            cout << "Podaj punkt A(x,y): "; cin >> A[0] >> A[1];
            cout << "Podaj punkt B(x,y): "; cin >> B[0] >> B[1];
            cout << "Podaj punkt C(x,y): "; cin >> C[0] >> C[1];
            czyPunktyPodane = true;
            czyWspoliniowe = true;
            system("cls");
            break;
        }
        case 2: {
            czyWspoliniowe = CzyLezaNaProstej(A[0],A[1], B[0], B[1], C[0], C[1]);
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
          
            cout << "Pole trojkata = " << PoleTrojkata(A[0], A[1], B[0], B[1], C[0], C[1]) << "\n";

            break;
        }
        case 4: {
            cout << "koniec programu";
            break;
        }
        default:
            cout << "zly wybor";
            system("cls");
            break;
        }

    } while (wybor != 4);


    return 0;
}
bool CzyLezaNaProstej(float x1, float y1, float x2, float y2, float x3, float y3) {
    if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1)) {
        return true;
    }
    return false;
}

float PoleTrojkata(float x1, float y1, float x2, float y2, float x3, float y3) {
    float wyz = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    return 0.5 * fabs(wyz);
}


