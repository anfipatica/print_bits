# Explicación ejercicio print_bits [ES]

### English version:
![CLICK HERE](https://github.com/anfipatica/print_bits/blob/main/README_EN.md)

-------------------------------------------------------------------------------------


El primer examen como alumno de 42 tiene un posible ejercicio llamado print_bits que requiere ciertos conocimientos de temas que hasta ahora no hemos tocado en 42.

Es un código sencillo que por lo que tengo entendido mucha gente simplemente memoriza, pero yo quería entenderlo bien y he pensado que podía escribir aquí de una manera sencilla el funcionamiento del código,además de explicar brevemente 3 conceptos claves que son imprescindibles:

1. Qué es el código binario y por qué lo utilizan los ordenadores.
2. Qué es bitmasking
3. Qué son los bitwise operators u operadores a nivel bit.

## Qué es el código binario

El binario como tal no es más que un sistema numérico, tal como el decimal. Se caracteriza por ser de base 2:

- Binario [base 2] -> 0, 1.
- Decimal [base 10] -> 0, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9.

El decimal es un sistema numérico muy eficiente, permite escribir números muy grandes de manera corta, sencilla y efectiva. 

El binario en cambio, a nivel fundamental se asemeja algo más a contar con palitos: Mientras que con el decimal una única posición puede tener hasta 10 valores, el binario solo tiene dos, sí o no. 

Si tenemos dos manzanas, ponemos dos palitos. Pero qué pasa cuanto queremos representar números muy grandes? Si queremos escribir el número 100, tener que escribir 100 palitos es muy poco eficiente. Y es aquí donde el binario entra en acción. Pese a que cada posición sólo puede ser sí o no (1 - 0), El valor real de cada una de sus posiciones no es 1 constantemente como con los palitos, sino que aumenta de manera exponencial:

| Binario:    | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
| ---      | --- | --- | --- | --- | --- | --- | --- | ---


Se sumará el valor de todas las posiciones en donde se encuentre un 1. De esta manera, con solo 8 posiciones podemos obtener cualquier número entre 0 y 255:

| Binario:    | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
| ---      | --- | --- | --- | --- | --- | --- | --- | ---
| 1:    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | **``1``**
| 2:    | 0 | 0 | 0 | 0 | 0 | 0 | **``1``** | 0
| 3:    | 0 | 0 | 0 | 0 | 0 | 0 | **``1``** | **``1``**
| 5:    | 0 | 0 | 0 | 0 | 0 | **``1``** | 0 | **``1``**
| 10:    | 0 | 0 | 0 | 0 | **``1``** | 0 | **``1``** | 0
| 15:    | 0 | 0 | 0 | 0 | **``1``** | **``1``** | **``1``** | **``1``**
| 50:    | 0 | 0 | **``1``** | **``1``** | 0 | 0 | **``1``** | 0
| 255:    | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** |  **``1``** 

Los ordenadores trabajan con microtransistores, pequeños componentes que o bien reciben una pequeña señal (1) o no la reciben (0). Por tanto, trabajan con código binario.

## Qué es bit masking y bitwise operators

Una vez visto brevemente lo básico del funcionamento del código binario, volvemos a leer el subject del ejercicio. Nos pide que pasemos un byte (un número del 0 al 255 o un caracter correspondiente del código ascii), y escribamos su código binario. Debido a que debemos emplear *write*, no hay forma directa de obtener el código binario.

Usaremos bit masking: Es una manera de poder trabajar bits de manera individual dentro de un conjunto de estos, tal como un byte. Digamos que es un filtro, un colador: Un byte conteien 8 bits, si queremos acceder al estado de un único bit, tenemos que "filtrarlo".

La manera de hacer esto dependerá de la operación que queramos hacer, es decir, del operador a nivel de bit (bitwise operator) que usemos. Para el ejercicio usaremos dos, uno de comparación y otro de movimiento:
- & (AND). *No confundir con el operador lógico &&*. **&** Compara dos bits, sólo devolverá 1 si ambos bits son "1".
  - Como Para que nos devuelva 1 ambos bits deben de ser 1, en nuestra máscara colocaremos un 1 en aquellas posiciones que queramos comparar.

- \>\> (Desplazamiento a la derecha). Desplazará una posición a la derecha el valor que le indiquemos.

Teniendo esto en cuenta, queremos ir comprobando posición a posición del binario de nuestro byte si el bit correspondiente es un 0 o un 1, si encuentra un 1 que nos escriba "1", y si no, que nos escriba "0".

El código resultaría en: 

```c
void	print_bits(unsigned char octet)
{
	int mask = 0b10000000;
	for (int i = 0; i <= 7; i++){
		(octet & mask ? write(1,"1",1) : write(1,"0",1));
		mask >>= 1;
	}
}
```
En cada vuelta del bucle empleo un condicional ternario (una versión simplificada de un if else) para filtrar con la máscara y comprobar si *octet* contiene un 1 en la posición filtrada por la máscara, escribo por pantalla el valor correspondiente y procedo a filtrar la siguiente posición, así durante las 8 "posiciones" del byte.

Destacar también que la máscara, *mask*, la he escrito directamente como binario. Esto se puede hacer en c gracias a usar 0b delante.
- Como dato curioso, si quieres imprimir un número mediante printf, puedes pasarlo en decimal o también como binario, es decir: ```printf("%d",170);```es lo mismo que ```printf("%d",0b10101010);```

Adjunto una pequeña imagen que espero que aclare el proceso de filtrado, desplazamiento y comparación:

<img width=600 alt="bit masking" src="https://imgur.com/SJFTETJ.png">

Y esta sería la explicación del ejercicio, espero que te haya ayudado a comprender el por qué del código, a mi desde luego me ha ayudado a terminar de aclarar las ideas al respecto. ¡Suerte en el examen!
