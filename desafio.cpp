#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>

#define destino_final "Bucharest"

using namespace std;

//CLASES///////////////////////////////////
class City {
public:
    string ciudad;
    vector<int> distances;
    vector<string> vecinos;
};

class State {
public:
    int distanciaRecorrida;
    City ciudadActual;
    vector<City> ciudadesRecorridas;
};

class Action {
public:
    string nombre_ciudad;
    int distancia;
};

//VARIABLES GLOBALES////////////////////
vector<City> ciudades;
vector<City> visitados;


//FUNCIONES////////////////////////////
bool is_valid_state(State &s, Action a) {

    for(int i=0;i < (int)s.ciudadesRecorridas.size();i++){
        City c = s.ciudadesRecorridas[i];
        if(c.ciudad.compare(a.nombre_ciudad) == 0){
            return false;
        }
    }
    return true;
}

bool is_final_state(State &s) {
    int size = s.ciudadesRecorridas.size();
    if (size == 0) return false;
    City ultima_ciudad = s.ciudadesRecorridas[size-1];
    if (ultima_ciudad.ciudad.compare(destino_final) == 0)
        return true;
    return false;
}

City buscador_ciudad(string nombreC){
    for (int i = 0; i < (int)ciudades.size(); i++){
        if(ciudades[i].ciudad.compare(nombreC) == 0){
            return ciudades[i];
        }
    }
    return City();
}

// Funcion validada
State transition(State &s, Action &a) {
    State new_state = s;
    City c = buscador_ciudad(a.nombre_ciudad);
    
    new_state.ciudadActual = c ;
    new_state.ciudadesRecorridas.push_back(c);
    new_state.distanciaRecorrida += a.distancia;
    
    return new_state;
}

vector<Action> get_actions(State &s) {
    vector<Action> actions;
    int size = s.ciudadActual.vecinos.size();
    
    for (int i = 0; i < size; i++) {
        Action a;
        a.nombre_ciudad = s.ciudadActual.vecinos[i];
        a.distancia = s.ciudadActual.distances[i];
        if (is_valid_state(s, a)) {
            actions.push_back(a);
        }
    }
    return actions;
}

//CARGA DE DATOS
void Fill_Map(vector<City> &ciudades){
    City ciudad1;
    ciudad1.ciudad = "Arad";
    ciudad1.vecinos.push_back("Zerind");
    ciudad1.distances.push_back(75);
    ciudad1.vecinos.push_back("Sibiu");
    ciudad1.distances.push_back(140);
    ciudad1.vecinos.push_back("Timisoara");
    ciudad1.distances.push_back(118);
        
    ciudades.push_back(ciudad1);

    City ciudad2;
    ciudad2.ciudad = "Zerind";
    ciudad2.vecinos.push_back("Arad");
    ciudad2.distances.push_back(75);
    ciudad2.vecinos.push_back("Oradea");
    ciudad2.distances.push_back(71);

    ciudades.push_back(ciudad2);

    City ciudad3;
    ciudad3.ciudad = "Oradea";
    ciudad3.vecinos.push_back("Zerind");
    ciudad3.distances.push_back(71);
    ciudad3.vecinos.push_back("Sibiu");
    ciudad3.distances.push_back(151);

    ciudades.push_back(ciudad3);

    City ciudad4;
    ciudad4.ciudad = "Sibiu";
    ciudad4.vecinos.push_back("Fagaras");
    ciudad4.distances.push_back(99);
    ciudad4.vecinos.push_back("Oradea");
    ciudad4.distances.push_back(151);
    ciudad4.vecinos.push_back("Arad");
    ciudad4.distances.push_back(140);
    ciudad4.vecinos.push_back("Rimnicu Vilcea");
    ciudad4.distances.push_back(80);

    ciudades.push_back(ciudad4);

    City ciudad5;
    ciudad5.ciudad = "Fagaras";
    ciudad5.vecinos.push_back("Sibiu");
    ciudad5.distances.push_back(99);
    ciudad5.vecinos.push_back("Bucharest");
    ciudad5.distances.push_back(211);

    ciudades.push_back(ciudad5);

    City ciudad6;
    ciudad6.ciudad = "Neamt";
    ciudad6.vecinos.push_back("Lasi");
    ciudad6.distances.push_back(87);

    ciudades.push_back(ciudad6);

    City ciudad7;
    ciudad7.ciudad = "Lasi";
    ciudad7.vecinos.push_back("Neamt");
    ciudad7.distances.push_back(87);
    ciudad7.vecinos.push_back("Vaslui");
    ciudad7.distances.push_back(92);

    ciudades.push_back(ciudad7);

    City ciudad8;
    ciudad8.ciudad = "Vaslui";
    ciudad8.vecinos.push_back("Lasi");
    ciudad8.distances.push_back(92);
    ciudad8.vecinos.push_back("Urziceni");
    ciudad8.distances.push_back(142);

    ciudades.push_back(ciudad8);

    City ciudad9;
    ciudad9.ciudad = "Eforie";
    ciudad9.vecinos.push_back("Hirsova");
    ciudad9.distances.push_back(86);

    ciudades.push_back(ciudad9);

    City ciudad10;
    ciudad10.ciudad = "Hirsova";
    ciudad10.vecinos.push_back("Eforie");
    ciudad10.distances.push_back(86);
    ciudad10.vecinos.push_back("Urziceni");
    ciudad10.distances.push_back(98);

    ciudades.push_back(ciudad10);

    City ciudad11;
    ciudad11.ciudad = "Urziceni";
    ciudad11.vecinos.push_back("Hirsova");
    ciudad11.distances.push_back(98);
    ciudad11.vecinos.push_back("Vaslui");
    ciudad11.distances.push_back(142);
    ciudad11.vecinos.push_back("Bucharest");
    ciudad11.distances.push_back(85);

    ciudades.push_back(ciudad11);

    City ciudad12;
    ciudad12.ciudad = "Bucharest";
    ciudad12.vecinos.push_back("Urziceni");
    ciudad12.distances.push_back(85);
    ciudad12.vecinos.push_back("Fagaras");
    ciudad12.distances.push_back(211);
    ciudad12.vecinos.push_back("Pitesti");
    ciudad12.distances.push_back(101);
    ciudad12.vecinos.push_back("Giurgiu");
    ciudad12.distances.push_back(90);

    ciudades.push_back(ciudad12);

    City ciudad13;
    ciudad13.ciudad = "Giurgiu";
    ciudad13.vecinos.push_back("Bucharest");
    ciudad13.distances.push_back(90);

    ciudades.push_back(ciudad13);

    City ciudad14;
    ciudad14.ciudad = "Timisoara";
    ciudad14.vecinos.push_back("Arad");
    ciudad14.distances.push_back(118);
    ciudad14.vecinos.push_back("Lugoj");
    ciudad14.distances.push_back(111);

    ciudades.push_back(ciudad14);

    City ciudad15;
    ciudad15.ciudad = "Lugoj";
    ciudad15.vecinos.push_back("Timisoara");
    ciudad15.distances.push_back(111);
    ciudad15.vecinos.push_back("Mehadia");
    ciudad15.distances.push_back(70);

    ciudades.push_back(ciudad15);

    City ciudad16;
    ciudad16.ciudad = "Mehadia";
    ciudad16.vecinos.push_back("Lugoj");
    ciudad16.distances.push_back(70);
    ciudad16.vecinos.push_back("Dobreta");
    ciudad16.distances.push_back(75);

    ciudades.push_back(ciudad16);

    City ciudad17;
    ciudad17.ciudad = "Dobreta";
    ciudad17.vecinos.push_back("Mehadia");
    ciudad17.distances.push_back(75);
    ciudad17.vecinos.push_back("Craiova");
    ciudad17.distances.push_back(120);

    ciudades.push_back(ciudad17);

    City ciudad18;
    ciudad18.ciudad = "Craiova";
    ciudad18.vecinos.push_back("Dobreta");
    ciudad18.distances.push_back(120);
    ciudad18.vecinos.push_back("Pitesti");
    ciudad18.distances.push_back(138);
    ciudad18.vecinos.push_back("Rimnicu Vilcea");
    ciudad18.distances.push_back(146);

    ciudades.push_back(ciudad18);

    City ciudad19;
    ciudad19.ciudad = "Pitesti";
    ciudad19.vecinos.push_back("Rimnicu Vilcea");
    ciudad19.distances.push_back(97);
    ciudad19.vecinos.push_back("Bucharest");
    ciudad19.distances.push_back(101);
    ciudad19.vecinos.push_back("Craiova");
    ciudad19.distances.push_back(138);

    ciudades.push_back(ciudad19);

    City ciudad20;
    ciudad20.ciudad = "Rimnicu Vilcea";
    ciudad20.vecinos.push_back("Sibiu");
    ciudad20.distances.push_back(80);
    ciudad20.vecinos.push_back("Pitesti");
    ciudad20.distances.push_back(97);
    ciudad20.vecinos.push_back("Craiova");
    ciudad20.distances.push_back(146);

    ciudades.push_back(ciudad20);
}

struct Comp{
    bool operator()(State &a, State &b) {
        return a.distanciaRecorrida>b.distanciaRecorrida;
    }
};


State BFS_solve(State &initial) {
    priority_queue<State, vector<State>, Comp> S;
    S.push(initial);

    while (!S.empty()) {
        State state = S.top();        
        S.pop();
        
        if (is_final_state(state)) {
            return state;
        }

        vector<Action> actions = get_actions(state);
        
        for (Action a : actions) {
            State result = transition(state, a);
            S.push(result);
        }
    }

}

int main () {
    Fill_Map(ciudades);

    State initial;
    initial.distanciaRecorrida = 0;
    initial.ciudadActual = ciudades[0];
    initial.ciudadesRecorridas.push_back(initial.ciudadActual);

    State final_state = BFS_solve(initial);
    cout << "distancia: " << endl;
    cout << final_state.distanciaRecorrida<< endl;
    cout << "Resultado final: " << endl;
    cout << final_state.ciudadActual.ciudad<< endl;

    for (City c : final_state.ciudadesRecorridas) {
        cout << c.ciudad << endl;
    }
    
    return 0;
    
}