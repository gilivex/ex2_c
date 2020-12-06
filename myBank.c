// BASAD
#include <stdio.h>
#include "myBank.h"
#define DiffArrFromAccounts 901
#define Rest  0
#define Status 1
#define True 1
#define False 0
#define Close 0
#define Open 1

double accounts[SumAccounts][2]={0};
int sizeAccounts = 0;
int sizeOpenAccounts = 0;

int isRealNumAccount(int account_num){
       if (account_num > 950 || account_num < 901)
    {
        printf("Account number %d not exist\n", account_num);
        return False;
    }
    return True;
}

int isPosAmount(int amount){
    if(amount < 0){
         printf("The amount negative\n");
         return  False;
    }
    return True;

}
double toTwoDigits( double amount){
    return ((int)(amount*100))/100.;
}



void open_account(double amount){
    if(isPosAmount(amount)){
       if (sizeOpenAccounts < SumAccounts){
           sizeOpenAccounts++;
           sizeAccounts++;
            for(int i=0; i<sizeAccounts; i++){
                if (accounts[i][Status] == Close){
                     accounts[i][Rest] =toTwoDigits(amount);
                     accounts[i][Status] = Open;
                     printf("This is your account number: %d\n" ,(i+DiffArrFromAccounts));
                     break;
                }
            }
       }
        else{
             printf("Sorry, the bank is full!!\n");
        }
    }
}

void rest(int account_num){
     if(isRealNumAccount(account_num)){
         printf("Your rest: %0.2lf\n", accounts[account_num-DiffArrFromAccounts][Rest]);
     }
}

void depositing_money(int account_num, double amount){
    if(isRealNumAccount(account_num) && isPosAmount(amount)){
        if(accounts[account_num-DiffArrFromAccounts][Status]==Open){
            accounts[account_num-DiffArrFromAccounts][Rest] =toTwoDigits(accounts[account_num-DiffArrFromAccounts][Rest]+ amount);
            printf("Your rest after the deposition: %0.2lf\n", accounts[account_num-DiffArrFromAccounts][Rest]);
        }
        else 
             printf("The accuont number: %d close\n", account_num);
    }
}

void withrawal_money(int account_num, double amount){
    if(isRealNumAccount(account_num) && isPosAmount(amount)){
        if (accounts[account_num-DiffArrFromAccounts][Rest] >= amount && accounts[account_num-DiffArrFromAccounts][Status]==Open){
            accounts[account_num-DiffArrFromAccounts][Rest] =toTwoDigits(accounts[account_num-DiffArrFromAccounts][Rest]- amount) ;
            printf("Rest: %0.2lf\n", accounts[account_num-DiffArrFromAccounts][Rest]);
        }
        else{
            printf("Sorry, the account number: %d close, or you don't have enough money in your account\n", account_num);
        }
    }
}

void close_account(int account_num){
   
    if(isRealNumAccount(account_num)){
        if (accounts[account_num- DiffArrFromAccounts][Status]==Open){
            accounts[account_num- DiffArrFromAccounts][Status]=Close;
            accounts[account_num- DiffArrFromAccounts][Rest]=0;
            sizeOpenAccounts--;
            printf("Account number %d closed\n", account_num);
        }
        else{
            printf("Cant close account number %d because the account was closed\n", account_num);
        }
    }
    
    

}

void add_interest(double interest){
    for(int i=0; i<sizeAccounts; i++){
        if(accounts[i][Status] == Open){
            accounts[i][Rest] =toTwoDigits(accounts[i][Rest]+ (interest*accounts[i][Rest])/100);
        }
    }
}

void print_open_account(){
    for(int i=0; i<sizeAccounts; i++){
        if(accounts[i][Status] == Open){
            printf("Account number: %d  Rest: %0.2lf\n", i+DiffArrFromAccounts, accounts[i][Rest]);
        }
    }
}

void close_all(){
    for(int i=0; i<sizeAccounts; i++){
        accounts[i][Rest] = 0;
        accounts[i][Status] = Close;
    }
}




