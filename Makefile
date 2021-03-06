build:
gcc -Wfatal-errors \
-std=c99 \
./*.c \
-I"C:\SDL2\include" \
-L"C:\SDL2\lib" \
-lmingw32 \
-lSDL2main \
-lSDL2 \
-o exemple.exe
