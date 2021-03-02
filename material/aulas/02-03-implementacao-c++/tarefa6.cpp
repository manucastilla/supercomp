#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>
using namespace std;
int main()
{
    int n;
    std::cin >> n;

    vector<double> x;
    vector<double> y;

    double inputX, inputY;

    for (int i = 0; i < n * 2; i++)
    {
        cin >> inputX >> inputY;
        x.push_back(inputX);
        y.push_back(inputY);
    }
}