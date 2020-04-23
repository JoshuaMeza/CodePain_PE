# Mapeo de Requerimientos

## Requerimientos Funcionales

- [x] El usuario puede elegir el país que desea consultar.
- [ ] El usuario puede volver a la página principal tras realizar una consulta.

## Requerimientos No funcionales

- [x] Al ingresar, el sistema despliega la lista de países que se pueden consultar.
- Al seleccionar un país, el sistema:
    - [x] Despliega una tabla con los números de casos confirmados de Covid-19 a través del tiempo.
    - [x] Pone el número de casos confirmados totales de Covid-19 hasta la fecha.
    - [x] Imprime el logaritmo que decribe el aumento de casos confirmados hasta la fecha.
    - [x] Despliega una tabla con los números de defunciones por Covid-19 a través del tiempo.
    - [x] Pone el número de defunciones totales por Covid-19 hasta la fecha.
    - [x] Imprime el logartirmo que describe el aumento de defunciones hasta la fecha.
- [ ] Se coloca un botón que permita redireccionarse a la página principal durante cada consulta.

## Resúmen de Avances

Durante el desarrollo del primer prototipo se investigaron múltiples API's, a lo que se encontró la que más se adaptaba a las necesidades del sistema. Tras investigar sobre las bibliotecas *json* y *http.client* se construyó el código de tal manera que se recuperen los datos específicos necesarios para la construcción de las gráficas, guardando los datos en forma de enteros en dos listas separadas.

Durante el desarrollo del segundo prototipo se investigaron algoritmos de regresiones exponenciales que sirvieran para generar las ecuaciones que modelan el comportamiento y predicción de los casos y muertes, usando logaritmos se buscaba obtener una ecuación del tipo *y=A*e^Bx, misma que es obtenida con la ayuda de la librería *Math* la cual fue usada para el empleo de la palabra reservada "log", los valores se almacenan en diferentes variables, las cuales permiten el fácil manejo de los datos de tipo float.

Durante el desarrollo del tercer prototipo se investigó e implementó la librería "Matplotlib" que sirvió para generar la grafica de pastel que se muestran al principio y el grafico de lineas al final, que representan los casos y muertes así como el aumento pronosticado de los mismos respectivamente


## Mapeo

En las funciones *askCountry*, *getCases*, y *getDeaths* se cumplen los requerimientos relacionados con el servicio web, ya que se encargan de permitir al usuario elegir el país que desean consultar y al sistema de recopilar dicha información.

En las funciones *getAvalue*, *...*, ...

## Resultados y Avances

[Tabla 1](https://github.com/JoshuaMeza/CodePain_PE/tree/master/Recursos/Tabla1.JPG)

[Tabla 2](https://github.com/JoshuaMeza/CodePain_PE/tree/master/Recursos/Tabla2.JPG)

[Impresión](https://github.com/JoshuaMeza/CodePain_PE/tree/master/Recursos/Impresión.JPG)
