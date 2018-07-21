
int powerSupplyMaster(){

    char ps_block[161];
    char aux1 [81];
    char a[2] = "x";
    int i;

    values[0] = '/0';

    //LEITURA INAS RASP MASTER E ESCRITA NO ARQUIVO PS_AUX
    system("python ina.py");
  
    //ENVIA CARACTERE VIA UART PARA RASP SLAVE PARA INICIAR LEITURA INAS RASP SLAVE
    tx_uart(a,1);

    //RECEBE VIA UART DADOS INA RASP SLAVE
    rx_uart(aux1); 
    //ESCRITA PS_AUX DADOS INA RASP SLAVE
    writeMessage(PS_AUX, aux1, 1, , 0);		
    //ESCREVER NO ARQUIVO PS_FILE, A PARTIR DO PS_AUX 
    readMessage(PS_AUX, ps_block, 0, PS_SIZE, 0);
    valueGetter(PS_NUMBER, &i);
    writeMessage(PS_FILE, ps_block, i+1, PS_SIZE, 0);
    valueSetter(PS_NUMBER, i+1);

    return 1;
}




int powerSupplySlave(){
	char aux[81];
	system("python ina2.py"); //LEITURA DADOS INAS RASP SLAVE E ESCRITA NO ARQUIVO PS_AUX2
	readMessage(PS_AUX2, aux, 0, 80, 0);	 //LEITURA DO ARQUIVO PS_AUX2
	tx_uart(aux,80);		// ENVIO PARA A RASP MASTER OS DADOS DOS INAS DA RASP SLAVE

	return 1;

}