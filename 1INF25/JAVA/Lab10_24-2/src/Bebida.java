
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
public class Bebida extends Producto{
    private char tipoBebida;
    @Override
    public void cargar(Scanner archivo){
        super.cargar(archivo);
        String tipo;
        tipo = archivo.next();
        setTipoBebida(tipo.charAt(0));
        
    }
    
    
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.print("Tipo: ");
        switch (tipoBebida){
            case 'C':
                System.out.println("Cafe");
                break;
            case 'H':
                System.out.println("Chocolate");
                break;
            case 'T':
                System.out.println("Te");
                break;
            default:
                System.out.println("Infusion");
                break;
        }
    }

    /**
     * @return the tipoBebida
     */
    public char getTipoBebida() {
        return tipoBebida;
    }

    /**
     * @param tipoBebida the tipoBebida to set
     */
    public void setTipoBebida(char tipoBebida) {
        this.tipoBebida = tipoBebida;
    }
}
