
#include <iostream>
#include "RouteRep.h"
#include "Countries.h"
#include "Image.h"

using namespace std;

#define RESULTADO "./datos/pruebas/resultado_final.ppm"


/**
 * @brief Calculate the position of a coordinate on a Image
 * @param row The row in the image. Return parameter
 * @param col The col in the image. Return parameter
 * @param I The image in which is calculated the position of the coordinate
 * @param loc The coordinate
*/
void posInImage(double &row, double &col, const Image &I, const Coord &loc){
    row = ((double)I.num_filas()/180) * (90 - loc.getLatitude());
    col = ((double)I.num_cols()/360) * (180+loc.getLongitude());
}

void paintFlag(const Countries &countries, const Coord &loc, const string &dir_flags, Image &world){
    Countries::const_iterator it_country = countries.find(*it);
    if (it_country != countries.cend()){
        // Imprimo el pais por pantalla
        cout << (*it_country).getName() << " ";
        
        string path_flag = dir_flags + (*it_country).getFlagPath();
        Image flag;
        flag.LeerImagen(path_flag.c_str());

        double row, col;
        posInImage(row, col, world, loc);
        world.PutImagen(row, col, flag, BLENDING);
    }
}


int main(int argc, char **argv){
    if (argc!=7){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.-Fichero con la informacion de los paises"<<endl;
        cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
        cout<<"3.-Directorio con las banderas"<<endl;
        cout<<"4.-Fichero con el almacen de rutas"<<endl;
        cout<<"5.- Nombre de la imagen con el avion"<<endl;
        cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;

        return 0;
    }

    Countries countries;
    ifstream f(argv[1]);
    f >> countries;

    Image world;
    world.LeerImagen(argv[2]);

    Image plane;
    plane.LeerImagen(argv[5], argv[6]);

    RouteRep rr(argv[4]);
    //f.close();
    //f.open(argv[4]);
    //f >> rr;

    cout << "Las rutas son:" << endl << rr << endl;

    cout << "Dime el código de una ruta: ";
    string a;

    cin >> a;

    Route R = rr.getRoute(a);

    string dir_flags = argv[3];
    if (dir_flags[dir_flags.length()-1] != '/') dir_flags += '/';

    Route::iterator it, it2;

    double angulo;
    Image rotated_plane;

    for (it = R.begin(), it2 = ++R.begin(); it2 != R.end(); ++it, ++it2){
        // Angulo de orientacion de los aviones
        angulo = (*it).orientation(*it2);
        rotated_plane = plane.Rota(angulo);

        // Fila y columna donde pegar el primer avion y la bandera en su caso

        double col_plane, row_plane;
        posInImage(row_plane, col_plane, world, *it);

        // El tipo de pegado para los aviones y las banderas
        Tipo_Pegado tp = BLENDING;

        // Pego el avion ya rotado
        world.PutImagen(row_plane, col_plane, rotated_plane, tp);
        
        // Pegar el avion en el punto medio 
        Coord midpoi = (*it).midpoint(*it2);
        double col_mid, row_mid;
        posInImage(row_mid, col_mid, world, midpoi);
        world.PutImagen(row_mid, col_mid, rotated_plane, tp);

        // Busco el pais que es y si el punto es un pais pego la bandera
        paintFlag(countries, *it, dir_flags, world);
        
    }    

    double col_plane, row_plane;
    posInImage(row_plane, col_plane, world, *it);

    world.PutImagen(row_plane, col_plane, rotated_plane, BLENDING);

    paintFlag(countries, *it, dir_flags, world);

    world.EscribirImagen(RESULTADO);


    return 0;
}