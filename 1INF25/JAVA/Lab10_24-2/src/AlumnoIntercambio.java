
import java.util.ArrayList;
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
public class AlumnoIntercambio extends Alumno {
    
    private String paisOrigen;
    private final ArrayList<String> idiomas;
    private int numeroDeSemestres;
    
    AlumnoIntercambio(){
        idiomas= new ArrayList<String>();
    }
    @Override
    public void cargar(Scanner archivo){
        super.cargar(archivo);
        setPaisOrigen(archivo.next());
        
        while(!archivo.hasNextInt()){
            String idioma = archivo.next();
            this.idiomas.add(idioma);
        }
        setNumeroDeSemestres(archivo.nextInt());
    }
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Pais de origen: " + paisOrigen);
        System.out.print("Idiomas que habla: " );
        System.out.print(idiomas.size());
        for (String idioma : idiomas) {
            System.out.print(" "+idioma);
        }
        System.out.println();
        System.out.println("Se quedara "+numeroDeSemestres+" semestres");
        System.out.println("=======================================================================");
    }
    /**
     * @return the paisOrigen
     */
    @Override
    public String getPaisOrigen() {
        return paisOrigen;
    }

    /**
     * @param paisOrigen the paisOrigen to set
     */
    public void setPaisOrigen(String paisOrigen) {
        this.paisOrigen = paisOrigen;
    }

    /**
     * @return the numeroDeSemestres
     */
    public int getNumeroDeSemestres() {
        return numeroDeSemestres;
    }

    /**
     * @param numeroDeSemestres the numeroDeSemestres to set
     */
    public void setNumeroDeSemestres(int numeroDeSemestres) {
        this.numeroDeSemestres = numeroDeSemestres;
    }

    
}
