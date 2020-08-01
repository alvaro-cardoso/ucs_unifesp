package formas;

import java.util.Random;

public class ManipulaFiguras {

  
  public static void m(Figura f) {
    double af = f.area();
  }
  
  public static void main(String[] args) {
    Figura f;
    
    Random aleatorio = new Random();
    int valor = aleatorio.nextInt(100) + 1;
    
    if(valor < 50)
      f = new Triangulo();
    else
      f = new Quadrado();
    
    m(f);
  }
  
}
