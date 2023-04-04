### Semáforo com botão de prioridade - README

Este código implementa um semáforo comum para dois sentidos de uma rua e um sinal de pedestres. Além disso, um botão de prioridade para pedestres é incluído no semáforo. O sistema funciona com ciclos de tempo predefinidos e muda automaticamente entre os sinais verde, amarelo e vermelho para os veículos e pedestres, de acordo com a ordem padrão. No entanto, se o botão de prioridade para pedestres for pressionado, o ciclo de tempo é interrompido, e o semáforo muda imediatamente para permitir a travessia segura dos pedestres.

## Componentes
- Arduino Uno
- 4x Led Vermelho
- 3x Led Amarelo
- 4x Led Verde
- 1x Botão de pressão
- 11x Resistor de 10kΩ
- Cabos Jumper

## Configuração
O código define os pinos que serão usados para cada componente e define suas funções no método setup().

Os pinos usados para o semáforo são:

```code
const int rua_a_desc_vermelho = 5;
const int rua_a_desc_amarelo = 4;
const int rua_a_desc_verde = 3;
const int rua_a_subin_vermelho = 8;
const int rua_a_subin_amarelo = 7;
const int rua_a_subin_verde = 6;
const int rua_b_vermelho = 11;
const int rua_b_amarelo = 10;
const int rua_b_verde = 9;
const int pedestre_vermelho = 12;
const int pedestre_verde = 13;
```
O botão de prioridade é definido como:

```code
const int botao_prioridade = 2;
```

O tempo de cada ciclo também pode ser definido:

```code
const int tempo_delayVerde = 4500;
const int tempo_delayAmarelo = 2500;
const int tempo_delayVermelho = 4500;
const int tempo_delayPassagemPedestre = 2500;
```

## Funcionamento

O programa é dividido em três funções principais, cada uma responsável por controlar um dos semáforos: ```coderotinaRuaA()```, ```coderotinaRuaB()``` e ```coderotinaPedestre()```. Cada rotina controla a troca de sinal em seu semáforo de acordo com o ciclo de tempo definido.

O botão de prioridade é verificado com a função ```codeverificaBotaoPressionado()```, que interrompe o ciclo de tempo atual caso o botão seja pressionado.

## Como Usar

- Conecte os componentes de acordo com o esquema apresentado.
- Carregue o código no Arduino Uno.
- Acione o botão de prioridade para testar o funcionamento do semáforo.
- Verifique a troca de sinais entre os semáforos.
- Também é possivel utilizar o ambiente de simulação https://www.tinkercad.com/

## Screenshots

![App Screenshot](https://github.com/bredbk/Sem-foro-com-bot-o-de-prioridade-Arduino/blob/main/demonstration.jpeg.jpeg))

## Autores

- [@Bredbk](https://www.github.com/bredbk)
