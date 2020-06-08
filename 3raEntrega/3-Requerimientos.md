# Requerimientos

## Actores del Sistema

- **Usuario:** Viene siendo cualquier persona que quiera ver la situación actual en cuanto a casos confirmados y defunciones por Covid-19 de algún país en Norte América.
- **Sistema:** La aplicación misma.

## Requerimientos de Usuario

El usuario ingresa a una interfaz dónde están enlistados todos los países que se pueden consultar. Al seleccionar uno se le presentan los datos, las gráficas y las ecuaciones logarítmicas correspondientes.

El usuario puede consultar los países sin necesidad de reiniciar la aplicación.

## Requerimientos de Sistema

El usuario selecciona el país que desea consultar, después el sistema recupera la selección y lo traduce al código asociado a una API (Application Programming Interface), de la cual extrae los datos de casos confirmados y defunciones por Covid-19, posteriormente, convierte los datos en gráficas y los utiliza para crear una ecuación logarítmica que describa el cambio en dicha información. Por último, presenta los resultados al usuario. 

## Requerimientos Funcionales

- El usuario puede elegir el país que desea consultar.
- El usuario puede consultar los datos las veces que desee en la aplicación.

## Requerimientos No funcionales

- Al ingresar, el sistema despliega la lista de países que se pueden consultar.
- Al seleccionar un país, el sistema:
    - Despliega una tabla con los números de casos confirmados de Covid-19 a través del tiempo.
    - Pone el número de casos confirmados totales de Covid-19 hasta la fecha.
    - Imprime el logaritmo que decribe el aumento de casos confirmados hasta la fecha.
    - Despliega una tabla con los números de defunciones por Covid-19 a través del tiempo.
    - Pone el número de defunciones totales por Covid-19 hasta la fecha.
    - Imprime el logaritmo que describe el aumento de defunciones hasta la fecha.
- Se realiza la funcionalidad de consultar las veces que el usuario desee.

## Diagrama de Casos de Uso

[Diagrama de Casos de Uso](https://github.com/JoshuaMeza/CodePain_PE/tree/master/Recursos/DiagramaCasosDeUso.jpg)

En la imagen se presenta cómo el usuario es necesario para que el sistema sepa a que ruta acceder y recoger la información, para que posteriormente él la analice, la transfiera a tablas y la devuelva en una forma sencilla de entender para el usuario.

## Entidades de Información Necesarias

El sistema utiliza las bibliotecas *http.client* y *json* para obtener los casos confirmados y las defunciones totales, recuperadas de la API (Application Programming Interface) *[COVID-19](https://rapidapi.com/api-sports/api/covid-193?endpoint=apiendpoint_dfb9e52d-bd90-48ec-a571-8b78610a736d)* de api-sports.

El algoritmo de regresión exponencial utiliza la biblioteca *Math* para el uso de logaritmos, dicho algoritmo es usado para generar la ecuación del comportamiento de los casos y de las muertes. La información fue recuperada de vídeos de youtube y de páginas matemáticas.

Para las tablas, el sistema utiliza la librería *Numpy* y la mega-libreria *Matpotlib* que puede producir todas las gráficas que necesitaremos de una manera sencilla y agradable para la vista del usuario. La cual fue investigada en el mismo foro de la librería: "https://matplotlib.org/".

Para el aspecto visual de la aplicación el sistema utiliza la librería *Tkinter*, el cual permite colocar las secciones, colores, botones y cajas presentes en la interfaz.

Para la documentación, se utiliza la biblioteca *pydoc*.

## Requerimientos Especiales para el Usuario

1. Para ejecutar el *CodePain_Coronavirus.exe*, favor de no sacar el archivo de su carpeta de origen, para evitar errores de ejecución.

2. Si se desea ejecutar el archivo *main.py version 1.4.0* en vez del *CodePain_Coronavirus.exe*, es necesario realizar las siguientes acciones:

- Tener instalado en su computador *Python* y todas las bibliotecas utilizadas en el desarrollo del producto final (*Extras fuera de python: http.client y Matpotlib*). 
    - Para instalar las bibliotecas extras, realizar: *pip install <...>*
- Colocar el cmd (línea de comandos) en la carpeta dónde se encuentra el archivo.

En caso de no realizar las medidas anteriormente explicadas, el archivo no se ejecutará correctamente.
