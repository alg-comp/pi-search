// pi-search.cpp : Defines the entry point for the application.
//
#include "generate-pi.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Please specify up to which place Pi should be calculated" << endl;
        return EXIT_FAILURE;
    }
    int place = atoi(argv[1]);
    return Chudnovsky(place);
}