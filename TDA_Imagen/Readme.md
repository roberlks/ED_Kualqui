/*! \mainpage Expansión e implementación del TDA Imagen

# Introducción

Se presenta un breve resumen de los aspectos tenidos en cuenta en el proyecto, en lo que respecta a la representación interna y los diferentes métodos requeridos en la práctica.

Comenzaremos por analizar la representación interna de la clase Image:

Inicialmente, la imagen se encontraba almacenada en una matriz, representada internamente mediante un array de punteros a bytes, donde la imagen se 
representaba como un array unidimensional. Los punteros del array mencionado apuntaban al inicio de cada fila de la imagen. Además, se registraban el 
número de filas y columnas. Sin embargo, debido a la implementación de la función ShuffleRows(), que se explicará más adelante, hemos introducido un nuevo 
miembro en la representación interna: un encabezado (header) que apunta al inicio del array de bytes. Este encabezado resulta útil al destruir el objeto, 
como se detallará posteriormente en la sección sobre el método ShuffleRows().

Otro detalle que merece la pena destacar es la modificación en el método WritePGMImage. En un principio, este método tomaba como parámetro un array unidimensional de datos, 
de bytes, para escribirlos en el fichero de salida. Pero, de nuevo debido al ShuffleRows(), se ha modificado
ligeramente para que reciba una matriz, es decir un array de punteros a byte. Esto nos permite guardar la imagen de forma correcta aunque los punteros 
hayan sido reordenados, como pasa en el ShuffleRows().

## Método AdjustContrast():

Este método permite ajustar el contraste de una imagen. Se aplican cuatro umbrales para definir la transformación de píxeles: in1, in2, out1 y out2. Es importante 
destacar que estos umbrales deben cumplir con ciertas condiciones (0 <= in1, in2, out1, out2 <= 255) y que in1 debe ser menor que in2, y out1 menor que out2. La imagen 
se modifica mediante la aplicación de una función de ajuste de contraste. Es importante mencionar que este método no devuelve una nueva imagen, sino que modifica el objeto actual.

La fórmula utilizada para realizar el ajuste es la siguiente:

@image html formula_contraste.png

Visualmente, esto se puede representar de la siguiente manera:

@image html grafica_contraste.png

## Método Subsample():

El método "Subsample" se utiliza para crear un icono o una versión reducida de una imagen existente. El propósito principal es reducir la resolución de la imagen original, 
lo que resulta en una imagen más pequeña con menos detalle. El tamaño de la nueva imagen reducida se calcula en función de un factor de reducción especificado. Para llevar 
a cabo este procedimiento, se emplea el método Mean().
El procedimiento sería algo así:
@image html ejemplo_icono.png

## Método Crop():

Es importante mencionar que en este método se gestionan las precondiciones de dos maneras posibles:

1. El primer caso se refiere a cuando el inicio de la imagen recortada está fuera de la imagen original. En este escenario, el método devuelve una imagen vacía.

2. El segundo caso se presenta cuando la altura o la anchura de la imagen recortada se extiende más allá de los límites de la imagen original. En este caso, la imagen recortada 
se ajusta a las dimensiones de la imagen original, de modo que comienza en el píxel especificado por @p nrow y @p ncol y termina en los bordes de la imagen original si se excede de ellos.

## Método Zoom2X():

En este método, se utiliza el método Mean() para calcular la media entre los píxeles necesarios en cada momento. El proceso se puede visualizar como sigue:

@image html ejemplo_zoom.png

Las flechas indican las filas y columnas que se insertan, y los decimales se redondean después de realizar los cálculos.

## Método ShuffleRows():

El método "ShuffleRows" se emplea para reorganizar de manera pseudoaleatoria las filas de una imagen. Las filas se reordenan siguiendo un algoritmo basado en un número primo _p. 
Es importante destacar que _p debe ser un número primo y que debe ser mayor o igual al número de filas de la imagen. Como las imágenes se representan internamente como un array de 
punteros a bytes, se pueden intercambiar las filas simplemente modificando a qué posición apunta cada elemento del array. Esto hace necesario agregar un puntero al inicio real de la 
imagen en memoria, "HEADER," para poder liberar la memoria de manera adecuada al destruir la imagen.

## Operador "Operator==":

Además, se ha añadido el operador relacional "==" para permitir la verificación de que la generacion de imágenes es correcta. Este operador primero verifica si las imágenes tienen 
el mismo número de filas y columnas, y luego procede a comparar píxel a píxel para confirmar que las imágenes son idénticas.


# Ejecutables


## Negativo:

Calcula el negativo de una imagen

> __negativo__ \<FichImagenOriginal\> \<FichImagenDestino\>
@param "<FichImagenOriginal>" Imagen PGM a la que se va a calcular el negativo
@param <FichImagenDestino> Imagen PGM resultado de calcular el negativo

@image html invert.png

## Subimagen: 

Recorta una imagen PGM

> __subimagen__ \<FichImagenOriginal\> \<FichImagenDestino\> \<fila\> \<columna\> \<altura\> <anchura> 

@param "<FichImagenOriginal>" Imagen PGM que se va a recortar
@param <FichImagenDestino> Imagen PGM resultado de recortar la imagen
@param <fila> La fila donde empieza el recorte.
@param <columna> La columna donde empieza el recorte.
@param <altuara> Las filas de la imagen recortada, la altura.
@param <anchura> Las columnas de la imagen recortada, la anchura.

@image html Vacas_subimagen.png

## Zoom:

Recorta una imagen PGM y le hace zoom

> __zoom__ \<FichImagenOriginal\> \<FichImagenDestino\> \<fila\> \<columna\> <lado>

@param "<FichImagenOriginal>" Imagen PGM que se va a aumentar.
@param <FichImagenDestino> Imagen PGM resultado aumentada.
@param <fila> La fila donde empieza el zoom.
@param <columna> La columna donde empieza el zoom.
@param <lado> El lado de la imagen que recortamos para hacerle zoom a posteriori.

@image html Vacas_zoom.png

## Barajar:

Baraja de forma pseudoaleatoria una imagen PGM.

> __barajar__ \<FichImagenOriginal\> \<FichImagenDestino\> [<primo>]

@param "<FichImagenOriginal>" Imagen PGM que se va a barajar.
@param <FichImagenDestino> Imagen PGM resultado barajada.
@param [<primo>] Numero primo para barajar la imagen. Es opcional.

## Icono:

Calcula el icono de una imagen PGM.

> __icono__ \<FichImagenOriginal\> \<FichImagenDestino\> <factor>

@param "<FichImagenOriginal>" Imagen PGM a la que se le va a hacer el icono.
@param <FichImagenDestino> Icono de la imagen original.
@param <factor> El factor con el que ser reduce la imagen.

@image html Vacas_icono.png

## Contraste:

Ajusta el contraste de una imagen PGM (estiramiento del histograma)

> __contraste__ \<FichImagenOriginal\> \<FichImagenDestino\> <e1> <e2> <s1> <s2>

@param "<FichImagenOriginal>" Imagen PGM a la que se le va a ajustar el contraste.
@param <FichImagenDestino> Imagen PGM resultado de ajustar el contraste.
@param <e1> Umbral inferior de la imagen de entrada.
@param <e2> Umbral superior de la imagen de entrada.
@param <s1> Umbral inferior de la imagen de salida.
@param <s2> Umbral superior de la imagen de salida.

@image html Vacas_contraste.png

## Check:

Comprueba si dos imágenes son iguales.

> __check__ <FichImagen1> <FichImagen2> 

@param <FichImagen1> La primera imagen a comparar.
@param <FichImagen2> La segunda imagen a comparar.
*/
