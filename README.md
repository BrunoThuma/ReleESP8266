# ReleESP8266
Projeto com o intuito de fazer um interruptor conectado a rede para o meu quarto.

O modulo que utilizei é um muito semelhante ao da equipe do Felipe Folope em uma publicação sobre [Introdução ao Uso de Rele com ESP8266](https://www.filipeflop.com/blog/rele-wifi-com-esp8266/)

## final.ino
Arquivo com o codigo semi-funcional a ser carregado no modulo ESP, presente na pasta "final"

Os demais arquivos servem de suporte ou foram usados como referencia para a criação de final.ino


## Funcionamento
Para funcionamento do codigo final.ino é necessario, após baixar o arquivo final.ino, seguir os seguinter passos:
1. Inserir o ssid e senha de sua rede WiFi nas strings vazias das variaveis ssid e password, respectivamente.
2. Seguir os passos descritos [neste link](https://help.ubidots.com/en/articles/928408-program-the-esp8266-with-the-arduino-ide-in-3-simple-steps) para carregar o codigo para ele a partir de um arduino UNO
  - É possivel usar para esse item a imagem de referencia colocada nesse repo para melhor visualização das conexões propostas
3. Desfazer as preparações realizadas no passo anterior
4. Ligar o rele propriamente na fiação da luz
5. Alimentar o ESP com uma fonte apropriada

## Demais arquivos no repositorio
### ExibirSerial
Como o nome já diz exibe o que é mandado para o serial do modulo. 

O intuito desse codigo é poder ver as mensagens recebidas pelo modulo ESP atraves de um modulo Arduino conectado a suas portas seriais e por USB a um computador com serial aberta

### FelipeFolopeReleESP8266
Codigo do blog Felipe Folope sobre introdução ao modulo ESP acoplado a um rele

Disponivel [neste link](https://www.filipeflop.com/blog/rele-wifi-com-esp8266/) acessado por ultimo em 23/080/2022

### UDP_ServerESP8266
Codigo para transformar o modulo ESP em um servidor que constantemente ouve por chamadas na porta 4210

O codigo foi retirado de varias partes da web e compilado nesse cara ai. Somado as funcionalidades do codigo FelipeFolopeReleESP8266 que se criou a solução final

### UDP_Client.py
Codigo em python para cliente UDP com o objetivo de testar comunicação com o modulo uma vez tendo-o implementado

### Imagen de suporte
Imagem ilustrando a pinagem do modulo ESP para referencia
