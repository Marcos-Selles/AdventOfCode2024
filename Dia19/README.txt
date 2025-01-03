# Explicación Día 19

Compilación y ejecucción:
g++ -o test Dia19.cpp
./test Puzzle19

Seleccionamos este problema porque nos pareció apto para resolver con la última técnica que nos quedaba por utilizar en este reto que eran los arboles binarios debido su enfoque en la verificación de construcciones válidas de cadenas a partir de patrones dados que requería combinar búsqueda eficiente y optimización 

Se utilizó un árbol binario para almacenar los patrones disponibles optimizando así las búsquedas, ya que permiten un acceso rápido a los patrones

Probamos también si se podían usar listas o vectores para almacenar patrones, pero estas estructuras no eran lo suficientemente eficientes para búsquedas rápidas en conjuntos grandes. También evaluamos las tablas hash que ofrecen búsquedas rápidas en promedio, pero su mayor consumo de memoria y falta de orden intrínseco complicaban el manejo de los patrones en ciertos casos.

