#ifndef FINITE_FIELDS_H
#define FINITE_FIELDS_H
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//Each element of the field is represented as a vector. If the Field is Prime^PrimePower, then the vector
//will be n dimentional with each entry modulo Prime
//In each of these arguments, Field = Prime^PrimePower


//Adds two elements of the field
vector<int> Add (vector<int> firstpoly, vector<int> secondpoly, int Prime);

//Subtracts the second element from the first
vector<int> Subtract (vector<int> firstpoly, vector<int> secondpoly, int Prime);

//Multiplies two elements of the field
vector<int> Multiply (vector<int> firstpoly, vector<int> secondpoly, vector<int> MinimumPolynomial, int Prime);

//Gives the smallest generator of the field
int generator (int Prime, int PrimePower, vector<int> MinimumPolynomial);

//Some hardcoded minimum polynomials
vector<int> MinPoly (int Prime, int PrimePower);

//Converts vector to integer
int toInt (vector<int> vector, int Prime);

//Converts integer to vector
vector<int> toVec (int Integer, int Prime, int PrimePower);
#endif