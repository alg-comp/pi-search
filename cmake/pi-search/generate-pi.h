#pragma once
#include <iostream>
#include <fstream>
#include <gmpxx.h>
using namespace std;

mpz_class A = 13591409;
mpz_class B = 545140134;
mpz_class C = 640320;
mpz_class D = 426880;
mpz_class E = 10005;
int DigitsPerTerm = log(pow(53360, 3)) / log(10);
mpz_class CCubeDivided24;
string FileName = "pi.txt";

typedef struct _BSA {
    mpz_class P;
    mpz_class Q;
    mpz_class T;
} BSA;


BSA BinarySplitting(int a, int b)
{
    mpz_class mpza = a;
    mpz_class mpzb = b;
    BSA toReturn;

    if (mpza + 1 == mpzb)
    {
        if (mpza == 0) {
            toReturn.P = 1;
            toReturn.Q = 1;
        }
        else {
            toReturn.P = (6 * mpza - 5) * (2 * mpza - 1) * (6 * mpza - 1);
            toReturn.Q = (mpza * mpza * mpza * CCubeDivided24);
        }
        toReturn.T = toReturn.P * (A + B * mpza);
        mpz_class check;
        mpz_class one = 1;
        mpz_and(check.get_mpz_t(), mpza.get_mpz_t(), one.get_mpz_t());
        if (check == 1)
        {
            toReturn.T = toReturn.T * -1;
        }
    }
    else {
        mpz_class m = (mpza + mpzb) / 2;
        BSA AtoM = BinarySplitting(mpza.get_d(), m.get_d());
        BSA MtoB = BinarySplitting(m.get_d(), mpzb.get_d());
        toReturn.P = AtoM.P * MtoB.P;
        toReturn.Q = AtoM.Q * MtoB.Q;
        toReturn.T = MtoB.Q * AtoM.T + AtoM.P * MtoB.T;
    }
    return toReturn;
}

int Chudnovsky(int place)
{
    mpz_pow_ui(CCubeDivided24.get_mpz_t(), C.get_mpz_t(), 3); CCubeDivided24 = CCubeDivided24 / 24;
    //call bsa
    int n = floor(place / DigitsPerTerm + 1);
    BSA result = BinarySplitting(0, n);
    mpz_class oneSquared;
    mpz_class ten = 10;
    mpz_pow_ui(oneSquared.get_mpz_t(), ten.get_mpz_t(), 2 * place);
    mpz_class cSqrt;
    mpz_class Etimes = E * oneSquared;
    mpz_sqrt(cSqrt.get_mpz_t(), Etimes.get_mpz_t());
    mpz_class pi = result.Q * D * cSqrt / result.T;

    fstream out;
    out.open(FileName, ios_base::out);

    if (!out.is_open()) {
        cout << "failed to open " << FileName << '\n';
    }
    else {
        out << pi.get_str() << endl;
        cout << "Done Writing!" << endl;
    }

    out.close();

    return EXIT_SUCCESS;
}