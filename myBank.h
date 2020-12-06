#ifndef _MYBANK_H_
#define _MYBANK_H_
#define SumAccounts 50
void open_account(double amount);

void rest(int account_num);

void depositing_money(int account_num, double amount);

void withrawal_money(int account_num, double amount);

void close_account(int ccount_num);

void add_interest(double interst);

void print_open_account();

void close_all();

int isPosAmount(int amount);

int isRealNumAccount(int account_num);

double toTwoDigits( double amount);
// Per account has two cells, the first for the rest and the second for account status: 0- close, 1- open.
extern double accounts[SumAccounts][2];

#endif