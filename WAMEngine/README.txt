
Como crear un mundo y cuerpo - WAMEngine -

Primero que todo se debe crear un mundo y un cuerpo. Para crear un cuerpo y un mundo se debe incluir la libreria #include "WAMWorld.h"
	esta libreria contiene "Body" y "Calculations", que son dos librerias necesarias para general los cuerpos y los calculos.
	Ahora para generar un mundo y generar un cuerpo se debe colocar esto en el main.cpp del codigo 
	-
				Posiciones:	x	y
		WAMWorld firstSimulation(vec2D(0.0f, 9.81f));
		WBody firstBody;
	-
Empezando desde el WAMWordl, se inicia llamando al struct WAMWorld e inicializandolo, en este caso lo llamamos firstSimulation con los 
parametros (vec2D(0.0f,9.81f)). Estos valores que se le mandan al constructor del struct son necesarios para la simulacion de un mundo.
En otras palabras esos valores son que determinan la gravedad. 

Ahora con WBody se inicializa igualmente que WAMWorld. Al inicializar el struct este genera un cuerpo. 

La razon por la que es necesario crear un "World" es debido a que se necesita dar los parametros del mundo para que el programa pueda crear
una simulacion de movimiento. Lo que hace el programa no es visual pero la simulacion de movimiento hay esta. 

	+ Libreria WAMWorld +

	WAMWorld::SetGravity - Funcion que resice el valor de gravedad que es establecido dentro de la libreria 
		= WAMWorld(vec2D gravity) : gravity(gravity) {} = 
		dentro de la libreria se crea un vec2D gravity, al crear instanciar la struct este le iguala los parametros
		a este valor 

	WAMWorld::addBody - Funcion que se encarga de guardar el valor de la posicion del cuerpo. Dentro de la libreria esta.
		= std::vector<WBody*> bodies = 
		Se crea un vector para poder guardar las posiciones de los cuerpos creados. Dentro de la funcion en el .cpp este 
		le hace push_back a los cuerpos guardandolos en un vector, de esta manera al impirmirlos se puede ver los avences realizados

	void WAMWorld::Step - Funcion que se encarga de analizar los pasos o el movimiento. Esta funcion recibe el frametime establecido en el main.cpp,
	 	= firstSimulation.Step(frametime) =
		en este caso nosotros establecimos el framtime, pero el frame time es necesario debido a que tenemos una variable de tiempo. En caso de que
		no se le de un valor al frametime y se utiliza el framerate de la emision este puede tener un movimiento constane dependiendo de el frame rate. 
		De la manera en la que esta la ecuacion es propensa a errores debido a que si el frame rate cambia, la ecuacion no cambiara con el frame rate 
		este se mantendra igual y podra tener errores visuales o en calculos. 
