# Requerimientos

## Actores del Sistema

- **Usuario:** Viene siendo cualquier persona que quiera ver la situación actual en cuanto a casos confirmados y defunciones por Covid-19 de algún país en América.
- **Sistema:** El sistema mismo.

## Requerimientos de Usuario

El usuario ingresa a una interfaz dónde están enlistados todos los países que se pueden consultar. Al seleccionar uno se le presentan los datos, las gráficas y las ecuaciones logarítmicas correspondientes.

Si el usuario lo requiere, puede regresar a la página principal presionando un botón.

## Requerimientos de Sistema

El usuario ingresa el país que desea consultar, después el sistema lo traduce al código asociado a la API (Application Programming Interface) de la OMS (Organización Mundial de la Salud) y extrae los datos de casos confirmados y defunciones por Covid-19, posteriormente, convierte los datos en tablas y los utiliza para crear una ecuación logarítmica que describa el cambio en dicha información. Por último, presenta los resultados al usuario. 

## Requerimientos Funcionales

- El usuario puede elegir el país que desea consultar
- El usuario puede volver a la página principal desde una consulta

## Requerimientos No funcionales

- Al ingresar, el sistema despliega la lista de países que se pueden consultar
- Al seleccionar un país, el sistema:
    - Despliega una tabla con los números de casos confirmados de Covid-19 a través del tiempo.
    - Pone el número de casos confirmados totales de Covid-19 hasta la fecha.
    - Imprime el logaritmo que decribe el aumento de casos confirmados hasta la fecha.
    - Despliega una tabla con los números de defunciones por Covid-19 a través del tiempo.
    - Pone el número de defunciones totales por Covid-19 hasta la fecha.
    - Imprime el logartirmo que describe el aumento de defunciones hasta la fecha.
- Se coloca un botón que permita redireccionarse a la página principal durante cada consulta.

## Diagrama de Casos de Uso

https://github.com/JoshuaMeza/CodePain_PE/tree/master/Recursos/DiagramaCasosDeUso.jpg

En la imagen se presenta cómo el usuario es necesario para que el sistema sepa a que ruta acceder y recoger la información, para que posteriormente él la analice, la transfiera a tablas y la devuelva en una forma sencilla de entender para el usuario.

## Entidades de Información Necesarias

El sistema necesitará de la biblioteca *requests* para obtener información de la API (Application Programming Interface) de la OMS (Organización Mundial de la Salud).

Para las tablas, el sistema utilizará la biblioteca *_________________________*.

Para la documentación, se necesitará de la biblioteca *pydoc*.
