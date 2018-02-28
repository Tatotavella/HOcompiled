En un archivo de texto `respuestas.md`:

1. Escriban qué esperan de cada uno de los pasos
2. ¿Qué agregó el preprocesador?
3. Identificar en la rutina de assembler las funciones
4. Explicar qué quieren decir los símbolos que se crean en el objeto
5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

1. En el primer paso, de preprocesamiento, vamos a obtener archivos de nuestro codigo con texto insertado en las directivas y los reemplazos de los macros. Después ocurre el paso más pesado de compilacion en donde se obtienen archivos escritos en Assembler. Luego se hace una traducción a lenguaje de máquina. Por último se realiza el linkeo de todos los archivos de objeto buscando definir todas aquellas variables y funciones que no lo estén.

2. El preprocesador agregó arriba del código de calculadora.c el contenido de calculadora.h y además muchas otras declaraciones de funciones que provienen de haber incluido stdio.h

3. Dentro de calculator.asm parece haber un bloque que corresponde a la función main (Marcado por main: y en la linea de abajo .LFB0:) en donde linea por linea parece haber instrucciones del tipo push, mov, and, call. Esta última hace referencia a las otras dos funciones presentes en el main: add_numbers y printf.
Así como para el main existe otro bloque para la función add_numbers en la cual hay presentes instrucciones del tipo push, mov, add y pop.
NO hay un bloque dedicado a la función printf. Seguramente sea debido a que no se encuentra su implementación, solo su declaración. Eso debería concretarse en el paso de linkeo.

4. Dentro del objeto tenemos lo siguiente: 
0000003d T add_numbers
00000000 T main
         U printf

Podemos ver las 3 funciones con letras en mayúscula (columna intermedia), eso quiere decir que las 3 funciones son accesibles desde fuera del objeto (descriptor). La primer columna hace referencia a la posición en memoria y la tercera es el nombre asignado a cada función (entrada). El descriptor T hace referencia a código que se ejecuta (en contraste a la letra D que se refiere a data). En cambio el descriptor U se refiere a undefined, algo que está en acuerdo a la ausencia de un bloque para la función printf en Assembler 

5.Los objetos de ejecutable son los siguientes:
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080484fc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048640 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a014 A __bss_start
0804a00c D __data_start
080484b0 t __do_global_ctors_aux
08048360 t __do_global_dtors_aux
0804a010 D __dso_handle
         w __gmon_start__
080484a2 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
080484a0 T __libc_csu_fini
08048430 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a014 A _edata
0804a01c A _end
080484dc T _fini
080484f8 R _fp_hw
080482b4 T _init
08048330 T _start
08048421 T add_numbers
0804a014 b completed.6159
0804a00c W data_start
0804a018 b dtor_idx.6161
080483c0 t frame_dummy
080483e4 T main
         U printf@@GLIBC_2.0
Aparecen muchas entradas nuevas y se puede ver que printf sigue indefinida pero ahora tiene un agregado (@@GLIBC_2.0), éste hace referencia a una biblioteca dinámica. Es decir que la implementación de la función printf no se encuentra dentro de este ejecutable, sino que la instrucción de qué hacer es leída de una biblioteca presente en la máquina.
También se puede notar que la variable sum, por ejemplo, presente en calculator.c, no genera un objeto ni en calculator.o ni en calculator.e. Esto se debe a que son variables internas de la función add_numers.
