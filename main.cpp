// Libraries Used
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

// Will Count the number of Digits in a Integer
int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

// Function to Correct the Data Entered
int correct(int first, int last)
{
    int count = first;
    for (int i = 0; i < countDigit(last); i++)
    {
        count *= 10;
    }
    return count + last;
}

// Function to calculate MEAN
float Mean(vector<int> a)
{
    int sum = 0;
    float mean = 0;
    for (int i = 0; i < 1000; ++i)
    {
        sum += a[i];
    }
    mean = sum / 1000;
    return mean;
}

// Function to Calculate Population Standard Deviation
float StandardDeviation(vector<int> a)
{
    float variance = 0.0, stdDeviation = 0.0, mean = Mean(a);
    for (int i = 0; i < 1000; ++i)
    {
        variance += pow(a[i] - mean, 2);
    }
    variance = variance / 1000;
    stdDeviation = sqrt(variance);
    return stdDeviation;
}

// Function to Calculate Sample Mean
float SampleMean(vector<int> a, int start, int end)
{
    int sum = 0;
    float mean = 0;
    int SampleSize = end - start;
    for (int i = 0; i < SampleSize; i++)
    {
        sum += a[i];
    }
    mean = sum / SampleSize;
    return mean;
}

// Function for Calculating Z-Distribution Value
float Zvalue(vector<int> a, int N, float SampleMean)
{
    float Z = 0.0;
    Z = (float)(((Mean(a) - SampleMean) / (StandardDeviation(a))) * (sqrt(N)));
    return Z;
}

// Main Function
int main()
{
    ifstream in;
    in.open("EmployeeData.csv");

    // Vector/Array for Data Storing
    vector<int> data(1000);

    string a;
    int first, last, final, i = 0;

    // Loop to Extract Data from EmployeeData.CSV File
    while (i < 1000)
    {
        in.ignore(1000, '\n');
        in.ignore(1000, '$');
        in >> first;
        in.ignore();
        in >> last;
        final = correct(first, last);
        if (countDigit(final) <= 4)
        {
            final *= 10;
        }
        data[i] = final;
        i++;
    }

    // SRAND for generating Random Values
    srand(time(0));

    // Vector/Array for Storing values for Sample Size = 10
    vector<int> Sample_10(10);

    // Vector/Array for Storing Z-Values
    vector<float> Z_10(10);

    // Loop for Repeating 300 Times
    for (int j = 0; j < 300; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int r = rand() % 1000;
                Sample_10.push_back(data[r]);
            }
            Z_10[i] = Zvalue(data, 10, SampleMean(Sample_10, 0, Sample_10.size()));
        }
    }

    // output the Values in .txt File
    fstream out;
    out.open("Output10.txt");
    for (int i = 0; i < 10; i++)
    {
        out << Z_10[i] << endl;
    }
    out.close();

    // Vectors/Arrays for Storing Sample Values & Z-Value for N = 300
    vector<int> Sample_300(300);
    vector<float> Z_300(300);

    // Loop for repeating it 300 times
    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            int r = rand() % 1000;
            Sample_300[j] = data[r];
        }
        Z_300[i] = Zvalue(data, 300, SampleMean(Sample_300, 0, 300));
        cout<<endl<<Z_300[i];
    }

    // Output the values for N=300
    out.open("test.txt");
    for (int i = 0; i < 300; i++)
    {
        out << Z_300[i] << endl;
    }

    return 0;
}
// Program Ends
