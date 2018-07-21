#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int tx_uart (char * a, int tam){
  int serial_port, i,j,aux;
  char* senddat;
  if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0){	//open serial port
    fprintf (stderr, "Unable to open /dev/ttyAMA0\n");
    return 1;
  }

  if (wiringPiSetup () == -1){					//start wiringPi setup
    fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
    return 1;
  }
  j = 0;
  while (tam>0){
	serialPutchar(serial_port, a[j]);	
	tam--;
	j++;
}		
  
  
}



#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int rx_uart (char * dat){
  int serial_port, i,aux;
  //char dat [20];
  
  if ((serial_port = serialOpen ("/dev/ttyS0", 9600)) < 0){	//open serial port
    fprintf (stderr, "Unable to open /dev/ttyAMA0\n");
    return 1;
  }

  if (wiringPiSetup () == -1){					//start wiringPi setup
    fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
    return 1;
  }


  aux = 1;
  i = 0;
  while(aux){
	if(serialDataAvail(serial_port)){
		while (aux){
		if (serialDataAvail(serial_port)){
		dat[i] = serialGetchar(serial_port);
		if (dat[i] == '\0')
		   aux = 0;		//receive character from the serial port
		fflush(stdout);
		i++;}
	   }
  	//printf("chegou %s\n", dat);	
	//i = 0;
  }
}
}