#include <openssl/des.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enc_ecb(char *in, char *key, char *out)
{
  FILE *fIn, *fOut;
  fIn = fopen(in, "rb");
  fOut = fopen(out, "wb");

  if (fIn == NULL || fOut == NULL)
  {
    printf("Erro na abertura do ficheiro!");
    exit(0);
  }

  DES_cblock bIn, bOut, Key2;

  DES_key_schedule ks;
  DES_set_odd_parity(&Key2);
  DES_set_key_checked(&Key2, &ks);

  while (!feof(fIn))
  {
    fread(&bIn, 8, 1, fIn);

    DES_ecb_encrypt(&bIn, &bOut, &ks, DES_ENCRYPT);

    fwrite(&bOut, 8, 1, fOut);
  }

  fclose(fIn);
  fclose(fOut);
}

void des_ecb(char *in, char *key, char *out)
{
  FILE *fIn, *fOut;
  fIn = fopen(in, "rb");
  fOut = fopen(out, "wb");

  if (fIn == NULL || fOut == NULL)
  {
    printf("Erro na abertura do ficheiro!");
    exit(0);
  }

  DES_cblock bIn, bOut, Key2;

  DES_key_schedule ks;
  DES_set_odd_parity(&Key2);
  DES_set_key_checked(&Key2, &ks);

  while (!feof(fIn))
  {
    fread(&bIn, 8, 1, fIn);

    DES_ecb_encrypt(&bIn, &bOut, &ks, DES_DECRYPT);

    fwrite(&bOut, 8, 1, fOut);
  }

  fclose(fIn);
  fclose(fOut);
}

int main(int argc, char *argv[])
{
  if (argc > 5)
  {
    printf("Too many arguments supplied.\n");
  }
  else if (argc < 5)
  {
    printf("4 arguments expected.\n");
  }
  else
  {
    if (strcmp(argv[1], "-e") == 0)
    {
      enc_ecb(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
      des_ecb(argv[2], argv[3], argv[4]);
    }
  }

  return 0;
}