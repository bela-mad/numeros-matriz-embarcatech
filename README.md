<samp>
<h1 align="center"> Números na Matriz de LED :desktop_computer: </h1>
  
<h2 align="center"> Sobre :pencil: </h2>

<p> &emsp;&emsp;&emsp;&emsp; Repositório com o objetivo de consolidar a compreensão dos conceitos relacionados ao uso de interrupções no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, como parte de uma tarefa desenvolvida na Unidade 4 do Capítulo 4 da EmbarcaTech, residência de Sistemas Embarcados. Essa tarefa foi desenvolvida pela residente Isabela Madureira.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar os seguintes componentes:

  1. Matriz 5x5 de LEDs (endereçáveis) WS2812, conectada à GPIO 7;
  2. LED RGB, com os pinos conectados às GPIOs (11, 12 e 13);
  3. Botão A conectado à GPIO 5;
  4. Botão B conectado à GPIO 6.

 &emsp;&emsp;&emsp;&emsp; O programa deve possuir as seguintes funcionalidades:

<p align="justify">  1. O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo; </p>
<p align="justify">  2. O botão A deve incrementar o número exibido na matriz de LEDs cada vez que for pressionado; </p>
<p align="justify">  3. O botão B deve decrementar o número exibido na matriz de LEDs cada vez que for pressionado; </p>
<p align="justify">  4. Os LEDs WS2812 devem ser usados para criar efeitos visuais representando números de 0 a 9. A formatação fixa é que cada número deve ser exibido na matriz em um formato fixo, como
caracteres em estilo digital (ex.: segmentos iluminados que formem o número) e, alternativamente, é permitido utilizar um estilo criativo, desde que o número seja claramente identificável. </p>

<h3> Estruturação dos Arquivos </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de uma pasta chamada 'wokwi', com os arquivos diagram.json e wokwi.toml (para a simulação no Wokwi), uma pasta chamada 'include', que possui 4 arquivos na extensão .c, que são: animation.c (que organiza as funções relacionadas à animação), button.c (que organiza as funções relacionadas aos botões), led-rgb.c (que organiza as funções relacionadas ao LED RGB) e matriz_led.c (que organiza as funções relacionadas à matriz de LEDs), 4 arquivos na extensão .h, que são: animaton.h, button.h, led-rgb.h e matriz_led.h (em que ambos possuem o cabeçalho das funções) e um arquivo ws2818b.pio, e os arquivos contador-embarcatech.c (que gerencia todo o projeto) e READ.ME (descrição do projeto).

<h3></h3>
<h2 align="center"> Vídeo :video_camera: </h2>
<p align="justify"> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>
<p align="center"> https://youtube.com/shorts/0zFoVwcjHgA?feature=share </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Conectar a placa BitDogLab em modo BOOTSEL;
- Compilar e executar o projeto.

</samp>
