/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunterosMultiples1Examen01Pregunta01.cpp
 * Author: 999
 * 
 * Created on May 15, 2025, 10:58 PM
 */

#include "PunterosMultiples1Examen01Pregunta01.hpp"

void cargarVentas(char**&ventasLibroCodigo,int **&ventasDniFechaPuntaje,const char *nom){
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input,nom);
    
    int capacidad=0, n_datos=0,dni,fecha,calificacion ;
    ventasDniFechaPuntaje=nullptr;
    ventasLibroCodigo=nullptr;
    char *codigo;
    while(true){
        codigo=lee_cadena(input,10,',');
        if(input.eof()) break;
        if(n_datos==capacidad)
            aumentar_capacidad(ventasDniFechaPuntaje,ventasLibroCodigo,capacidad,n_datos);
        leer_info(input,dni,fecha,calificacion);
        ingresar_datos(codigo,dni,fecha,calificacion,ventasDniFechaPuntaje[n_datos-1],ventasLibroCodigo[n_datos-1]);      
        n_datos++;
    }   
}
void pruebaCargaVentas(char **ventasLibroCodigo,int **ventasDniFechaPuntaje,const char *nom){
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output,nom);
    
    for (int i = 0; ventasDniFechaPuntaje[i]; i++) {
        int *datos= ventasDniFechaPuntaje[i];
        output << left<<setw(10)<<ventasLibroCodigo[i]<<setw(10)<<datos[0]<<setw(10)<<datos[1]<<datos[2]<<endl;
    }

}
void ingresar_datos(char *codigo,int dni, int fecha,int calificacion,int *&ventasDniFechaPuntaje,char *&ventasLibroCodigo){
    
    ventasLibroCodigo=codigo;
    
    ventasDniFechaPuntaje=new int[3];
    ventasDniFechaPuntaje[0]=dni;
    ventasDniFechaPuntaje[1]=fecha;
    ventasDniFechaPuntaje[2]=calificacion;
}
void leer_info(ifstream &input,int &dni, int&fecha,int&calificacion){
    //CRY6839,34460612,15/10/2023,93
//WPU8819,42302422,9/2/2024,15
    char c;
    int d,m,a;
    input >> dni>>c>>d>>c>>m>>c>>a>>c>>calificacion;
    fecha=d+m*100+a*10000;
    input.get();
}
void aumentar_capacidad(int **&ventasDniFechaPuntaje,char **&ventasLibroCodigo,int &capacidad,int &n_datos){
    capacidad+=INCREMENTO;
    int **aux_int;
    char **aux_char;
    if(ventasDniFechaPuntaje==nullptr){
        ventasDniFechaPuntaje=new int*[capacidad]{};
        ventasLibroCodigo=new char*[capacidad]{};
        ventasDniFechaPuntaje[0]=nullptr;
        ventasLibroCodigo[0]=nullptr;
        n_datos=1;        
    }else{
        aux_char=new char*[capacidad]{};
        aux_int=new int*[capacidad]{};
        for (int i = 0; i < n_datos; i++) {
            aux_char[i]=ventasLibroCodigo[i];
            aux_int[i]=ventasDniFechaPuntaje[i];
        }
        delete ventasDniFechaPuntaje;
        delete ventasLibroCodigo;
        ventasDniFechaPuntaje=aux_int;
        ventasLibroCodigo=aux_char;
    }
}
char *lee_cadena(ifstream &input, int size, char delim){
    char *cadena,buffer[size];
    input.getline(buffer,size,delim);
    if(input.eof()) return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}


void cargaLibros(char ***&libro,const char *nom){
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input,nom);
    char **buffer[300]{}, *titulo,*codigo,*autor;
    int n_datos=0;
    while(true){
        codigo=lee_cadena(input,10,',');
        if(input.eof()) break;
        titulo=lee_cadena(input,100,',');
        autor=lee_cadena(input,100,'\n');
        pasar_datos_libros(codigo,titulo,autor,buffer[n_datos]);
        n_datos++;
    }
    libro= new char**[n_datos]{};
    for (int i = 0; i < n_datos; i++) {
        libro[i]=buffer[i];
    }
    qsort(libro,n_datos,sizeof(char**),cmpcadena);
}
void pruebaLibros(char ***libro,const char *nom){
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output,nom);
    
    for (int i = 0; libro[i]; i++) {
        char **reg=libro[i];
        output << left<<setw(10)<<reg[0]<<setw(60)<<reg[1]<<reg[2]<<endl;
    }

}
int cmpcadena(const void *a,const void* b){
    void **ai=(void**)a;
    void **bi=(void**)b;
    void **rega=(void**)(*ai);
    void **regb=(void**)(*bi);
    char *noma=(char*)rega[1];
    char *nomb=(char*)regb[1];
    return strcmp(noma,nomb);
}
void pasar_datos_libros(char* codigo,char *titulo,char *autor,char **&registro){
    registro= new char*[3];
    registro[0]=codigo;
    registro[1]=titulo;
    registro[2]=autor;
}