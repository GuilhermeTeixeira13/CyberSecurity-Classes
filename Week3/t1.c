#include<stdio.h>
#include<time.h>


void encrypt(char * in, char * out, int ikey){
	srand(ikey);

	FILE *fIN, *fOUT;
	fIN = fopen(in, "r");
	fOUT = fopen(out, "w");
	int b;
	while(!feof(fIN)){
		b = fgetc(fIN);
		//printf("%x\n",b);
		b = b ^ rand();
		fputc(b, fOUT);
	}
}

int main(){
	unsigned int ikey = 123456789;
	srand(ikey);
	int i;
	for(i=0; i<1000; i++){
		//printf("%u\n", (unsigned int) rand());
	}

	//encrypt("plaintext.txt", "ciphertext.txt", 123456789);
	encrypt("ciphertext.txt", "plaintext-2.txt", 123456789);

	return 0;
}
