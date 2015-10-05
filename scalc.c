#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	int a;
	int b;
	int result;
	char op;

	if (argc != 4) {
		printf("Invalid parameters. Usage:\n");
		printf("scalc <operand> <operator> <operand>\n");
		printf("operand should be integers, and operator one of +, -, *"
								    " or /.\n");
		exit(1);
	}
	
	a = atoi(argv[1]);
	op = argv[2][0];
	b = atoi(argv[3]);

	switch(op) {
		case '+':
			result = a+b;
			break;
		case '-':
			result = a-b;
			break;
		case '*':
			result = a*b;
			break;
		case '/':
			if (b != 0) {
				result = a/b;
				break;
			}
		default:
			printf("Invalid operation!\n");
			exit(2);
	}
	
	printf("%d\n", result);
	return 0;
}

