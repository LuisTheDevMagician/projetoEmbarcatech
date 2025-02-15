# Projeto Embarcatech - Display OLED com Raspberry Pi Pico

Este projeto demonstra como utilizar um display OLED SSD1306 com um Raspberry Pi Pico, controlando a exibição de textos e imagens através de botões. O código foi desenvolvido em C utilizando o SDK do Raspberry Pi Pico.

---

## Descrição do Projeto

O projeto consiste em um sistema que exibe uma mensagem de boas-vindas no display OLED. Quando os botões A ou B são pressionados, diferentes imagens são exibidas no display. O código foi desenvolvido para ser simples e fácil de entender, sendo ideal para quem está começando com o Raspberry Pi Pico e displays OLED.

---

## Componentes Necessários

- Raspberry Pi Pico
- Display OLED SSD1306 (128x64 pixels)
- 2 Botões
- Resistores de pull-up (se necessário)
- Jumpers e protoboard

---

## Conexões

| Raspberry Pi Pico | Display OLED SSD1306 | Botão A | Botão B |
|-------------------|----------------------|---------|---------|
| GPIO 14 (SDA)     | SDA                  | -       | -       |
| GPIO 15 (SCL)     | SCL                  | -       | -       |
| 3.3V              | VCC                  | -       | -       |
| GND               | GND                  | -       | -       |
| -                 | -                    | GPIO 5  | GPIO 6  |
| -                 | -                    | GND     | GND     |

---

## Funcionalidades

1. **Inicialização do Display**: O display é inicializado e uma mensagem de boas-vindas é exibida.
2. **Controle por Botões**:
   - **Botão A**: Exibe uma imagem pré-definida no display.
   - **Botão B**: Exibe outra imagem pré-definida no display.

---

## Estrutura do Código

- **Inicialização**: O código inicializa os pinos dos botões e o display OLED.
- **Loop Principal**: O programa entra em um loop infinito onde verifica o estado dos botões e atualiza o display conforme necessário.

---

## Como Compilar e Executar

### 1. Configuração do Ambiente
   - Instale a exntensão Raspberry Pi Pico no VS Code.

### 2. Compilação
   - Clone este repositório.
   - Navegue até o diretório do projeto e compile o código usando a extensão Raspberry Pi Pico no VS Code.


### 3. Upload para o Raspberry Pi Pico
   - Conecte o Raspberry Pi Pico ao computador no modo de bootloader.
   - Copie o arquivo `.uf2` gerado para o Pico.
   - Ou na própia extensão tem uma função chamada 'Run Project(USB)'. Dessa forma não será necessário copiar o arquivo `.uf2` diretamente para placa.

---

## Exemplo de Uso

1. Conecte os componentes conforme o diagrama de conexões.
2. Carregue o código no Raspberry Pi Pico.
3. Ao ligar o sistema, a mensagem de boas-vindas será exibida no display.
4. Pressione os botões A ou B para alternar entre as imagens exibidas no display.

---

**Autor**: Luis Eduardo  
**Projeto**: Embarcatech  
**Data**: 15/02/2025  

---

**Link para o vídeo no YouTUbe**: https://youtu.be/Cmp-5v7_Efw
