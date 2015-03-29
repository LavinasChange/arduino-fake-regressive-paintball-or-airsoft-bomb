# arduino-fake-regressive-paintball-or-airsoft-bomb
Automatically exported from code.google.com/p/arduino-fake-regressive-paintball-or-airsoft-bomb
Will need a Arduino Mega 2560, a LCD 16x2 and a PS2 Keyboard

1 - Download the Code 2 - Download Arduino software 3 - Upload 4 - Configure 5 - Play Paintball

Prop Pump Use The device is switched on and off via a three way switch , where the lithium battery is connected to the middle of a side of the charger and the other arduino.Isto causes the material is mobile and can be recharged without need to open . The switch helps prevent players accidentally turn off the device , invalidating the game . Once connected , the LCD displays the password setting , where you set the password and then shown what was typed for two seconds , then is the time required in minutes , ex . 60 minutes and the same time a game 120 minutes, even if two hours of game play and so forth. At the end of configuration, the player has five seconds with audible indication that you can start the game.

The LCD displays the prompt code to disarm the device . After typing the code, you can not undo . It was well done to increase the tension during the game , as it will be in an unfavorable environment to disarm . In the first mistake , you will have 3 chances before " detonation " pump .

Arming the prop The LCD displays " Enter Code " . By entering the code on the keyboard arm , the digits appear on the first line , however, to make it even harder , the digit will be masked by a " " .

Pressing an incorrect digit . You should start to type the code from the beginning of his arrival to the device . Once the correct code is entered ( up to 15 digits) , the timer is still showing on the LCD and check should be tightened to enter.Não button you can undo this first version which was entered

While armed, the prop will " chirp " every typing of code, making it identified that someone is messing with the device. This makes the game becomes more exciting .

Disarming the prop The LCD displays the countdown on line two , and the text " Enter Code : " on line one . No switching required to enter the disarm code . The user can start typing the code and take as long as they want (assuming the weather does not end ) to enter. This entry code works the same as the Arm code , as you type the code on the keypad , the masked digits will appear on the top line if err, the text on the first line back to the previous state after informing the penalty . . The countdown will be disabled and hidden LCD and replaced with a message " disarmed the bomb."

After some time , you will have continued showing the message " OK , good day ! " Indicating that the game is over and then a 30 second countdown timer with audible warning will appear indicating that you can get on or off the device

When the detonation countdown end or miss 3 times the code disarmament , the bell / siren is activated displaying a string that indicates the explosion of the bomb, then a message " Dead Soldier " is displayed on the LCD screen .

Hardware information The stand can be powered by anything between 8.4V and 12V . If more than 12v , you use a heatsink or fan should be placed on the 5v voltage regulator to prevent it from shutting down due to overheating. Using less than 8.4v can result in hardware failures, using less than 5V and may damage the support. The maximum theoretical voltage is 30v . The audible alarm circuit shall be controlled by a solid state relay with a maximum current consumption of 1A .

////////////////////////////////////////////////////////////////////////////////////////

USO DA BOMBA

O dispositivo é ligado e desligado através de um interruptor de três vias, onde a bateria de lithium é ligada ao meio, de um lado o carregador e do outro o arduino.Isto faz com que o material seja móvel e que possa ser recarregado sem a necessidade de abrir. O interruptor ajuda a impedir que os jogadores desliguem acidentalmente o dispositivo, invalidando o jogo. Uma vez ligado, o LCD exibe a configuração da senha, onde você define o password e depois é mostrado o que foi digitado por dois segundos, em seguida é solicitado o tempo em minutos, ex. 60 minutos é o mesmo que uma hora de jogo, 120 minutos, o mesmo que duas horas de jogo e assim por diante. No final da configuração, o jogador tem cinco segundos com indicação sonora de que pode iniciar o jogo.

O LCD exibe o prompt do Código para desarmar o dispositivo. Após a digitação do código, não é possível desfazer. Foi feito assim para aumentar a tensão durante o jogo, uma vez que estará em um ambiente desfavorável para desarmar. No primeiro erro, você terá 3 chances antes da " detonação " da bomba.

ARMAR O DISPOSITIVO

O LCD exibe "Digite o Código:" . Ao digitar o código de braço no teclado , os dígitos aparecerão na primeira linha , no entanto, para dificultar ainda mais, o dígito será mascarado por um " ".

PRESSIONANDO O DÍGITO ERRADO

Você deve começar a digitar o código desde o início de sua chegada até o dispositivo. Uma vez que o código correto for digitado ( um máximo de 15 dígitos) , o temporizador é continua mostrando no LCD e para verificação deve ser apertada a tecla enter.Não é possível desfazer nessa primeira versão o que foi digitado

Embora armado, o prop vai " piar " a cada digitação de código, fazendo com que seja identificado que alguém está mexendo no dispositivo. Isso faz com que o jogo fique mais emocionante.

DESARMAR O DISPOSITIVO

O LCD exibe a contagem regressiva na linha dois , eo texto " Digite o Código:" na linha um. Não há interrupção necessária para digitar o código de desarme . O usuário pode começar a digitar o código e levar o tempo que eles querem (assumindo que o tempo não acabe ) para entrar. Esta entrada do código funciona da mesma forma o Código Arm, enquanto você digita o código no teclado , os dígitos mascarados aparecerão ao na linha superior, caso erre, o texto na primeira linha volta ao estado anterior depois de informar a penalidade. . A contagem regressiva será desativada e escondida do LCD e substituído por uma mensagem de " bomba desarmada " .

Depois de algum tempo, você terá continuação da mensagem exibindo "[OK, bom dia!]" indicando que o jogo acabou e então aparecerá um contador regressivo de 30 segundos com aviso sonoro para indicar que pode começar ou desligar o dispositivo

Detonação Quando a contagem regressiva acabar ou errar 3 vezes o código de desarmamento, a campainha / sirene é ativada exibindo uma sequência que indica a explosão da bomba , em seguida, uma mensagem de " Soldado Morto! " é exibido na tela LCD.

INFORMAÇÕES DE HARDWARE

O suporte pode ser alimentado por qualquer coisa entre 8.4V e 12V . Se mais de 12v , é utilizado um dissipador de calor ou ventilador deve ser colocado sobre o regulador de tensão de 5v para impedi-lo de ser encerrado devido a superaquecimento. Utilizando menos do que 8.4v pode resultar em falhas de hardware , e utilizando menos de 5v pode danificar o suporte . A tensão máxima teórica é 30v . O circuito de alarme sonoro deverá ser controlado por um relé de estado sólido com um consumo de corrente máximo de 1A .
