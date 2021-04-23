// $> g++ -Wall -O3 matriz.cpp -o matriz &&./matriz < t6-in-0.txt
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <math.h>
#include <iomanip>

void calcula_dist(vector<vector<double>> &D, int N, vector<double> &cordX, vector<double> &cordY)
{
    for (int i = 0; i < N; i++)
    {
        vector<double> a;
        //D.push_back(a);
        for (int j = 0; j < N; j++)
        {
            if (i <= j)
            {
                double DX = cordX[i] - cordX[j];
                double DY = cordY[i] - cordY[j];
                a.push_back(sqrt(DX * DX + DY * DY));
                //D[i].push_back(sqrt(DX * DX + DY * DY));
            }
            else
            {
                a.push_back(D[j][i]);
            }
        }

        D.push_back(a);
    }
}

int main()
{
    int N;
    std::cin >> N;

    vector<double> cordX;
    vector<double> cordY;
    vector<vector<double>> D;

    double x, y;
    for (int i = 0; i < N * 2; i++)
    {

        cin >> x >> y;
        cordX.push_back(x);
        cordY.push_back(y);
    }

    calcula_dist(D, N, cordX, cordY);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << fixed;
            cout << setprecision(2) << D[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}