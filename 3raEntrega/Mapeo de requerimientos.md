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
    - [x] Imprime el logaritmo que describe el aumento de defunciones hasta la fecha.
- [ ] Se coloca un botón que permita redireccionarse a la página principal durante cada consulta.

## Resumen de Avances

Durante el desarrollo de este cuarto prototipo se implemento el diseño visual así como la interfaz con la que el usuario interactuará al momento de ejecutar el programa, El cual se elaboró con la librería Tkinter por medio de cajas de casos, A continuacion se construyó el codigo para usar los recursos de una carpeta, ("resources"), en el mismo espacio de trabajo, donde a su vez se modificó el codigo de las graficas para que ahora estás se guardaran en la carpeta anteriormente mencionada para posteriormente ser mostradas en la interfaz

## Mapeo

En la funcion *main* se cumple el requerimento relacionado con la interfaz del usuario para elegir que pais desea consultar de forma más interactiva y visual.

En la funcion *genGraphic* y *genGraphic2* se cumple de manera más eficaz y funcional los requerimentos relacionados con el despliegue de graficas al ser adaptadas a la nueva interfaz

Igualmente en la funcion "main" se cumplen los requerimentos de imprimir los datos obtenidos pero ahora de una manera integrada a la nueva interfaz.

## Resultado y Avances

[Interfaz de inicio](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Interfaz%201.png)

[Interfaz de salida](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Interfaz%20con%20resultados.png)

[Carpeta de recursos con graficas](https://github.com/JoshuaMeza/CodePain_PE/tree/master/3raEntrega/Prototipo%204/resources)
