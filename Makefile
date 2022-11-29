default:
	gcc src/*.c -o Run.exe -O2 -Wall -Wno-missing-braces -I include/ -I Headers/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	run