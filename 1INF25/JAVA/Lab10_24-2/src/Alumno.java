
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 999
 */
public abstract class Alumno extends Registro{
    private int codigo;
    private String nombre;
    
    @Override
    public void cargar(Scanner archivo){
        setCodigo(archivo.nextInt());
        setNombre(archivo.next());
        
    }
    @Override
    public void imprimir(){
        System.out.println(nombre+"     "+ codigo);
    }
    
    public abstract String getPaisOrigen();
//    public abstract double calcularPrecio();
    
    

    /**
     * @return the codigo
     */
    public int getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    
}
