/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int Perceptron(
    int X1,
    int X2,
    float W1,
    float W2,
    float Wb,
    float Bias
)
{
    int i;
    float Compute;
    int Y;
    //Initialize
    Y = 5; // just to see the final output of y differnt than 0
    Compute = 0;
    Compute = (W1 * X1) + (W2 * X2) + (Bias * Wb);
    //printf ("\nCompute %0.2f\n", Compute);
    
    if (Compute > 0) {
        Y = 1;
    } else {
        Y = 0;
    }

    return Y;
}

int main ()
{
    float W1;
    float W2;
    float Wb;
    int Bias;
    int i;
    int Iteration;
    int Count;
    float Compute;
    float LearningRate;
    float DeltaW1;
    float DeltaW2;
    float DeltaWb;
    float Error;
    int X1[] = {0,0,1,1};
    int X2[] = {0,1,0,1};
    int Target[]  = {1,0,0,1}; 
    float Current[4];
   
    DeltaW1 = DeltaW2 = DeltaWb = 0;
    Iteration = 0;
    Count = 0;
    W1 = 0.5;
    W2 = 1;
    Wb = 0.25;
    LearningRate = 0.25;
    Bias = 1; // 2 for NAND, 1 for NOR, -1 for AND (weights are 1)
    
    for (i=0; i<4; i++) {
        Current[i] = Perceptron (X1[i], X2[i], W1, W2, Wb, Bias);
        printf ("Current[%d] %f\n", i, Current[i]);
        while (Current[i] != Target[i]) 
        {
            Iteration += 1;
            // Gradient Descent
            Error = Target[i] - Current[i];
            DeltaW1 = Error * X1[i] * LearningRate;
            DeltaW2 = Error * X2[i] * LearningRate;
            DeltaWb = Error * 1 * LearningRate;
            W1 += DeltaW1;
            W2 += DeltaW2;
            Wb += DeltaWb;
            // end
            Current[i] = Perceptron (X1[i], X2[i], W1, W2, Wb, Bias);
            printf ("Input\tCurrent\tError\tDeltaW1\tDeltaW2\tDeltaWb\tIteration\n");
            
            printf ("%d\t %0.2f\t %0.2f\t %0.2f\t %0.2f\t %0.2f\t %d\n", i, Current[i], Error, DeltaW1, DeltaW2, DeltaWb, Iteration);
            if (Iteration == 10) {
                break;
            }
            
        } 
        Count+= Iteration;
        Iteration = 0; //reset 
    }
    printf ("\nCount %d\n", Count);
    printf ("Trained Weights\n");
    printf ("W1 %0.2f  W2 %0.2f Wb %0.2f\n", W1, W2, Wb);
    
    //accuracy test
    printf ("Accuracy test\n");
    for (i=0; i<4; i++) {
        Current[i] = Perceptron (X1[i], X2[i], W1, W2, Wb, Bias);
        printf ("Current %0.2f Target %d\n", Current[i], Target[i]);
        if (Current[i] != Target[i]) {
            printf ("Accuracy test failed for inputs %d\n", i);
        }
    }
}



