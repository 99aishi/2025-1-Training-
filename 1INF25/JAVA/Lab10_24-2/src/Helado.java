
import java.util.ArrayList;
import java.util.List;
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
public class Helado extends Producto{
    private List<String>toppings;

    public Helado() {
        toppings= new ArrayList<>();
    }
    
    
    
    
    @Override
    public void cargar(Scanner archivo){
        super.cargar(archivo);
        int c_topings=archivo.nextInt();
        
        for (int i = 0; i < c_topings; i++) {
            String topping;
            topping = archivo.next();
            toppings.add(topping);
        }
        
        
    }
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.print("Toppings disponibles:");
        for (String topping : toppings) {
            System.out.print(" "+topping);
        }
        System.out.println("");
    }
    
//    
//    public void imprimir(Alumno alumno, Pais pais){
//        
//    }
    
}
