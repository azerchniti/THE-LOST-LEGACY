prog: main.o mini.o background.o player.o text.o score.o  enemy.o enigma.o background_menu.o button_menu.o menu.o sound.o
	gcc main.o mini.o background.o player.o text.o score.o enemy.o enigma.o background_menu.o button_menu.o menu.o sound.o -o prog -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
mini.o:mini.c
	gcc -c mini.c -g
background.o:background.c
	gcc -c background.c -g
player.o:player.c
	gcc -c player.c  -g
text.o:text.c
	gcc -c text.c -g
score.o:score.c
	gcc -c score.c -g
enemy.o: enemy.c
	gcc -c enemy.c -g
enigma.o: enigma.c
	gcc -c enigma.c -g
background_menu.o: background_menu.c
	gcc -c background_menu.c -g
button_menu.o:button_menu.c
	gcc -c button_menu.c -g
menu.o:menu.c
	gcc -c menu.c -g
sound.o:sound.c
	gcc -c sound.c -g
	
