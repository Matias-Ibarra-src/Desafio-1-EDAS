# Desafio-1-EDAS
<h1>TSP Problem</h1>

<h3>Instrucciones de ejecución</h3>

- Ingresar al link https://codecollab.io/@cristoferfb/Desafio%20OII443-1
- Ya en la pagina pedira un nombre de usuario, poner cualquiera.
- Estando ya dentro del compilador clickear el archivo main.cpp 
- Teniendo el archivo seleccionado clickear el boton ejecutar

Para cambiar las ciudades:

- Editar la lineas:
  #define destino_final "Lugoj"
  #define inicio Hirsova
- PRECAUCIÓN: inicio es un enum por lo que va sin ""

<h3>Descripción del problema</h3>

El problema del vendedor ambulante o  TSP por sus siglas en ingles (Travelling Salesman Problem) fue formulado por primera vez en 1930
y es uno de los problemas de optimización más estudiados. Es usado como prueba para muchos métodos de optimización. Aunque el problema
es computacionalmente complejo, se conoce gran cantidad de heurísticas y métodos exactos, así que es posible resolver planteamientos 
concretos del problema desde cien hasta miles de ciudades.

El problema responde a la siguiente pregunta: dada una lista de ciudades y las distancias entre cada par de ellas, ¿cuál es la ruta más 
corta posible que visita desde una ciudad exactamente a otra y al finalizar regresa a la ciudad origen?, En Este caso de estudio nuestro 
grupo se enfoco en resolver solo la ruta de ida del vendedor.

El TSP tiene diversas aplicaciones aún en su formulación más simple, tales como: la planificación, la logística y la fabricación de 
circuitos electrónicos. Un poco modificado, aparece como subproblema en muchos campos como la secuenciación de ADN. En esta aplicación, 
el concepto de “ciudad” representa, por ejemplo: clientes, puntos de soldadura o fragmentos de ADN y el concepto de “distancia” representa
el tiempo de viaje o costo, o una medida de similitud entre los fragmentos de ADN. En muchas aplicaciones, restricciones adicionales como 
el límite de recurso o las ventanas de tiempo hacen el problema considerablemente difícil. El TSP es un caso especial de los Problemas del 
Comprador Viajante (travelling purchaser problem).

Caso práctico
En el problema se presentan N! rutas posibles, aunque se puede simplificar ya que dada una ruta nos da igual el punto de partida y esto
reduce el número de rutas a examinar en un factor N quedando (N-1)!. Como no importa la dirección en que se desplace el viajante, 
el número de rutas a examinar se reduce nuevamente en un factor 2. Por lo tanto, hay que considerar (N-1)!/2 rutas posibles.

En la práctica, para un problema del viajante con 5 ciudades hay (5-1)!/2=12 rutas diferentes y no necesitamos un ordenador para encontrar 
la mejor ruta, pero apenas aumentamos el número de ciudades las posibilidades crece factorialmente:

Para 10 ciudades hay (10-1)!/2=181.440 rutas diferentes
Para 30 ciudades hay más de 4·10^30 rutas posibles.

Puede comprobarse que por cada ciudad nueva que incorporemos, el número de rutas se multiplica por el factor N y crece factorialmente. 
Por ello el problema pertenece a la clase de problemas NP-completos.


<h3>Descripción del algoritmo</h3>

Para nuestra solución hemos optado por almacenar cada ciudad en un Vector, cada una de las cuales contiene además la distancia a todos 
sus vecinos a los que se puede viajar directamente. Con esta representación de datos se planea construir un grafo y resolver el problema 
por medio de un algoritmo de búsqueda del tipo Best First Search.

En nuestro caso concreto, se define un estado como la distancia total recorrida y un vector con todas las ciudades visitadas. Por otro 
lado una acción se define como la ciudad de destino a la que viajar, además de la distancia (o coste) de viajar a dicha ciudad. Para 
obtener las posibles transiciones para un estado concreto se puede acceder fácilmente a los posibles vecinos de una ciudad desde el 
vector de datos mencionado anteriormente que contiene todas las ciudades y sus vecinos.

Para poder aplicar una estrategia de búsqueda del tipo BFS se implementa además una cola con prioridad que ordena los estados según 
algún algoritmo o heurística. Para nuestra situación utilizamos la distancia recorrida por cada estado priorizando aquellos que 
cuenten con una distancia de viaje menor.

Se fija una constante global destino_final que contiene el nombre de la ciudad de destino y que permite identificar un estado final 
comparando la última ciudad visitado con el nombre presente en la global. Adicionalmente contamos con un array de ciudades visitadas 
con el fin de tener identificado en todo momento aquellas ciudades que ya han sido visitadas previamente por nuestro algoritmo.

Por último se puede establecer un estado inicial que contenga una única ciudad y que representara la ciudad de inicio desde la cual se 
comenzarán a generar los posibles estados adyacentes. 

Con todo esto ya mencionado es posible organizar esta información de manera de que nuestra implementación va explorando todos aquellos 
estados que aparentan ser más prometedores, debido a la implementación de la cola con prioridad el algoritmo automáticamente descarta 
aquellos estados que ya evidencia una distancia mayor que otras alternativas permitiendo de esta manera reducir el número de posibles 
iteraciones necesarias para resolver el problema.

Una vez ejecutado el algoritmo la solución se presenta como la distancia mínima necesaria para recorrer entre las ciudades A y B además 
de entregar una lista con las ciudades que se deben recorrer para cumplir el objetivo, esta lista de ciudades comienza por la ciudad 
inicial y finaliza en la ciudad de destino esperada. De esta manera nuestro código ejecuta exitosamente su tarea.

<h3>Cooevaluación</h3>
<img src="https://drive.google.com/file/d/1692rHD27tcl_bgEZp6mNSdHVpuSLpWNE/view?usp=sharing)" alt="coo"/>

<h3>Video Presentación</h3>
https://drive.google.com/file/d/1aCS4INWbHttOj1jQqqGcYAeBSdnq1nus/view?usp=drivesdk

