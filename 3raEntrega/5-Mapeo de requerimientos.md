# Mapeo de Requerimientos

## Requerimientos Funcionales

- [x] El usuario puede elegir el país que desea consultar.
- [x] El usuario puede consultar los datos las veces que desee en la aplicación.
## Requerimientos No funcionales

- [x] Al ingresar, el sistema despliega la lista de países que se pueden consultar.
- Al seleccionar un país, el sistema:
    - [x] Despliega una tabla con los números de casos confirmados de Covid-19 a través del tiempo.
    - [x] Pone el número de casos confirmados totales de Covid-19 hasta la fecha.
    - [x] Imprime el logaritmo que decribe el aumento de casos confirmados hasta la fecha.
    - [x] Despliega una tabla con los números de defunciones por Covid-19 a través del tiempo.
    - [x] Pone el número de defunciones totales por Covid-19 hasta la fecha.
    - [x] Imprime el logaritmo que describe el aumento de defunciones hasta la fecha.
- [x] Se realiza la funcionalidad de consultar las veces que el usuario desee.

## Resumen de Avances

Durante el desarrollo del **primer prototipo** se investigaron múltiples API's, a lo que se encontró la que más se adaptaba a las necesidades del sistema. Tras investigar sobre las bibliotecas *json* y *http.client* se construyó el código de tal manera que se recuperen los datos específicos necesarios para la construcción de las gráficas, guardando los datos en forma de enteros en dos listas separadas.

Durante el desarrollo del **segundo prototipo** se investigaron algoritmos de regresiones exponenciales que sirvieran para generar las ecuaciones que modelan el comportamiento y predicción de los casos y muertes, usando logaritmos se buscaba obtener una ecuación del tipo *y=A*e^Bx, misma que es obtenida con la ayuda de la librería *Math* la cual fue usada para el empleo de la palabra reservada "log", los valores se almacenan en diferentes variables, las cuales permiten el fácil manejo de los datos de tipo float.

Durante el desarrollo del **tercer prototipo** se investigó e implementó la librería "Matplotlib" que sirvió para generar la gráfica de pastel que se muestran al principio y el gráfico de líneas al final, que representan los casos y muertes, así como el aumento pronosticado de los mismos respectivamente.

Durante el desarrollo del **cuarto prototipo** se implementó el diseño visual así como la interfaz con la que el usuario interactuará al momento de ejecutar el programa, el cual se elaboró con la librería *Tkinter* por medio de cajas de casos. A continuación se construyó el código para usar los recursos dentro de una carpeta, "resources", en el mismo espacio de trabajo, dónde a su vez se modificó el código de las gráficas para que ahora estas, en vez de desplegarse como una ventana emergente, se guardaran en la carpeta anteriormente mencionada. Igualmente se borraron funciones obsoletas y se actualizaron otras.

En el **quinto prototipo** se añadió la función de poder mostrar las gráficas dentro de la aplicación y se solucinó un error que impedía poder generar gráficas indefinidamente, ya que estas se superponían.

En el **sexto prototipo** se dividió en cuatro archivos el sistema, se redujo el número de bibliotecas necesarias en el programa, se cambió el sistema de generación de gráficas para que fueran ventanas emergentes independientes, se modificó el aspecto visual del Prototipo 5 y se solucionaron los dos errores de ejecución presentes en el prototipo anterior que impedían la correcta generación de gráficas y la finalización del proceso. 

En el **producto final** se creó y convirtió el archivo *main.py version 1.4.0* en *main.exe*, se facilitó la utilización de la aplicación al convertir en ejecutable el programa y se le proporcionó un ícono personalizado al ejecutor.

## Mapeo

En el archivo *PutValues* se cumplen los requerimientos relacionados con el servicio web, ya que se encargan de recopilar el código de la API, y consultar el historial de casos confirmados y de defunciones.

En el archivo *PutValues* se cumple con el requerimiento de generar el algoritmo que represente el crecimiento de casos confirmados y de defunciones hasta la fecha.

En los archivos *GenGraphic1* y *GenGraphic2* se cumplen los requerimientos relacionados con la creación de las gráficas de casos confirmados y de defunciones.

En el archivo *Main* se encuentra redactado el aspecto visual. En esta zona se cumplen con los requerimientos de desplegar los resultados al usuario y de permitirle consultar el número de veces que desee la información disponible.


## Resultado

[Interfaz de inicio](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Interfaz.png)

[Interfaz de salida](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/InterfazResultados.png)

[Gráfica 1](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Grafica1.PNG)

[Gráfica 2](https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Grafica2.PNG)
