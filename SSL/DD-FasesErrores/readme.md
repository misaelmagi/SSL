Usando Windows como SO y gcc como compilador.
1-Genero archivo "hello2.c".
2-Genero archivo "hello2.i" en base a "hello2.c" con el comando:
	gcc -E hello2.c -o hello2.i
	En "hello2.i" se observa que el preprocesamiento elimino el "#include <stdio.h>" y "/*medio*/".
	El archivo contiene las declaraciones de la biblioteca "stdio", el archivo sigue siendo legible.
3-Genero archivo "hello3.c".
4-Significa que la funcion printf se encuentra declarada con ese prototipo.
5-Genero archivo "hello3.i" en base a "hello3.c" con el comando:
	gcc -E hello3.c -o hello3.i
	En "hello3.i" se encuentra el mismo contenido que en "hello3.c" (con algunos encabezados) ya que en este ultimo no habia comentarios ni includes.
	A diferencia de "hello2.i", "hello3.i" no contiene las declaraciones de la biblioteca "stdio", ya que no se hizo
	la inclusion de dicha biblioteca en "hello3.c"
6-Intento ensamblar "hello3.i" con el comando:
	gcc -S hello3.i -o hello3.s
	Pero obtengo el siguiente error:
		hello3.c: In function 'main':
		hello3.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
		prontf("La respuesta es %d\n");
		^~~~~~
		hello3.c:4:2: error: expected declaration or statement at end of input.
	Esto se debe a que no hay llave de cierre para main().
7-Genero el archivo "hello4.c" agregando la llave de cierre para main().
  A continuacion genero "hello4.i" en base a "hello4.c" con el siguiente comando:
  gcc -E hello4.c -o hello4.i
  A continuacion genero "hello4.s" a partir de "hello4.i" con el siguiente comando:
  gcc -S hello4.i -o hello4.s
  Este proceso genera el siguiente warning:
	hello4.c: In function 'main':
	hello4.c:4:2: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
	prontf("La respuesta es %d\n");
	^~~~~~
8-El archivo "hello4.s" es el archivo Assembler que se corresponde con el codigo fuente en "hello4.c",
  que se genero especificamente con el set de instrucciones de la maquina donde se genero el archivo .s:
		.file	"hello4.c"  /* El nombre del archivo fuente */
		.def	___main;	.scl	2;	.type	32;	.endef  
		.section .rdata,"dr"  /* la cadena "La respuesta es %d\12\0" es incluida en la seccion ".rdata" */
	LC0:	
		.ascii "La respuesta es %d\12\0" 
		.text
		.globl	_main
		.def	_main;	.scl	2;	.type	32;	.endef /* definicion de main como global */
	_main:
	LFB0:
		.cfi_startproc
		pushl	%ebp
		.cfi_def_cfa_offset 8
		.cfi_offset 5, -8
		movl	%esp, %ebp
		.cfi_def_cfa_register 5
		andl	$-16, %esp
		subl	$32, %esp 
		call	___main /* llama a main */
		movl	$42, 28(%esp)
		movl	$LC0, (%esp)
		call	_prontf /* llama a prontf */
		movl	$0, %eax
		leave
		.cfi_restore 5
		.cfi_def_cfa 4, 4
		ret
		.cfi_endproc
	LFE0:
		.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
		.def	_prontf;	.scl	2;	.type	32;	.endef
9- Genero el archivo "hello4.o" en base a "hello4.s" con el siguiente comando:
	gcc -O hello4.s -o hello4.o
	El proceso devuelve el siguiente error:
		C:\Users\admin1\AppData\Local\Temp\ccdxTWSi.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
		collect2.exe: error: ld returned 1 exit status
	Ya que "prontf" no esta definido, no se genera el archivo objeto.
10- El archivo ejecutable no se puede generar ya que no se genero el archivo objeto.
11- Genero "hello5.c" corrigiendo "prontf" por "printf" y genero el archivo ejecutable con el siguiente comando:
	gcc hello5.c -o hello5.exe
12- Ejecuto el archivo "hello5.exe" en la linea de comando, obteniendo la siguiente salida:
	La respuesta es 4200768
	Esto se debe a que a la sentencia printf("La respuesta es %d\n") le falta especificar el segundo argumento, el cual es esperado
	por la presencia de %d en el primer argumento. 
13- Genero "hello6.c" agregando la variable i como segundo parametro para printf, luego genero el ejecutable con el siguiente comando:
	gcc hello6.c -o hello6.exe
	Ejecuto "hello6.exe" en la linea de comando obteniendo el resultado esperado:
	La respuesta es 42
14- Genero el archivo "hello7.c" y genero el archivo ejecutable:
	gcc hello7.c -o hello7.exe
	El proceso devuelve el siguiente warning:
		hello7.c: In function 'main':
		hello7.c:3:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
		printf("La respuesta es %d\n", i);
		^~~~~~
		hello7.c:3:2: warning: incompatible implicit declaration of built-in function 'printf'
		hello7.c:3:2: note: include '<stdio.h>' or provide a declaration of 'printf'
	El warning se debe a que en "hello7.c" se omite la inclusion de "<stdio.h>" y una declaracion para "printf".
15- El programa igualmente funciona ya que, si bien printf no se encuentra declarada en el archivo fuente y no hay una libreria de referencia 
	incluida en la que se encuentre printf, es el Linker quien, ante la llamada a printf encuentra la definicion de la funcion en la bibilioteca standard-.