#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "finitefields.h"
using namespace std;

vector<int> Add(vector<int> a, vector<int> b, int q)
{
    int n  = a.size();
    int t;
    vector<int> c;
    for(int i = 0; i < n; i++)
    {
        t = a[i] + b[i];
        t %= q;
        c.push_back(t);
    }
    return c;
}

vector<int> Subtract(vector<int> a,vector<int> b, int q){
	int n=b.size();
	for (int i=0;i<n;i++){
		b[i]=q-b[i];
	}
	return Add(a,b,q);
}

vector<int> Remainder(vector<int> a, vector<int> b, int q)
{
    int na = a.size();
    int nb = b.size();
    int i, j;
    for(i = 0; i < na; i++)
    {
        if(a[i] != 0)
            break;
    }
    for(j = 0; j < nb; j++)
    {
        if(b[j] != 0)
            break;
    }
    int len = nb-j;
    int t;
    while(i <= (na-len))
    {
        t = a[i];
        int k = 0;
        while(k < nb-j)
        {
            a[i+k] -= t*b[j+k];
            a[i+k] = ((a[i+k] % q) + q) % q;
            k++;
        }
        i++;
    }
    vector<int> c;
    for (i=(na-nb+1);i<na;i++){
        c.push_back(a[i]);
    }
    return c;
}

bool isNull(vector<int> v){
    int flag = 0;
    int i, n = v.size();
    for (i=0; i<n; i++){
        if (v[i]!=0){
            flag = 1;
            break;}
    }
    if (flag==0) return true; else return false;
    }

vector<int> Multiply(vector<int> a,vector<int> b,vector<int> poly,int q){
    int l1=a.size();
    int l2=b.size();
    vector<int> c;
    int i;
    for (i=0;i<(l1+l2-1);i++){
        c.push_back(0);
    }
    while (l2>0){
        l1=a.size();
        while (l1>0){
            c[l1+l2-2]=(c[l1+l2-2]+a[l1-1]*b[l2-1])%q;
            l1--;
        }
        l2--;
    }
    return Remainder(c,poly,q);
}

vector<int> toVec(int a,int q,int n){
    vector<int> temp;
    while (n>0){
        temp.push_back(a%q);
        a=a/q;
        n--;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int toInt(vector<int> n,int q){
    int a = 1, result = 0;
    int l = n.size();
    while (l>0){
        result=result+a*n[l-1];
        a=a*q;
        l--;
    }
    return result;
}

int generator(int n, int n1, vector<int> poly){
    if (n1==1){
        int i, j;
        int order = n-1;
        int g;
        for (i=2;i<n;i++)
        {
            int temp = i;
            for(j = 2; j < n; j++)
            {
                temp = (temp*i)%n;
                if(temp == 1)
                    break;
            }
            if(j == order){
                g=i;
                break;
            }
        }
        return g;
    }
    else{
        int i;
        int p = llround(pow(n,n1));
        for (i=2;i<p;i++){
            int j;
            vector<int> num = toVec(i,n,n1);
            vector<int> temp,temp3;
            for (j=0;j<n1;j++){
                temp.push_back(0);
                temp3.push_back(0);
            }
            temp3[n1-1]=1;
            for (j=0;j<poly.size();j++){
                int k;
                vector<int> temp2;
                for (k=0;k<n1;k++)
                    temp2.push_back(0);
                temp2[n1-1] = poly[poly.size()-j-1];
                temp2 = Multiply(temp2,temp3,poly,n);
                temp = Add(temp,temp2,n);
                temp3 = Multiply(temp3,num,poly,n);
            }
            if (isNull(temp))
                break;
        }
        return i;
    }
}

vector<int> MinPoly(int q, int n)
{
    vector<int> minpoly;
    if(n==2)
    {
        switch(q)
        {
            case 3: minpoly = {1,2,2}; break;
			case 5: minpoly = {1,4,2}; break;
			case 7: minpoly = {1,6,3}; break;
			case 11: minpoly = {1,7,2}; break;
			case 13: minpoly = {1,12,2}; break;
			case 19: minpoly = {1,18,2}; break;
			case 23: minpoly = {1,21,5}; break;
			case 29: minpoly = {1,24,2}; break;
			case 31: minpoly = {1,29,3}; break;
			case 41: minpoly = {1,38,6}; break;
			case 43: minpoly = {1,42,3}; break;
			case 59: minpoly = {1,58,2}; break;
			case 61: minpoly = {1,60,2}; break;
			case 67: minpoly = {1,63,2}; break;
			case 71: minpoly = {1,69,7}; break;
			case 79: minpoly = {1,78,3}; break;
			case 83: minpoly = {1,82,2}; break;
			case 89: minpoly = {1,82,3}; break;
			case 101: minpoly = {1,97,2}; break;
			case 103: minpoly = {1,102,5}; break;
			case 109: minpoly = {1,108,6}; break;
			case 113: minpoly = {1,101,3}; break;
			case 131: minpoly = {1,127,2}; break;
			case 139: minpoly = {1,138,2}; break;
			case 149: minpoly = {1,145,2}; break;
			case 151: minpoly = {1,149,6}; break;
			case 181: minpoly = {1,177,2}; break;
			case 211: minpoly = {1,207,2}; break;
			case 229: minpoly = {1,228,6}; break;
			case 239: minpoly = {1,237,7}; break;
			case 281: minpoly = {1,280,3}; break;
			case 349: minpoly = {1,348,2}; break;
			case 379: minpoly = {1,374,2}; break;
			case 419: minpoly = {1,418,2}; break;
			case 461: minpoly = {1,460,2}; break;
			case 571: minpoly = {1,570,3}; break;
			case 659: minpoly = {1,655,2}; break;
			case 769: minpoly = {1,765,11}; break;
			case 911: minpoly = {1,909,17}; break;
			case 1231: minpoly = {1,1229,3}; break;
			case 1429: minpoly = {1,1425,6}; break;
        }
    }
    else if(n==3)
    {
        switch(q)
        {
            case 3: minpoly = {1,0,2,1}; break;
			case 7: minpoly = {1,6,0,4}; break;
			case 11: minpoly = {1,0,2,9}; break;
        }
    }
    else if(n==4)
    {
        switch(q)
        {
            case 3: minpoly = {1,2,0,0,2}; break;
			case 5: minpoly = {1,0,4,4,2}; break;
			case 7: minpoly = {1,0,5,4,3}; break;
			case 11: minpoly = {1,0,8,10,2}; break;
			case 13: minpoly = {1,0,3,12,2}; break;
        }
    }
    else if(n==6)
    {
        switch(q)
        {
            case 5: minpoly = {1,0,1,4,1,0,2}; break;
        }
    }
    return minpoly;
}
