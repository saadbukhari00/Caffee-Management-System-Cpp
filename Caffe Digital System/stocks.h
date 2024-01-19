#ifndef STOCKS_H
#define STOCKS_H

#include "project.h"

void displaybyprice();
void displaybyquantity();
void displaybyname();
void searchitem();
int adminsearch();
void addstock();
void deletestock();
void updatestock();
void setcolor(int color);
void ordermore();
int stockcount();
int outofstockcount();
int lowstockcount();
int totalsales();
void comparestocks();
void randomdecrease();


#endif