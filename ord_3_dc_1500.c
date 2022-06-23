/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 3
Sampling Frequency: 1000 KHz
Cut Frequency: 1.500000 KHz
Coefficents Quantization: float

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.990619 + j -0.000001
z = 0.995266 + j -0.008123
z = 0.995266 + j 0.008123
***************************************************************/
#define NCoef 3
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.00000009589949295588,
        0.00000028769847886764,
        0.00000028769847886764,
        0.00000009589949295588
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        -2.98115051383676200000,
        2.96247826068065790000,
        -0.98132691750910928000
    };

    static float y[NCoef+1]; //output samples
    static float x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
