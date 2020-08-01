package biologia;

public class Mamifero extends Vertebrado {
  
  public String quemSou() {
    return super.quemSou() + " mamífero.";
  }
  
  public static void main(String[] args) {
    Mamifero m = new Mamifero();
    System.out.println(m.quemSou() + " " + m.getEnergia());
  }

  @Override
  public void correr() {
    System.out.println("Mamífero correndo...");
  }

}
