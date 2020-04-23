# Estándar de codificación

## Nombrado

- **Variables:** Uso de sustantivos con formato camelCase.
- **Funciones:** Uso de verbos y sustantivos con formato camelCase.
- **Archivos:** Describen qué son utilizando mayúsculas al inicio de cada palabra.
- **Bibliotecas:** Describen su función iniciando con mayúsculas cada palabra.

## Plantilla de documentación

- **Lenguaje:** Todo el código estará escrito en inglés.
- **Bloque Inicial:** Se coloca antes de iniciar un comentario con los autores del código, la versión y la función del programa.
```python
"""
Author Joshua Meza, Jonathan Gómez and Irving Poot
Date dd/mm/yyyy
Version 1.0.0
Instruction here
"""
```
- **Funciones:** Al iniciar el bloque de funciones se pone un comentario que referencie al bloque de funciones. Dentro de cada función, en la primera línea se pone un comentario que describa su utilidad, los argumentos que utiliza y que retorna. Dentro de la función "main" se pone comentarios que dividan las secciones en *Entrada*, *Proceso* y *Salida*; cada sección se documenta como una función normal, exceptuando que no se incluye retorno.
```python
#Functions
def readNumber():
    """
    Read a number
    Args:
        number (int): The number
    Returns:
        The number
    """
    number=int(input("Insert a number: " ))

    return number

def sumNumbers(a,b):
    """
    Sum the numbers
    Args:
        a (int): First Number
        b (int): Second Number
    Returns:
        Result of the sum
    """
    result=a+b

    return result

def printResult(a):
    """
    Print the result
    Args:
        a (int): The result
    Returns:
        Nothing
    """
    print(a)

def main():
    #Input
    """
    Read 2 numbers
    Args:
        numberOne (int): First Number
        numberTwo (int): Second Number
    """
    numberOne=readNumber()
    numberTwo=readNumber()

    #Process
    """
    Sum the numbers
    Args: 
        result (int): Result of the sum
    """
    result=sumNumbers(numberOne,numberTwo)

    #Output
    """
    Print the result
    Args:
        result (int): Result of the sum
    """
    printResult(result)

    return 0
```
- **Comentarios de procedimiento:** Se escriben antes de algún paso que requiera explicación, como referenciación o un procedimiento complicado, y en ella se pone de manera resumida lo que hace la(s) sentencia(s).
- **Comentarios para pruebas:** Se colocan al final del código, y en ellas se escribe los valores de entrada y salida que se usaron y si pasaron la prueba.
```python
"""
Entry: 2,3
Output: 5
Pass: 1
"""
```

## Herramienta de documentación

Se utiliza la herramienta de *pydoc* para la documentación automática.

- El archivo html se encuentra en la carpeta "Recursos".