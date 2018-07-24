#!/usr/bin/env python
from ina219 import INA219
from ina219 import DeviceRangeError

SHUNT_OHMS = 0.1

def escreve(val):
    aux = 0
    temp = 0
    arq = open("ps_aux_2.dat","wb")
    for i in range(8):
        aux = val[i]*1000
        temp = int(aux)
        aux = float(temp)
        temp = aux/1000
        strg = str(temp)
        ap = len(strg)
        while (ap<9):
            arq.write("0")
            ap += 1
        arq.write(strg)
        arq.write(";")
    arq.close()

def read():
    values = []

    inaSol1 = INA219(SHUNT_OHMS, 1, address=0x40)
    inaSol1.configure()
    v_s1 = inaSol1.voltage()
    c_s1 = inaSol1.current()
    '''print("SOL1:")
    print("Voltage %.3f mV" % v_s1)
    print("Current %.3f mA" % c_s1)'''
    values.append(v_s1)
    values.append(c_s1)

    inaSol2 = INA219(SHUNT_OHMS, 1, address=0x40)
    inaSol2.configure()
    v_s2 = inaSol2.voltage()
    c_s2 = inaSol2.current()
    '''print("SOL2:")
    print("Voltage %.3f mV" % v_s2)
    print("Current %.3f mA" % c_s2)'''
    values.append(v_s2)
    values.append(c_s2)

    inaSol3 = INA219(SHUNT_OHMS, 1, address=0x40)
    inaSol3.configure()
    v_s3 = inaSol3.voltage()
    c_s3 = inaSol3.current()
    '''print("SOL3:")
    print("Voltage %.3f mV" % v_s3)
    print("Current %.3f mA" % c_s3)'''
    values.append(v_s3)
    values.append(c_s3)

    inaSol4 = INA219(SHUNT_OHMS, 1, address=0x40)
    inaSol4.configure()
    v_s4 = inaSol4.voltage()
    c_s4 = inaSol4.current()
    '''print("SOL4:")
    print("Voltage %.3f mV" % v_s4)
    print("Current %.3f mA" % c_s4)'''
    values.append(v_s4)
    values.append(c_s4)

    #print(values)

    escreve(values)

if __name__ == "__main__":
    read()
