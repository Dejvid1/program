#include <iostream>

using namespace std;
struct punkt{
float x;
float y;
};
bool CzyLezaNaProstej(punkt p1,punkt p2,punkt p3);
void PoleTrojkata(punkt p1,punkt p2,punkt p3);
int main()
{
  punkt p1 ={1,3};
  punkt p2 ={2,5};
  punkt p3 ={3,7};

    if(CzyLezaNaProstej(p1,p2,p3)){
        cout<<"prawda";
    }
    else{
        cout<<"falsz";
    }

    return 0;
}
bool CzyLezaNaProstej(punkt p1,punkt p2,punkt p3){
if((p2.x - p1.x)*(p3.y-p1.y) == (p2.y-p1.y)*(p3.x-p1.x)){
    return true;
}
return false;
}
void PoleTrojkata(punkt p1,punkt p2,punkt p3){

}
