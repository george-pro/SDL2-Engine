@ECHO OFF

SET cpp_folder=source

g++ -c %cpp_folder%/main.cpp
g++ -c %cpp_folder%/Game.cpp
g++ -c %cpp_folder%/Application.cpp
g++ -c %cpp_folder%/Keyboard.cpp
g++ -c %cpp_folder%/Key.cpp
g++ -c %cpp_folder%/Sprite.cpp

g++ main.o Game.o Application.o Keyboard.o Key.o Sprite.o -o run.exe -lmingw32 -lSDL2main -lSDL2

del *.o

pause