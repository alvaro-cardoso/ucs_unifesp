package biologia;

public class Inseto extends Invertebrado {
  
  public String quemSou() {
    return super.quemSou() + " inseto";
  }

  public static void main(String[] args) {
    Inseto i = new Inseto();
    System.out.println(i.quemSou());
  }

  public void correr() {
    System.out.println("Inseto correndo...");
  }
}
