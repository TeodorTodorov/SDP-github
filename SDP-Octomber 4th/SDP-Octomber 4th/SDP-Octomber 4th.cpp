// SDP-Octomber 4th.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"UnionFind.h"
#include<iostream>

using namespace std;
int main()
{
	UnionFind* uf = new UnionFind(4);
	uf->connect(0, 1);
	uf->connect(0, 4);
	uf->connect(3, 4);
	cout << uf->checkConnectivity(0, 1);
	cout << uf->checkConnectivity(1, 0);
	cout << uf->checkConnectivity(1, 4);
	cout << uf->checkConnectivity(2, 4);
	cout << uf->checkConnectivity(3, 4);
    return 0;
}

