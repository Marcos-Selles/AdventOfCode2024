Explicación del Dia4:
Este problema fue seleccionado por su desafio al tener que hacer una busqueda multidireccional de la matriz, teniendo que ver si se encontraba la cadena XMAS tanto vertical,horizontal como diagonalmente.

Para resolver el problema se ha utilizado grafos, considerando cada celda de la matriz como un nodo conectado a sus vecinos para ir verificando si alguna de las celdas contiguas era válida para seguir con la formación de la palabra "XMAS". Además usamos vectores para manejar las direcciones de búsqueda.

La alternativa inicial fue explorar las celdas de manera recursiva, pero dado el volumen de el input del problema cambiamos a realizarlo con grafos ya que es mejor para explorar correctamente todas las direcciones posibles.
