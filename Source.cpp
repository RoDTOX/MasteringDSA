#include <assert.h>
#include <limits.h>
#include <stdio.h>

enum E {
    E0,
    E1,
    E2 = 3,
    E3 = 3,
    E4,
    E5 = INT_MAX,
#if 0
    /* error: overflow in enumeration values */
    E6,
#endif
};
struct LUT_min_max { int min; int max; };
LUT_min_max LUT_Range_Values_IeEBII_Cnt_CLBStatSyncId[10] = { {1,2},{3,4} };
void myFunc()
{
    LUT_Range_Values_IeEBII_Cnt_CLBStatSyncId[0].min = 5;
}

int main(void) {
    myFunc();
    //LUT_Range_Values_IeEBII_Cnt_CLBStatSyncId[0].min = 0;
    printf("%d\n", LUT_Range_Values_IeEBII_Cnt_CLBStatSyncId[0].min);

    return 0;
}