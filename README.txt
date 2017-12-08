SSC144 – Arquitetura de Computadores
Prof.a Dra. Sarita Mazzini Bruschi

Trabalho Prático - Desenvolvimento de um Recurso Educacional para ensinar Pipeline do MIPS

Grupo:
Allan Silva Domingues - 9293290
Chan Ken Chen - 9436170
Elisa Saltori Trujillo - 8551100
Gustavo Moreira Pereira - 9312964


Sobre o projeto:
	O projeto foi feito utilizando a linguagem C++. A fim de criar uma interface gráfica para o simulador, foi utilizado o framework Qt. O projeto pode ser aberto e compilado por meio da IDE
Qt Creator, utilizando o arquivo .pro contido no diretório.
	A fim de que não seja necessária a recompilação para a execução do simulador, foi fornecido junto ao envio um arquivo .AppImage, executável nas principais distribuições Linux.


Instruções para execução:
	
	Estando no diretório do arquivo .AppImage, deve-se executar os seguintes comandos:
		chmod a+x sim.AppImage
		./sim.AppImage

	Os seguintes arquivos deverão estar presentes no diretório do aplicativo:

		instrucoes.in
			Este arquivo contém as instruções a serem executadas pelo programa. Ele deve conter uma instrução por linha. O primeiro item corresponde à posição de memória 0 e os demais às posições seguintes (4, 8, 12...).

			Exemplo:
				add $r4, $r10, $r1
				lw $r2, 4($r0)
				beq $r1, $r3, 4

		registrador.in
			Este arquivo contém os valores contidos inicialmente na memória de dados. Ele deve conter um número inteiro por linha. O primeiro item corresponde à posição de memória 0 e os demais às posições seguintes (4, 8, 12...).

			Exemplo:
				1
				2
				50
				987
				12
			
	Arquivos de exemplo prontos para utilização foram fornecidos no diretório do projeto, junto ao aplicativo.

Instruções de uso:
	Na interface gráfica, há duas opções disponíveis para o usuário:
		
		Próximo ciclo
			Avança a execução do pipeline em um ciclo.
		
		Resetar
			Reinicia a execução das instruções fornecidadas.

	Caso o usuário deseje executar um arquivo diferente de instruções, é necessário que ele substitua o arquivo instrucoes.in presente no diretório e reabra o aplicativo do simulador.

