#include <iostream>
#include <stdlib.h>
#include "IndividualRetirementAccount.h"
#include "BankDeposit.h"
#include "Contract.h"
#include "InvestmentFundShare.h"
#include "RealEstate.h"
#include "Wallet.h"
#include <stdio.h>
#include "Interface.h"
#include "Simulation.h"
#include "Utils.h"
#include <cstdlib>


using namespace std;



int main()
{
    srand(time(NULL));
    bool exit=false, isValid=false;
    int option = 0;
    Wallet<Asset> wallet;
    Interface interface;
    Simulation simulation;
    FileWriter fw;
    Utils utils;
    string msg = "", inp;

    fw.loadWalletState(wallet);
    cout << "Welcome to your wallet application!" << endl;

    while(!exit){
        fw.saveWalletState(wallet);
        interface.showMainMenu();
        while(!isValid){
            cout<<msg;
            cout <<"Your choice: ";
            cin>>inp;
            if(utils.is_number(inp)){
                isValid=true;
                option = atoi( inp.c_str() );
                msg="";
            }else{
                msg = "This is not a number!\n";
            }
        }
        isValid=false;
        msg="";


        system("cls");
        switch(option){
        case 1:
            interface.showAddMenu(wallet);
            break;
        case 2:
            if(wallet.getAssets().size()==0){
                cout<<"Nothing to remove."<<endl;
                system("pause");
                system("cls");
            }else interface.showRemoveMenu(wallet);
            break;
        case 3:
            interface.showViewMenu(wallet);
            break;
        case 4:
            interface.showEditMenu(wallet);
            break;
        case 5:
            interface.showBalance(wallet);
            break;
        case 6:
            simulation.beginSimulation(wallet);
            break;
        case 7:
            exit=true;
            wallet.getAssets().clear();
            break;
        }
    }
    return 0;
}


