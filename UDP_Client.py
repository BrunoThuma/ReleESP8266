#!/usr/bin/env python3
import socket
import sys
import time

print("iniciando ...")

ipESP = ""
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

porta = 4210

def registrarESP(socket):
    global ipESP
    socket.sendto(bytes("Reg", "utf-8"), ("192.168.15.255", porta))
    try:
        data, addr = socket.recvfrom(1024)
        if len(data):
            print(addr," enviou: ", data)
            ipESP = addr
            return False
        else:
            return True
    except:
        print('\nErro ao registrar')
        return True

while registrarESP(s) or ipESP == "":
    print("Esperando resposta do ESP na porta", porta)
    time.sleep(1)

print('Rele registrado em ', ipESP)

while True:
    
    print("Entre com a mensagem: ")
    msg = input()

    if msg == "":
        print("Certeza que deseja encerrar? (Enter)Sim")
        msg = input()
        if msg == "":
            s.close()
            exit()
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