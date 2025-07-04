
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
public class Producto extends Registro {

    private String codigo;
    private List<Traduccion> nombres;
    private List<Traduccion> descripciones;
    private double precio;
    private int stock;

    Producto() {
        nombres = new ArrayList<Traduccion>();
        descripciones = new ArrayList<Traduccion>();
    }

    @Override
    public void cargar(Scanner archivo) {
        setCodigo(archivo.next());

        while (!archivo.hasNextDouble()) {
            Traduccion trad;
            trad = new Traduccion();
            trad.setIdioma(archivo.next());
            trad.setTexto(archivo.next());
            nombres.add(trad);
        }
        setPrecio(archivo.nextDouble());
        while (!archivo.hasNextInt()) {
            Traduccion trad;
            trad = new Traduccion();
            trad.setIdioma(archivo.next());
            trad.setTexto(archivo.next());
            descripciones.add(trad);
        }
        setStock(archivo.nextInt());
    }

    @Override
    public void imprimir() {

        String nombre = obtenerNombre("ES");
        System.out.println(codigo + ": " + nombre);
        String descripcion = obtenerDescripcion("ES");
        System.out.println(descripcion);
        System.out.println("Precio: S/" + precio);
        System.out.print("Disponible: ");
        if (stock > 0) {
            System.out.println("Si");
        } else {
            System.out.println("No");
        }
    }

    public void imprimir(Alumno alumno, Pais pais) {
        String nombre = obtenerNombre(pais.getIdioma());
        System.out.println(codigo + ": " + nombre);
        String descripcion = obtenerDescripcion(pais.getIdioma());
        System.out.println(descripcion);
        System.out.println("Precio: "+pais.getMoneda() + " "+precio*pais.getTipoCambio());
        System.out.print("Disponible: ");
        if (stock > 0) {
            System.out.println("Si");
        } else {
            System.out.println("No");
        }
    }

    /**
     * @return the codigo
     */
    public String getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    /**
     * @return the precio
     */
    public double getPrecio() {
        return precio;
    }

    /**
     * @param precio the precio to set
     */
    public void setPrecio(double precio) {
        this.precio = precio;
    }

    /**
     * @return the stock
     */
    public int getStock() {
        return stock;
    }

    /**
     * @param stock the stock to set
     */
    public void setStock(int stock) {
        this.stock = stock;
    }

    public String obtenerNombre(String idioma) {
        String nom;
        nom = new String();
        for (Traduccion nombre : nombres) {
            if (idioma.compareTo(nombre.getIdioma()) == 0) {
                nom = nombre.getTexto();
            }
        }
        return nom;
    }

    public String obtenerDescripcion(String idioma) {
        String desc;
        desc = new String();
        for (Traduccion descripcion : descripciones) {
            if (idioma.compareTo(descripcion.getIdioma()) == 0) {
                desc = descripcion.getTexto();
            }
        }
        return desc;
    }
}
