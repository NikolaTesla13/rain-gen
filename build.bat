@ECHO OFF

g++ -c src/line.cpp bin/lib/glad.o  -o bin/lib/line.o -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32
g++ src/main.cpp bin/lib/glad.o bin/lib/line.o  -o bin/relase/game.exe -Wwrite-strings -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32

cd bin
cd relase
game
cd..
cd..