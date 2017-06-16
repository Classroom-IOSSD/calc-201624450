#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	double operand1, operand2;
	char operator = ' ';
	double result;
	int line = 0;
	int i;
	double (*op) (double, double);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);	
		for(i=0; i<line-1; i++) {
			fscanf(fp, "%lf %c %lf",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				op = add;
				break;
				case '-':
				op = minus;
				break;
				case '*':
				op = mul;
				break;
				case '/':
				op = div;
				break;
			}		
			result = op(operand1, operand2);
			printf("%f %c %f = %f\n",operand1, operator, operand2, result);
		}
	}
	return 0;
}

