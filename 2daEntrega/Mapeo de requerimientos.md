# Mapeo de Requerimientos

## Requerimientos Funcionales

- [x] El usuario puede elegir el país que desea consultar.
- [] El usuario puede volver a la página principal tras realizar una consulta.

## Requerimientos No funcionales

- [x] Al ingresar, el sistema despliega la lista de países que se pueden consultar.
- Al seleccionar un país, el sistema:
    - [] Despliega una tabla con los números de casos confirmados de Covid-19 a través del tiempo.
    - [x] Pone el número de casos confirmados totales de Covid-19 hasta la fecha.
    - [] Imprime el logaritmo que decribe el aumento de casos confirmados hasta la fecha.
    - [] Despliega una tabla con los números de defunciones por Covid-19 a través del tiempo.
    - [x] Pone el número de defunciones totales por Covid-19 hasta la fecha.
    - [] Imprime el logartirmo que describe el aumento de defunciones hasta la fecha.
- [] Se coloca un botón que permita redireccionarse a la página principal durante cada consulta.

## Resúmen de Avances

Durante el desarrollo del primer prototipo se investigaron múltiples API's, a lo que se encontró la que más se adaptaba a las necesidades del sistema. Tras investigar sobre las bibliotecas *json* y *http.client* se construyó el código de tal manera que se recuperen los datos específicos necesarios para la construcción de las gráficas, guardando los datos en forma de enteros en dos listas separadas. 
