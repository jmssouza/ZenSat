#!/usr/bin/env python
from ina219 import INA219
from ina219 import DeviceRangeError

SHUNT_OHMS = 0.1

def escreve(val):
    aux = 0
    temp = 0
    arq = open("ps_aux_1.dat","wb")
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

    inaBateria = INA219(SHUNT_OHMS, 1, address=0x40)
    inaBateria.configure()
    v_bat = inaBateria.voltage()
    c_bat = inaBateria.current()
    '''print("Battery:")
    print("Voltage %.3f mV" % v_bat)
    print("Current %.3f mA" % c_bat)'''
    values.append(v_bat)
    values.append(c_bat)

    ina5v = INA219(SHUNT_OHMS, 1, address=0x41)
    ina5v.configure()
    v_5v = ina5v.voltage()
    c_5v = ina5v.current()
    '''print("5v:")
    print("Voltage %.3f mV" % v_5v)
    print("Current %.3f mA" % c_5v)'''
    values.append(v_5v)
    values.append(c_5v)

    ina3v = INA219(SHUNT_OHMS, 1, address=0x44)
    ina3v.configure()
    v_3v = ina3v.voltage()
    c_3v = ina3v.current()
    '''print("3v:")
    print("Voltage %.3f mV" % v_3v)
    print("Current %.3f mA" % c_3v)'''
    values.append(v_3v)
    values.append(c_3v)

    inaCharger = INA219(SHUNT_OHMS, 3, address = 0x45)
    inaCharger.configure()
    v_Ch = inaCharger.voltage()
    c_Ch = inaCharger.current()
    '''print("Charger:")
    print("Voltage %.3f mV" % v_Ch)
    print("Current %.3f mA" % c_Ch)'''
    values.append(v_Ch)
    values.append(c_Ch)

    #print(values)

    escreve(values)

if __name__ == "__main__":
    read()
