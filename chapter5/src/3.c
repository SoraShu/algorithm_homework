#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize)
{
    int nfive = 0;
    int nten = 0;
    for (int i = 0; i < billsSize; ++i)
    {
        switch (bills[i])
        {
        case 5:
            ++nfive;
            break;
        case 10:
            --nfive;
            ++nten;
            break;
        case 20:
            --nten;
            --nfive;
            if (nten < 0)
            {
                ++nten;
                nfive -= 2;
            }
        }
        if (nfive < 0)
            return false;
    }
    return true;
}
