#include <iostream>
#include <vector>

using namespace std;

// functions prototypes
void fairData(vector<float> &mpu6050Data, vector<float> &bno55Data, vector<float> &FairData);                                             // function to calculate the fair data and store it in fairData vector
void goodData(vector<float> &mpu6050Data, vector<float> &bno55Data, vector<float> &GoodData, float mpu6050Accuracy, float bno55Accuracy); // function to calculate the good data and store it in goodData vector

int main()
{

    vector<float> mpu6050Data;
    vector<float> bno55Data;
    vector<float> FairData;
    vector<float> GoodData;
    vector<float> HeroData;
    vector<float> LegendHeroData;
    float mpu6050Accuracy = 0.78, bno55Accuracy = 0.92;

    mpu6050Data = {0.0, 11.68, 18.95, 23.56, 25.38, 22.65, 18.01, 10.14, -0.26};
    bno55Data = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    
    fairData(mpu6050Data, bno55Data, FairData);
    goodData(mpu6050Data, bno55Data, GoodData, mpu6050Accuracy, bno55Accuracy);

    return 0;
}

void fairData(vector<float> &mpu6050Data, vector<float> &bno55Data, vector<float> &FairData) // function to calculate the fair data and store it in fairData vector
{
    cout << "Fair Data: ";
    for (int i = 0; i < mpu6050Data.size(); i++)
    {
        FairData.push_back((mpu6050Data[i] + bno55Data[i]) / 2); // formula of average
        if (i == mpu6050Data.size() - 1)
        {
            cout << FairData[i];
        }
        else
            cout << FairData[i] << ", ";
    }
    cout << endl;
}

void goodData(vector<float> &mpu6050Data, vector<float> &bno55Data, vector<float> &GoodData, float mpu6050Accuracy, float bno55Accuracy) // function to calculate the good data and store it in goodData vector
{
    cout << "Good Data: ";
    for (int i = 0; i < mpu6050Data.size(); i++)
    {

        GoodData.push_back(((mpu6050Data[i] * mpu6050Accuracy) + (bno55Data[i] * bno55Accuracy)) / (mpu6050Accuracy + bno55Accuracy)); // formula of weighted average
        if (i == mpu6050Data.size() - 1)
        {
            cout << GoodData[i];
        }
        else
            cout << GoodData[i] << ", ";
    }
    cout << endl;
}
