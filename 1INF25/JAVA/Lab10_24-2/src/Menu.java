
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
public class Menu {

    private List<Producto> productos;

    public Menu() {
        productos = new ArrayList<>();
    }
    
    
    
    
    public void cargarProductos(Scanner archivo) {
        while (archivo.hasNext()) {
            String tipo;
            tipo = archivo.next();
            Producto producto;
            if (tipo.compareTo("B") == 0) {
                producto = new Bebida();
            } else {
                producto = new Helado();
            }
            producto.cargar(archivo);
            productos.add(producto);
        }
    }

    public void imprimirMenu() {
        System.out.println("===============MENU DEL DIA =================");
        for (Producto producto : productos) {
            producto.imprimir();
            System.out.println("=======================================================================");
        }
    }

    public void imprimirMenuPersonalizado(Alumno alumno, Pais pais) {
        System.out.println("====================MENU en " + pais.getNombre() + " para, " + alumno.getCodigo()+":"+alumno.getNombre()+"======================");
        for (Producto producto : productos) {
            producto.imprimir(alumno,pais);
        }
    }

}
