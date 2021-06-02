#ifndef TRIGCALCX_H
#define TRIGCALCX_H


class TrigCalcx
{
public:
    TrigCalcx();
    struct patch_formulas{
        int initSinMul = 9;
        int lengthStep = 20;
        int lengthMax = 30;
        int anASib = 15;
        int angPropCircle = 180;
        int lineParam = 2;
        int textCon = 5;
    };
    patch_formulas tr_calc;
};

#endif // TRIGCALCX_H
