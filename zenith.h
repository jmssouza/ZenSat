/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ZenSat v1.0 - CubeSat                                                           *
 * Authors: João Matheus Siqueira Souza      (jmssouza)                            *
 *          Orlando Wozniak de Lima Nogueira (orlandowzk97)                        *
 *          Vinicius Eiji Sasaki             (sasakivinicius)                      *
 * São Carlos School of Engineering - University of São Paulo                      *
 * First semester - 2018                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CODE_ZENITH_H
#define CODE_ZENITH_H




    //Libraries are declared here
        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <time.h>
        #include <sys/ioctl.h>
        #include <linux/spi/spidev.h>
        #include <errno.h>
        #include <wiringPi.h>
        #include <wiringSerial.h>
        #include <unistd.h>
        #include <fcntl.h>
        #include <sys/ioctl.h>
        #include <linux/i2c-dev.h>
        #include <string.h>
        #include "constants.h"
        #include "zenith.c"

    //Functions body are declared here
        //Files manipulation functions
            int valueGetter(char *file_name, int *value);
            int valueSetter(char *file_name, int value);
            int writeMessage(char *file_name, char *message, int position, int size, int check);
            int readMessage(char *file_name, char *message, int position, int size, int check);
        //General purpose functions
            void delay(unsigned int micros);
            void reverse(char *str, int len);
            int  intToStr(int x, char str[], int d);
            void ftoa(float n, char *res, int afterpoint);
            int  correctValue(int *values);
            void tenBlock(char *str);
            int  headerInterface();
            void getDate(char *time);
        //Package manipulation functions
            int blockBuilder(char *block, int operating_mode, int whoami, int aux);
            int packageCreator(char *pack_num_file, char *pack_cycle_file, char *block, char *message);
            int missedPackagesChecker(int expected_package, int received_package, int expected_cycle, int received_cycle);
            int packageAnalyzer();
        //Initialize and check functions
            int createBackup();
            int recoveryFiles();
            int initializingCubeSat(int check);
        //Communication functions
            int write_i2c(char *file_name, int packet, int qt, int addr,int chan);
            int read_i2c(char *file_name, int position, int addr,int chan);
            int tx_uart (char *str, int tam);
            int rx_uart (char *str);
            int spiTxRx(unsigned char txDat, int fd);
            void spi_str_tx(unsigned char* str, int size);
            int sendSimpleMessage(char *block, int op_mode, int whoami, int aux);
            int powerSupplyMaster();
            int powerSupplySlave();
            int computerVision();
        //CubeSat missions functions
            int standardState();
            int healthInfo();
            int powerSupplyCheck();
            int oneAxisStabilization();
            int horizonDetermination();
            int pointing();
            int livefeed();
            int temperatureMonitor();
        //Base interface functions
            int interfaceOperator();
            int displayData(char *package);
            int changeOperatingMode();
            int checkZenSatState();
            int readPackages(int mode);
            int changeToMasterMode();
            int shutdownZenSat();
        //Main functions
            int CubeSatSlave();
            int CubeSatMaster();
            int Base();
        //Test functions
            long int file_size(char* file_name);
            int livefeed_file_check();
            int livefeed_w_message(char* file_name, char* info, int size);
            int livefeed_p_creator(char *pack_num_file, char *pack_cycle_file, char *block, char *package);
            void livefeed_p_to_b(char* block, char* package);
            int livefeed_tx();
        //Install functions
            int createFile(char *file_name);
            int createZenithFiles();
            int compileCodes(int mode);
            int installer();

#endif //CODE_ZENITH_H
