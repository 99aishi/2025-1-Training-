import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Cafeteria {
    private final List<Pais> paises;
    private final Scanner archivo;
    //TODO: agregar miembros faltantes
    private final ArrayList<Alumno>participantes;
    private Menu menu;
    public Cafeteria() {
        paises = new ArrayList<>();
        archivo = new Scanner(System.in);
        //TODO: inicializar miembros faltantes
        participantes=new ArrayList<Alumno>();
        menu= new Menu();
    }
    
    public Cafeteria(final String nombreArchivo) throws FileNotFoundException {
        archivo = new Scanner(new File(nombreArchivo));
        paises = new ArrayList<>();
        //TODO: inicializar miembros faltantes
        participantes=new ArrayList<Alumno>();
        menu= new Menu();
    }
    
    public void cargarPaises() {
        while (archivo.hasNext()) {
            char tipo = archivo.next().charAt(0);
            if (!(tipo == 'I' || tipo == 'N')) break;
            
            Pais pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }
    
    public void cargarParticipantes() {
        //TODO: cargar participantes
        while(archivo.hasNext()){      
            Alumno alumno;
            String indicador;
            indicador=archivo.next();
            if(indicador.compareTo("FIN")==0) break;
            if(indicador.compareTo("I")==0){
                alumno = new AlumnoIntercambio();
            }else{
                alumno = new AlumnoRegular();
            }
            alumno.cargar(archivo);
            participantes.add(alumno);
        }
    }
    
    public void cargarMenu() {
        //TODO: cargar menu
        menu.cargarProductos(archivo);
    
    }
    
    public void imprimirPaises() {
        System.out.println("==================LISTADO DE PAISES===================");
        System.out.println("------------------------------------------------------");
        System.out.println(String.format("%-15s\t%-10s\t%-10s\t%-10s", "NOMBRE", "MONEDA", "TIPO-CAMBIO", "IDIOMA"));
        System.out.println("------------------------------------------------------");
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("======================================================");
        System.out.println();
    }
    
    public void imprimirParticipantes() {
        //TODO: cargar participantes
        for(Alumno alm : participantes){
            alm.imprimir();
        }
    }
    
    public void imprimirMenuPredeterminado() {
        //TODO: imprimir menu predeterminado
        menu.imprimirMenu();
    }
    
    public void imprimirMenusPersonalizados() {
        //TODO: imprimir menús personalizados
        for (Alumno participante : participantes) {
            String paisOrigen=participante.getPaisOrigen();
            for (Pais pais : paises) {
                if(pais.getNombre().compareTo(paisOrigen)==0)
                    menu.imprimirMenuPersonalizado(participante, pais);
            }
            
        }

    }
    
    private Pais buscarPais(String nombre) {
        for (Pais pais : paises) {
            if (pais.getNombre().equals(nombre)) {
                return pais;
            }
        }
        
        return paises.get(0);
    }
}