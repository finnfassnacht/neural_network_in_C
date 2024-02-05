# include <stdio.h>
int main(){
    // input layer with its values
    float inputs[] = {1,2,3,2.5};
    // weights an biases
    float weights[3][4] = {{0.2,0.8,-0.5,1.0},{0.5,-0.91,0.26,-0.5},{-0.26,-0.27,0.17,0.87}};
    float biases[3] = {2,3,0.5};
    // loop to multiply all inputs with weights and add the bias
    // loop trough number of resulting neurons 
    for (int x = 0; x < 3; x++){
        float neuron = 0;
        // loop trough input neurons and thier weights
        for (int i = 0; i < 4; i++){
            // multiply weight with input
            float output = (inputs[i]*weights[x][i]);
            neuron += output;

        }
        // add the bias
        neuron += biases[x];
        printf("neuron %i > %f\t",x,neuron);
        printf("\n");
    }
    return 0;
}