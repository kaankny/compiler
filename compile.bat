
nasm -o win64demo.obj -fwin64 output.asm 
gcc -m64 win64demo.obj -o a.exe