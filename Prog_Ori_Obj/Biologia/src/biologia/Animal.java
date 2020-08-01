package biologia;

public abstract class Animal {
  
  private int energia = 10;
  
  public int getEnergia() {
    return energia;
  }
  
  public String quemSou() {
    return "animal";
  }
  
  public abstract void correr();

}
