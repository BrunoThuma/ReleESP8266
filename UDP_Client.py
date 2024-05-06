#!/usr/bin/env python3
import socket
import sys
import time

print("iniciando ...")

ipESP = ""
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

porta = 4210

def registrarESP(s):
    global ipESP
    s.sendto(bytes("Register", "utf-8"), ("192.168.15.255", porta))
    try:
        data, addr = s.recvfrom(1024)
        if len(data):
            print(addr," enviou: ", data)
            ipESP = addr
            return False
        else:
            return True
    except:
        print('\nErro ao registrar')
        return True

while registrarESP(s):
    print("Esperando resposta do sensor na porta ", porta)
    time.sleep(1)

print('Rele registrado em ', ipESP)

while True:
    
    print("Entre com a mensagem: ")
    msg = input()

    while msg == "":
        print("Entre com a mensagem: ")
        msg = input()
    msg = bytes(msg, "utf-8")


    s.sendto(msg, ipESP)
    s.setblocking(0)
    time.sleep(1)
    try:
        data, addr = s.recvfrom(1024)
        print(addr," enviou: ", data)
    except:
        print("Nao houve confirmacao de recebimento")
        break

print("o cliente encerrou")
s.close()