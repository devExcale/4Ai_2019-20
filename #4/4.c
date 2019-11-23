#include <stdio.h>
#define len 20
#define EOL '\n'

void zeroFill(char *str);

void main() {
	
	char str1[len], str2[len];
	
	printf("Inserire prima stringa: ");
	fgets(str1, len, stdin);
	
	zeroFill(str1);
	printf("%s", str1);
	
	printf("Inserire seconda stringa: ");
	fgets(str2, len, stdin);
	
	
}

void zeroFill(char *str) {
	int i=0, j;
	while(*(str+i) != '\n')
		i++;
	i++;
	*(str+len-1) = 0;
	for(j=len-2; j>i; j--)
		*(str+j) = '0';
}
