/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ZenSat v1.0 - CubeSat                                                           *
 * Authors: João Matheus Siqueira Souza      (jmssouza)                            *
 *          Orlando Wozniak de Lima Nogueira (orlandowzk97)                        *
 *          Vinicius Eiji Sasaki             (sasakivinicius)                      *
 * São Carlos School of Engineering - University of São Paulo                      *
 * First semester - 2018                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CODE_CONSTANTS_H
#define CODE_CONSTANTS_H

//Values constants
    #define PACK_SIZE  255
    #define BLOCK_SIZE 248
    #define PASSWORD   0000
    #define TIME_SIZE  21
    #define PS_SIZE    161
    #define ADC_SIZE   61
    #define ENTRY_SZ   10


    #define LF_FILE         "livefeed_packages.dat"
    #define LF_NUM          "lf_num.dat"
    #define LF_CYCLE        "lf_cycle.dat"
    #define PICTURE         "picture.jpg"


    #define ADD_I2C_ATMEGA       0x08 //TEM QUE ARRUMAR
    #define ADD_I2C_ATMEGA_BASE  0x08
    #define COD_VISAO       "VisaoCubeSat.py"
    #define PICTURE_NAME    "zenith.jpg"

//Files names
    #define CHECK_POWERED   "check_powered.dat"
    #define NEW_TM          "new_tm.dat"
    #define TM_FILE         "tm_file.dat"
    #define TM_NUMBER       "tm_num.dat"
    #define TM_CYCLE        "tm_cycle.dat"
    #define NEW_TC          "new_tc.dat"
    #define TC_FILE         "tc_file.dat"
    #define TC_NUMBER       "tc_num.dat"
    #define TC_CYCLE        "tc_cycle.dat"
    #define MISSED_PACKAGES "missed_packets.dat"
    #define MODE_FILE       "op_mode.dat"
    #define PS_FILE         "ps_file.dat"
    #define PS_NUMBER       "ps_num.dat"
    #define ADC_TX_FILE     "adc_tx_file.dat"
    #define ADC_TX_NUMBER   "adc_tx_num.dat"
    #define ADC_RX_FILE     "adc_rx_file.dat"
    #define ADC_RX_NUMBER   "adc_rx_num.dat"
    #define FILE_CV         "adc_cv.dat"
    #define STD_LOOP        "std_loop.dat"
    #define PS_AUX1         "ps_aux_1.dat"
    #define PS_AUX2         "ps_aux_2.dat"
    #define OPEN_CV         "open_cv.dat"

//Backup files
    #define CHECK_POWERED_CP   "check_powered_cp.dat"
    #define NEW_TM_CP          "new_tm_cp.dat"
    #define TM_FILE_CP         "tm_file_cp.dat"
    #define TM_NUMBER_CP       "tm_num_cp.dat"
    #define TM_CYCLE_CP        "tm_cycle_cp.dat"
    #define NEW_TC_CP          "new_tc_cp.dat"
    #define TC_FILE_CP         "tc_file_cp.dat"
    #define TC_NUMBER_CP       "tc_num_cp.dat"
    #define TC_CYCLE_CP        "tc_cycle_cp.dat"
    #define MISSED_PACKAGES_CP "missed_packets_cp.dat"
    #define MODE_FILE_CP       "op_mode_cp.dat"
    #define PS_FILE_CP         "ps_file_cp.dat"
    #define PS_NUMBER_CP       "ps_num_cp.dat"
    #define ADC_TX_FILE_CP     "adc_tx_file_cp.dat"
    #define ADC_TX_NUMBER_CP   "adc_tx_num_cp.dat"
    #define ADC_RX_FILE_CP     "adc_rx_file_cp.dat"
    #define ADC_RX_NUMBER_CP   "adc_rx_num_cp.dat"
    #define FILE_CV_CP         "adc_cv_cp.dat"
    #define STD_LOOP_CP        "std_loop_cp.dat"
    #define PS_AUX1_CP         "ps_aux_1_cp.dat"
    #define PS_AUX2_CP         "ps_aux_2_cp.dat"
    #define OPEN_CV_CP         "open_cv_cp.dat"

#endif //CODE_CONSTANTS_H
