#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "Wallet.h"
#include "Asset.h"
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

class FileWriter
{
public:
    FileWriter();
    void saveWalletState(Wallet<Asset> &w);
    void loadWalletState(Wallet<Asset> &w);
private:
};

#endif // FILEWRITER_H
