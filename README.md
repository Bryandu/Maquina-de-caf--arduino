# Máquina de Café em Arduino Uno

Este pequeno projeto feito com dois arduinos uno, ligados através de I2C, consiste em um sistema simples que prepara um café com leite e após uma certa quantidade de cafés servidos avisa que o café acabou. A pessoa pode escolher entre café puro ou café com leite. Também verifica se há um copo prensente, caso sontrário mostra um aviso na tela LCD.


## Files

São dois arquivos C++, um chamado Mestre que contém o código do Arduino mestre que envia informações para seu escravo. O outro arquivo chamado escravo recebe às informações do mestre para exibi-las no display LCD. 

###### Link para a simulação do projeto: https://www.tinkercad.com/things/1mH65scB19w-sistema-de-cafe
