#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

void my_fscanf(FILE *fp, const char *format, ...){
	va_list list;
	int arg;
	double num;
	char t;
	while(*format){
		if(*format == '%'){
			format++;
			switch(*format){
				case 'd':
					while(isdigit(fp)){
					t = getc(fp);	
					arg = &atoi((void*)&t);
						num = num*10 + arg;
					}
					ungetc(num, fp);
				case 'c':
					arg = fgetc(fp);
					if(arg == '+')
						ungetc('+',fp);
					else if(arg == '-')
						ungetc('-',fp);
					else if(arg == '/')
						ungetc('/',fp);
					else if(arg == '*')
						ungetc('*',fp);
			}
		}
		else if(*format == ' '){
			format++;
			if(*format == '\n')
				break;
		}
	}
		
	va_end(list);
};
