
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
public class AlumnoRegular extends Alumno {
    private String especialidad;
    private String facultad;

    public AlumnoRegular() {
    }
    
    
    @Override
    public void cargar(Scanner archivo){
        super.cargar(archivo);
        setEspecialidad(archivo.next());
        setFacultad(archivo.next());
    }
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Facultad: " + facultad);
        System.out.println("Especialidad: "+especialidad);
        System.out.println("=======================================================================");
    }
    @Override
    public  String getPaisOrigen(){
        return "Peru";
    }
    /**
     * @return the especialidad
     */
    public String getEspecialidad() {
        return especialidad;
    }

    /**
     * @param especialidad the especialidad to set
     */
    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    /**
     * @return the facultad
     */
    public String getFacultad() {
        return facultad;
    }

    /**
     * @param facultad the facultad to set
     */
    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }
    
}
