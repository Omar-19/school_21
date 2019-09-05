#include <stdio.h> 
#include <string.h> 
int main() 
{ 
//	char csrc1[100] = "Geeksfor"; 
//	memcpy(csrc1-1, csrc1, strlen(csrc1)+1);
//	//memmove(csrc2-1, csrc2, strlen(csrc2)+1); 
//	printf("memcpy =  %s\n", csrc1);
	
	char csrc2[100] = "Geeksfor"; 
//	memmove(csrc2-1, csrc2, strlen(csrc2)+1); 
	memmove(NULL, NULL, strlen(csrc2)+1);
	printf("memmove = %s\n", csrc2);
	return 0; 
} 
