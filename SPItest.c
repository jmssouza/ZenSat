#include <wiringPiSPI.h>
int main()
{int a;
char buffer[100];
a=wiringPiSPISetup(CHANNEL, 500000);
buffer[0] = 'x';
buffer[1] = 'y';
wiringPiSPIDataRW(CHANNEL, buffer, 2); // escreve (envia) 'xy'
buffer[0] = 0;
buffer[1] = 0;
wiringPiSPIDataRW(CHANNEL, buffer, 3); // Le 3 bytes
printf("recebido - %s",buffer);
return 0;
}
