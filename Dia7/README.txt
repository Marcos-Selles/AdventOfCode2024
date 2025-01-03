# Explicación Día 7

Se eligió este problema porque comprobamos qeu al requerir una generación y evaluación de todas las posibilidades era un reto que encajaba perfectamente con el uso de memoria dinámica para almacenarlas y evitar repeticiones.

Utilizamos un algoritmo de memoria dinámica para generar y evaluar combinaciones de operadores eficientemente. Esta técnica es adecuada porque evita reevaluaciones redundantes al almacenar resultados intermedios. Además, empleamos estructuras de datos como vectores para gestionar números y operadores de manera flexible.
La memoria dinámica minimiza el tiempo de ejecución al reutilizar cálculos previos, lo que la convierte en una opción óptima para este ejercicio donde las soluciones pueden ser reutilizadas en múltiples contextos.

Probamos a utilizar recursión sin el uso de esta memoria intermedia, pero resultaba en unos iempos de ejecución significativamente mayores. Esta opción fue descartada por su ineficiencia y falta de escalabilidad para entradas más grandes.
