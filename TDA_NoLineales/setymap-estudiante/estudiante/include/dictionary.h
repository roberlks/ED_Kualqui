#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

#endif
#include <set>
#include <string>
#include <vector>

using namespace std;
class Dictionary {
private:
    set<string> words;
public:

                            /**>Constructores por defecto y de copia<**/
    /**
     * @brief Constructor por defecto
     */

    Dictionary();

    /**
     * @brief Constructor de copia
     * @brief Crea un Dictionary con el mismo contenido que el que se pasa como argumento
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary& other);


                /**>Métodos para insertar, consultar la presencia, y borrar un elemento<**/

    /**
     * @brief Indica si una palabra está en el diccionario o no.
     * @brief Este metodo comprueba si una determinada palabra se encuentra o no en el diccionario
     * @param word Palabra que se quiere buscar
     * @return True si la palabra está en el diccionario, false en caso contrario
     */
    bool exists(const string& word) const;

     /**
      * @brief Inserta una palabra en el diccionario
      * @param word palabra a insertar en el diccionario
      * @return True si la palabra se ha insertado correctamente, false en caso contrario
      */
    bool insert (const string & word);

     /**
      * @brief Elimina una palabra del diccionario
      * @param word palabra a borrar del diccionario
      * @return True si la palabra se ha borrado correctamente, false en caso contrario
      */
    bool erase (const string & word);

        /**>Métodos para consultar el tamaño, consultar si el diccionario está vacío, y limpiar el diccionario<**/

    /**
     * @brief Limpia el dictionary
     * @brief Este método elimina todas las palabras contenidas en el conjunto
     */
    void clear();
    
    /**
     * @brief Comprueba si el diccionario está vacío
     * @return True si el diccionario esta vacio, false en caso contrario
     */
    bool empty() const;
    
    /**
     * @brief Tamaño del diccionario
     * @return Numero de palabras guardadas en el diccionario
     */
    unsigned int size () const;


    		/**>Las palabras de una determinada longitud<**/
    		
    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada.
     * @param Length Longitud de las palabras bucadas
     * @return Vector de palabras con la longitud deseada
     */
    std::vector<string> wordsOfLength (int length);
    
    
        	/**>Número de veces que aparece un determinado caracter en el diccionario<**/
   
    /**
     * @brief Indica el numero de aparciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el numero de apariciones
     */
     
    int getOcurrences (const char c);

    friend Dictionary operator+(const Dictionary& dic1, const Dictionary& dic2);
    



};
