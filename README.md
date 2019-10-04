# PerceptronLogicGates
Realize all logic gates with single perceptron model.

Test accuracy - After weights have been trained for all 4 possible cases then rerun the inputs to see if the prediction is correct.

AND Gate
![ANDOutput](https://user-images.githubusercontent.com/56049621/66228932-8822ac00-e695-11e9-98ef-1048ae32051a.png)
Accuracy is 100%

NAND Gate
![NANDOp](https://user-images.githubusercontent.com/56049621/66229388-91f8df00-e696-11e9-9b0a-60863e512e05.png)
Accuracy is 25%

OR Gate
![OROp](https://user-images.githubusercontent.com/56049621/66229451-adfc8080-e696-11e9-885d-8bbc84779999.png)
Accuracy is 100%

NOR Gate
![NOROp](https://user-images.githubusercontent.com/56049621/66229443-aa68f980-e696-11e9-800f-c773f16a53d5.png)
Accuracy is 75%

XOR Gate
![XOROp](https://user-images.githubusercontent.com/56049621/66229469-b654bb80-e696-11e9-9e7f-e0a0c4ba76c0.png)
Accuracy is 50% but it could be 75% as the Linear separation can predict 3/4 outputs correctly.

XNOR Gate 
![XNOROp](https://user-images.githubusercontent.com/56049621/66229465-b2289e00-e696-11e9-8b0f-1170b3a5a526.png)
Accuracy is 75%

So we see that with the single perceptron training for the linear separation individually for each input isnt able to pass the accuracy test with 100% accuracy for OR, AND, NAND and NOR gates and atleast 75% accuracy for XOR and XNOR gates.
