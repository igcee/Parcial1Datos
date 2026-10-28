#include <iostream>
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(int v)   
 {        
   valor = v;        
   siguiente = NULL;     
}

nodo(int v, nodo  *signodo)
    {
       valor = v;
       siguiente = signodo;
    }


   private:
    int valor=0;
    nodo *siguiente;
    
        
   friend class lista;
};

typedef nodo *pnodo; //Alias

class lista {
   public:
    lista() { primero =  NULL; }
    ~lista();
    
    void InsertarInicio(int v);//No retornan nada
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void Sumanum(int num);
    int largoLista();// retorno un valor numerico
    void creaNumLista(int num);
    int obtenerPos(int pos);
    //void DOS(int numero);
    //void CUATRO(int num1, int num2, int num3);
    
   private:
    pnodo primero;
   
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    cout<< endl;
    }
    
}

void lista::InsertarInicio(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);
     
   }
   else
   {
     
   primero=new nodo (v,primero);
     
    
    
     
   }
}
 
void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}


void lista::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1)
		{
        	//OPcion1
         // pnodo nuevo = new nodo(v);
          //nuevo->siguiente= primero;
          //primero= nuevo;     
          //OPcion 2
          InsertarInicio(v);
        }      
        else{
             nodo *aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;
        } 
		else 
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1)
		{
        	pnodo temp=primero;
        	primero=primero->siguiente;
        	delete temp; //BorrarInicio();
        }
		else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}

 void lista::Sumanum(int num)
{
   if (num == 0)
      cout << "Suma igual a 0";
   else
   {
   
       while (num!=0)
       {
	   
	     int temp=num%10;
		 InsertarInicio(temp);
		 num=num/10;
       }
      int suma=0;
      pnodo aux=primero; 
      while(aux !=NULL)
      {
      	suma=suma+aux->valor;
      	aux=aux->siguiente;
	  }
	  cout<<suma<<endl;
   }
	
}

void lista::creaNumLista(int num){
	int numero = num;
	while (numero!= 0){
		InsertarInicio(numero%10);
		numero = numero/10;
	}
}

int cuentadigitos(int num){
	int contador = 0;
	if (num == 0){
		return 0;
	}
	
	else{
		while (num != 0){
			num = num/10;
			contador++;		
		}
		return contador;
	}
}

int lista::obtenerPos(int pos){
	pnodo aux = primero;
	int i = 0;
	while (i<pos){
		aux = aux->siguiente;
		i++;
	}
	return aux->valor;
}





void DOS (int numero){
	int num = abs(numero);
	int cantidad = cuentadigitos(num);
	
	if (cantidad%5 != 0){
		cout << "Error ejercicio DOS: el largo del numero recibido no es multiplo de 5. Su largo es: " << cantidad%5 << endl;;
		return;
	}
	cout << "Numero original: " << numero << endl;
	lista listilla;
	while (num !=0){
		listilla.InsertarInicio(num%10);
		num = num/10;
		
		
	}
	
}


void CUATRO (int num1, int num2, int num3){
	cout << "test" << endl;
	int largo1 = cuentadigitos(num1);
	int largo2 = cuentadigitos(num2);
	int largo3 = cuentadigitos(num3);
	cout << "test" << endl;
	if (num1 < 0 or num2 < 0 or num3 < 0){
		cout << "Error ejercicio CUATRO: uno de los 3 numeros dados no es positivo" << endl;
		return;
	}
	else if (largo1%2 == 0 or largo2%2 == 0 or largo3%2 == 0){
		cout << "Error ejercicio CUATRO: uno de los 3 numeros dados no es de largo impar" << endl;
		return;
	}
	
	else if (largo1 != largo2 or largo2 != largo3 or largo1 != largo3){
		cout << "Error ejercicio CUATRO: los 3 numeros dados no son todos del mismo largo" << endl;
		return;
	}
	
	else{
		cout << "test" << endl;
		lista lista1;
		lista lista2;
		lista lista3;
		cout << "test" << endl;
		lista1.creaNumLista(num1);
		lista2.creaNumLista(num2);
		lista3.creaNumLista(num3);
		
		int largo = lista1.largoLista();
		int mitad = largo/2;
		

		int i = 0;
		cout << "test" << endl;
		lista listilla;
		cout << "=== NUMEROS ORIGINALES ===" << endl;
		cout << "Primer numero: " << num1<< endl;
		cout << "Segundo numero: " << num2<< endl;
		cout << "Tercer numero: " << num3<< endl;
		while (i < mitad){
			int j = largo-1-i;
			
			listilla.InsertarFinal(101);
			listilla.InsertarFinal(lista1.obtenerPos(mitad));
			listilla.InsertarFinal(lista3.obtenerPos(i));
			listilla.InsertarFinal(lista3.obtenerPos(j));
			listilla.InsertarFinal(010);
			
			listilla.InsertarFinal(101);
			listilla.InsertarFinal(lista3.obtenerPos(mitad));
			listilla.InsertarFinal(lista1.obtenerPos(i));
			listilla.InsertarFinal(lista1.obtenerPos(j));
			listilla.InsertarFinal(010);
			
			listilla.InsertarFinal(101);
			listilla.InsertarFinal(lista1.obtenerPos(mitad));
			listilla.InsertarFinal(lista2.obtenerPos(i));
			listilla.InsertarFinal(lista2.obtenerPos(mitad));
			listilla.InsertarFinal(010);
			
			listilla.InsertarFinal(101);
			listilla.InsertarFinal(lista3.obtenerPos(mitad));
			listilla.InsertarFinal(lista2.obtenerPos(j));
			listilla.InsertarFinal(lista2.obtenerPos(mitad));
			listilla.InsertarFinal(010);
			
			i++;
			
			
		}
		listilla.Mostrar();
		
		// 
		
		
		
	}
	
	
}





int main()
{
	/*
   lista Lista;//instancia null
   
    
  // Lista.Sumanum(234567); 
   cout<< "***************************************************************************************"<<endl;
   Lista.InsertarInicio(20);
   Lista.InsertarInicio(2);
   Lista.InsertarFinal(10);
   Lista.Mostrar();
   cout<<endl;
   cout<<endl;
   cout << Lista.largoLista();

   Lista.~lista();
   cin.get();
   
   */
   cout << "hola" << endl;
   int num1 = 3123590;
   int num2 = 8901285;
   int num3 = 4357623;
   
   CUATRO(num1,num2,num3);
   return 0;
}



