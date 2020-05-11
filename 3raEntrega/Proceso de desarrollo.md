# Proceso de desarrollo

## Metodología

Se utilizará el modelo basado en prototipos, ya que no se conoce a ciencia cierta si todos los requerimientos ya están completamente definidos, así como tampoco si se están teniendo en cuenta todas las tecnologías necesarias para completarlo, por lo que se buscará adaptar y mejorar la calidad de los prototipos durante sus despliegues, así como acompletar los requerimientos y herramientas que serán necesarias.

## Herramientas

- Hangouts
- Whats App
- Slack
- Visual Studio Code
- GitHub
- GitHub Desktop
- Microsoft Teams

### Comunicación

La comunicación se realiza principalmente en las mañanas y en las noches, comentando avances, prioridades y posibles desperfectos existentes en el software. Se busca estar todos al tanto de las condiciones del proyecto y apoyarse en la búsqueda de soluciones de manera rápida y efectiva.

### Planeación

Se realizan llamadas grupales semanales para comentar las próximas metas a lograr, se dividen objetivos y se proponen lapsos determinados para entregar los avances.

### Monitoreo

Cada integrante avisa de su desempeño a los demás, marca su casilla en el mapeo de requerimientos y redacta los avances obtenidos hasta ese momento. 

Tras cada prototipo lanzado se realizan las pruebas y se documentan en el código. 

Es indispensable que todo el equipo analice el avance de los demás en busca de errores, desperfectos u optimizaciones que se puedan realizar, con el fin de mantener un buen standar de calidad. 

### Bitácoras

A modo de llevar un registro de las actividades a realizar se usará una bitácora sencilla pero eficiente, misma que contiene los siguientes apartados:
- Fecha
- Actividad realizada
- ¿Cuánto tiempo se usó para realizarla?
- Comentarios (¿falta algo?, ¿necesita revisión?, etc.)
- [x] Se adjunta el enlace a la bitácora: 
 https://alumnosuady-my.sharepoint.com/:w:/g/personal/a16000959_alumnos_uady_mx/EWRmBJ-8S4xNubJXExbF7ccBhcJt0DwiPAms1QvGcGovKQ?e=A1PCji
 
## Métrica

Para evaluar el desempeño de los integrantes del proyecto se usará una plantilla de excel, misma que contiene los siguientes puntos para tener en cuenta.
-Cada integrante cuenta con su propia "sección", ya que básicamente el proyecto cuenta con 3 partes escenciales, el servicio web, el algoritmo logarítmico y la graficación del mismo. 
- Es importante que cada miembro asista a las reuniones grupales mediante hang outs para dar a conocer sus avances, problemáticas y sugerencias. Este apartado califica a cuántas de las reuniones totales asistió.
- Cada miembro debe documentar su sección del código y del proyecto ya que ellos tienen el conocimiento de lo que hicieron. Este apartado igual es calificado en la métrica.
- [x] Se adjunta el enlace a la métrica:
 https://alumnosuady-my.sharepoint.com/:x:/g/personal/a16000959_alumnos_uady_mx/ESS0Z0Blue5HkKZGh4JlJN4Btg6g_9zs8N6o0BO9OqPs3A?e=T3PnWE
 
## Reporte de avance individual por entrega
Jonathan:

-Entrega 1:Participó en la creación del repositorio junto con su documentación, llevando a cabo el apartado "Proceso de desarrollo". Elaboró la ppt para la primera entrega.

-Entrega 2:Elaboró el segundo prototipo funcional, mismo que está mejor descrito en la sección de "Mapeo de requerimientos", básicamente la diferencia entre el primero y el segundo es que ahora el código produce y genera la ecuación exponencial que modela las defunciones y contagios del virus.

-Entrega 3: Participó redactando la documentación del apartado de "Proceso de desarrollo" e implementando una porción del código para la interfaz con la ayuda de Tkinter.
## Resúmen de Avances

Durante el desarrollo del primer prototipo se investigaron múltiples API's, a lo que se encontró la que más se adaptaba a las necesidades del sistema. Tras investigar sobre las bibliotecas *json* y *http.client* se construyó el código de tal manera que se recuperen los datos específicos necesarios para la construcción de las gráficas, guardando los datos en forma de enteros en dos listas separadas.

Durante el desarrollo del segundo prototipo se investigaron algoritmos de regresiones exponenciales que sirvieran para generar las ecuaciones que modelan el comportamiento y predicción de los casos y muertes, usando logaritmos se buscaba obtener una ecuación del tipo *y=A*e^Bx, misma que es obtenida con la ayuda de la librería *Math* la cual fue usada para el empleo de la palabra reservada "log", los valores se almacenan en diferentes variables, las cuales permiten el fácil manejo de los datos de tipo float.

Durante el desarrollo del tercer prototipo se investigó e implementó la librería "Matplotlib" que sirvió para generar la gráfica de pastel que se muestran al principio y el gráfico de líneas al final, que representan los casos y muertes, así como el aumento pronosticado de los mismos respectivamente.

## Calendario de Actividades

| Actividades | Fecha | Responsable(s) | Artefacto(s) |
| ----------- | ----- | -------------- | ------------ |
| Creación del repositorio | 17/04/20 | Joshua Meza | Repositorio |
| Definición y análisis de la problemática | 18/04/20 | Todos | Problemática |
| Definición de objetivos | 18/04/20 | Todos | Objetivos |
| Definición de requerimientos | 18/04/20 | Todos | Requerimientos de usuario, sistema, funcionales y no funcionales |
| Redacción y corrección del repositorio | 18/04/20 | Todos | Repositorio |
| Desarrollo del archivo "*Main v1.0.0*" | 19/04/20 | Todos | Prototipo 1 |
| Desarrollo del archivo "*Main v1.1.0*" | 20/04/20 | Todos | Prototipo 2 |
| Desarrollo del archivo "*Main v1.2.0*" | 21/04/20 | Todos | Prototipo 3 |
| Mejora en la redacción del repositorio | 22/04/20 | Todos | Repositorio |

## Repositorio

- [x] https://github.com/JoshuaMeza/CodePain_PE
