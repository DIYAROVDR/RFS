#include "mathhelper.h"

MathHelper::MathHelper()
{

}


double MathHelper::factorial(int n)
{
    if (n < 0)
    {
        return 0;
    }
    return !n ? 1 : n * factorial(n - 1);
}
