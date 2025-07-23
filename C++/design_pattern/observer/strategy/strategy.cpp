#include <iostream>
#include "Business.h"
#include "StrategyClass.h"
#include "BubbleStrategy.h"

int main()
{
    //business
    Business* business = new Business();
    
    //strategy
    StrategyClass* strategy = new BubbleStrategy();

    //DI
    business->setStrategy(strategy);

    //use case of business
    business->engagement();

    delete business;

    return 0;
}
